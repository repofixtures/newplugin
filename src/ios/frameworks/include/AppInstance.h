//
//  AppInstance.h
//  ios-sdk
//
//  Intel Cloud Services iOS SDK - 29/04/13.
//  Copyright (c) 2013 Intel ; Licensed MIT
//

#import <Foundation/Foundation.h>

/**
 * Represents the app instance.
 */
@interface AppInstance : NSObject

/**
 * Application instance ID.
 */
@property (nonatomic,strong) NSString *instance;

- (id)initWithDictionary:(NSDictionary*)data;

@end
