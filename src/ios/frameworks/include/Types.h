//
//  TypeBase.h
//  context
//
//  Created by Waldemar Krumrick on 9/10/13.
//  Copyright (c) 2013 Intel. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CommonContextSDK.h"

@class LocationType;
@class BatteryType;
@class MusicType;
@class CallType;
@class ContactsType;
@class InstalledAppsType;
@class CurrentAppsType;
@class CalendarType;
@class NetworkType;
@class InformationType;
@class MessageType;

@interface Type : NSObject

@property(nonatomic,strong) NSString *urn;
@property(nonatomic,strong) NSString *situationType;

+ (Type*)createTypeWithUrn:(NSString*)urn situationType:(NSString*)situationType;

+ (LocationType*)getLocationType;

+ (MusicType*)getMusicType;

+ (CallType*)getCallType;

+ (BatteryType*)getBatteryType;

+ (ContactsType*)getContactsType;

+ (InstalledAppsType*)getInstalledAppsType;

+ (CurrentAppsType*)getCurrentAppsType;

+ (CalendarType*)getCalendarType;

+ (NetworkType*)getNetworkType;

+ (InformationType*)getInformationType;

+ (MessageType*)getMessageType;

- (id)initWithUrn:(NSString*)urn situationType:(NSString*)situationType;

- (NSMutableDictionary *)parseToDictionary;

@end

@interface LocationType : Type

@end

@interface MusicType : Type

@end

@interface CallType : Type

@end

@interface BatteryType : Type

@end

@interface ContactsType : Type

@end

@interface InstalledAppsType : Type

@end

@interface CurrentAppsType : Type

@end

@interface CalendarType : Type

@end

@interface NetworkType : Type

@end

@interface InformationType : Type

@end

@interface MessageType : Type

@end