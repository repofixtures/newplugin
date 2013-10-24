//
//  Items.h
//  ios-sdk
//
//  Intel Cloud Services iOS SDK - 5/23/13.
//  Copyright (c) 2013 Intel ; Licensed MIT
//

#import <Foundation/Foundation.h>

@class ItemContext;

@interface ListItems : NSObject

@property (strong, strong) NSMutableArray *items;

+(ListItems*)createListItems;

-(id)initFromDictionary:(NSDictionary*)data;

-(void)addItemsFromDictionary:(NSDictionary*)data;

-(ItemContext*)addItemFromDictionary:(NSDictionary*)data;

-(void)addItem:(ItemContext*)item;

-(NSData*)serializeList;

-(NSData*)serializeListForStore;

@end