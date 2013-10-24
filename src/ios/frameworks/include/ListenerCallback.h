//
//  ListenerCallback.h
//  Context
//
//  Created by Waldemar Krumrick on 9/14/13.
//  Copyright (c) 2013 Intel. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ListenerCallback : NSObject

@property(nonatomic,assign) SEL mSelector;
@property(nonatomic,assign) SEL mSelectorError;
@property(nonatomic,strong) NSObject *listenerObject;

- (id)initWithSelector:(SEL)selector selectorError:(SEL)selectorError listenerObject:(NSObject*)listenerObject;

@end
