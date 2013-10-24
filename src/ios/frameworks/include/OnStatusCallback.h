//
//  OnStatusCallback.h
//  ContextSDK
//
//  Created by Waldemar Krumrick on 9/10/13.
//  Copyright (c) 2013 Intel. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ContextError.h"

@protocol OnStatusCallback <NSObject>

//- (void)onSuccess;

- (void)onError:(NSError*)error;

@end