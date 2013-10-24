//
//  BehaviorModels.h
//  ios-sdk
//
//  Intel Cloud Services iOS SDK - 6/3/13.
//  Copyright (c) 2013 Intel ; Licensed MIT
//

#import <Foundation/Foundation.h>

@class PlaceBehavior;
@class DestinationBehavior;
@class PointOfInterestBehavior;

@interface PlaceBehavior : NSObject

@property(nonatomic,strong) NSString *placeId;
@property(nonatomic,assign) double latitude;
@property(nonatomic,assign) double longitude;

-(id)initFromDictionary:(NSDictionary*)data;

@end

@interface DestinationBehavior : PlaceBehavior

@property(nonatomic,assign) double distance_factor;
@property(nonatomic,assign) double weight;
@property(nonatomic,strong) NSString *poi_type;

-(id)initFromDictionary:(NSDictionary*)data;

@end

@interface PointOfInterestBehavior : NSObject

@property(nonatomic,assign) double price;
@property(nonatomic,strong) NSString *cuisine;
@property(nonatomic,assign) double weight;

-(id)initFromDictionary:(NSDictionary*)data;

@end