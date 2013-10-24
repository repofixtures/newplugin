//
//  StateManager.h
//  ContextSDK
//
//  Created by Waldemar Krumrick on 9/10/13.
//  Copyright (c) 2013 Intel. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "StateManagerDelegate.h"
#import "CloudConnectorDelegate.h"
#import "StateDAO.h"

@interface StateManager : NSObject <StateManagerDelegate>

@property(nonatomic,strong) StateDAO *mDBConnection;
@property(nonatomic,strong) NSMutableDictionary *mListeners;
@property(nonatomic,strong) id<CloudConnectorDelegate> mCloudConnector;

- (id)initWithStateDAO:(StateDAO*)stateDAO cloudConnector:(id<CloudConnectorDelegate>)cloudConnector;

@end
