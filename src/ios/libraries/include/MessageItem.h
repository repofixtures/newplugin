//
//  MessageItem.h
//  Context
//
//  Created by Waldemar Krumrick on 9/25/13.
//  Copyright (c) 2013 Intel. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Item.h"

@interface MessageInfo : NSObject

@property(nonatomic,strong) NSString *message;
@property(nonatomic,strong) NSDate *date;

- (NSDictionary *)toDictionary;

@end

@interface MessageItem : Item

@property(nonatomic,strong) NSString *mPhoneNumber;
@property(nonatomic,strong) NSString *mContactName;
@property(nonatomic,assign) int mTotalMessagesUnread;
@property(nonatomic,strong) NSArray *mUnreadMessages;
@property(nonatomic,assign) int mTotalMessagesSent;
@property(nonatomic,strong) NSArray *mSentMessages;
@property(nonatomic,assign) int mTotalMessagesRead;
@property(nonatomic,strong) NSArray *mReadMessages;

@end
