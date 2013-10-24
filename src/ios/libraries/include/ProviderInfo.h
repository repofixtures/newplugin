//
//  ProviderInfo.h
//  ContextSDK
//
//  Created by Waldemar Krumrick on 9/11/13.
//  Copyright (c) 2013 Intel. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "StateProviderDelegate.h"
#import "ProviderPublishDelegate.h"

@interface ProviderInfo : NSObject

@property(nonatomic,strong) id<StateProviderDelegate> provider;
@property(nonatomic,assign) BOOL started;

- (id)initWithProvider:(id<StateProviderDelegate>)provider;

- (void)start:(id<ProviderPublishDelegate>)publisher options:(NSDictionary*)options;

- (void)stop;

@end
