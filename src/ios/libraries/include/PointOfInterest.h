//
//  PointOfInterest.h
//  ios-sdk
//
//  Intel Cloud Services iOS SDK - 7/30/13.
//  Copyright (c) 2013 Intel ; Licensed MIT
//

#import <Foundation/Foundation.h>

FOUNDATION_EXPORT NSString *const CATEGORY_RESTAURANTS;
FOUNDATION_EXPORT NSString *const CATEGORY_HOTELS;
FOUNDATION_EXPORT NSString *const CATEGORY_GAS_STATIONS;

@class CategoryInterest;

@interface PointOfInterest : NSObject

enum CategoryPoint {
    RESTAURANTS,
    GAS_STATIONS,
    HOTELS
};

typedef enum CategoryPoint CurrentCategory;

@property(nonatomic,strong) NSString *_id;
@property(nonatomic,strong) NSString *name;
@property(nonatomic,strong) CategoryInterest *category;
//Address
@property(nonatomic,strong) NSString *country;
@property(nonatomic,strong) NSString *state;
@property(nonatomic,strong) NSString *city;
@property(nonatomic,strong) NSString *streetAddress;
@property(nonatomic,strong) NSString *postalCode;
//Location
@property(nonatomic,assign) double latitude;
@property(nonatomic,assign) double longitude;
@property(nonatomic,assign) double altitude;
//Contact point
@property(nonatomic,strong) NSString *phone;
@property(nonatomic,strong) NSString *website;
@property(nonatomic,strong) NSString *email;

+ (BOOL)isValidArrayOfCategoryTypes:(NSArray *)array;

+ (Class)findClassByCategory:(CategoryInterest *)category;

- (id)initFromDictionary:(NSDictionary *)data;

- (BOOL)isRestaurant;

- (BOOL)isHotel;

- (BOOL)isGasStation;

@end

@interface CategoryInterest : NSObject

- (id)initFromDictionary:(NSDictionary *)data;

@end

@interface Hotel : CategoryInterest

@property(nonatomic,assign) int stars;
@property(nonatomic,assign) int price;
@property(nonatomic,assign) BOOL roomService;
@property(nonatomic,assign) BOOL accessibleWheelchair;
@property(nonatomic,assign) BOOL freeBreakfast;
@property(nonatomic,assign) BOOL businessCenter;
@property(nonatomic,assign) BOOL freeInternet;
@property(nonatomic,assign) BOOL fitnessCenter;
@property(nonatomic,assign) BOOL parking;
@property(nonatomic,assign) BOOL restaurant;
@property(nonatomic,assign) BOOL barLounge;
@property(nonatomic,assign) BOOL petsAllowed;
@property(nonatomic,strong) NSString *currenciesAccepted;
@property(nonatomic,strong) NSDictionary *hours;

- (id)initFromDictionary:(NSDictionary *)data;

@end

@interface Restaurant : CategoryInterest

@property(nonatomic,strong) NSString *cuisine;
@property(nonatomic,assign) int price;
@property(nonatomic,strong) NSDictionary *hours;
@property(nonatomic,assign) double rating;
@property(nonatomic,assign) BOOL mealLunch;
@property(nonatomic,assign) BOOL mealDinner;
@property(nonatomic,assign) BOOL parking;
@property(nonatomic,assign) BOOL accessibleWheelchair;
@property(nonatomic,assign) BOOL wifi;
@property(nonatomic,assign) BOOL groupsGoodFor;
@property(nonatomic,assign) BOOL reservations;
//@property(nonatomic,strong) NSString *creditCardsAccepted;
@property(nonatomic,assign) BOOL paymentCashOnly;
@property(nonatomic,assign) BOOL mealBreakfast;
@property(nonatomic,assign) BOOL alcohol;
@property(nonatomic,assign) BOOL kidsGoodFor;
@property(nonatomic,assign) BOOL optionsOrganic;
@property(nonatomic,assign) BOOL mealDeliver;
@property(nonatomic,assign) BOOL optionsVegetarian;
@property(nonatomic,assign) BOOL optionsHealthy;
@property(nonatomic,strong) NSString *status;
@property(nonatomic,assign) BOOL optionsLowfat;
@property(nonatomic,assign) BOOL smoking;
@property(nonatomic,assign) BOOL seatingOutdoor;

- (id)initFromDictionary:(NSDictionary *)data;

@end

@interface GasStation : CategoryInterest

@property(nonatomic,assign) float regularGas;
@property(nonatomic,assign) float midgrade;
@property(nonatomic,assign) BOOL convenienceStore;
@property(nonatomic,assign) BOOL airHose;
@property(nonatomic,assign) BOOL paymentCashOnly;
@property(nonatomic,strong) NSString *currenciesAccepted;
@property(nonatomic,assign) BOOL payAtPump;
@property(nonatomic,assign) BOOL atm;
@property(nonatomic,assign) BOOL autoRepairShop;
@property(nonatomic,assign) BOOL carWash;
@property(nonatomic,assign) BOOL restrooms;
@property(nonatomic,assign) BOOL payPhone;
@property(nonatomic,assign) BOOL restaurant;
@property(nonatomic,assign) BOOL truckStop;

- (id)initFromDictionary:(NSDictionary *)data;

@end