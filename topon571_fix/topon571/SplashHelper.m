//
//  SplashHelper.m
//  topon571
//
//  Created by lmm on 2020/11/5.
//

#import "SplashHelper.h"
#import <AnyThinkSplash/AnyThinkSplash.h>

static BOOL splashIsShown;

@interface SplashHelper ()<ATSplashDelegate>
@end


@implementation SplashHelper



- (void)showSplash:(UIWindow *)window placementId:(NSString *)placementId
{
    if (!splashIsShown) {
        splashIsShown = YES;
//        [self.window makeKeyAndVisible];
        [[ATAdManager sharedManager] loadADWithPlacementID:placementId extra:@{kATSplashExtraTolerateTimeoutKey:@5.5} customData: nil delegate:self window:window containerView:nil];
    }
}


- (void)didFailToLoadADWithPlacementID:(NSString *)placementID error:(NSError *)error {
    splashIsShown = NO;
    NSLog(@"error: %@", error);
}

- (void)didFinishLoadingADWithPlacementID:(NSString *)placementID {
    
}

- (void)splashDidClickForPlacementID:(NSString *)placementID extra:(NSDictionary *)extra {
    
}

- (void)splashDidCloseForPlacementID:(NSString *)placementID extra:(NSDictionary *)extra {
    splashIsShown = NO;
}

- (void)splashDidShowForPlacementID:(NSString *)placementID extra:(NSDictionary *)extra {
}

@end
