//
//  ListState.h
//  ios-sdk
//
//  Intel Cloud Services iOS SDK - 8/2/13.
//  Copyright (c) 2013 Intel ; Licensed MIT
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

//Location context types
FOUNDATION_EXPORT NSString *const CONTEXT_TYPE_LOCATION_CURRENT;
FOUNDATION_EXPORT NSString *const CONTEXT_TYPE_LOCATION_PLACE;
FOUNDATION_EXPORT NSString *const CONTEXT_TYPE_LOCATION_GEOGRAPHIC;
FOUNDATION_EXPORT NSString *const CONTEXT_TYPE_LOCATION_NEAR_RESTAURANTS;

//Time context types
FOUNDATION_EXPORT NSString *const CONTEXT_TYPE_DATETIME_DATE;
FOUNDATION_EXPORT NSString *const CONTEXT_TYPE_DATETIME_TIME;
FOUNDATION_EXPORT NSString *const CONTEXT_TYPE_DATETIME_TIMEZONE;

//Media context types
FOUNDATION_EXPORT NSString *const CONTEXT_TYPE_MEDIA_AUDIO;

//Device context types
FOUNDATION_EXPORT NSString *const CONTEXT_TYPE_DEVICE_CALL;
FOUNDATION_EXPORT NSString *const CONTEXT_TYPE_DEVICE_CURRENT_APPS;
FOUNDATION_EXPORT NSString *const CONTEXT_TYPE_DEVICE_INSTALLED_APPS;
FOUNDATION_EXPORT NSString *const CONTEXT_TYPE_DEVICE_BATTERY;
FOUNDATION_EXPORT NSString *const CONTEXT_TYPE_DEVICE_NETWORK;
FOUNDATION_EXPORT NSString *const CONTEXT_TYPE_DEVICE_CALENDAR;
FOUNDATION_EXPORT NSString *const CONTEXT_TYPE_DEVICE_MESSAGES;
FOUNDATION_EXPORT NSString *const CONTEXT_TYPE_DEVICE_INFORMATION;
FOUNDATION_EXPORT NSString *const CONTEXT_TYPE_DEVICE_CONTACTS;

@class StateOwner;
@class UserStateOwner;
@class DeviceStateOwner;
@class ApplicationStateOwner;
@class StateDeprecated;
@class State;
@class DeviceCallState;

@interface ListStates : NSObject

@property(nonatomic,strong) NSString *kind;
@property(nonatomic,strong) NSMutableArray *states;
@property(nonatomic,strong) StateOwner *owner;
@property(nonatomic,strong) StateDeprecated *deprecated;

+ (ListStates*)createListStates;

- (id)initFromDictionary:(NSDictionary*)data;

- (ListStates*)addState:(State*)state;

- (BOOL)hasStates;

- (NSDictionary*)parseToDictionary;

- (NSDictionary*)parseToDictionaryForCreate;

- (NSData*)serialize;

- (NSData*)serializeForCreate;

- (void)setRuntime:(NSString*)runtime;

- (void)setDeviceId:(NSString*)deviceId;

+ (State*)createStateFromDictionary:(NSDictionary*)data;

@end

@interface State : NSObject

@property(nonatomic,strong) NSString *type;
@property(nonatomic,strong) NSString *activity;
@property(nonatomic,strong) NSDictionary *value;
@property(nonatomic,strong) NSString *dateTime;

+ (State*)createStateWithType:(NSString*)type activity:(NSString*)activity value:(NSDictionary*)value dateTime:(NSDate*)dateTime;

+ (State*)createStateWithType:(NSString*)type value:(NSDictionary*)value dateTime:(NSDate*)dateTime;

- (id)initFromDictionary:(NSDictionary*)data;

- (NSDictionary*)parseToDictionary;

- (NSDictionary*)parseToDictionaryForCreate;

- (NSData*)serialize;

@end

@interface StateOwner : NSObject

@property(nonatomic,strong) UserStateOwner *user;
@property(nonatomic,strong) DeviceStateOwner *device;
@property(nonatomic,strong) ApplicationStateOwner *application;

- (BOOL)hasUserOwner;

- (BOOL)hasDeviceOwner;

- (BOOL)hasApplicationOwner;

- (NSDictionary*)parseToDictionary;

@end

@interface StateDeprecated : NSObject

@property(nonatomic,strong) NSString *reason;
@property(nonatomic,assign) int code;

- (id)initFromDictionary:(NSDictionary*)data;

- (NSDictionary*)parseToDictionary;

@end

@interface StateOwnerBasic : NSObject

@property(nonatomic,strong) NSString *_id;
@property(nonatomic,strong) NSString *name;

- (id)initFromDictionary:(NSDictionary*)data;

- (NSDictionary*)parseToDictionary;

@end

@interface UserStateOwner : StateOwnerBasic

@end

@interface DeviceStateOwner : UserStateOwner

@property(nonatomic,strong) NSString *runtime;

@end

@interface ApplicationStateOwner : UserStateOwner

@end