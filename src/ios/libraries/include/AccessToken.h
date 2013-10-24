//
//  AccessToken.h
//  ios-sdk
//
//  Intel Cloud Services iOS SDK - 23/04/13.
//  Copyright (c) 2013 Intel ; Licensed MIT
//

#import <Foundation/Foundation.h>

/**
 * Handles detailed information about a current token.
 */
 
@interface AccessToken : NSObject{
    @private
    NSData *_tokenEncrypt;
    NSData *_refreshTokenEncrypt;
}

/**
 *Credential provided by Intel Cloud Services Platform that grants temporary access to the protected resources.
 */
@property (nonatomic,strong) NSString *token;

/**
 *Time in seconds that the token is valid.
 */
@property (nonatomic,assign) NSInteger expiresIn;

/**
 *Used to acquire a new token from the Intel Cloud Services Platform if the original token expires.
 */
@property (nonatomic,strong) NSString *refreshToken;

/**
 *Scope associated with the token.
 */
@property (nonatomic,strong) NSString *scope;

/**
 *OAuth token type.
 */
@property (nonatomic,strong) NSString *token_type;

+ (AccessToken*)loadFromStore;

- (id)initWithDictionary:(NSDictionary*)data;

- (void) save;

@end
