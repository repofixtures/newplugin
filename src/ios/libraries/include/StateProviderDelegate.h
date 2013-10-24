//
//  StateProviderDelegate.h
//  ContextSDK
//
//  Created by Waldemar Krumrick on 9/10/13.
//  Copyright (c) 2013 Intel. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Context.h"
#import "ProviderPublishDelegate.h"

@protocol StateProviderDelegate <NSObject>

- (void)start:(id<ProviderPublishDelegate>)publisher options:(NSDictionary*)options;

- (void)stop;

@end
