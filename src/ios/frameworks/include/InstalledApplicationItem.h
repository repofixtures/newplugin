//
//  InstalledApplicationItem.h
//  Context
//
//  Created by Waldemar Krumrick on 9/19/13.
//  Copyright (c) 2013 Intel. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Item.h"

@interface InstalledApplicationsItem : Item

@property(nonatomic,strong) NSArray *applications;

@end

@interface InstalledApplication : NSObject

@property(nonatomic,strong) NSString *appName;
@property(nonatomic,strong) NSString *packageName;
@property(nonatomic,strong) NSString *version;

@end
