//
//  ListRecommendation.h
//  ios-sdk
//
//  Intel Cloud Services iOS SDK - 7/11/13.
//  Copyright (c) 2013 Intel ; Licensed MIT
//

#import <Foundation/Foundation.h>

@class Metadata;

@interface ListRecommendation : NSObject

@property (nonatomic,strong) NSMutableArray *recommendations;
@property (nonatomic,strong) Metadata *metadata;

-(id)initFromDictionary:(NSDictionary*)data;

@end

@interface Recommendation : NSObject

@property (nonatomic,strong) NSString *_id;
@property (nonatomic,assign) double similarityFactor;
@property (nonatomic,strong) NSString *targetItemUri;
@property (nonatomic,strong) NSString *type;
@property (nonatomic,strong) NSString *source;
@property (nonatomic,strong) NSString *sourceItemId;
@property (nonatomic,strong) NSString *targetItemId;
@property (nonatomic,strong) NSString *apiKey;

-(id)initFromDictionary:(NSDictionary*)data;

@end