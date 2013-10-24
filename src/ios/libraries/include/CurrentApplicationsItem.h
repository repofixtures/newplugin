//
//  CurrentApplicationItem.h
//  Context
//
//  Created by Waldemar Krumrick on 9/20/13.
//  Copyright (c) 2013 Intel. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Item.h"

@interface CurrentApplicationsItem : Item

@property(nonatomic,strong) NSArray *applications;

@end

@interface CurrentApplication : NSObject

@property(nonatomic,assign) int processId;
@property(nonatomic,strong) NSString *processName;

@end
