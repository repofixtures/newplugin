//
//  ContextSDK.h
//  ContextSDK
//
//  Created by Waldemar Krumrick on 9/11/13.
//  Copyright (c) 2013 Intel. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "OnStatusCallback.h"
#import "Types.h"
#import "LocalServiceStartServiceDelegate.h"
#import "ListenerCallback.h"

@interface ContextSDK : NSObject

+ (BOOL)isInit;

+ (void)initialize:(id<OnStatusCallback>)callback;

+ (void)stopService;

+ (void)addListener:(Type*)type listener:(ListenerCallback*)listener options:(NSDictionary*)options;

+ (void)removeListener:(ListenerCallback*)listener;

+ (void)enableProvider:(Type *)state options:(NSDictionary *)options;

+ (void)disableProvider:(Type *)state;

@end