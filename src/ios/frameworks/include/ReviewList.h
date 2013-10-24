//
//  ReviewList.h
//  ios-sdk
//
//  Intel Cloud Services iOS SDK - 6/27/13.
//  Copyright (c) 2013 Intel ; Licensed MIT
//

#import <Foundation/Foundation.h>
#import "FeedbackStructure.h"

@class ContextUser;
@class Metadata;

@interface ReviewList : FeedbackList

-(id)initFromDictionary:(NSDictionary*)data;

@end

@interface Review : FeedbackItem

-(id)initFromDictionary:(NSDictionary *)data;

@end

@interface ActionPayloadReview : FeedbackActionPayload

@property(nonatomic,strong) NSString *review;

-(id)initFromDictionary:(NSDictionary *)data;

-(NSDictionary*)parseToDictionary;

@end