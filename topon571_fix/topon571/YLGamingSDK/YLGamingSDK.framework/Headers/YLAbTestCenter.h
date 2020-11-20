//
//  YLAbTestCenter.h
//  YLGamingSDK
//
//  Created by lmm on 2019/9/23.
//  Copyright © 2019 kaixin001.com. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface YLAbTestCenter : NSObject



/// 通过key获取配置的值
/// @param key 对应的key
/// @param defaultValue 默认值
/// @param result 返回配置
+ (void)abTestConfigValueForKey:(NSString *)key defaultValue:(id)defaultValue result:(void (^)(id))result;

/// 获取AB测试所有配置
/// @param defaultValue 默认配置
/// @param result 返回配置
+ (void)abTestAllConfigValue:(NSString *)defaultValue result:(void (^)(NSString *))result;


/// 实时监听配置
/// @param configValue 返回变化后的配置
+ (void)abTestConfigChanged:(void (^)(NSString *))configValue;


@end

NS_ASSUME_NONNULL_END
