//
//  AppDelegate.m
//  topon571
//
//  Created by lmm on 2020/11/2.
//

#import "AppDelegate.h"
#import <AnyThinkSDK/AnyThinkSDK.h>
#import <AnyThinkSplash/AnyThinkSplash.h>
#import "SplashHelper.h"
#import "ViewController.h"
#import <WebKit/WebKit.h>
#import <AppTrackingTransparency/AppTrackingTransparency.h>


@interface AppDelegate ()

@end

@implementation AppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    // Override point for customization after application launch.
    
    [ATAPI setLogEnabled:YES];
    [[ATAPI sharedInstance]
     startWithAppID:@""
     appKey:@"" error:nil];
    return YES;
}



@end
