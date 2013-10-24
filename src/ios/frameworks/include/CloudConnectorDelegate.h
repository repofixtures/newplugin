//
//  CloudConnectorDelegate.h
//  Context
//
//  Created by Waldemar Krumrick on 9/23/13.
//  Copyright (c) 2013 Intel. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ActionDataState.h"

@protocol CloudConnectorDelegate <NSObject>

- (void)pushStates;

//Only for the moment
- (void)pushActionDataState:(ActionDataState*)actionData;

@end
