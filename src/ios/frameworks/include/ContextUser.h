//
//  ContextUser.h
//  ios-sdk
//
//  Intel Cloud Services iOS SDK - 6/26/13.
//  Copyright (c) 2013 Intel ; Licensed MIT
//

#import <Foundation/Foundation.h>

FOUNDATION_EXPORT NSString *CONTEXT_DAY_OF_WEEK_MONDAY;
FOUNDATION_EXPORT NSString *CONTEXT_DAY_OF_WEEK_TUESDAY;
FOUNDATION_EXPORT NSString *CONTEXT_DAY_OF_WEEK_WEDNESDAY;
FOUNDATION_EXPORT NSString *CONTEXT_DAY_OF_WEEK_THURSDAY;
FOUNDATION_EXPORT NSString *CONTEXT_DAY_OF_WEEK_FRIDAY;
FOUNDATION_EXPORT NSString *CONTEXT_DAY_OF_WEEK_SATURDAY;
FOUNDATION_EXPORT NSString *CONTEXT_DAY_OF_WEEK_SUNDAY;

@class LocationContext;

@interface ContextUser : NSObject

@property (nonatomic,strong) NSString *dayOfWeek;
@property (nonatomic,strong) LocationContext *location;
@property (nonatomic,strong) NSString *place;
@property (nonatomic,strong) NSString *timeOfDay;

+(ContextUser*)createContextUserWithDayOfWeek:(NSString*)dayOfWeek location:(LocationContext*)location place:(NSString*)place timeOfDay:(NSString *)timeOfDay;

-(id)initFromDictionary:(NSDictionary*)data;

-(NSDictionary*)parseToDictionary;

@end

@interface LocationContext : NSObject

@property (nonatomic,assign) double latitude;
@property (nonatomic,assign) double longitude;

+(LocationContext*)createLocationContextWithLatitude:(double)latitude longitude:(double)longitude;

-(id)initFromDictionary:(NSDictionary*)data;

-(NSDictionary*)parseToDictionary;

@end