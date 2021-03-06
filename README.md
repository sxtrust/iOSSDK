
# 山西信托iOS SDK

## 安装依赖

###### 1、pod安装
```
稳定版：
当前最新可用版本为v1.0.3
```
```
pod 'SXTrustSDK'
```

###### 2、手动安装

```
1)、从tag中下载对应的SXTrustSDK.framework和SXTrustSDKBundle.bundle文件;
2）、添加进项目;
3）、添加依赖 AVFoundation.framework、WebKit.framework、JavaScriptCore.framework、libxml2;
4）、在'Target - Build Settings - Other Linker Flags' 里添加 '-ObjC';
```

## 权限设置

```
需在项目工程的 info.plist 文件中配置相关权限
NSCameraUsageDescription  // 相机
NSMicrophoneUsageDescription // 麦克风
NSAppleMusicUsageDescription // 媒体资料
NSPhotoLibraryUsageDescription // 相册
```

## 接口

###### 1、Header引入

```
#import <SXTrustSDK/SXTrustSDK.h>
```

###### 2、在调用sdk前，设置渠道号和环境参数

```
typedef NS_ENUM(NSInteger,SXTrustEnv) {
    SXTrustEnvPublish,      // 生产环境
    SXTrustEnvPublicTest    // 外网测试    
};

/**
 *  山西信托实例注册
 *  @param channelKey  渠道号,由山西信托给予. 必填
 *  @param env 环境
 */
+ (SXTrust *)registerClient:(NSString *)channelKey env:(SXTrustEnv)env;

```

###### 3、方法调用

```
/**
 *  山西信托产品列表入口
 *  @param prodCodes  需要具体展示产品列表. 为空时默认展示渠道下的全部产品.  可选.  调用方式比如 @[@"PN001",@"PN002"]
 *  @param navigator 控制器.  用于视图管理.  必填
 *  @param callback 事务回调.  可选
 */
+ (void)showProducts:(nullable NSArray <NSString *>*)prodCodes
           navigator:(UINavigationController *)navigator
            callback:(nullable void(^)(SXTrustResultCode code, NSString *message))callback;
    
```

###### v1.0.2新增
```
/**
 *  保存实名信息用于实名流程填写.  需在showProducts:navigator:callback:前调用.  否则实名信息不会填写，需用户自己输入.
 *  只内存保存，下次启动app需重新赋值
 */
+ (void)saveUserInfo:(SXTrustUserInfo *)userInfo;
```
```
/**
 *  删除保存的信息
 */
+ (void)deleteUserInfo;
```
