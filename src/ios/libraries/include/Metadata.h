//
//  Metadata.h
//  ios-sdk
//
//  Intel Cloud Services iOS SDK - 7/5/13.
//  Copyright (c) 2013 Intel ; Licensed MIT
//

#import <Foundation/Foundation.h>

@interface Metadata : NSObject

@property (nonatomic,assign) int totalItems;
@property (nonatomic,assign) int limit;
@property (nonatomic,strong) NSString *previous;
@property (nonatomic,assign) int pageNumber;
@property (nonatomic,strong) NSString *next;
@property (nonatomic,assign) int startIndex;
@property (nonatomic,strong) NSString *type;

-(id)initMetadata:(NSDictionary*)data;

-(BOOL)isPrevious;

-(BOOL)isNext;

-(NSDictionary*)parseToDictionary;

@end
