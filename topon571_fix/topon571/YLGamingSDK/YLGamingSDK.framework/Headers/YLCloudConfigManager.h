//
//  KXCloudConfigManager.h
//  KXGamingSDK
//
//  Created by lmm on 2019/12/4.
//  Copyright © 2019 kaixin001.com. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface YLCloudConfigManager : NSObject

+ (void)obtainConfigFromCloud:(NSString *)defaultValue result:(void (^)(NSString *resultStr))config;

/// 实时监听配置
/// @param configValue 返回变化后的配置
+ (void)cloudConfigChanged:(void (^)(NSString *resultStr))configValue;

@end

NS_ASSUME_NONNULL_END
