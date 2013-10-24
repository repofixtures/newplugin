//
//  ContextPusher.h
//  Context
//
//  Created by Waldemar Krumrick on 9/23/13.
//  Copyright (c) 2013 Intel. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CloudConnector.h"
#import "CloudConnectorDelegate.h"

@interface ContextPusher : NSObject

@property(nonatomic,strong) CloudConnector *cloudConnector;

- (id)initWithCloudConnector:(CloudConnector*)cloudConnector;

- (void)start;

@end
