//
//  ItemContext.h
//  ios-sdk
//
//  Intel Cloud Services iOS SDK - 24/05/13.
//  Copyright (c) 2013 Intel ; Licensed MIT
//

#import <Foundation/Foundation.h>

FOUNDATION_EXPORT NSString *const ROUTE_ALGORITHM_FASTEST;
FOUNDATION_EXPORT NSString *const ROUTE_ALGORITHM_SHORTEST;
FOUNDATION_EXPORT NSString *const ROUTE_ALGORITHM_PEDESTRIAN;

FOUNDATION_EXPORT NSString *const AVOID_ROAD_TYPE_FERRY;
FOUNDATION_EXPORT NSString *const AVOID_ROAD_TYPE_HIGHWAY;
FOUNDATION_EXPORT NSString *const AVOID_ROAD_TYPE_TOLLWAY;
FOUNDATION_EXPORT NSString *const AVOID_ROAD_TYPE_UNPAVED;

FOUNDATION_EXPORT NSString *const MEASUREMENT_METRIC;
FOUNDATION_EXPORT NSString *const MEASUREMENT_IMPERIAL;
FOUNDATION_EXPORT NSString *const MEASUREMENT_IMPERIAL_FEET;

FOUNDATION_EXPORT NSString *const ALT_TYPE_JSON;
FOUNDATION_EXPORT NSString *const ALT_TYPE_XML;

@class ItemRating;
@class ItemLocationCurrent;

@interface ItemContext : NSObject

@property(nonatomic,strong) NSString *idItem;
@property(nonatomic,strong) NSString *contextType;
@property(nonatomic,strong) NSString *provider;
@property(nonatomic,strong) NSString *owner;
@property(nonatomic,strong) NSDate *serverModifiedTime;
@property(nonatomic,strong) NSDate *serverCreatedTime;
@property(nonatomic,strong) NSDate *clientCreatedTime;
@property(nonatomic,strong) NSDictionary *extension;

+(ItemContext*)createItemContextFromDictionary:(NSDictionary*)data;

-(id)initFromDictionary:(NSDictionary*)data;

-(NSDictionary*)parseToDictionary;

-(NSDictionary*)parseToDictionaryForStore;

@end

@interface ItemRating : ItemContext

@property(nonatomic,assign) int rating;
@property(nonatomic,strong) NSString *domain;
@property(nonatomic,strong) NSString *href;

/**
 Create a item context of rating/like type.
 @throw RequiredDataEmpty If (domain or href parameters) are nil or empty.
 @return ItemRating class instance
 */
+(ItemRating*)createRatingWithDomain:(NSString*)domain href:(NSString*)href extension:(NSDictionary*)extension;

@end

@interface ItemLocationCurrent : ItemContext

@property(nonatomic,assign) double altitude;
@property(nonatomic,assign) double latitude;
@property(nonatomic,assign) double longitude;
@property(nonatomic,assign) double altitudeAccuracy;
@property(nonatomic,assign) double speed;
@property(nonatomic,assign) double heading;
@property(nonatomic,assign) double accuracy;

/**
 Create a item context of current location type.
 @throw LatitudeLongitude If latitude isn't between -90.0 and 90.0, or if longitude isn't between -180.0 and 180.0
 @return ItemLocationCurrent class instance
 */
+(ItemLocationCurrent*)createLocationCurrentWithLatitude:(double)latitude longitude:(double)longitude extension:(NSDictionary*)extension;

@end

@interface ItemLocationVisits : ItemContext{
    
}

@property(nonatomic,assign) double latitude;
@property(nonatomic,assign) double longitude;
@property(nonatomic,assign) float accuracy;
@property(nonatomic,strong) NSString *pointId;
@property(nonatomic,strong) NSString *datetime;

/**
 Create a item context of location visits type.
 @throw LatitudeLongitude If latitude isn't between -90.0 and 90.0, or if longitude isn't between -180.0 and 180.0
 @throw NullValueException If (pointId or dateTime parameters) are nil or empty.
 @return ItemLocationVisits class instance
 */
+(ItemLocationVisits*)createLocationVisitsWithLatitude:(double)latitude longitude:(double)longitude accuracy:(float)accuracy pointId:(NSString*)pointId dateTime:(NSString*)dateTime extension:(NSDictionary*)extension;

@end

@interface ItemLocationSearch : ItemContext{
    
}

@property(nonatomic,assign) double latitude;
@property(nonatomic,assign) double longitude;
@property(nonatomic,strong) NSString *type;
@property(nonatomic,strong) NSString *datetime;
@property(nonatomic,strong) NSString *value;
@property(nonatomic,strong) NSString *source_domain;
@property(nonatomic,strong) NSString *name;

/**
 Create a item context of location search type.
 @throw LatitudeLongitude If latitude isn't between -90.0 and 90.0, or if longitude isn't between -180.0 and 180.0
 @return ItemLocationVisits class instance
 */
+(ItemLocationSearch*)createLocationSearchWithLatitude:(double)latitude longitude:(double)longitude extension:(NSDictionary*)extension;

@end

@interface ItemAppSpecificData : ItemContext{
    
}

@property(nonatomic,strong) NSString *typeId;

+(ItemAppSpecificData*)createAppSpecificDataWithTypeId:(NSString*)typeId extension:(NSDictionary*)extension;

+(ItemAppSpecificData*)createAppSpecificDataWithTypeId:(NSString*)typeId;

@end

@interface ItemTravelRoute : ItemContext{
    
}

@property(nonatomic,assign) double latitude; //origin
@property(nonatomic,assign) double longitude; //origin
@property(nonatomic,strong) NSString *date; //origin
@property(nonatomic,strong) NSString *routeAlgorithm;
@property(nonatomic,strong) NSMutableArray *avoidRoads;
@property(nonatomic,assign) double destinationLatitude; //destination
@property(nonatomic,assign) double destinationLongitude; //destination
@property(nonatomic,strong) NSString *destinationDate; //destination
@property(nonatomic,assign) double zoom;
@property(nonatomic,strong) NSMutableArray *preferredRoads;
@property(nonatomic,strong) NSString *measurementType;
@property(nonatomic,strong) NSString *altType;
@property(nonatomic,assign) BOOL trafficAware;
@property(nonatomic,strong) NSMutableArray *viaPoints;

/**
 Create a item context of travel route type.
 @throw LatitudeLongitude If latitude isn't between -90.0 and 90.0, or if longitude isn't between -180.0 and 180.0
 @throw NullValue If dateTime is nill or empty.
 @return ItemLocationVisits class instance
 */
+(ItemTravelRoute*)createTravelRouteWithOriginLatitude:(double)originLatitude originLongitude:(double)originLongitude originDateTime:(NSString *)originDateTime destinationLatitude:(double)destinationLatitude destinationLongitude:(double)destinationLongitude destinationDateTime:(NSString *)destinationDateTime extension:(NSDictionary *)extension;

-(ItemTravelRoute*)addViaPointWithLatitude:(double)latitude longitude:(double)longitude;

@end