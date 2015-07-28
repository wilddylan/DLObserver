//
//  ViewController.m
//  DLObserver
//
//  Created by XueYulun on 15/7/28.
//  Copyright © 2015年 __Dylan. All rights reserved.
//

#import "ViewController.h"
#import "DLObserver.h"

@implementation DLModel

@end

@interface ViewController () {
    
    DLModel * newModel;
}

@property (weak, nonatomic) IBOutlet UILabel *DLLabel;
@property (weak, nonatomic) IBOutlet UITextField *DLTextField;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    [DLBind(_DLLabel, text) subScribeBlock:^(id value) {
        
        NSLog(@"Label: %@", value);
    }];
    
    [DLBind(_DLTextField, text) subScribeBlock:^(id value) {
       
        NSLog(@"TextField: %@", value);
        
        _DLLabel.text = value;
    }];
    
    // Label
    
    _DLLabel.text = @"Hello, Dylan";
    
    // TextField
    
//    _DLTextField.text = @"Hello, Dylan (TextField)";
    
    newModel = [[DLModel alloc] init];
    newModel.name = @"A_Student";
    
    [DLBind(newModel, name) subScribeBlock:^(id value) {
       
        NSLog(@"%@", value);
    }];
    
    newModel.name = @"B_Student";
    
    DLDraw(newModel, name);
    
    newModel.name = @"C_Student";
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
