//
// Created by Leon on 2019-06-25.
// Copyright (c) 2019 kaixin001.com. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol YLRewardedVideoAdDelegate;
@class YLRewardedVideoAdReward;
@class UIViewController;

// 激励视频广告
@interface YLRewardedVideoAd : NSObject

// 初始化激励视频广告
- (instancetype)initWithAdUnitID:(NSString *)adUnitID
                    withDelegate:(id <YLRewardedVideoAdDelegate>)delegate;

// 加载激励视频广告
- (void)loadAd;

// 激励视频广告是否就绪
- (BOOL)isReady;

// 弹出激励视频广告
- (void)presentFromViewController:(UIViewController *)viewController;

@end


@protocol YLRewardedVideoAdDelegate <NSObject>

@required
// 激励视频广告播放，达到激励条件时回调
- (void)rewardedVideoAdShouldReward:(YLRewardedVideoAd *)rewardedVideoAd reward:(YLRewardedVideoAdReward *)reward;

@optional

// 激励视频广告加载成功时回调
- (void)rewardedVideoAdDidLoad:(YLRewardedVideoAd *)rewardedVideoAd;

// 激励视频广告加载失败时回调
- (void)rewardedVideoAd:(YLRewardedVideoAd *)rewardedVideoAd didFailToLoadWithError:(NSError *)error;

// 激励视频广告播放失败时回调
- (void)rewardedVideoAd:(YLRewardedVideoAd *)rewardedVideoAd didFailToPlayWithError:(NSError *)error;

// 激励视频广告将要呈现时回调
- (void)rewardedVideoAdWillAppear:(YLRewardedVideoAd *)rewardedVideoAd;

// 激励视频广告已经呈现时回调
- (void)rewardedVideoAdDidAppear:(YLRewardedVideoAd *)rewardedVideoAd;

// 激励视频广告将要关闭时回调
- (void)rewardedVideoAdWillDisappear:(YLRewardedVideoAd *)rewardedVideoAd;

// 激励视频广告已经关闭时回调
- (void)rewardedVideoAdDidDisappear:(YLRewardedVideoAd *)rewardedVideoAd;

// 激励视频广告被点击时回调
- (void)rewardedVideoAdDidClicked:(YLRewardedVideoAd *)rewardedVideoAd;

// 激励视频广告播放完成时回调
- (void)rewardedVideoAdDidCompletePlaying:(YLRewardedVideoAd *)rewardedVideoAd;

// 用户点击后需要离开当前App时（如跳转到其他App）回调
- (void)rewardedVideoAdWillLeaveApplication:(YLRewardedVideoAd *)rewardedVideoAd;

@end
