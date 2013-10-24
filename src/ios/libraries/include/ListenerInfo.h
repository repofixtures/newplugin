//
//  ListenerInfo.h
//  Context
//
//  Created by Waldemar Krumrick on 9/13/13.
//  Copyright (c) 2013 Intel. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ListenerCallback.h"
#import "StateManagerDelegate.h"

@interface ListenerInfo : NSObject

@property(nonatomic,strong) ListenerCallback *mListener;
@property(nonatomic,strong) id<StateManagerDelegate> mStateManager;

- (id)initWithStateManager:(id<StateManagerDelegate>)stateManager listenerCallback:(ListenerCallback*)listenerCallback;

@end