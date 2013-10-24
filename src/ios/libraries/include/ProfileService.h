//
//  ProfileService.h
//  ios-sdk
//
//  Intel Cloud Services iOS SDK - 08/05/13.
//  Copyright (c) 2013 Intel ; Licensed MIT
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "Common.h"
#import "Profile.h"
#import "Services.h"

FOUNDATION_EXPORT NSString *const PROFILE_FULL_ERROR_DOMAIN;
FOUNDATION_EXPORT NSString *const PROFILE_ERROR_DOMAIN;

typedef void (^ProfileCallback) (Profile*);

typedef void (^ApplicationProfileKeyCallback) (NSDictionary*);

typedef void (^ApplicationProfileValueCallback) (NSData*);

typedef void (^ApplicationProfileImageCallback) (UIImage*);

typedef void (^ApplicationProfileJsonCallback) (NSDictionary*);

typedef void (^KeyDataCallback) (NSData*);

/**
 *Resolves all calls to Profile Services.<br/>
 *<ul>
 *<li>Get Full Profile</li>
 *<li>Update Full Profile</li>
 *<li>Get Basic Profile</li>
 *<li>Post Application-Specific Profile</li>
 *<li>Update Application-Specific Profile</li>
 *<li>Get Application-Specific Profile Key</li> 
 *<li>Get the List of Application-Specific Profile Keys</li>  
 *<li>Delete Application Specific Profile</li>   
 *</ul>
 */
@interface ProfileService : Services{
    
}

/**
 *Returns an object Profile, if getUserProfile or getBasicProfile were not executed, it returns nil.
 *@return Profile
 */
+ (Profile*)getProfile;

/**
 *Converts an NSData to UIImage.
 *@param data NSData representing an Image.
 *@return UIImage
 */
+(UIImage*)dataProfileToUIImage:(NSData*)data;

/**
 *Returns the user’s credentials, linked social accounts and session information.
 *@throw AuthInitException If Auth is not correctly initialized or the login method was not executed.
 *@param callback Block of code that is executed if the answer is correct and sends as parameter an object Profile.
 *@param errorCallBack Block of code that is executed if the answer is not correct and sends as parameter an object NSError.
 *@snippet ProfileSample getUserProfile
 */
- (void)getUserProfile:(ProfileCallback)callback errorCallback:(ErrorCallback)errorCallback;

/**
 *Returns user's credentials, linked social accounts and session information.
 *@throw AuthInitException Thrown if the Auth class is not correctly initialized or if the login method was not executed.
 *@param callback Block of code that is executed if the answer is correct and sends as parameter an object Profile.
 *@param errorCallBack Block of code that is executed if the answer is not correct and sends as parameter an object NSError.
 *@snippet ProfileSample getUserProfile
 */
- (void)getBasicProfile:(ProfileCallback)callback errorCallback:(ErrorCallback)errorCallback;

/**
 *Returns user's credentials, linked social accounts and session information.
 *@throw AuthInitException Thrown if the Auth class is not correctly initialized or if the login method was not executed.
 *@throw ProfileUpdateException If getUserProfile is not run, or if executed above getBasicProfile.
 *@param callback Block of code that is executed if the answer is correct and sends as parameter an object Profile.
 *@param errorCallBack Block of code that is executed if the answer is not correct and sends as parameter an object NSError .
 *<br/><b>Sample code</b><br/>
 *@snippet ProfileSample updateUserProfile
 */
- (void)updateUserProfile:(ProfileCallback)callback errorCallback:(ErrorCallback)errorCallback;

/**
 *Adds an image in base64 format in the Application Profile of a logged user.
 *@param callback Block of code that is executed if the answer is correct.
 *@param errorCallBack Block of code that is executed if the answer is not correct and sends as parameter an object NSError.
 *@param key The name of the application-specific profile item.
 *@param image Image to be uploaded.
 *<br/><b>Sample code</b><br/>
 *@snippet ProfileSample postImageProfile 
 */
- (void)postImageProfile:(OkCallback)callback errorCallback:(ErrorCallback)errorCallback key:(NSString*)key image:(UIImage *)image;

/**
 *Adds a json string in the Application Profile of a logged user.
 *@param callback Block of code that is executed if the answer is correct.
 *@param errorCallBack Block of code that is executed if the answer is not correct and sends as parameter an object NSError.
 *@param key The name of the application-specific profile item.
 *@param dictionary Dictionary representing the json object.
 *@snippet ProfileSample postJsonProfile
 */
- (void)postJsonProfile:(OkCallback)callback errorCallback:(ErrorCallback)errorCallback key:(NSString*)key dictionary:(NSDictionary*)dictionary;

/**
 *Adds data in the Application Profile of logged user.
 *@param callback Block of code that is executed if the answer is correct.
 *@param errorCallBack Block of code that is executed if the answer is not correct and sends as parameter an object NSError.
 *@param key The name of the application-specific profile item.
 *@param data Any type of data.
 *@snippet ProfileSample addKey
 */
- (void)addKey:(OkCallback)callback errorCallback:(ErrorCallback)errorCallback key:(NSString*)key data:(NSData*)data;

/**
 *Updates data in the Application Profile of a logged user.
 *@param callback Block of code that is executed if the answer is correct.
 *@param errorCallBack Block of code that is executed if the answer is not correct and sends as parameter an object NSError.
 *@param key The name of the application-specific profile item to update.
 *@param data Any type of data
 *@snippet ProfileSample updateKey
 */
- (void)updateKey:(OkCallback)callback errorCallback:(ErrorCallback)errorCallback key:(NSString*)key data:(NSData*)data;

/**
 *Updates an image in base64 format in the Application Profile of a logged user.
 *@param callback Block of code that is executed if the answer is correct.
 *@param errorCallBack Block of code that is executed if the answer is not correct and sends as parameter an object NSError.
 *@param key The name of the application-specific profile item to update.
 *@param image Image to be uploaded.
 *@snippet ProfileSample updateImageProfile
 */
- (void)updateImageProfile:(OkCallback)callback errorCallback:(ErrorCallback)errorCallback key:(NSString*)key image:(UIImage*)image;

/**
 *Updates a json string in the Application Profile of a logged user.
 *@param callback Block of code that is executed if the answer is correct.
 *@param errorCallBack Block of code that is executed if the answer is not correct and sends as parameter an object NSError.
 *@param key The name of the application-specific profile item to update.
 *@param dictionary Dictionary representing the object json to update.
 *@snippet ProfileSample updateJsonProfile
 */
- (void)updateJsonProfile:(OkCallback)callback errorCallback:(ErrorCallback)errorCallback key:(NSString*)key dictionary:(NSDictionary*)dictionary;

/**
 *Returns the key of the items in the Application Profile.
 *@param callback Block of code that is executed if the answer is correct and sends as parameter an object NSDictionary.
 *@param errorCallBack Block of code that is executed if the answer is not correct and sends as parameter an object NSError.
 *@snippet ProfileSample getKeys
 */
- (void)getKeys:(ApplicationProfileKeyCallback)callback errorCallback:(ErrorCallback)errorCallback;

/**
 *Returns key value of the application profile.
 *@param callback Block of code that is executed if the answer is correct and the data type is not an image, not a json object, and send as a parameter an object NSData.
 *@param imageCallback Block of code that is executed if the answer is correct and the data type is an image, and send as a parameter an object UIImage.
 *@param jsonCallback Block of code that is executed if the answer is correct and the data type is a json object, and sends as a parameter an object NSDictionary.
 *@param errorCallBack Block of code that is executed if the answer is not correct and sends as parameter an object NSError.
 *@snippet ProfileSample getValue
 */
- (void)getValue:(ApplicationProfileValueCallback)callback
                     imageCallBack:(ApplicationProfileImageCallback)imageCallback
                        jsonCallBack:(ApplicationProfileJsonCallback)jsonCallback
                            errorCallback:(ErrorCallback)errorCallback key:(NSString*)key;

/**
 *Removes a key from the Application profile.
 *@param callback Block of code that is executed if the answer is correct.
 *@param errorCallBack Block of code that is executed if the answer is not correct and sends as parameter an object NSError.
 *@snippet ProfileSample deleteKey
 */
- (void)deleteKey:(OkCallback)callback errorCallback:(ErrorCallback)errorCallback key:(NSString*)key;


@end