//
//  Auth.h
//  ios-sdk
//
//  Intel Cloud Services iOS SDK - 23/04/13.
//  Copyright (c) 2013 Intel ; Licensed MIT
//

#import <Foundation/Foundation.h>
#import "LoginDialogDelegate.h"
#import "AccessToken.h"
#import "AppInstance.h"
#import "TokenInformation.h"
#import "AuthInitException.h"
#import "Common.h"


//scopes
FOUNDATION_EXPORT NSString *const SCOPE_USER_DETAIL;
FOUNDATION_EXPORT NSString *const SCOPE_PROFILE_BASIC;
FOUNDATION_EXPORT NSString *const SCOPE_PROFILE_FULL;
FOUNDATION_EXPORT NSString *const SCOPE_PROFILE_FULL_WRITE;
FOUNDATION_EXPORT NSString *const SCOPE_USER_BASIC;
FOUNDATION_EXPORT NSString *const SCOPE_USER;
FOUNDATION_EXPORT NSString *const SCOPE_BILLING_CONFIRM;
FOUNDATION_EXPORT NSString *const SCOPE_LOCATION_BASIC;
FOUNDATION_EXPORT NSString *const SCOPE_RECOMENDATION_BASIC;
FOUNDATION_EXPORT NSString *const SCOPE_APPLICATION_PROFILE_READ;
FOUNDATION_EXPORT NSString *const SCOPE_APPLICATION_PROFILE_WRITE;
FOUNDATION_EXPORT NSString *const SCOPE_POST_LOCATION_DETAILED;
FOUNDATION_EXPORT NSString *const SCOPE_CONTEXT_DEVELOPER_SPECIFIC;
FOUNDATION_EXPORT NSString *const SCOPE_CONTEXT_LOCATION_SEARCH;
//
FOUNDATION_EXPORT NSString *const SCOPE_CONTEXT_LOCATION_DETAILED;
FOUNDATION_EXPORT NSString *const SCOPE_CONTEXT_POST_LOCATION_DETAILED;
FOUNDATION_EXPORT NSString *const SCOPE_CONTEXT_LOCATION_CHECKIN;
FOUNDATION_EXPORT NSString *const SCOPE_CONTEXT_POST_LOCATION_CHECKIN;
FOUNDATION_EXPORT NSString *const SCOPE_CONTEXT_POI_SEARCH;
FOUNDATION_EXPORT NSString *const SCOPE_CONTEXT_POST_POI_SEARCH;
FOUNDATION_EXPORT NSString *const SCOPE_CONTEXT_RATINGS;
FOUNDATION_EXPORT NSString *const SCOPE_CONTEXT_POST_RATINGS;
FOUNDATION_EXPORT NSString *const SCOPE_CONTEXT_PREDICTION_LOCATION;
FOUNDATION_EXPORT NSString *const SCOPE_CONTEXT_PREDICTION_POI_WEIGHTS;
FOUNDATION_EXPORT NSString *const SCOPE_CONTEXT_PREDICTION_LOCATION_ID;
FOUNDATION_EXPORT NSString *const SCOPE_CONTEXT_PREDICTION_ACTIVITY;
FOUNDATION_EXPORT NSString *const SCOPE_CONTEXT_POST_MEDIA_CONSUMPTION;
FOUNDATION_EXPORT NSString *const SCOPE_CONTEXT_MEDIA_CONSUMPTION;
FOUNDATION_EXPORT NSString *const SCOPE_CONTEXT_GEOLOCATION_DETAILED;

FOUNDATION_EXPORT NSString *const SCOPE_DEVICE_CALENDAR;
FOUNDATION_EXPORT NSString *const SCOPE_DEVICE_POST_CALENDAR;
FOUNDATION_EXPORT NSString *const SCOPE_DEVICE_STATUS_BATTERY;
FOUNDATION_EXPORT NSString *const SCOPE_TIME_DETAILED;
FOUNDATION_EXPORT NSString *const SCOPE_DEVICE_POST_STATUS_BATTERY;
FOUNDATION_EXPORT NSString *const SCOPE_DEVICE_APPLICATIONS_RUNNING;
FOUNDATION_EXPORT NSString *const SCOPE_DEVICE_POST_APPLICATIONS_RUNNING;
FOUNDATION_EXPORT NSString *const SCOPE_DEVICE_TELEPHONY;
FOUNDATION_EXPORT NSString *const SCOPE_DEVICE_POST_TELEPHONY;

//Environments
FOUNDATION_EXPORT NSString *const ENVIRONMENT_PRODUCTION;
FOUNDATION_EXPORT NSString *const ENVIRONMENT_DEVTEST;
FOUNDATION_EXPORT NSString *const ENVIRONMENT_STRESS;
FOUNDATION_EXPORT NSString *const ENVIRONMENT_QA;
FOUNDATION_EXPORT NSString *const ENVIRONMENT_INT;

//Actions
FOUNDATION_EXPORT NSString *const ACTION_CREATE;
FOUNDATION_EXPORT NSString *const ACTION_LOGIN;

//error domains
FOUNDATION_EXPORT NSString *const TOKEN_INFO_ERROR_DOMAIN;
FOUNDATION_EXPORT NSString *const APP_INSTANCE_ERROR_DOMAIN;
FOUNDATION_EXPORT NSString *const TOKEN_ERROR_DOMAIN;
FOUNDATION_EXPORT NSString *const LOGOUT_ERROR_DOMAIN;
FOUNDATION_EXPORT NSString *const LOGIN_ERROR_DOMAIN;

//providers
FOUNDATION_EXPORT NSString *const PROVIDER_AUTH_INTEL;
FOUNDATION_EXPORT NSString *const PROVIDER_AUTH_GOOGLE;
FOUNDATION_EXPORT NSString *const PROVIDER_AUTH_FACEBOOK;
FOUNDATION_EXPORT NSString *const PROVIDER_AUTH_YAHOO;

@class Rest;

@protocol AuthDelegate;

typedef void (^TokenInformationCallback)(TokenInformation*);

typedef void (^AppInstanceCallback)(AppInstance*);

typedef void (^AccessTokenCallback)(AccessToken*);

typedef void (^LogoutCallback)();

/**
    Resolves all calls to Identity Services.<br/>
    <ul>
    <li>Authorization Code</li>
    <li>Login</li>
    <li>Authorization Token</li>
    <li>Refresh token</li>
    <li>Application instance</li>
    <li>Get an Access Token by the provided Resource Owner Credentials</li>
    <li>Token Information</li>
    <li>Log out</li>
    </ul>

 Class constants scopes
 <ul>
    <li>SCOPE_USER_DETAIL</li>
    <li>SCOPE_PROFILE_BASIC</li>
    <li>SCOPE_PROFILE_FULL</li>
    <li>SCOPE_PROFILE_FULL_WRITE</li>
    <li>SCOPE_USER_BASIC</li>
    <li>SCOPE_BILLING_CONFIRM</li>
    <li>SCOPE_LOCATION_BASIC</li>
    <li>SCOPE_RECOMENDATION_BASIC</li>
 </ul>
 
 Class constants error domains<br/>
 Error domain used to identify errors in calls to the services
 <ul>
    <li>TOKEN_INFO_ERROR_DOMAIN</li>
    <li>APP_INSTANCE_ERROR_DOMAIN</li>
    <li>TOKEN_ERROR_DOMAIN</li>
    <li>LOGOUT_ERROR_DOMAIN</li>
    <li>LOGIN_ERROR_DOMAIN</li>
 </ul>
 */
@interface Auth : NSObject<LoginDialogDelegate>{
    @private
    id <AuthDelegate> _delegate;
    NSString *_code;
    NSString *_state;
    bool     _isInit;
    bool _isLogin;
    bool _validToken;
    AccessTokenCallback _accessTokenCallBack;
    ErrorCallback       _errorAccessTokenCallBack;
}

+(NSString*)getEnviroment;

/**
 Returns an object AccessToken. Returns nil if app has not been logged in. (Not recommended, but if app has created more than one class Auth, always returns the same AccessToken.)
 *@return AccessToken
 */
+ (AccessToken*)getAuthStatus;

/**
 *Returns an object TokenInformation. Returns nil if app still did not execute getApplicationInstance. (Not recommended, but if app has created more than one class Auth, always returns the same TokenInformation).
 *@return TokenInformation
 */
+ (TokenInformation*)getTokenInfo;

/**
 *Returns an object AppInstance.
 *Returns nil, if app still did not execute getTokenInfo. (Not recommended, but if app has created more than one class Auth, always returns the same TokenInformation).
 *@return TokenInformation
 */
+ (AppInstance*)getApplicationInstance;

/**
 *Returns the scope assigned during initialization of Auth. 
 *Returns nil if Auth is not initialized correctly.
 *@return NSString
 */
+ (NSString*)getScope;

/**
 *Returns all the scopes allowed by the API.
 *@return NSArray
 */
+ (NSArray*)getAllScopes;

/**
 *Returns the client id assigned during initialization of Auth. 
 *Returns nil if Auth is not initialized correctly.
 *@return NSString
 */
+ (NSString*)getClientId;

/**
 *Auth initialized to perform subsequent calls to services. The default environment is ENVIRONMENT_DEVTEST.
 *@param clientId Client ID for app obtained from the Developer Portal.
 *@param secretId Client secret for app obtained from the Developer Portal.
 *@param delegate Delegate that implements the protocol AuthDelegate.
 *<b>Sample code</b><br/>
 *@snippet AuthSample init
 */
- (id)initWithClientId:(NSString*)clientId secretKey:(NSString*)secretKey scope:(NSArray*)scope delegate:(id)delegate;

/**
 *Auth initialized to perform subsequent calls to services. The default action is ACTION_LOGIN.
 *@param environment The environment to connect with. Use constants ENVIRONMENT_ from Auth class.
 *@param clientId Client ID for app obtained from the Developer Portal.
 *@param secretId Client secret for app obtained from the Developer Portal.
 *@param delegate Delegate that implements the protocol AuthDelegate.
 *@throw ParameterException The environment is not valid.
 */
- (id)initWithEnvironment:(NSString *)environment clientId:(NSString *)clientId secretKey:(NSString *)secretKey scope:(NSArray *)scope delegate:(id)delegate;

/**
 *Auth initialized to perform subsequent calls to services.
 *@param action The action to realize. This value can be ACTION_LOGIN (for login) or ACTION_CREATE (for create new account) constants.
 *@param environment The environment to connect with. Use constants ENVIRONMENT_ from Auth class.
 *@param clientId Client ID for app obtained from the Developer Portal.
 *@param secretId Client secret for app obtained from the Developer Portal.
 *@param delegate Delegate that implements the protocol AuthDelegate.
 *@throw ParameterException The environment is not valid.
 */
- (id)initWithAction:(NSString *)action environment:(NSString *)environment clientId:(NSString *)clientId secretKey:(NSString *)secretKey scope:(NSArray *)scope delegate:(id)delegate;


/**
 *Displays the login popup.
 *@throw AuthInitException App has not properly initialized Auth.
 *@param callback Block of code that is executed if the response is correct.
 *@param errorCallBack Block of code that is executed if the response is not correct.
 *@snippet AuthSample login
 */
- (void)login:(AccessTokenCallback)callback errorCallBack:(ErrorCallback)errorCallBack;


/**
 *Displays the login popup.
 *@throw AuthInitException App has not properly initialized Auth.
 *@param callback Block of code that is executed if the response is correct.
 *@param errorCallBack Block of code that is executed if the response is not correct.
 *@param provider Identity provider that will authenticate the user. Valid values are intel, facebook, google and yahoo.
 *@snippet AuthSample login
 */
- (void)login:(AccessTokenCallback)callback errorCallBack:(ErrorCallback)errorCallBack provider:(NSString*)provider;

/**
Removes login cookies.
 */
- (void)logout:(LogoutCallback)callback;

/**
 *Starts Application instance service call.
 *@throw AuthInitException App has not properly initialized Auth.
 *@param callback Block of code that is executed if the response is correct.
 *@param errorCallBack Block of code that is executed if the response is not correct.
 *@snippet AuthSample getApplicationInstance
*/
- (void)getApplicationInstance:(AppInstanceCallback)callback errorCallBack:(ErrorCallback)errorCallBack;

/**
 Starts Token information service call.
 @throw AuthInitException AuthInitException App has not properly initialized Auth.
 *@param callback Block of code that is executed if the response is correct.
 *@param errorCallBack Block of code that is executed if the response is not correct.
 *@snippet AuthSample getTokenInfo
 */
- (void)getTokenInfo:(TokenInformationCallback)callback errorCallback:(ErrorCallback)errorCallBack;

/**
 Gets the social token.
 @param provider Provider to use to get the access token. The default provider is INTEL.
 @return TokenInformation Client id and scopes of user associated with this token.
 */

- (void)getSocialToken:(TokenInformationCallback)callback errorCallBack:(ErrorCallback)errorCallback provider:(NSString *)provider;

/**
 Starts Refresh token service call.
 @throw AuthInitException App has not properly initialized Auth.
 *@param callback Block of code that is executed if the response is correct.
 *@param errorCallBack Block of code that is executed if the response is not correct.
 *@snippet AuthSample refreshToken
 */
- (void)refreshToken:(AccessTokenCallback)callback errorCallBack:(ErrorCallback)errorCallBack;

/**
 *Gets an Access Token by the provided Resource Owner Credentials.
 *@throw AuthInitException App has not properly initialized Auth.
 *@param user User logged into the application.
 *@param password Password of the user logged into the application.
 *@param scope Scopes for the user registered in the application.
 *@param callback Block of code that is executed if the response is correct.
 *@param errorCallBack Block of code that is executed if the response is not correct.
 @snippet AuthSample getAuthStatus
 */
- (void)getAuthStatus:(NSString*)user
              password:(NSString*)password
                 scope:(NSArray*) scopes
                    accessTokenCallBack:(AccessTokenCallback)callback
                        errorCallBack:(ErrorCallback)errorCallBack;

/**
 *Indicates whether Auth has been initialized properly or not.
 *@return true Auth initialized correctly.
 *@return false Auth not initialized correctly.
 */
- (bool)isInit;

/**
 *Returns whether Auth is logged in or not.
 *@return true Auth is logged in.
 *@return false Auth is not logged in.
 */
- (bool)isLogin;

@end

/**
 *Protocol should implement the subclasses that need to receive the results of calls to Intel Identity Services
 */
@protocol AuthDelegate <NSObject>

@optional

/**
 *Subclasses must implement this method to perform some action after opening the login popup.
 */
- (void)dialogWillAppear;

/**
 *Subclasses must implement this method to perform some action after closing the popup login.
 */
- (void)dialogWillDisappear;

@required

- (void)resultToken:(AccessToken*)result;

/**
 *Subclasses must implement this method for any errors that occur in the log in call.
 *@param error
 *   Known Domains
 *  <ul>
 *       <li>TOKEN_INFO_ERROR_DOMAIN Indicates an error in the call to the Token Information service.</li>
 *       <li>APP_INSTANCE_ERROR_DOMAIN Indicates an error in the call to the Application Instance service.</li>
 *       <li>TOKEN_ERROR_DOMAIN Indicates an error in the call to the Get Token or Refresh Token service.</li>
 *       <li>LOGOUT_ERROR_DOMAIN Indicates an error in the call to the Log Out services</li>
 *       <li>LOGIN_ERROR_DOMAIN Indicates an error in the call to the Log In service.</li>
 *  </ul>
 *
 *It may access the error domain as follows.
 *
 *[error domain]
 *
 *It may access the error description as follows.
 *[[error userInfo] objectForKey: @ "message"]
 */
- (void) error:(NSError*) error;

@end
