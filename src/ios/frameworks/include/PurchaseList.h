//
//  PurchaseList.h
//  ios-sdk
//
//  Intel Cloud Services iOS SDK - 6/26/13.
//  Copyright (c) 2013 Intel ; Licensed MIT
//

#import <Foundation/Foundation.h>
#import "FeedbackStructure.h"

@class ContextUser;
@class ActionPayload;
@class Metadata;

@interface PurchaseList : FeedbackList

-(id)initFromDictionary:(NSDictionary *)data;

@end

@interface Purchase : FeedbackItem

@end

@interface ActionPayloadPurchase : FeedbackActionPayload

@end