//
//  Item.h
//  ContextSDK
//
//  Created by Waldemar Krumrick on 9/12/13.
//  Copyright (c) 2013 Intel. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Types.h"

@interface Item : NSObject

@property(nonatomic,strong) NSString *mActivity;
@property(nonatomic,strong) NSNumber *mTimestamp;
@property(nonatomic,strong) NSNumber *mId;
@property(nonatomic,assign) BOOL pushToSensingRequired;
@property(nonatomic,assign) BOOL pushToSituationRequired;

- (Type*)getStateType;

- (NSMutableDictionary*)toDictionary;

@end
