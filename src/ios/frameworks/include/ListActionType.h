//
//  ListActionType.h
//  ios-sdk
//
//  Intel Cloud Services iOS SDK - 6/26/13.
//  Copyright (c) 2013 Intel ; Licensed MIT
//

#import <Foundation/Foundation.h>

@interface ListActionType : NSObject

@property(nonatomic,strong) NSMutableArray *action_types;
@property(nonatomic,strong) NSString *api_key;

-(id)initFromDictionary:(NSDictionary*)data;

@end

@interface ActionType : NSObject

@property(nonatomic,strong) NSString *name;

-(id)initFromDictionary:(NSDictionary*)data;

@end