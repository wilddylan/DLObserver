//
//  DLObserver.h
//  DLObserver
//
//  Created by XueYulun on 15/7/28.
//  Copyright © 2015年 __Dylan. All rights reserved.
//

#import <Foundation/Foundation.h>

#define metamacro_exprify(...) \
((__VA_ARGS__), true)
#define metamacro_stringify(VALUE) \
metamacro_stringify_(VALUE)
#define metamacro_concat(A, B) \
metamacro_concat_(A, B)
#define metamacro_at(N, ...) \
metamacro_concat(metamacro_at, N)(__VA_ARGS__)
#define metamacro_argcount(...) \
metamacro_at(20, __VA_ARGS__, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1)
#define metamacro_foreach(MACRO, SEP, ...) \
metamacro_foreach_cxt(metamacro_foreach_iter, SEP, MACRO, __VA_ARGS__)
#define metamacro_foreach_cxt(MACRO, SEP, CONTEXT, ...) \
metamacro_concat(metamacro_foreach_cxt, metamacro_argcount(__VA_ARGS__))(MACRO, SEP, CONTEXT, __VA_ARGS__)
#define metamacro_foreach_cxt_recursive(MACRO, SEP, CONTEXT, ...) \
metamacro_concat(metamacro_foreach_cxt_recursive, metamacro_argcount(__VA_ARGS__))(MACRO, SEP, CONTEXT, __VA_ARGS__)
#define metamacro_foreach_concat(BASE, SEP, ...) \
metamacro_foreach_cxt(metamacro_foreach_concat_iter, SEP, BASE, __VA_ARGS__)
#define metamacro_for_cxt(COUNT, MACRO, SEP, CONTEXT) \
metamacro_concat(metamacro_for_cxt, COUNT)(MACRO, SEP, CONTEXT)
#define metamacro_head(...) \
metamacro_head_(__VA_ARGS__, 0)
#define metamacro_tail(...) \
metamacro_tail_(__VA_ARGS__)
#define metamacro_take(N, ...) \
metamacro_concat(metamacro_take, N)(__VA_ARGS__)
#define metamacro_drop(N, ...) \
metamacro_concat(metamacro_drop, N)(__VA_ARGS__)
#define metamacro_dec(VAL) \
metamacro_at(VAL, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19)
#define metamacro_inc(VAL) \
metamacro_at(VAL, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21)
#define metamacro_if_eq(A, B) \
metamacro_concat(metamacro_if_eq, A)(B)
#define metamacro_if_eq_recursive(A, B) \
metamacro_concat(metamacro_if_eq_recursive, A)(B)
#define metamacro_is_even(N) \
metamacro_at(N, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1)
#define metamacro_not(B) \
metamacro_at(B, 1, 0)
#define metamacro_stringify_(VALUE) # VALUE
#define metamacro_concat_(A, B) A ## B
#define metamacro_foreach_iter(INDEX, MACRO, ARG) MACRO(INDEX, ARG)
#define metamacro_head_(FIRST, ...) FIRST
#define metamacro_tail_(FIRST, ...) __VA_ARGS__
#define metamacro_consume_(...)
#define metamacro_expand_(...) __VA_ARGS__
#define metamacro_foreach_concat_iter(INDEX, BASE, ARG) metamacro_foreach_concat_iter_(BASE, ARG)
#define metamacro_foreach_concat_iter_(BASE, ARG) BASE ## ARG
#define metamacro_at0(...) metamacro_head(__VA_ARGS__)
#define metamacro_at1(_0, ...) metamacro_head(__VA_ARGS__)
#define metamacro_at2(_0, _1, ...) metamacro_head(__VA_ARGS__)
#define metamacro_at3(_0, _1, _2, ...) metamacro_head(__VA_ARGS__)
#define metamacro_at4(_0, _1, _2, _3, ...) metamacro_head(__VA_ARGS__)
#define metamacro_at5(_0, _1, _2, _3, _4, ...) metamacro_head(__VA_ARGS__)
#define metamacro_at6(_0, _1, _2, _3, _4, _5, ...) metamacro_head(__VA_ARGS__)
#define metamacro_at7(_0, _1, _2, _3, _4, _5, _6, ...) metamacro_head(__VA_ARGS__)
#define metamacro_at8(_0, _1, _2, _3, _4, _5, _6, _7, ...) metamacro_head(__VA_ARGS__)
#define metamacro_at9(_0, _1, _2, _3, _4, _5, _6, _7, _8, ...) metamacro_head(__VA_ARGS__)
#define metamacro_at10(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, ...) metamacro_head(__VA_ARGS__)
#define metamacro_at11(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, ...) metamacro_head(__VA_ARGS__)
#define metamacro_at12(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, ...) metamacro_head(__VA_ARGS__)
#define metamacro_at13(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, ...) metamacro_head(__VA_ARGS__)
#define metamacro_at14(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, ...) metamacro_head(__VA_ARGS__)
#define metamacro_at15(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, ...) metamacro_head(__VA_ARGS__)
#define metamacro_at16(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, ...) metamacro_head(__VA_ARGS__)
#define metamacro_at17(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, ...) metamacro_head(__VA_ARGS__)
#define metamacro_at18(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, ...) metamacro_head(__VA_ARGS__)
#define metamacro_at19(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, ...) metamacro_head(__VA_ARGS__)
#define metamacro_at20(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, ...) metamacro_head(__VA_ARGS__)

#define metamacro_if_eq0(VALUE) \
metamacro_concat(metamacro_if_eq0_, VALUE)

#define metamacro_if_eq0_0(...) __VA_ARGS__ metamacro_consume_
#define metamacro_if_eq0_1(...) metamacro_expand_
#define metamacro_if_eq0_2(...) metamacro_expand_
#define metamacro_if_eq0_3(...) metamacro_expand_
#define metamacro_if_eq0_4(...) metamacro_expand_
#define metamacro_if_eq0_5(...) metamacro_expand_
#define metamacro_if_eq0_6(...) metamacro_expand_
#define metamacro_if_eq0_7(...) metamacro_expand_
#define metamacro_if_eq0_8(...) metamacro_expand_
#define metamacro_if_eq0_9(...) metamacro_expand_
#define metamacro_if_eq0_10(...) metamacro_expand_
#define metamacro_if_eq0_11(...) metamacro_expand_
#define metamacro_if_eq0_12(...) metamacro_expand_
#define metamacro_if_eq0_13(...) metamacro_expand_
#define metamacro_if_eq0_14(...) metamacro_expand_
#define metamacro_if_eq0_15(...) metamacro_expand_
#define metamacro_if_eq0_16(...) metamacro_expand_
#define metamacro_if_eq0_17(...) metamacro_expand_
#define metamacro_if_eq0_18(...) metamacro_expand_
#define metamacro_if_eq0_19(...) metamacro_expand_
#define metamacro_if_eq0_20(...) metamacro_expand_

#define metamacro_if_eq1(VALUE) metamacro_if_eq0(metamacro_dec(VALUE))
#define metamacro_if_eq2(VALUE) metamacro_if_eq1(metamacro_dec(VALUE))
#define metamacro_if_eq3(VALUE) metamacro_if_eq2(metamacro_dec(VALUE))
#define metamacro_if_eq4(VALUE) metamacro_if_eq3(metamacro_dec(VALUE))
#define metamacro_if_eq5(VALUE) metamacro_if_eq4(metamacro_dec(VALUE))
#define metamacro_if_eq6(VALUE) metamacro_if_eq5(metamacro_dec(VALUE))
#define metamacro_if_eq7(VALUE) metamacro_if_eq6(metamacro_dec(VALUE))
#define metamacro_if_eq8(VALUE) metamacro_if_eq7(metamacro_dec(VALUE))
#define metamacro_if_eq9(VALUE) metamacro_if_eq8(metamacro_dec(VALUE))
#define metamacro_if_eq10(VALUE) metamacro_if_eq9(metamacro_dec(VALUE))
#define metamacro_if_eq11(VALUE) metamacro_if_eq10(metamacro_dec(VALUE))
#define metamacro_if_eq12(VALUE) metamacro_if_eq11(metamacro_dec(VALUE))
#define metamacro_if_eq13(VALUE) metamacro_if_eq12(metamacro_dec(VALUE))
#define metamacro_if_eq14(VALUE) metamacro_if_eq13(metamacro_dec(VALUE))
#define metamacro_if_eq15(VALUE) metamacro_if_eq14(metamacro_dec(VALUE))
#define metamacro_if_eq16(VALUE) metamacro_if_eq15(metamacro_dec(VALUE))
#define metamacro_if_eq17(VALUE) metamacro_if_eq16(metamacro_dec(VALUE))
#define metamacro_if_eq18(VALUE) metamacro_if_eq17(metamacro_dec(VALUE))
#define metamacro_if_eq19(VALUE) metamacro_if_eq18(metamacro_dec(VALUE))
#define metamacro_if_eq20(VALUE) metamacro_if_eq19(metamacro_dec(VALUE))

#define keypath(...) \
_Pragma("clang diagnostic push") \
_Pragma("clang diagnostic ignored \"-Warc-repeated-use-of-weak\"") \
metamacro_if_eq(1, metamacro_argcount(__VA_ARGS__))\
(keypath1(__VA_ARGS__))\
(keypath2(__VA_ARGS__))
_Pragma("clang diagnostic pop") \

#define keypath1(PATH) \
(((void)(NO && ((void)PATH, NO)), strchr(# PATH, '.') + 1))

#define keypath2(OBJ, PATH) \
(((void)(NO && ((void)OBJ.PATH, NO)), # PATH))

/*!
 *  回调Block
 */
typedef void(^ValueChangedBlock)(id value);

/*!
 *  信号, 用作后期的处理, 回调处理
 */
@interface DLGun : NSObject

@property (nonatomic, assign) id target;
@property (nonatomic, strong) NSString * keyPath;
@property (nonatomic, assign) void * context;
@property (nonatomic, copy  ) ValueChangedBlock fireBlock;

- (void)subScribeBlock: (ValueChangedBlock)block;

@end

#define DLBind(TARGET, KEYPATH) \
[[DLObserver Observer] AimAt:(TARGET) location:(@keypath(TARGET, KEYPATH))] // @ 宏定义, 快速创建监听

#define DLDraw(TARGET, KEYPATH) \
[[DLObserver Observer] Draw:(TARGET) location:(@keypath(TARGET, KEYPATH))] // @ 宏定义, 快速移除

@interface DLObserver : NSObject

+ (instancetype)Observer;

/*!
 *  瞄准这个位置的属性 (监听)
 *
 *  @param target  敌人
 *  @param keyPath 敌人的位置
 *
 *  @return 返回这把枪, 用于Fire Block
 */
- (DLGun *)AimAt: (id)target location: (NSString *)keyPath;

/*!
 *  撤退！(不在监听)
 *
 *  @param target   敌人
 *  @param keyPAath 敌人的位置
 */
- (void)Draw: (id)target location: (NSString *)keyPAath;

/*!
 *  跑！（移除所有监听）
 */
- (void)DrawAll;

@end
