//
//  ListCollection.h
//  ios-sdk
//
//  Intel Cloud Services iOS SDK - 6/19/13.
//  Copyright (c) 2013 Intel ; Licensed MIT
//

#import <Foundation/Foundation.h>
#import "Metadata.h"

@class ItemCuration;
@class ItemCatalog;

@interface CollectionList : NSObject

@property (nonatomic,readonly) NSMutableArray *lists;
@property (nonatomic,strong) Metadata *metadata;

-(id)initFromDictionary:(NSDictionary*)data;

-(BOOL)hasMetadata;

-(NSDictionary*)parseToDictionary;

@end

@interface ListCuration : NSObject

@property (nonatomic,strong) NSString *name;
@property (nonatomic,strong) NSString *userId;
@property (nonatomic,strong) NSString *listId;
@property (nonatomic,strong) NSString *_id;
@property (nonatomic,strong) NSString *publicItemsUrl;
@property (nonatomic,strong) NSDictionary *fields;
@property (nonatomic,readonly) NSMutableArray *items;
@property (nonatomic,assign) BOOL isPublic;
@property (nonatomic,assign) int version;
@property (nonatomic,strong) Metadata *metadata;

+(ListCuration*)createListCuration;

-(id)initFromDictionary:(NSDictionary *)data;

-(ListCuration*)addItem:(ItemCuration*)itemCuration;

-(NSDictionary*)parseToDictionary;

-(NSDictionary*)parseToDictionaryForCreate;

-(NSData*)serialize;

-(NSData*)serializeForCreate;

@end

@interface ItemCuration : NSObject

@property (nonatomic,strong) NSString *catalogUri;
@property (nonatomic,assign) int order;
@property (nonatomic,strong) ItemCatalog *sourceItem;
@property (nonatomic,strong) NSString *_id;
@property (nonatomic,strong) NSString *itemId;
@property (nonatomic,strong) NSString *status;
@property (nonatomic,strong) NSString *comment;

+(ItemCuration*)createItemCuration;

-(id)initFromDictionary:(NSDictionary *)data;

-(NSDictionary*)parseToDictionary;

-(NSData*)serialize;

@end