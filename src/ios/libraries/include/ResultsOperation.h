//
//  ResultsOperation.h
//  ios-sdk
//
//  Intel Cloud Services iOS SDK - 7/30/13.
//  Copyright (c) 2013 Intel ; Licensed MIT
//

#import <Foundation/Foundation.h>

@interface ResultsOperation : NSObject

@property(nonatomic,assign) int updated;
@property(nonatomic,assign) int inserted;
@property(nonatomic,assign) int deleted;
@property(nonatomic,strong) NSArray *errors;

@end

@interface ResultError : NSObject

@end
