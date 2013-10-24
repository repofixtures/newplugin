//
//  Results.h
//  ios-sdk
//
//  Intel Cloud Services iOS SDK - 8/1/13.
//  Copyright (c) 2013 Intel ; Licensed MIT
//

#import <Foundation/Foundation.h>

@class ListItemsCatalog;

@interface Results : NSObject

@property(nonatomic,assign) int updated;
@property(nonatomic,assign) int deleted;
@property(nonatomic,assign) int inserted;
@property(nonatomic,strong) NSMutableArray *items;
@property(nonatomic,strong) NSMutableArray *errors;

- (id)initFromDictionary:(NSDictionary *)data;

- (BOOL)hasErrors;

- (BOOL)hasItems;

@end