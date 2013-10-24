//
//  Place.h
//  ios-sdk
//
//  Intel Cloud Services iOS SDK - 5/27/13.
//  Copyright (c) 2013 Intel ; Licensed MIT
//

#import <Foundation/Foundation.h>

FOUNDATION_EXPORT NSString *const PLACE_HOME;
FOUNDATION_EXPORT NSString *const PLACE_WORK;

@interface Place : NSObject

@property (nonatomic, strong) NSString *placeId;
@property (nonatomic, strong) NSString *latitude;
@property (nonatomic, strong) NSString *longitude;

-(id)initFromDictionary:(NSDictionary*)data;

@end