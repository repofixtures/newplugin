//
//  CallItem.h
//  Context
//
//  Created by Waldemar Krumrick on 9/20/13.
//  Copyright (c) 2013 Intel. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Item.h"

@interface CallItem : Item

@property(nonatomic,strong) NSString *mCaller;
@property(nonatomic,strong) NSString *mNotificationType;
@property(nonatomic,strong) NSString *mContactName;
@property(nonatomic,strong) NSString *mRingQuantity;
@property(nonatomic,strong) NSString *mMissedQuantity;

@end
