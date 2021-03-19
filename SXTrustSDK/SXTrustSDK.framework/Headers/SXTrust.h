//
//  SXTrust.h
//  SXTrust
//
//  Created by Shan Xi Trust on 2021/3/4.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger,SXTrustResultCode) {
    SXTrustResultBack = 0,         // 返回按钮返回
    SXTrustResultParamError = 1    // 相关入参错误
};

typedef NS_ENUM(NSInteger,SXTrustEnv) {
    SXTrustEnvPublish,      // 生产环境
    SXTrustEnvPublicTest    // 外网测试    
};

@interface SXTrust : NSObject

/**
 *  山西信托实例注册
 *  @param channelKey  渠道号. 必填
 *  @param env 环境
 */
+ (SXTrust *)registerClient:(NSString *)channelKey env:(SXTrustEnv)env;

/**
 *  山西信托产品列表入口
 *  @param prodCodes  需要具体展示产品列表. 为空时默认展示渠道下的全部产品.  可选
 *  @param navigator 控制器.  用于视图管理.  必填
 *  @param callback 事务回调.  可选
 */
+ (void)showProducts:(nullable NSArray <NSString *>*)prodCodes
           navigator:(UINavigationController *)navigator
            callback:(nullable void(^)(SXTrustResultCode code, NSString *message))callback;
                

@end

NS_ASSUME_NONNULL_END