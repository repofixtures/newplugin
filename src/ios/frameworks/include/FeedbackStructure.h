//
//  FeedbackStructure.h
//  ios-sdk
//
//  Intel Cloud Services iOS SDK - 6/27/13.
//  Copyright (c) 2013 Intel ; Licensed MIT
//

#import <Foundation/Foundation.h>

@class FeedbackActionPayload;
@class Metadata;
@class ContextUser;

@interface FeedbackList : NSObject

@property (nonatomic,strong) NSMutableArray *items;
@property (nonatomic,strong) Metadata *metadata;

-(id)initFromDictionary:(NSDictionary*)data;

@end

@interface FeedbackItem : NSObject

@property (nonatomic,strong) NSString *_id;
@property (nonatomic,strong) NSString *api_key;
@property (nonatomic,strong) NSString *userId;
@property (nonatomic,strong) NSString *actionType;
@property (nonatomic,strong) NSString *itemId;
@property (nonatomic,strong) ContextUser *contextUser;
@property (nonatomic,strong) FeedbackActionPayload *actionPayload;

+(FeedbackItem*)createFeedbackItemWithContextUser:(ContextUser*)contextUser;

-(id)initFromDictionary:(NSDictionary*)data;

-(NSDictionary*)parseToDictionary;

-(NSData*)serialize;

@end

@interface FeedbackActionPayload : NSObject

@property (nonatomic,strong) NSString *collectionId;
@property (nonatomic,strong) NSString *datasetId;
@property (nonatomic,strong) NSString *itemId;
@property (nonatomic,strong) NSString *itemUri;
@property (nonatomic,strong) NSString *date;

+(FeedbackActionPayload*)createActionPayloadWithItemUri:(NSString*)itemUri;

-(id)initWithItemUri:(NSString *)itemUri;

-(id)initFromDictionary:(NSDictionary*)data;

-(NSDictionary*)parseToDictionary;

-(NSData*)serialize;

@end
