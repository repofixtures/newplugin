//
//  Profile.h
//  ios-sdk
//
//  Intel Cloud Services iOS SDK - 08/05/13.
//  Copyright (c) 2013 Intel ; Licensed MIT
//

#import <Foundation/Foundation.h>

/**
 * Represents user profiles.
 */
@interface Profile : NSObject{
    @private
    BOOL _isBasic;
}

@property(nonatomic,strong) NSString *firstName;
@property(nonatomic,strong) NSString *lastName;
@property(nonatomic,strong) NSString *country;
@property(nonatomic,strong) NSString *locality;
@property(nonatomic,strong) NSString *region;
@property(nonatomic,strong) NSString *street;
@property(nonatomic,strong) NSString *zipCode;
@property(nonatomic,strong) NSString *telephoneHome;
@property(nonatomic,strong) NSString *telephoneMobile;
@property(nonatomic,strong) NSString *telephoneWork;
@property(nonatomic,strong) NSDate   *birthDay;
@property(nonatomic,strong) NSString *education;
@property(nonatomic,strong) NSString *gender;
@property(nonatomic,strong) NSString *language;
@property(nonatomic,strong) NSString *maritalStatus;
@property(nonatomic,strong) NSString *ocupation;

- (id)initProfile:(NSDictionary*)data;

- (NSDictionary*)profileToDictionary;

- (BOOL)isBasic;

@end
