//
// Created by Leon
// Copyright (c) 2019 kaixin001.com. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol YLInterstitialAdDelegate;
@class UIViewController;

@interface YLInterstitialAd : NSObject

@property(nonatomic, strong) NSString *adUnitID;
@property(nonatomic, weak) id <YLInterstitialAdDelegate> delegate;

- (instancetype)initWithAdUnitID:(NSString *)adUnitID
                        delegate:(id <YLInterstitialAdDelegate>)delegate;

- (void)loadAd;

- (BOOL)isReady;

- (void)presentFromRootViewController:(UIViewController *)viewController;
@end

@protocol YLInterstitialAdDelegate <NSObject>
@optional
// 广告请求成功时回调
- (void)interstitialDidReceiveAd:(YLInterstitialAd *)ad;

// 广告请求失败时回调
- (void)interstitial:(YLInterstitialAd *)ad didFailToReceiveAdWithError:(NSError *)error;

// 广告将要展现时回调
- (void)interstitialWillPresentScreen:(YLInterstitialAd *)ad;

// 广告已经展现时回调
- (void)interstitialDidPresentScreen:(YLInterstitialAd *)ad;

// 广告将要关闭时回调
- (void)interstitialWillDismissScreen:(YLInterstitialAd *)ad;

// 广告已经关闭时回调
- (void)interstitialDidDismissScreen:(YLInterstitialAd *)ad;

// 广告被点击后回调
- (void)interstitialClicked:(YLInterstitialAd *)ad;

// 用户点击广告后，将要打开其他App（离开当前App）时回调
- (void)interstitialWillLeaveApplication:(YLInterstitialAd *)ad;

// 广告展示失败
- (void)interstitialShowFailed:(YLInterstitialAd *)ad withError:(NSError *)error;

@end
