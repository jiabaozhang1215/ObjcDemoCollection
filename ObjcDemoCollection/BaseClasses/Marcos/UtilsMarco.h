//
//  UtilsMarco.h
//  OCProjects
//
//  Created by jiabaozhang on 2017/12/7.
//  Copyright © 2017年 jiabaozhang. All rights reserved.
//

#ifndef UtilsMarco_h
#define UtilsMarco_h

//-------------------系统版本------------------------
#define SystemVersionGreaterOrEqualThan(version) ([[[UIDevice currentDevice] systemVersion] floatValue] >= version)
#define IOS8_LATER SystemVersionGreaterOrEqualThan(8.0)
#define IOS9_LATER SystemVersionGreaterOrEqualThan(9.0)
#define IOS10_LATER SystemVersionGreaterOrEqualThan(10.0)
#define IOS11_LATER SystemVersionGreaterOrEqualThan(11.0)

//-------------------判空宏------------------------
#define StringIsNullOrEmpty(str) (NO == [str isKindOfClass:[NSString class]] || [str isKindOfClass:[NSNull class]] || str.length <= 0)
#define DictionaryIsNullOrEmpty(dict) (NO == [dict isKindOfClass:[NSDictionary class]] || [dict isKindOfClass:[NSNull class]] || [dict count] <= 0)
#define ArrayIsNullOrEmpty(arr) (NO == [arr isKindOfClass:[NSArray class]] || [arr isKindOfClass:[NSNull class]] || [arr count] <= 0)

//-------------------机型适配------------------------
#define kScreenHeight  [[UIScreen mainScreen] bounds].size.height
#define kScreenWidth   [[UIScreen mainScreen] bounds].size.width
#define iPhone4 ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(640, 960), [[UIScreen mainScreen] currentMode].size) : NO)
#define iPhone5 ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(640, 1136), [[UIScreen mainScreen] currentMode].size) : NO)
#define iPhone4or5 (iPhone4||iPhone5)
#define iPhoneX  ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(1125, 2436), [[UIScreen mainScreen] currentMode].size) : NO)
#define ALD(x) ((kScreenWidth / 375) * x)

//-------------------快捷创建------------------------
#define SCREEN_WIDTH  ([UIScreen mainScreen].bounds.size.width)
#define SCREEN_HEIGHT ([UIScreen mainScreen].bounds.size.height)
#define WS(weakSelf) __weak __typeof(&*self)weakSelf = self;
#define STRONGSELF(weakSelf) __strong __typeof(&*weakSelf) self = weakSelf;
#define RGBA(r,g,b,a) [UIColor colorWithRed:r/255.0f green:g/255.0f blue:b/255.0f alpha:a]
#define FONT(value) [UIFont systemFontOfSize:value]

//-------------------颜色常量------------------------
#define kThemeColor RGBA(27,108,250,1.0f)
#define kUIViewBgColor [UIColor whiteColor]
#define kTableViewCellBgColor [UIColor whiteColor]
#define kTableViewBgColor [UIColor whiteColor]
// rgb颜色转换（16进制->10进制）
#define UIColorFromRGB(rgbValue) [UIColor colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0 green:((float)((rgbValue & 0xFF00) >> 8))/255.0 blue:((float)(rgbValue & 0xFF))/255.0 alpha:1.0]

#define SuppressPerformSelectorLeakWarning(Stuff) \
do { \
_Pragma("clang diagnostic push") \
_Pragma("clang diagnostic ignored \"-Warc-performSelector-leaks\"") \
Stuff; \
_Pragma("clang diagnostic pop") \
} while (0)

//适配iOS11的scrollView属性改变automaticallyAdjustsScrollViewInsets
#define  adjustsScrollViewInsets_NO(scrollView,vc)\
SuppressPerformSelectorLeakWarning(\
if (@available(iOS 11.0, *)) {\
[scrollView setContentInsetAdjustmentBehavior:UIScrollViewContentInsetAdjustmentNever];\
} else {\
vc.automaticallyAdjustsScrollViewInsets = NO;\
}\
)

#define  adjustsScrollViewInsets_YES(scrollView,vc)\
SuppressPerformSelectorLeakWarning(\
if (@available(iOS 11.0, *)) {\
[scrollView setContentInsetAdjustmentBehavior:UIScrollViewContentInsetAdjustmentAlways];\
} else {\
vc.automaticallyAdjustsScrollViewInsets = YES;\
}\
)

#endif /* UtilsMarco_h */
