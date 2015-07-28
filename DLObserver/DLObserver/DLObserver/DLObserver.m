//
//  DLObserver.m
//  DLObserver
//
//  Created by XueYulun on 15/7/28.
//  Copyright © 2015年 __Dylan. All rights reserved.
//

#import "DLObserver.h"
#import <UIKit/UIKit.h>

@implementation DLGun

- (void)subScribeBlock: (ValueChangedBlock)block {
    
    self.fireBlock = block;
}

@end

@interface DLObserver ()

@property (nonatomic, strong) NSMutableArray * GunArray;

@end

static DLObserver * observer = nil;

@implementation DLObserver

+ (instancetype)Observer {
    
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        
        observer = [[[self class] alloc] init];
    });
    return observer;
}

- (DLGun *)AimAt:(id)target location:(NSString *)keyPath {
    
    DLGun * newGun = [[DLGun alloc] init];
    newGun.target = target;
    newGun.keyPath = keyPath;
    newGun.context = (__bridge void *)target;
    [self AddGun:newGun];
    
    return newGun;
}

- (void)Draw:(id)target location:(NSString *)keyPAath {
    
    __block DLGun * currentGun = nil;
    [self.GunArray enumerateObjectsUsingBlock:^(DLGun *  __nonnull gun, NSUInteger idx, BOOL * __nonnull stop) {
        
        if (gun.context == (__bridge void *)target) {
            
            currentGun = gun;
        }
    }];
    
    if (currentGun) {
        
        [self.GunArray removeObject:currentGun];
        [target removeObserver:self forKeyPath:keyPAath context:currentGun.context];
    }
}

- (void)DrawAll {
    
    [self.GunArray enumerateObjectsUsingBlock:^(DLGun *  __nonnull gun, NSUInteger idx, BOOL * __nonnull stop) {
        
        [gun.target removeObserver:self forKeyPath:gun.keyPath context:gun.context];
    }];
    
    [self.GunArray removeAllObjects];
}

- (void)AddGun: (DLGun *)newGun {
    
    [self.GunArray addObject:newGun];
    
    // Add Observer
    [newGun.target addObserver:self forKeyPath:newGun.keyPath options:NSKeyValueObservingOptionNew context:newGun.context];
    
    if (
        [newGun.target isKindOfClass:[UITextField class]]) {
        
        [newGun.target addTarget:self action:@selector(valueChanged:) forControlEvents:UIControlEventAllEvents];
    }
}

- (void)observeValueForKeyPath:(nullable NSString *)keyPath ofObject:(nullable id)object change:(nullable NSDictionary<NSString *,id> *)change context:(nullable void *)context {
    
    __block DLGun * currentGun = nil;
    [self.GunArray enumerateObjectsUsingBlock:^(DLGun *  __nonnull gun, NSUInteger idx, BOOL * __nonnull stop) {
       
        if (gun.context == context) {
            
            currentGun = gun;
        }
    }];
    
    if (currentGun) {
        
        currentGun.fireBlock([currentGun.target valueForKeyPath:currentGun.keyPath]);
    }
}

- (void)valueChanged: (id)sender {
    
    // 枚举, 操作一下目标的值, 简单的操作。
    
    [self.GunArray enumerateObjectsUsingBlock:^(DLGun * obj, NSUInteger idx, BOOL *stop) {
        
        if (obj.target == sender) {
            
            obj.fireBlock([obj.target valueForKeyPath:obj.keyPath]);
        }
    }];
}

- (NSMutableArray *)GunArray {
    
    if (!_GunArray) {
        
        _GunArray = [NSMutableArray arrayWithCapacity:10];
    }
    return _GunArray;
}

@end
