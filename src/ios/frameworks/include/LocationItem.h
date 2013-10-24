//
//  LocationItem.h
//  context
//
//  Created by Waldemar Krumrick on 9/10/13.
//  Copyright (c) 2013 Intel. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Item.h"
#import <CoreLocation/CoreLocation.h>

@interface LocationItem : Item

@property(nonatomic,strong) NSString *mName;
@property(nonatomic,strong) CLLocation *mLocation;
@property(nonatomic,strong) NSNumber *mAccuracy;

@end
