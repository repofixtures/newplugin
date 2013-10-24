//
//  LocationTrackingService.h
//  ContextSDK
//
//  Created by Waldemar Krumrick on 9/10/13.
//  Copyright (c) 2013 Intel. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "StateProviderDelegate.h"
#import "LocationClassifierListenerDelegate.h"
#import <MapKit/MapKit.h>
#import <CoreLocation/CoreLocation.h>

@interface LocationTrackingService : NSObject <UIApplicationDelegate, StateProviderDelegate, LocationClassifierListenerDelegate, CLLocationManagerDelegate>

@property(nonatomic,strong) CLLocationManager *locationManager;

@end
