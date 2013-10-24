//
//  ProfileUpdateException.h
//  ios-sdk
//
//  Intel Cloud Services iOS SDK - 08/05/13.
//  Copyright (c) 2013 Intel ; Licensed MIT
//

#import <Foundation/Foundation.h>

FOUNDATION_EXPORT NSString *PROFILE_UPDATE_EXCEPTION;
FOUNDATION_EXPORT NSString *PROFILE_NIL_UPDATE_EXCEPTION;

@interface ProfileUpdateException : NSException

+ (ProfileUpdateException*)profileUpdateException;

+ (ProfileUpdateException*)profileIsNilUpdateException;


@end
