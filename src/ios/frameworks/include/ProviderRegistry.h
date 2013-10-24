//
//  ProviderRegistry.h
//  ContextSDK
//
//  Created by Waldemar Krumrick on 9/10/13.
//  Copyright (c) 2013 Intel. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ProviderPublishDelegate.h"
#import "Types.h"
#import "StateProviderDelegate.h"
#import "ListenerCallback.h"
#import "StateManagerDelegate.h"

@interface ProviderRegistry : NSObject <ProviderPublishDelegate>

@property(nonatomic,strong) NSMutableDictionary *mProviders;
@property(nonatomic,strong) NSMutableDictionary *mOptionsTypes;
@property(nonatomic,strong) NSMutableDictionary *listenerByType;
@property(nonatomic,strong) id<OnStatusCallback> onStatusCallback;

- (id)initWithStateManager:(id<StateManagerDelegate>)stateManagerReceived;

- (void)start:(Type*)type options:(NSDictionary*)options;

- (void)stop:(Type*)type;

- (void)stopProviders;

@end
