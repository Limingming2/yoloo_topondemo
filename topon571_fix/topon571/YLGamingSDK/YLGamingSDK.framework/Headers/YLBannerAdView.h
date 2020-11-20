//
// Created by Leon
// Copyright (c) 2019 kaixin001.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>


NS_ASSUME_NONNULL_BEGIN


typedef NS_ENUM(NSUInteger, YLAdBannerSize) {
    KXAdBannerSize320_50,
    KXAdBannerSize468_60,
    KXAdBannerSize728_90,
};

@protocol YLBannerAdViewDelegate;

@interface YLBannerAdView : UIView

@property(nonatomic, strong) id <YLBannerAdViewDelegate> delegate;

- (instancetype)initWithAdUnitID:(NSString *)adUnitID
                            size:(YLAdBannerSize)size
              rootViewController:(UIViewController *)viewController;

- (void)loadAd;

- (void)hiddenBanner;

- (void)showBanner;

@end

@protocol YLBannerAdViewDelegate <NSObject>
@optional

// 横幅广告获取到新广告时回调
- (void)bannerAdViewDidReceiveAd:(YLBannerAdView *)bannerView;

// 横幅广告获取新广告失败时回调
- (void)bannerAdViewFailRequestAd:(YLBannerAdView *)bannerView error:(NSError *)error;

- (void)bannerAdViewFailRenderAd:(YLBannerAdView *)bannerView error:(NSError *)error;

// 横幅广告将要呈现全屏视图时回调
- (void)bannerAdViewWillPresentScreen:(YLBannerAdView *)bannerView;

// 横幅广告呈现全屏视图后回调
- (void)bannerAdViewDidPresentScreen:(YLBannerAdView *)bannerView;

// 横幅广告将要关闭全屏视图后回调
- (void)bannerAdViewWillDismissScreen:(YLBannerAdView *)bannerView;

// 横幅广告关闭全屏视图后回调
- (void)bannerAdViewDidDismissScreen:(YLBannerAdView *)bannerView;

// 用户与横幅广告交互后，将要离开当前应用（如跳转到其他应用）是回调
- (void)bannerAdViewWillLeaveApplication:(YLBannerAdView *)bannerView;
@end

NS_ASSUME_NONNULL_END
