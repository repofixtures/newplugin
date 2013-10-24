//
//  TokenInformation.h
//  ios-sdk
//
//  Intel Cloud Services iOS SDK - 29/04/13.
//  Copyright (c) 2013 Intel ; Licensed MIT
//

#import <Foundation/Foundation.h>
/**
 * Represents detailed information about an issued access token
 */
@interface TokenInformation : NSObject

/**
 Client ID for app obtained from the Developer Portal.
 */
@property (nonatomic,strong) NSString *clientId;

/**
 Scopes associated with the access token.
 */
@property (nonatomic,strong) NSArray *scopes;

- (id)initWithDictionary:(NSDictionary*)data;

@end
