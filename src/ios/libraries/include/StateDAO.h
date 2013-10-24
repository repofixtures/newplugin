//
//  StateDAO.h
//  ContextSDK
//
//  Created by Waldemar Krumrick on 9/10/13.
//  Copyright (c) 2013 Intel. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "Types.h"
#import "Item.h"
#import "sqlite3.h"
#import "FMDatabase.h"

@interface StateDAO : NSObject <UIApplicationDelegate>

- (void)open;

- (void)close;

- (void)storeState:(Item *)item;

- (void)deleteState:(Item *)item;

- (NSArray *)getPendingStates;

- (void)exportDB;

@end
