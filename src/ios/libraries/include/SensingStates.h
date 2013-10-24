//
//  SensingStates.h
//  ios-sdk
//
//  Intel Cloud Services iOS SDK - 8/12/13.
//  Copyright (c) 2013 Intel ; Licensed MIT
//

#import <Foundation/Foundation.h>
#import "ListState.h"

//Activities for location
FOUNDATION_EXPORT NSString *const ACTIVITY_LOCATION_IN;
FOUNDATION_EXPORT NSString *const ACTIVITY_LOCATION_OUT;
FOUNDATION_EXPORT NSString *const ACTIVITY_LOCATION_MOVING;
FOUNDATION_EXPORT NSString *const ACTIVITY_LOCATION_STAYING;

//Activities for media (audio type so far)
FOUNDATION_EXPORT NSString *const ACTIVITY_MEDIA_BROWSING;
FOUNDATION_EXPORT NSString *const ACTIVITY_MEDIA_LISTENING;
FOUNDATION_EXPORT NSString *const ACTIVITY_MEDIA_RATING;
FOUNDATION_EXPORT NSString *const ACTIVITY_MEDIA_RECEIVING;
FOUNDATION_EXPORT NSString *const ACTIVITY_MEDIA_RECORDING;
FOUNDATION_EXPORT NSString *const ACTIVITY_MEDIA_REVIEWING;
FOUNDATION_EXPORT NSString *const ACTIVITY_MEDIA_SEARCHING;
FOUNDATION_EXPORT NSString *const ACTIVITY_MEDIA_SENDING;

//Ringer mode when the call occurs
FOUNDATION_EXPORT NSString *const DEVICE_CALL_NOTIFICATION_UNKOWN;
FOUNDATION_EXPORT NSString *const DEVICE_CALL_NOTIFICATION_NORMAL;
FOUNDATION_EXPORT NSString *const DEVICE_CALL_NOTIFICATION_SILENT;
FOUNDATION_EXPORT NSString *const DEVICE_CALL_NOTIFICATION_VIBRATE;

//Current device battery status (power related)
FOUNDATION_EXPORT NSString *const DEVICE_BATTERY_STATUS_UNKNOWN;
FOUNDATION_EXPORT NSString *const DEVICE_BATTERY_STATUS_CHARGING;
FOUNDATION_EXPORT NSString *const DEVICE_BATTERY_STATUS_DISCHARGING;
FOUNDATION_EXPORT NSString *const DEVICE_BATTERY_STATUS_NOT_CHARGING;
FOUNDATION_EXPORT NSString *const DEVICE_BATTERY_STATUS_FULL;

//The application current status
FOUNDATION_EXPORT NSString *const DEVICE_INSTALLED_APPS_INSTALLED;
FOUNDATION_EXPORT NSString *const DEVICE_INSTALLED_APPS_UNINSTALLED;
FOUNDATION_EXPORT NSString *const DEVICE_INSTALLED_APPS_UPDATED;

//Activities for device actions
FOUNDATION_EXPORT NSString *const DEVICE_ACTIVITY_CALL_RINGING;
FOUNDATION_EXPORT NSString *const DEVICE_ACTIVITY_CURRENT_APPS_RUNNING;
FOUNDATION_EXPORT NSString *const DEVICE_ACTIVITY_NETWORK_STAYING;

//Specific time of day
FOUNDATION_EXPORT NSString *const TIME_TIMEOFDAY_MORNING;
FOUNDATION_EXPORT NSString *const TIME_TIMEOFDAY_NOON;
FOUNDATION_EXPORT NSString *const TIME_TIMEOFDAY_AFTERNOON;
FOUNDATION_EXPORT NSString *const TIME_TIMEOFDAY_EVENING;
FOUNDATION_EXPORT NSString *const TIME_TIMEOFDAY_NIGHT;
FOUNDATION_EXPORT NSString *const TIME_DAYPARTING_DAY;
FOUNDATION_EXPORT NSString *const TIME_DAYPARTING_NIGHT;

//Specific weekdays
FOUNDATION_EXPORT NSString *const DATE_WEEKDAY_MONDAY;
FOUNDATION_EXPORT NSString *const DATE_WEEKDAY_TUESDAY;
FOUNDATION_EXPORT NSString *const DATE_WEEKDAY_WEDNESDAY;
FOUNDATION_EXPORT NSString *const DATE_WEEKDAY_THURSDAY;
FOUNDATION_EXPORT NSString *const DATE_WEEKDAY_FRIDAY;
FOUNDATION_EXPORT NSString *const DATE_WEEKDAY_SATURDAY;
FOUNDATION_EXPORT NSString *const DATE_WEEKDAY_SUNDAY;

//Specific part of day
FOUNDATION_EXPORT NSString *const DATE_PART_OF_WEEK_WEEKDAY;
FOUNDATION_EXPORT NSString *const DATE_PART_OF_WEEK_WEEKEND;

//Specific Season names
FOUNDATION_EXPORT NSString *const DATE_SEASON_SPRING;
FOUNDATION_EXPORT NSString *const DATE_SEASON_SUMMER;
FOUNDATION_EXPORT NSString *const DATE_SEASON_FALL;
FOUNDATION_EXPORT NSString *const DATE_SEASON_WINTER;

//Specifies what type of day it is
FOUNDATION_EXPORT NSString *const DATE_TYPEOFDAY_REGULAR;
FOUNDATION_EXPORT NSString *const DATE_TYPEOFDAY_HOLIDAY;

@class DeviceContactAddress;

//Location interface
@interface LocationState : State

@end

@interface LocationCurrentState : LocationState

@property(nonatomic,strong) NSNumber *latitude;
@property(nonatomic,strong) NSNumber *longitude;
@property(nonatomic,strong) NSNumber *accuracy;

+ (LocationCurrentState*)createLocationCurrentWithActivity:(NSString*)activity latitude:(NSNumber*)latitude longitude:(NSNumber*)longitude accuracy:(NSNumber*)accuracy;

- (id)initFromDictionary:(NSDictionary *)data;

@end

@interface LocationPlaceState : LocationState

@property(nonatomic,strong) NSString *type;

- (id)initFromDictionary:(NSDictionary *)data;

@end

@interface LocationGeographicState : LocationState

@property(nonatomic,strong) NSString *country;
@property(nonatomic,strong) NSString *city;
@property(nonatomic,strong) NSString *continent;
@property(nonatomic,strong) NSString *country_code;

- (id)initFromDictionary:(NSDictionary *)data;

@end

@interface NearRestaurant : NSObject

//Data contact
@property(nonatomic,strong) NSString *website;
@property(nonatomic,strong) NSString *city;
@property(nonatomic,strong) NSString *name;
@property(nonatomic,strong) NSString *streetAddress;
@property(nonatomic,strong) NSString *phone;
@property(nonatomic,strong) NSString *longitude;
@property(nonatomic,strong) NSString *latitude;
@property(nonatomic,strong) NSString *country;
@property(nonatomic,strong) NSString *state;

//Extended attributes
@property(nonatomic,assign) BOOL accessibleWheelchair;
@property(nonatomic,assign) BOOL groupsGoodFor;
@property(nonatomic,assign) BOOL alcohol;
@property(nonatomic,assign) BOOL paymentCashOnly;
@property(nonatomic,assign) BOOL optionsVegetarian;
@property(nonatomic,assign) BOOL mealDeliver;
@property(nonatomic,assign) BOOL kidsGoodFor;
@property(nonatomic,assign) BOOL mealLunch;
@property(nonatomic,assign) BOOL wifi;
@property(nonatomic,assign) BOOL optionsOrganic;
@property(nonatomic,strong) NSDictionary *hours;
@property(nonatomic,assign) double rating;
@property(nonatomic,assign) BOOL mealBreakfast;
@property(nonatomic,assign) BOOL reservations;
@property(nonatomic,assign) int price;
@property(nonatomic,assign) BOOL parking;
@property(nonatomic,strong) NSString *cuisine;
@property(nonatomic,assign) BOOL mealDinner;
@property(nonatomic,strong) NSString *creditCardsAccepted;
@property(nonatomic,assign) BOOL smoking;
@property(nonatomic,assign) BOOL optionsLowfat;
@property(nonatomic,assign) BOOL seatingOutdoor;
@property(nonatomic,assign) BOOL optionsHealthy;

- (id)initFromDictionary:(NSDictionary *)data;

@end

@interface LocationNearRestaurantsState : LocationState

@property(nonatomic,strong) NSMutableArray *restaurants; //Near restaurants objects

- (id)initFromDictionary:(NSDictionary *)data;

@end

//Media interface
@interface MediaState : State

@end

/**
 AUDIO STATE
*/

@interface MediaAudioState : MediaState

@property(nonatomic,strong) NSString *title;
@property(nonatomic,strong) NSString *author;
@property(nonatomic,strong) NSString *type;
@property(nonatomic,strong) NSString *language;
@property(nonatomic,strong) NSString *description;
@property(nonatomic,strong) NSMutableArray *genre;

- (id)initFromDictionary:(NSDictionary*)data;

+ (MediaAudioState*)createMediaAudioWithActivity:(NSString*)activity title:(NSString *)title author:(NSString *)author type:(NSString *)type language:(NSString *)language description:(NSString *)description genre:(NSArray *)genre additionalProperties:(NSDictionary *)additionalProperties;

@end

//Devices interfaces
@interface DeviceState : State

@end

@interface DeviceMessageInfo : NSObject

@property(nonatomic,strong) NSString *message;
@property(nonatomic,strong) NSDate *date;

- (id)initFromDictionary:(NSDictionary *)data;

- (NSDictionary *)parseToDictionary;

@end

@interface DeviceMessageState : DeviceState

@property(nonatomic,strong) NSString *mPhoneNumber;
@property(nonatomic,strong) NSString *mContactName;
@property(nonatomic,assign) int mTotalMessagesUnread;
@property(nonatomic,strong) NSMutableArray *mUnreadMessages;
@property(nonatomic,assign) int mTotalMessagesSent;
@property(nonatomic,strong) NSMutableArray *mSentMessages;
@property(nonatomic,assign) int mTotalMessagesRead;
@property(nonatomic,strong) NSMutableArray *mReadMessages;

+ (DeviceMessageState*)createDeviceMessagesState;

- (id)initFromDictionary:(NSDictionary*)data;

@end

@interface DeviceInformationState : DeviceState

// Device Information.
@property(nonatomic,strong) NSString *mManufacturer;
@property(nonatomic,strong) NSString *mModel;
@property(nonatomic,strong) NSString *mProductName;
@property(nonatomic,strong) NSString *mBrand;
@property(nonatomic,strong) NSString *mPhoneNumber;
// Hardware Information
@property(nonatomic,assign) double mTotalStorageSize;
@property(nonatomic,strong) NSString *mCpu;
@property(nonatomic,assign) double mTotalRamSize;
@property(nonatomic,strong) NSString *mHardwareName;
@property(nonatomic,strong) NSString *mBoard;
@property(nonatomic,assign) BOOL mHasExternalMemory;
// Software Information
@property(nonatomic,strong) NSString *mOsType;
@property(nonatomic,strong) NSString *mOsVersion;
// Display Information
@property(nonatomic,strong) NSString *mNaturalOrientation;
@property(nonatomic,assign) int mHeight;
@property(nonatomic,assign) int mDensity;
@property(nonatomic,assign) float mSize;
@property(nonatomic,assign) int mWidth;
// Sensors Information
@property(nonatomic,strong) NSDictionary *mSensorsInformation;

+ (DeviceInformationState*)createDeviceInformation;

- (id)initFromDictionary:(NSDictionary*)data;

@end

/**
 Device being called state
 */
@interface DeviceCallState : DeviceState

@property(nonatomic,strong) NSString *caller;
@property(nonatomic,strong) NSString *notificationType;
@property(nonatomic,strong) NSNumber *ringQuantity;
@property(nonatomic,strong) NSString *missedQuantity;
@property(nonatomic,strong) NSString *contactName;

- (id)initFromDictionary:(NSDictionary *)data;

/**
 @param caller The telephone number of the person that is calling. (Optional)
 @param notificationType The ringer mode when the call occurs. (Required)
 @param ringQuantity Times the telephone has already ringed for this call. (Required)
 @param missedQuantity Times the call has been missed (not answered) in the current day. (Optional)
 @param nameContact The name of the calling person. (Optional)
 */
+ (DeviceCallState*)createDeviceCallStateWithCaller:(NSString*)caller notificationType:(NSString*)notificationType ringQuantity:(NSNumber*)ringQuantity missedQuantity:(NSNumber*)missedQuantity nameContact:(NSString*)nameContact;

@end

/**
 Application from device
 */
@interface DeviceApplication : NSObject

@property(nonatomic,strong) NSString *className;
@property(nonatomic,strong) NSString *packageName;
@property(nonatomic,strong) NSString *appName;

- (id)initFromDictionary:(NSDictionary*)data;

- (NSDictionary*)parseToDictionary;

/**
 Creates a new application from device. Must be specified the appName (The application human readable name), packageName (The application package name) and className (The application class name)
 @param appName Required
 @param packageName Required
 @param className @Required
 @return DeviceApplication instance
 */
+ (DeviceApplication*)createApplicationWithName:(NSString*)appName packageName:(NSString*)packageName className:(NSString*)className;

@end

/**
 Applications running or lastly opened on the device
 */
@interface DeviceCurrentApplicationsState : DeviceState

@property(nonatomic,strong) DeviceApplication *currentApplication;
@property(nonatomic,strong) NSMutableArray *latestApplications;

- (id)initFromDictionary:(NSDictionary *)data;

/**
 @param currentApp The application that is currently running in foreground
 @param latestApplications Array containing "DeviceApplication" instances. The applications that are currently running or have been
 recently opened on the device
 @return Object instance for update this state
 */
+ (DeviceCurrentApplicationsState*)createDeviceCurrentAppsWithCurrentApp:(DeviceApplication*)currentApp latestApplications:(NSArray*)latestApplications;

@end

/**
 NETWORK INFORMATION STATE
 */
@interface DeviceNetworkState : DeviceState

@property(nonatomic,strong) NSString *mPhoneType;
@property(nonatomic,strong) NSString *mCellLocation;
@property(nonatomic,assign) int mLinkSpeed;
@property(nonatomic,strong) NSString *mNetworkType;
@property(nonatomic,strong) NSString *mSsid;
@property(nonatomic,strong) NSString *mSecurityType;
@property(nonatomic,strong) NSString *mSignalStrenght;
@property(nonatomic,assign) BOOL mRoamingActive;
@property(nonatomic,assign) int mOnlineTime;
@property(nonatomic,strong) NSString *mTrafficReceived;
@property(nonatomic,strong) NSString *mTrafficSent;
@property(nonatomic,strong) NSDictionary *mNearNetworks;

- (id)initFromDictionary:(NSDictionary *)data;

/**
 @return Object instance for update this state
 */
+ (DeviceNetworkState*)createDeviceNetwork;

@end

/**
 BATTERY INFORMATION STATE
 */
@interface DeviceBatteryState : DeviceState

@property(nonatomic,strong) NSNumber *level;
@property(nonatomic,strong) NSNumber *temperature;
@property(nonatomic,strong) NSNumber *timeOnBattery;
@property(nonatomic,assign) BOOL batteryPresent;
@property(nonatomic,strong) NSNumber *remainingBatteryLife;
@property(nonatomic,strong) NSString *status;
@property(nonatomic,assign) BOOL plugged;
@property(nonatomic,assign) BOOL powerSavingMode;

- (id)initFromDictionary:(NSDictionary *)data;

/**
 @param level Current battery level in percent. (Required)
 @param temperature Battery temperature in Celsius degrees. (Optional)
 @param timeOnBattery Time (in minutes) the device has been running powered by the battery. (Optional)
 @param batteryPresent Indicates if the device has the battery present or not. (Required)
 @param remainingBatteryLife Estimated remaining time (in minutes) the device can operate until the
 battery gets completely discharged. (Optional)
 @param status Current device battery status (power related). The following constants are allowed:DEVICE_BATTERY_STATUS_UNKNOWN,DEVICE_BATTERY_STATUS_CHARGING,DEVICE_BATTERY_STATUS_DISCHARGING,DEVICE_BATTERY_STATUS_NOT_CHARGING,DEVICE_BATTERY_STATUS_FULL. (Required)
 @param plugged Indicates if the device is plugged to an energy source or not. (Required)
 @param powerSavingMode Indicates if the device is on the power saving mode or not. (Optional)
 @return Object instance for update this state
 */

+ (DeviceBatteryState*)createDeviceBatteryWithLevel:(NSNumber*)level temperature:(NSNumber*)temperature timeOnBattery:(NSNumber*)timeOnBattery batteryPresent:(BOOL)batteryPresent remainingBatteryLife:(NSNumber*)remainingBatteryLife status:(NSString*)status plugged:(BOOL)plugged powerSavingMode:(BOOL)powerSavingMode;

@end

@interface DeviceContactsState : State

@property(nonatomic,strong) NSArray *contacts;

+ (DeviceContactsState *)createContactsStateWithContacts:(NSMutableArray *)contacts;

@end

@interface DeviceContact : NSObject

@property (nonatomic, strong) NSString *firstName;
@property (nonatomic, strong) NSString *lastName;
@property (nonatomic, strong) NSString *fullName;
@property (nonatomic, strong) NSDictionary *numbers;
@property (nonatomic, strong) NSDictionary *emails;
@property (nonatomic, strong) DeviceContactAddress *addressInformation;
@property (nonatomic, strong) NSDate *birthdayDate;

- (NSDictionary *)parseToDictionary;

@end

@interface DeviceContactAddress : NSObject

@property(nonatomic,strong) NSString *country;
@property(nonatomic,strong) NSString *zipCode;
@property(nonatomic,strong) NSString *countryCode;
@property(nonatomic,strong) NSString *city;
@property(nonatomic,strong) NSString *street;
@property(nonatomic,strong) NSString *state;

- (NSDictionary *)parseToDictionary;

@end

@interface DeviceEventCalendar : NSObject

@property(nonatomic,strong) NSString *startDate;
@property(nonatomic,strong) NSString *duration;
@property(nonatomic,strong) NSString *endDate;
@property(nonatomic,strong) NSString *title;
@property(nonatomic,strong) NSString *description;
@property(nonatomic,strong) NSString *location;
@property(nonatomic,strong) NSString *timeZone;

- (id)initFromDictionary:(NSDictionary*)data;

- (NSDictionary*)parseToDictionary;

+ (DeviceEventCalendar *)createEventWithStartDate:(NSString *)startDate duration:(NSString *)duration endDate:(NSString *)endDate title:(NSString *)title description:(NSString *)description location:(NSString *)location timeZone:(NSString *)timeZone;

@end

@interface DeviceCalendarState : DeviceState

@property(nonatomic,strong) NSMutableArray *events;

+ (DeviceCalendarState *)createDeviceCalendarWithEvents:(NSMutableArray *)events;

- (id)initFromDictionary:(NSDictionary*)data;

- (NSDictionary*)parseToDictionary;

@end

@interface DeviceInstalledApplication : NSObject

@property(nonatomic,strong) NSString *appName;
@property(nonatomic,strong) NSString *packageName;
@property(nonatomic,strong) NSString *version;
@property(nonatomic,strong) NSString *installationDate;
@property(nonatomic,strong) NSString *updateDate;
@property(nonatomic,strong) NSString *permissions;
@property(nonatomic,strong) NSString *status;

- (id)initFromDictionary:(NSDictionary*)data;

- (NSDictionary*)parseToDictionary;

+ (DeviceInstalledApplication*)createInstalledApplicationWithName:(NSString*)appName packageName:(NSString*)packageName version:(NSString*)version installationDate:(NSString*)installationDate updateDate:(NSString*)updateDate permissions:(NSString *)permissions status:(NSString *)status;

@end

@interface DeviceInstalledAppsState : DeviceState

@property(nonatomic,strong) NSMutableArray *applications;

- (id)initFromDictionary:(NSDictionary *)data;

+ (DeviceInstalledAppsState*)createDeviceInstalledAppsWithApps:(NSArray *)applications;

@end

/**
 Time states
 */
@interface TimeStateBase : State

@end

/**
 @param day Specifies the current weekday. The following constants are allowed: DATE_WEEKDAY_MONDAY, DATE_WEEKDAY_TUESDAY, DATE_WEEKDAY_WEDNESDAY, DATE_WEEKDAY_THURSDAY, DATE_WEEKDAY_FRIDAY, DATE_WEEKDAY_SATURDAY, DATE_WEEKDAY_SUNDAY. (Required)
 @param partOfWeek Specifies what part of the week it is. The following constants are allowed: DATE_PART_OF_WEEK_WEEKDAY, DATE_PART_OF_WEEK_WEEKEND. (Required)
 @param season The following constants are allowed: DATE_SEASON_SPRING,DATE_SEASON_SUMMER, DATE_SEASON_FALL, DATE_SEASON_WINTER. (Required)
 @param typeOfDay The following constants are allowed: DATE_TYPEOFDAY_REGULAR, DATE_TYPEOFDAY_HOLIDAY. (Optional)
 @param descriptionDay Array containing strings with descriptions of the day.
 @return Object instance for update this state
 */
@interface DateState : TimeStateBase

@property(nonatomic,strong) NSString *day;
@property(nonatomic,strong) NSString *partOfWeek;
@property(nonatomic,strong) NSString *season;
@property(nonatomic,strong) NSString *typeOfDay;
@property(nonatomic,strong) NSString *descriptionDay;

- (id)initFromDictionary:(NSDictionary *)data;

@end

/**
 @param timestamp TimeStamp in ISO 8601 format. (Required)
 @param timeOfDay The following constants are allowed:TIME_TIMEOFDAY_MORNING,TIME_TIMEOFDAY_NOON, TIME_TIMEOFDAY_AFTERNOON, TIME_TIMEOFDAY_EVENING, TIME_TIMEOFDAY_NIGHT. (Required)
 @param dayParting The following constants are allowed: TIME_DAYPARTING_DAY, TIME_DAYPARTING_NIGHT. (Required)
 @return Object instance for update this state
 */
@interface TimeState : TimeStateBase

@property(nonatomic,strong) NSString *timestamp;
@property(nonatomic,strong) NSString *timeOfDay;
@property(nonatomic,strong) NSString *dayParting;

- (id)initFromDictionary:(NSDictionary *)data;

@end

/**
 @param offset Specifies the offset of the time zone. (Required)
 @param zoneOffset Time zone offset in seconds. (Required)
 @param zoneDst Time zone offset in seconds for Daylight Saving Time. (Required)
 @param zoneTotalOffset Total time zone offset in seconds. (Required)
 @return Object instance for update this state
 */
@interface TimeZoneState : TimeStateBase

@property(nonatomic,strong) NSString *offset;
@property(nonatomic,strong) NSNumber *zoneOffset;
@property(nonatomic,strong) NSNumber *zoneDst;
@property(nonatomic,strong) NSNumber *zoneTotalOffset;

- (id)initFromDictionary:(NSDictionary *)data;

@end