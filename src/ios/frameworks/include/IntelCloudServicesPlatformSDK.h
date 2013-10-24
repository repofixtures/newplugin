//
//  IntelCloudServicesPlatformSDK.h
//  ios-sdk
//
//  Intel Cloud Services iOS SDK - 29/04/13.
//  Copyright (c) 2013 Intel ; Licensed MIT
//

/**
 \mainpage
 
\htmlonly
 <div class="textblock">Here are the classes, structs, unions and interfaces with brief descriptions:</div><div class="directory">
 <table class="directory">
 <tbody><tr id="row_0_" class="even"><td class="entry"><img src="ftv2node.png" alt="o" width="16" height="22"><img src="ftv2cl.png" alt="C" width="24" height="22"><a class="el" href="interface_access_token.html" target="_self">AccessToken</a></td><td class="desc">Handles detailed information about a current token</td></tr>
 <tr id="row_1_"><td class="entry"><img src="ftv2node.png" alt="o" width="16" height="22"><img src="ftv2cl.png" alt="C" width="24" height="22"><a class="el" href="interface_account.html" target="_self">Account</a></td><td class="desc">Handles detailed information about a social account</td></tr>
 <tr id="row_2_" class="even"><td class="entry"><img src="ftv2node.png" alt="o" width="16" height="22"><img src="ftv2cl.png" alt="C" width="24" height="22"><a class="el" href="interface_app_instance.html" target="_self">AppInstance</a></td><td class="desc">Represents the app instance</td></tr>
 <tr id="row_3_"><td class="entry"><img src="ftv2node.png" alt="o" width="16" height="22"><img src="ftv2cl.png" alt="C" width="24" height="22"><a class="el" href="interface_auth.html" target="_self">Auth</a></td><td class="desc">Resolves all calls to Identity Services</td></tr>
 <tr id="row_4_" class="even"><td class="entry"><img src="ftv2node.png" alt="o" width="16" height="22"><img src="ftv2cl.png" alt="C" width="24" height="22"><a class="el" href="protocol_auth_delegate-p.html" target="_self">&lt;AuthDelegate&gt;</a></td><td class="desc">Protocol should implement the subclasses that need to receive the results of calls to Intel Identity Services</td></tr>
 <tr id="row_5_"><td class="entry"><img src="ftv2node.png" alt="o" width="16" height="22"><img src="ftv2cl.png" alt="C" width="24" height="22"><a class="el" href="interface_catalog_service.html" target="_self">CatalogService</a></td><td class="desc">Resolves all calls to Catalog Services</td></tr>
 <tr id="row_6_" class="even"><td class="entry"><img src="ftv2node.png" alt="o" width="16" height="22"><img src="ftv2cl.png" alt="C" width="24" height="22"><a class="el" href="interface_context_service.html" target="_self">ContextService</a></td><td class="desc">Resolves all calls to Context Services</td></tr>
 <tr id="row_7_"><td class="entry"><img src="ftv2node.png" alt="o" width="16" height="22"><img src="ftv2cl.png" alt="C" width="24" height="22"><a class="el" href="interface_curation_service.html" target="_self">CurationService</a></td><td class="desc">Resolves all calls to Couration Services</td></tr>
 <tr id="row_8_" class="even"><td class="entry"><img src="ftv2node.png" alt="o" width="16" height="22"><img src="ftv2cl.png" alt="C" width="24" height="22"><a class="el" href="interface_intel_cloud_services_platform_s_d_k.html" target="_self">IntelCloudServicesPlatformSDK</a></td><td class="desc"><a class="el" href="interface_intel_cloud_services_platform_s_d_k.html" title="IntelCloudServicesPlatformSDK maintains a single instance of different services APIs.">IntelCloudServicesPlatformSDK</a> maintains a single instance of different services APIs</td></tr>
 <tr id="row_9_"><td class="entry"><img src="ftv2node.png" alt="o" width="16" height="22"><img src="ftv2cl.png" alt="C" width="24" height="22"><a class="el" href="interface_profile.html" target="_self">Profile</a></td><td class="desc">Represents user profiles</td></tr>
 <tr id="row_10_" class="even"><td class="entry"><img src="ftv2node.png" alt="o" width="16" height="22"><img src="ftv2cl.png" alt="C" width="24" height="22"><a class="el" href="interface_profile_service.html" target="_self">ProfileService</a></td><td class="desc">Resolves all calls to <a class="el" href="interface_profile.html" title="Represents user profiles.">Profile</a> Services</td></tr>
 <tr id="row_11_"><td class="entry"><img src="ftv2node.png" alt="o" width="16" height="22"><img src="ftv2cl.png" alt="C" width="24" height="22"><a class="el" href="interface_recommendation_service.html" target="_self">RecommendationService</a></td><td class="desc">Resolves all calls to Recommendation Services</td></tr>
 <tr id="row_12_" class="even"><td class="entry"><img src="ftv2node.png" alt="o" width="16" height="22"><img src="ftv2cl.png" alt="C" width="24" height="22"><a class="el" href="interface_token_information.html" target="_self">TokenInformation</a></td><td class="desc">Represents detailed information about an issued access token</td></tr>
 <tr id="row_13_"><td class="entry"><img src="ftv2node.png" alt="o" width="16" height="22"><img src="ftv2cl.png" alt="C" width="24" height="22"><a class="el" href="interface_user.html" target="_self">User</a></td><td class="desc">Handles detailed information about a <a class="el" href="interface_user.html" title="Handles detailed information about a User.">User</a></td></tr>
 <tr id="row_14_" class="even"><td class="entry"><img src="ftv2lastnode.png" alt="\" width="16" height="22"><img src="ftv2cl.png" alt="C" width="24" height="22"><a class="el" href="interface_user_service.html" target="_self">UserService</a></td><td class="desc">Resolves all calls to <a class="el" href="interface_user.html" title="Handles detailed information about a User.">User</a> Services</td></tr>
 </tbody></table>
 </div><!-- directory -->
 \endhtmlonly 
 */


#import <Foundation/Foundation.h>
#import "CurationService.h"
#import "UserService.h"
#import "Auth.h"
#import "ProfileService.h"
#import "ContextService.h"
#import "CatalogService.h"
#import "RecommendationService.h"

/**
 *IntelCloudServicesPlatformSDK maintains a single instance of different services APIs.
 */
@interface IntelCloudServicesPlatformSDK : NSObject

/**
 *Auth Initializes One Time. If the app runs the Auth logout method, it will need to authorize again then next time the app runs.
 *@param clientId Client ID for app obtained from the Developer Portal.
 *@param secretId Client secret for app obtained from the Developer Portal.
 *@param delegate Delegate that implements the protocol AuthDelegate.
 */
+ (Auth*)init:(NSString*)clientId secretKey:(NSString*)secretKey scope:(NSArray*)scope delegate:(id)delegate;

/**
 *Auth Initializes One Time. If the app runs the Auth logout method, it will need to authorize again then next time the app runs.
 *@param environment The environment to connect with. Uses ENVIRONMENT_ constants from Auth class.
 *@param clientId Client ID for app obtained from the Developer Portal.
 *@param secretId Client secret for app obtained from the Developer Portal.
 *@param delegate Delegate that implements the protocol AuthDelegate.
 */
+ (Auth*)initWithEnvironment:(NSString*)environment clientId:(NSString*)clientId secretKey:(NSString*)secretKey scope:(NSArray*)scope delegate:(id)delegate;

/**
 *Auth Initializes One Time. If the app runs the Auth logout method, it will need to authorize again then next time the app runs.
 *@param action The action to realize. Can be ACTION_LOGIN or ACTION_CREATE constants.
 *@param environment The environment to connect with. Use ENVIRONMENT_ constants from Auth class.
 *@param clientId Client ID for app obtained from the Developer Portal.
 *@param secretId Client secret for app obtained from the Developer Portal.
 *@param delegate Delegate that implements the protocol AuthDelegate.
 */
+ (Auth*)initWithAction:(NSString*)action environment:(NSString*)environment clientId:(NSString*)clientId secretKey:(NSString*)secretKey scope:(NSArray*)scope delegate:(id)delegate;

/**
 *Sets Auth instance
 */
+ (void)setAuth:(Auth*)auth;

/**
 *Gets Auth instance
 */
+ (Auth*)getAuth;

/**
 *Gets UserService instance
 */
+ (UserService*)getUser;

/**
 *Gets ProfileService instance
 */
+ (ProfileService*)getProfileService;

/**
 *Get CatalogService instance
 */
+ (CatalogService*)getCatalogService;

/**
 *Gets ContextService instance
 */
+ (ContextService*)getContextService;

/**
 *Get CatalogService instance
 *Gets CurationService instance
 */
+ (CurationService*)getCurationService;

/**
 *Gets RecommendationService instance
 */
+ (RecommendationService*)getRecommendationService;

@end

