//
//  ActionDataState.h
//  ContextSDK
//
//  Created by Waldemar Krumrick on 9/13/13.
//  Copyright (c) 2013 Intel. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ActionData.h"
#import "Types.h"
#import "Item.h"

@interface ActionDataState : NSObject <ActionData>

@property(nonatomic,strong) Type *state;
@property(nonatomic,strong) Item *value;

- (id)initWithState:(Type*)state value:(Item*)value;

@end