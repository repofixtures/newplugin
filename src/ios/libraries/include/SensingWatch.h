//
//  SensingWatch.h
//  ios-sdk
//
//  Intel Cloud Services iOS SDK - 5/27/13.
//  Copyright (c) 2013 Intel ; Licensed MIT
//

#import <Foundation/Foundation.h>
#import "Common.h"

@class ListStates;
@class ItemContext;
@class SensingWatch;

typedef void (^ListStatesUserCallback)(ListStates*);

@interface SensingWatch : NSObject{
    NSTimer *_timer;
    ListStatesUserCallback _statesCallback;
    ErrorCallback _errorCallback;
}

@property (nonatomic, strong) NSString *states;

-(void)activate:(ListStatesUserCallback)callback errorCallback:(ErrorCallback)errorCallback secsPolling:(double)secsPolling;

-(void)activate:(ListStatesUserCallback)callback errorCallback:(ErrorCallback)errorCallback secsPolling:(double)secsPolling contextTypeFilter:(NSString*)contextTypeFilter;

-(void)deactivate;

@end