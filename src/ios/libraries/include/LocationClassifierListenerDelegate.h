//
//  LocationClassifierListenerDelegate.h
//  ContextSDK
//
//  Created by Waldemar Krumrick on 9/10/13.
//  Copyright (c) 2013 Intel. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LocationItem.h"

@protocol LocationClassifierListenerDelegate <NSObject>

/**
 * Callback function to receive a LocationData event
 * @param locationData with Location info
 */
- (void)onLocationEvent:(LocationItem*)locationData;

@end
