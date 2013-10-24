//
//  Rate.h
//  ios-sdk
//
//  Intel Cloud Services iOS SDK - 6/27/13.
//  Copyright (c) 2013 Intel ; Licensed MIT
//

#import <Foundation/Foundation.h>
#import "FeedbackStructure.h"

@class ActionPayloadRate;
@class ContextUser;
@class Metadata;

@interface RateList : FeedbackList

-(id)initFromDictionary:(NSDictionary*)data;

@end

@interface Rate : FeedbackItem

-(id)initFromDictionary:(NSDictionary *)data;

@end

@interface ActionPayloadRate : FeedbackActionPayload

@property(nonatomic,strong) NSNumber *rate;

-(id)initFromDictionary:(NSDictionary *)data;

-(NSDictionary*)parseToDictionary;

@end

@interface AverageRate : NSObject

@property(nonatomic,strong) NSString *api_key;
@property(nonatomic,strong) NSString *itemId;
@property(nonatomic,assign) double rate;
@property(nonatomic,assign) int totalRates;

-(id)initFromDictionary:(NSDictionary*)data;

@end