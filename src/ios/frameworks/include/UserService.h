//
//  User.h
//  ios-sdk
//
//  Intel Cloud Services iOS SDK - 07/05/13.
//  Copyright (c) 2013 Intel ; Licensed MIT
//

#import <Foundation/Foundation.h>
#import "Common.h"
#import "User.h"
#import "Services.h"

FOUNDATION_EXPORT NSString *const USER_BASIC_DETAIL_ERROR_DOMAIN;
FOUNDATION_EXPORT NSString *const ACCESS_TOKEN_SCOPES_ERROR_DOMAIN;


typedef void (^UserCallback)(User*);

typedef void (^AccessTokenScopeCallback)(NSArray*);

/**
 *Resolves all calls to User Services.<br/>
 *<ul>
 *<li>Get User Basic Details</li>
 *<li>Get Access Token Scope</li> 
 *</ul>
 */
@interface UserService : Services{
    
}

/**
 *Returns an object User, getUserBasicDetail is not executed, it returns nil.
 *@return User
 */
+ (User*)getDetails;

/**
 *Returns user's credentials, linked social accounts and session information.
 *@throw AuthInitException Thrown if the Auth class is not correctly initialized or if the login method was not executed.
 *@param callback Block of code that is executed if the answer is correct and sends as parameter an object User.
 *@param errorCallBack Block of code that is executed if the answer is not correct and sends as parameter an object NSError.
 *@snippet UserSample getUser
 */
- (void)getUserBasicDetail:(UserCallback)callback errorCallback:(ErrorCallback)errorCallback;

/**
 *Returns the list of scopes authorized for a given access token.
 *@throw AuthInitException Thrown if the Auth class is not correctly initialized or if the login method was not executed.
 *@param callback Block of code to run if the answer is correct, it sends a NSArray with Authorized scopes.
 *@param errorCallBack Block of code that is executed if the answer is not correct and sends as parameter an object NSError.
 *@snippet UserSample getAuthStatusScope
 */
- (void)getScopes:(AccessTokenScopeCallback)callback errorCallback:(ErrorCallback)errorCallback;

@end
