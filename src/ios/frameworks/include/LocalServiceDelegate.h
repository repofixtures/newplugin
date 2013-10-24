//
//  LocalServiceDelegate.h
//  ContextSDK
//
//  Created by Waldemar Krumrick on 9/10/13.
//  Copyright (c) 2013 Intel. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Types.h"
#import "StateManagerDelegate.h"

@protocol LocalServiceDelegate <NSObject>

- (void)enableProvider:(Type*)state options:(NSDictionary*)options;

- (void)disableProvider:(Type*)state;

- (id<StateManagerDelegate>)getStateManager;

@end