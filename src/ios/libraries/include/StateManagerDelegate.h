//
//  StateManagerDelegate.h
//  ContextSDK
//
//  Created by Waldemar Krumrick on 9/10/13.
//  Copyright (c) 2013 Intel. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Types.h"
#import "ListenerCallback.h"
#import "ActionDataState.h"
#import "ActionData.h"
#import "CommonContextSDK.h"

@protocol StateManagerDelegate <NSObject>

- (void)addListener:(Type*)type listenerCallback:(ListenerCallback*)listenerCallback;
- (void)removeListener:(ListenerCallback*)listenerCallback;
- (void)updateState:(ActionDataState*)data;
- (void)actionTrigger:(enum ACTION_STATE)actionState actionData:(id<ActionData>)actionData;

@end
