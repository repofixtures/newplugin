//
//  PaginationException.h
//  ios-sdk
//
//  Intel Cloud Services iOS SDK - 7/22/13.
//  Copyright (c) 2013 Intel ; Licensed MIT
//

#import <Foundation/Foundation.h>

@interface PaginationException : NSException

+ (PaginationException*)ErrorNextPage;

+ (PaginationException*)ErrorPreviousPage;

@end
