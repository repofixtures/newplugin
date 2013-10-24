//
//  ListDataset.h
//  ios-sdk
//
//  Intel Cloud Services iOS SDK - 6/10/13.
//  Copyright (c) 2013 Intel ; Licensed MIT
//

#import <Foundation/Foundation.h>

@class Dataset;

@interface ListDataset : NSObject

@property (nonatomic,strong) NSString *kind;
@property (nonatomic,readonly) NSMutableArray *items;
@property (nonatomic,assign) int itemsPerPage;
@property (nonatomic,assign) int currentItemCount;
@property (nonatomic,assign) int totalItems;
@property (nonatomic,strong) NSString *nextLink;
@property (nonatomic,strong) NSString *previousLink;
@property (nonatomic,assign) int startIndex;
@property (nonatomic,strong) NSString *pagingLinkTemplate;

+(ListDataset*)createListDataset;

-(id)initFromDictionary:(NSDictionary *)data;

-(ListDataset*)addDataset:(Dataset*)dataset;

-(BOOL)hasNextPage;

-(BOOL)hasPreviousPage;

-(NSDictionary*)parseToDictionary;

-(NSData*)serialize;

@end

@interface Dataset : NSObject

@property (nonatomic,strong) NSString *name;
@property (nonatomic,assign) NSString *serverModifiedTime;
@property (nonatomic,assign) NSString *visibility;
@property (nonatomic,assign) NSString *link;
@property (nonatomic,strong) NSString *owner;
@property (nonatomic,strong) NSString *datasetId;

+(Dataset*)createDataset;

+(Dataset*)createDatasetWithName:(NSString*)name;

-(id)initFromDictionary:(NSDictionary *)data;

-(NSDictionary*)parseToDictionary;

-(NSData*)serialize;

@end