//
//  ViewController.m
//  topon571
//
//  Created by lmm on 2020/11/2.
//

#import "ViewController.h"
#import <AnyThinkRewardedVideo/AnyThinkRewardedVideo.h>


@interface ViewController ()<ATRewardedVideoDelegate>
@property (nonatomic, weak) IBOutlet UILabel *lab;
@property (nonatomic, weak) IBOutlet UIButton *btn;
@property (nonatomic, strong) ATRewardedVideo *rewardAd;
@property (nonatomic, strong) CADisplayLink *displayLink;
@property (nonatomic, assign) NSInteger count;

@end

static NSString *const kRewardPlacement = @"";

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.count = 0;
    self.displayLink = [CADisplayLink displayLinkWithTarget:self selector:@selector(onDisplay)];
    [self.displayLink addToRunLoop:[NSRunLoop currentRunLoop] forMode:NSRunLoopCommonModes];
    [self loadAd:kRewardPlacement];
    self.view.backgroundColor = [UIColor whiteColor];
    
}

- (void)onDisplay
{
    self.count++;
    self.lab.text = [NSString stringWithFormat:@"%zd", self.count];
}



- (IBAction)showAd:(id)sender
{
    if ([[ATAdManager sharedManager] rewardedVideoReadyForPlacementID:kRewardPlacement]) {
        [[ATAdManager sharedManager] showRewardedVideoWithPlacementID:kRewardPlacement inViewController:self delegate:self];
    }else {
        [self loadAd:kRewardPlacement];
    }
}

- (void)loadAd:(NSString *)placement {
    self.btn.titleLabel.backgroundColor = [UIColor whiteColor];
    [[ATAdManager sharedManager] loadADWithPlacementID:placement extra:@{kATAdLoadingExtraUserIDKey:@"test_user_id"} delegate:self];
}


- (void)didFailToLoadADWithPlacementID:(NSString *)placementID error:(NSError *)error {
    NSLog(@"topon: %@, reason: %@", NSStringFromSelector(_cmd), error);
}

- (void)didFinishLoadingADWithPlacementID:(NSString *)placementID {
    NSLog(@"topon: %@, %@", NSStringFromSelector(_cmd), placementID);
    self.btn.titleLabel.backgroundColor = [UIColor yellowColor];
}

- (void)rewardedVideoDidClickForPlacementID:(NSString *)placementID extra:(NSDictionary *)extra {
    NSLog(@"topon: %@", NSStringFromSelector(_cmd));
}

- (void)rewardedVideoDidCloseForPlacementID:(NSString *)placementID rewarded:(BOOL)rewarded extra:(NSDictionary *)extra {
    NSLog(@"topon: %@", NSStringFromSelector(_cmd));
    [self loadAd:kRewardPlacement];
    self.btn.titleLabel.backgroundColor = [UIColor whiteColor];
}

- (void)rewardedVideoDidEndPlayingForPlacementID:(NSString *)placementID extra:(NSDictionary *)extra {
    NSLog(@"topon: %@", NSStringFromSelector(_cmd));
}

- (void)rewardedVideoDidFailToPlayForPlacementID:(NSString *)placementID error:(NSError *)error extra:(NSDictionary *)extra {
    NSLog(@"topon: %@", NSStringFromSelector(_cmd));
}

- (void)rewardedVideoDidRewardSuccessForPlacemenID:(NSString *)placementID extra:(NSDictionary *)extra {
    NSLog(@"topon: %@", NSStringFromSelector(_cmd));
}

- (void)rewardedVideoDidStartPlayingForPlacementID:(NSString *)placementID extra:(NSDictionary *)extra {
    NSLog(@"topon: %@", NSStringFromSelector(_cmd));
}






@end
