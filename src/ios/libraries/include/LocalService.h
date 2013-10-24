//
//  LocalService.h
//  context
//
//  Created by Waldemar Krumrick on 9/10/13.
//  Copyright (c) 2013 Intel. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LocalServiceDelegate.h"
#import "Context.h"
#import "ListenerCallback.h"

@interface LocalService : NSObject <LocalServiceDelegate>

@property(nonatomic,assign) id<OnStatusCallback> onStatusCallback;

+ (LocalService *)sharedInstance:(id<OnStatusCallback>)onStatusCallback; //Singleton class

- (id)initWithStatusCallback:(id<OnStatusCallback>)onStatusCallback;

- (void)stopService;

@end