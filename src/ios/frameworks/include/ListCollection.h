//
//  ListCollection.h
//  ios-sdk
//
//  Intel Cloud Services iOS SDK - 6/19/13.
//  Copyright (c) 2013 Intel ; Licensed MIT
//

#import <Foundation/Foundation.h>

@class Collection;

@interface ListCollection : NSObject

@property (nonatomic,strong) NSString *kind;
@property (nonatomic,readonly) NSMutableArray *items;
@property (nonatomic,assign) int itemsPerPage;
@property (nonatomic,assign) int currentItemCount;
@property (nonatomic,assign) int totalItems;
@property (nonatomic,strong) NSString *nextLink;
@property (nonatomic,strong) NSString *previousLink;
@property (nonatomic,assign) int startIndex;
@property (nonatomic,strong) NSString *pagingLinkTemplate;

+(ListCollection*)createListCollection;

-(id)initFromDictionary:(NSDictionary *)data;

-(ListCollection*)addCollection:(Collection*)collection;

-(BOOL)hasNextPage;

-(BOOL)hasPreviousPage;

-(NSDictionary*)parseToDictionary;

-(NSData*)serialize;

@end

@interface Collection : NSObject

@property (nonatomic,strong) NSString *idCollection;
@property (nonatomic,strong) NSString *name;
@property (nonatomic,assign) NSString *serverModifiedTime;
@property (nonatomic,assign) NSString *visibility;
@property (nonatomic,assign) NSString *link;
@property (nonatomic,strong) NSString *owner;
@property (nonatomic,strong) NSString *datasetId;
@property (nonatomic,strong) NSString *schema; //Schema link

+(Collection*)createCollection;

+(Collection*)createCollectionWithName:(NSString*)name;

-(id)initFromDictionary:(NSDictionary *)data;

-(NSDictionary*)parseToDictionary;

-(NSData*)serialize;

@end