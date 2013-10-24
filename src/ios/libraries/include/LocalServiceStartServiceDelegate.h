//
//  LocalServiceStartServiceDelegate.h
//  ContextSDK
//
//  Created by Waldemar Krumrick on 9/11/13.
//  Copyright (c) 2013 Intel. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LocalServiceDelegate.h"
#import "ContextError.h"

@protocol LocalServiceStartServiceDelegate <NSObject>

- (void)onSuccess:(id<LocalServiceDelegate>)mService;

- (void)onError:(ContextError*)error;

@end