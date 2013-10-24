//
//  CurrentAppsTrackingService.h
//  ContextSDK
//
//  Created by Waldemar Krumrick on 9/10/13.
//  Copyright (c) 2013 Intel. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "StateProviderDelegate.h"
#import <UIKit/UIKit.h>

@interface CurrentAppsTrackingService : NSObject <UIApplicationDelegate, StateProviderDelegate>

@end