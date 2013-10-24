//
//  ResourcesType.h
//  ios-sdk
//
//  Intel Cloud Services iOS SDK - 5/23/13.
//  Copyright (c) 2013 Intel ; Licensed MIT
//

#import <Foundation/Foundation.h>
                                  
FOUNDATION_EXPORT NSString *const CONTEXT_TYPE_LOCATION_SEARCH_HISTORY;
FOUNDATION_EXPORT NSString *const CONTEXT_TYPE_TRAVEL_ROUTE_HISTORY;
FOUNDATION_EXPORT NSString *const CONTEXT_TYPE_LOCATION_VISITS;
FOUNDATION_EXPORT NSString *const CONTEXT_TYPE_LOCATION_VISITS_V1;
FOUNDATION_EXPORT NSString *const CONTEXT_TYPE_CURRENT_LOCATION;
FOUNDATION_EXPORT NSString *const CONTEXT_TYPE_LIKES_AND_RATING;
FOUNDATION_EXPORT NSString *const CONTEXT_TYPE_APPLICATION_SPECIFIED_DATA;
FOUNDATION_EXPORT NSString *const CONTEXT_TYPE_BEHAVIOR_MODEL;

@class ResourceTypeItem;
@class ResourcePropertyItem;

@interface ResourcesType : NSObject

@property (nonatomic,strong) NSMutableArray *items;

-(id)initFromDictionary:(NSDictionary*)data;

@end

@interface ResourceTypeItem : NSObject

@property (nonatomic,strong) NSString *identifier;
@property (nonatomic,strong) NSString *category;
@property (nonatomic,strong) NSString *lang;
@property (nonatomic,strong) NSString *shortName;
@property (nonatomic,strong) NSString *documentation;
@property (nonatomic,strong) NSMutableArray *schemas;

-(id)initFromDictionary:(NSDictionary*)data;

@end

@interface ResourceTypeSchema : NSObject

@property (nonatomic,assign) BOOL additionalProperties;
@property (nonatomic,strong) NSMutableArray *properties;

-(id)initFromDictionary:(NSDictionary*)data;

@end

@interface ResourcePropertyItem : NSObject

@property (nonatomic,strong) NSString *property;
@property (nonatomic,assign) BOOL required;
@property (nonatomic,strong) NSString *type;
@property (nonatomic,strong) NSString *description;
@property (nonatomic,strong) NSMutableArray *properties;

-(id)initFromDictionary:(NSDictionary*)data;

@end