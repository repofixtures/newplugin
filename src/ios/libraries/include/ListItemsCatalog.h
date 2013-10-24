//
//  ListItemsCatalog.h
//  ios-sdk
//
//  Intel Cloud Services iOS SDK - 6/14/13.
//  Copyright (c) 2013 Intel ; Licensed MIT
//

#import <Foundation/Foundation.h>

@class ItemCatalog;

@interface ListItemsCatalog : NSObject

@property (nonatomic,strong) NSString *kind;
@property (nonatomic,readonly) NSMutableArray *items;
@property (nonatomic,assign) int itemsPerPage;
@property (nonatomic,assign) int currentItemCount;
@property (nonatomic,assign) int totalItems;
@property (nonatomic,strong) NSString *nextLink;
@property (nonatomic,strong) NSString *previousLink;
@property (nonatomic,assign) int startIndex;
@property (nonatomic,strong) NSString *pagingLinkTemplate;

+(ListItemsCatalog*)createListItemsCatalog;

-(id)initFromDictionary:(NSDictionary *)data;

-(ListItemsCatalog*)addItemCatalog:(ItemCatalog *)itemCatalog;

-(BOOL)hasNextPage;

-(BOOL)hasPreviousPage;

-(NSDictionary*)parseToDictionary;

-(NSData*)serialize;

-(NSDictionary*)parseToDictionaryForUpdate;

-(NSData*)serializeForUpdate;

@end

@interface ItemCatalog : NSObject

@property (nonatomic,strong) NSDictionary *value;
@property (nonatomic,strong) NSString *serverModifiedTime;
@property (nonatomic,strong) NSString *link;
@property (nonatomic,strong) NSString *owner;
@property (nonatomic,strong) NSString *datasetId;
@property (nonatomic,strong) NSString *collectionId;
@property (nonatomic,strong) NSString *itemId;

+(ItemCatalog*)createItemCatalog;

-(id)initFromDictionary:(NSDictionary *)data;

-(NSDictionary*)parseToDictionary;

-(NSDictionary*)parseToDictionaryForCreate;

-(NSData*)serialize;

@end