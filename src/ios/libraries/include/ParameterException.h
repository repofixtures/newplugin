//
//  ParameterException.h
//  ios-sdk
//
//  Intel Cloud Services iOS SDK - 7/22/13.
//  Copyright (c) 2013 Intel ; Licensed MIT
//

#import <Foundation/Foundation.h>

FOUNDATION_EXPORT NSString *PARAMETER_OUT_OF_RANGE_EXCEPTION;
FOUNDATION_EXPORT NSString *PARAMETER_NULL_VALUE_EXCEPTION;
FOUNDATION_EXPORT NSString *PARAMETER_NOT_VALID_EXCEPTION;

@interface ParameterException : NSException

+ (ParameterException*)ValuesOutOfRangeException;

+ (ParameterException*)NullValueException;

+ (ParameterException*)NullValueExceptionWithParamName:(NSString *)paramName;

+ (ParameterException*)NotValidException;

@end
