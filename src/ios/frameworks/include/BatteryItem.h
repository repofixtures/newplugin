//
//  BatteryItem.h
//  Context
//
//  Created by Waldemar Krumrick on 9/17/13.
//  Copyright (c) 2013 Intel. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Item.h"

@interface BatteryItem : Item

@property(nonatomic,strong) NSNumber *batteryLevel;
@property(nonatomic,strong) NSString *batteryState;

- (id)initWithBatteryLevel:(NSNumber*)level state:(NSString*)state;

@end
