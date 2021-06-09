//
//  ZZCMacroDefine.h
//  ZZCMacroDefine_Example
//
//  Created by zzc on 2021/6/9.
//  Copyright © 2021 zhengzhicheng. All rights reserved.
//

#ifndef ZZCMacroDefine_h
#define ZZCMacroDefine_h

//获取系统对象
#define KApplication        [UIApplication sharedApplication]
#define KAppWindow          [UIApplication sharedApplication].delegate.window
#define KAppDelegate        (AppDelegate*)[UIApplication sharedApplication].delegate;
// 设备是否是 iPhoneX
#define KDevice_Is_iPhoneX \
({BOOL isPhoneX = NO;\
if (@available(iOS 11.0, *)) {\
isPhoneX = [[UIApplication sharedApplication] delegate].window.safeAreaInsets.bottom > 0.0;\
}\
(isPhoneX);})

#define KRootViewController [UIApplication sharedApplication].delegate.window.rootViewController

#define KStatusBarHeight [[UIApplication sharedApplication] statusBarFrame].size.height
#define KNavBarHeight 44.0
#define KTabBarHeight ([[UIApplication sharedApplication] statusBarFrame].size.height>20?83:49)
#define KTopHeight (kStatusBarHeight + kNavBarHeight)

//获取屏幕宽高
#define KScreenWidth ([[UIScreen mainScreen] bounds].size.width)
#define KScreenHeight [[UIScreen mainScreen] bounds].size.height
#define kScreen_Bounds [UIScreen mainScreen].bounds
#define KScreen_Resolution (SCREEN_WIDTH * SCREEN_HEIGHT * ([UIScreen mainScreen].scale))

#define Iphone6ScaleWidth KScreenWidth/375.0
#define Iphone6ScaleHeight KScreenHeight/667.0
//根据ip6的屏幕来拉伸
#define kKRealValue(with) ((with)*(KScreenWidth/375.0f))

//强弱引用
#define KWeakSelf(type)  __weak typeof(type) weak##type = type;
#define KStrongSelf(type) __strong typeof(type) type = weak##type;

//View 圆角和加边框
#define ViewBorderRadius(View, Radius, Width, Color)\
\
[View.layer setCornerRadius:(Radius)];\
[View.layer setMasksToBounds:YES];\
[View.layer setBorderWidth:(Width)];\
[View.layer setBorderColor:[Color CGColor]]

// View 圆角
#define ViewRadius(View, Radius)\
\
[View.layer setCornerRadius:(Radius)];\
[View.layer setMasksToBounds:YES]

// 当前系统版本
#define CurrentSystemVersion [[UIDevice currentDevice].systemVersion doubleValue]
//当前语言
#define CurrentLanguage (［NSLocale preferredLanguages] objectAtIndex:0])

//拼接字符串
#define NSStringFormat(format,...) [NSString stringWithFormat:format,##__VA_ARGS__]

//随机色
#define KRandomColor    KRGBColor(arc4random_uniform(256)/255.0,arc4random_uniform(256)/255.0,arc4random_uniform(256)/255.0)
// RGB颜色
#define KRGBColor(r, g, b) [UIColor colorWithRed:(r)/255.0 green:(g)/255.0 blue:(b)/255.0 alpha:1.0]
// RGB颜色 alpha
#define KRGBAColor(r, g, b, a) [UIColor colorWithRed:(r)/255.0 green:(g)/255.0 blue:(b)/255.0 alpha:a]
//16进制颜色
#define KRGB16Color(rgbValue) [UIColor colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0 green:((float)((rgbValue & 0xFF00) >> 8))/255.0 blue:((float)(rgbValue & 0xFF))/255.0 alpha:1.0]
//字体
#define BOLDSYSTEMFONT(FONTSIZE)[UIFont boldSystemFontOfSize:FONTSIZE]
#define SYSTEMFONT(FONTSIZE)    [UIFont systemFontOfSize:FONTSIZE]
#define FONT(NAME, FONTSIZE)    [UIFont fontWithName:(NAME) size:(FONTSIZE)]


//定义UIImage对象
#define ImageWithFile(_pointer) [UIImage imageWithContentsOfFile:([[NSBundle mainBundle] pathForResource:[NSString stringWithFormat:@"%@@%dx", _pointer, (int)[UIScreen mainScreen].nativeScale] ofType:@"png"])]
#define IMAGE_NAMED(name) [UIImage imageNamed:name]

//数据验证
#define StrValid(f) (f!=nil && [f isKindOfClass:[NSString class]] && ![f isEqualToString:@""])
#define SafeStr(f) (StrValid(f) ? f:@"")
#define HasString(str,key) ([str rangeOfString:key].location!=NSNotFound)

#define ValidStr(f) StrValid(f)
#define ValidDict(f) (f!=nil && [f isKindOfClass:[NSDictionary class]])
#define ValidArray(f) (f!=nil && [f isKindOfClass:[NSArray class]] && [f count]>0)
#define ValidNum(f) (f!=nil && [f isKindOfClass:[NSNumber class]])
#define ValidClass(f,cls) (f!=nil && [f isKindOfClass:[cls class]])
#define ValidData(f) (f!=nil && [f isKindOfClass:[NSData class]])
//获取通知中心
#define KNotificationCenter [NSNotificationCenter defaultCenter]
//快速发通知
#define KPost_Notify(_notificationName, _obj) [[NSNotificationCenter defaultCenter] postNotificationName:_notificationName object:_obj];
//添加观察者
#define KAdd_Observer(_observer, _observerSelector, _notificationName, _obj) [[NSNotificationCenter defaultCenter] addObserver:_observer selector:@selector(_observerSelector) name:_notificationName object: _obj];
//移除单个观察者
#define KRemove_Observer(_observer, _notificationName, _obj)   [[NSNotificationCenter defaultCenter] removeObserver:_observer name:_notificationName object:_obj];
//移除观察者
#define KRemove_AllObserver(_observer) [[NSNotificationCenter defaultCenter] removeObserver:_observer];

//NSUserDefaults 实例化
#define KUer_Defaults [NSUserDefaults standardUserDefaults]

//获取temp
#define KPathTemp NSTemporaryDirectory()

//获取沙盒Document
#define KPathDocument [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory,NSUserDomainMask, YES) firstObject]

//获取沙盒Cache
#define KPathCache [NSSearchPathForDirectoriesInDomains(NSCachesDirectory,NSUserDomainMask, YES) firstObject]


#endif /* ZZCMacroDefine_h */
