//
//  CloudConnector.h
//  Context
//
//  Created by Waldemar Krumrick on 9/23/13.
//  Copyright (c) 2013 Intel. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "StateDAO.h"
#import "CloudConnectorDelegate.h"
#import "ActionDataState.h"

@interface CloudConnector : NSObject <CloudConnectorDelegate>

@property(nonatomic,strong) StateDAO *dataSource;

//Delete this code when it's implement StateDAO logic here
//@property(nonatomic,strong) Item *itemToPush;

- (id)initWithStateDAO:(StateDAO*)datasource;

- (void)pushActionDataState:(ActionDataState*)actionData;

@end
