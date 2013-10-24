//
//  AuthInitException.h
//  ios-sdk
//
//  Intel Cloud Services iOS SDK - 29/04/13.
//  Copyright (c) 2013 Intel ; Licensed MIT
//

#import <Foundation/Foundation.h>

FOUNDATION_EXPORT NSString *AUTH_INIT_EXCEPTION;
FOUNDATION_EXPORT NSString *AUTH_INIT_LOGIN_EXCEPTION;

@interface AuthInitException : NSException

+ (AuthInitException*)noInitializeException;

+ (AuthInitException*)noLoginAuthException;

@end
