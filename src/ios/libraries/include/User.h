//
//  User.h
//  ios-sdk
//
//  Intel Cloud Services iOS SDK - 08/05/13.
//  Copyright (c) 2013 Intel ; Licensed MIT
//

#import <Foundation/Foundation.h>

/**
 *Handles detailed information about a User
 */
@interface User : NSObject

/**
 *A unique user identifier that is always the same across multiple applications.
 */
@property (nonatomic,strong) NSString *userId;

/**
 *A unique user identifier that changes across multiple applications.
 */
@property (nonatomic,strong) NSString *claimId;

/**
 * User emails.
 */
@property (nonatomic,strong) NSMutableArray *emails;

/**
 * Linked social accounts.
 */
@property (nonatomic,strong) NSMutableArray  *accounts;

/**
 * Means that this account was validated.
 */
@property (nonatomic,assign) BOOL     validated;

- (id) initWithDictionary:(NSDictionary*)data;

@end

/**
 * Handles detailed information about a social account.
 */
@interface Account : NSObject

/**
 * Identity provider that will authenticate the user. 
 * Valid values are intel, facebook, google and yahoo.
 */
@property (nonatomic,strong) NSString *provider;

/**
 * User name account
 */
@property (nonatomic,strong) NSString *userName;

- (id) initWithDictionary:(NSDictionary*)data;

@end
