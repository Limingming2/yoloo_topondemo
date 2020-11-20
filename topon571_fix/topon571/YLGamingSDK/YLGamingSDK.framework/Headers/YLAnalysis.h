//
//  YLAnalysis.h
//  YLGamingSDK
//
//  Created by lmm on 2019/7/18.
//  Copyright © 2019  All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface YLAnalysis : NSObject

#pragma mark GameLevel methods

/** 设置玩家等级属性.
 @param level 玩家等级
 */
+ (void)setUserLevelId:(int)level;

/** 进入关卡.
 @param level 关卡
 */
+ (void)onLevelStart:(int)level;

+ (void)onGameStart:(NSString *)levelName;

/** 通过关卡.
 @param level 关卡,如果level == nil 则为当前关卡
 */
+ (void)onLevelPassed:(int)level;

+ (void)onGamePassed:(NSString *)levelName;

// todo: 增加关卡，参数为字符串

/** 未通过关卡.
 @param level 关卡,如果level == nil 则为当前关卡
 */
+ (void)onLevelFailed:(int)level;

+ (void)onGameFailed:(NSString *)levelName;


#pragma mark event logs

///---------------------------------------------------------------------------------------
/// @name  事件统计
///---------------------------------------------------------------------------------------

/** 自定义事件,数量统计.
 使用前，请先到友盟App管理后台的设置->编辑自定义事件 中添加相应的事件ID，然后在工程中传入相应的事件ID
 @param  eventId 网站上注册的事件Id.
 */
+ (void)event:(NSString *)eventId; //等同于 event:eventId label:eventId;

/** 自定义事件,数量统计.
 使用前，请先到友盟App管理后台的设置->编辑自定义事件 中添加相应的事件ID，然后在工程中传入相应的事件ID
 */
+ (void)event:(NSString *)eventId attributes:(NSDictionary *)attributes;


#pragma mark - preDefine event

///---------------------------------------------------------------------------------------
/// @name  游戏中预定义事件
///---------------------------------------------------------------------------------------


/// 激励视频广告展示时调用，请在广告展示的回调中使用此方法
/// @param key 用于描述此次展示广告位置的key
+ (void)onRewardedAdImpression:(NSString *)key;


/// 激励视频广告达到激励条件时调用，请在广告达到激励条件的回调中使用
/// @param key 用于描述此次展示广告位置的key
+ (void)onRewardedAdReward:(NSString *)key;


/// 插屏广告展示时调用，请在广告展示的回调中使用此方法
/// @param key 用于描述此次展示广告位置的key
+ (void)onInterstitialAdImpression:(NSString *)key;


/// 游戏启动时的加载过程
+ (void)onEnterLaunchLoading;


/// 游戏启动后，进入游戏页面
+ (void)onEnterGame;

#pragma mark Pay methods

///---------------------------------------------------------------------------------------
/// @name  支付统计
///---------------------------------------------------------------------------------------

/** 记录玩家交易兑换货币的情况
 @param currencyAmount 现金或等价物总额
 @param currencyType 为ISO4217定义的3位字母代码，如CNY,USD等（如使用其它自定义等价物作为现金，可使￼用ISO4217中未定义的3位字母组合传入货币类型）￼
 @param virtualAmount 虚拟币数量
 @param channel 支付渠道
 @param orderId 交易订单ID
 */
+ (void)exchange:(NSString *)orderId currencyAmount:(double)currencyAmount currencyType:(NSString *)currencyType virtualCurrencyAmount:(double)virtualAmount paychannel:(int)channel;

/** 玩家支付货币兑换虚拟币.
 @param cash 真实货币数量
 @param source 支付渠道
 @param coin 虚拟币数量
 */

+ (void)pay:(double)cash source:(int)source coin:(double)coin;

/** 玩家支付货币购买道具.
 @param cash 真实货币数量
 @param source 支付渠道
 @param item 道具名称
 @param amount 道具数量
 @param price 道具单价
 */
+ (void)pay:(double)cash source:(int)source item:(NSString *)item amount:(int)amount price:(double)price;


#pragma mark Buy methods

///---------------------------------------------------------------------------------------
/// @name  虚拟币购买统计
///---------------------------------------------------------------------------------------

/** 记录玩家使用虚拟币的消费情况
 */


/** 玩家使用虚拟币购买道具
 @param item 道具名称
 @param amount 道具数量
 @param price 道具单价
 */
+ (void)buy:(NSString *)item amount:(int)amount price:(double)price;


#pragma mark Use methods


///---------------------------------------------------------------------------------------
/// @name  道具消耗统计
///---------------------------------------------------------------------------------------

/** 记录玩家道具消费情况
 */


/** 玩家使用虚拟币购买道具
 @param item 道具名称
 @param amount 道具数量
 @param price 道具单价
 */

+ (void)use:(NSString *)item amount:(int)amount price:(double)price;


#pragma mark Bonus methods


///---------------------------------------------------------------------------------------
/// @name  虚拟币及道具奖励统计
///---------------------------------------------------------------------------------------

/** 记录玩家获赠虚拟币及道具的情况
 */


/** 玩家获虚拟币奖励
 @param coin 虚拟币数量
 @param source 奖励方式
 */

+ (void)bonus:(double)coin source:(int)source;

/** 玩家获道具奖励
 @param item 道具名称
 @param amount 道具数量
 @param price 道具单价
 @param source 奖励方式
 */

+ (void)bonus:(NSString *)item amount:(int)amount price:(double)price source:(int)source;
#pragma mark - user methods

///---------------------------------------------------------------------------------------
/// @name 地理位置设置
/// 需要链接 CoreLocation.framework 并且 #import <CoreLocation/CoreLocation.h>
///---------------------------------------------------------------------------------------

/** 设置经纬度信息
 @param latitude 纬度.
 @param longitude 经度.
 */
+ (void)setLatitude:(double)latitude longitude:(double)longitude;

/** 设置经纬度信息
 @param location CLLocation 经纬度信息
 */
+ (void)setLocation:(id)location;

///---------------------------------------------------------------------------------------
/// @name Utility函数
///---------------------------------------------------------------------------------------

/** 判断设备是否越狱，依据是否存在apt和Cydia.app
 */
+ (BOOL)isJailbroken;

/** 判断App是否被破解
 */
+ (BOOL)isPirated;

/** 设置 app secret
 @param secret string
 */
+ (void)setSecret:(NSString *)secret;

+ (void)setCrashCBBlock:(void (^)(void))cbBlock;

/** DeepLink事件
 @param link 唤起应用的link
 */
+ (void)onDeepLinkReceived:(NSURL *)link;

/**
 * 设置预置事件属性 键值对 会覆盖同名的key
 */
+(void) registerPreProperties:(NSDictionary *)property;

/**
 *
 * 删除指定预置事件属性
 @param propertyName key
 */
+(void) unregisterPreProperty:(NSString *)propertyName;

/**
 * 获取预置事件所有属性；如果不存在，则返回空。
 */
+(NSDictionary *)getPreProperties;

/**
 *清空所有预置事件属性。
 */
+(void)clearPreProperties;


/**
 * 设置关注事件是否首次触发,只关注eventList前五个合法eventID.只要已经保存五个,此接口无效
 */
+(void)setFirstLaunchEvent:(NSArray *)eventList;

/** 设置是否自动采集页面, 默认NO(不自动采集).
 @param value 设置为YES, umeng SDK 会将自动采集页面信息
 */
+ (void)setAutoPageEnabled:(BOOL)value;


@end

NS_ASSUME_NONNULL_END
