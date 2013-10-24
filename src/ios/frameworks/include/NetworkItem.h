//
//  NetworkItem.h
//  Context
//
//  Created by Waldemar Krumrick on 9/19/13.
//  Copyright (c) 2013 Intel. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Item.h"

@interface NetworkItem : Item

@property(nonatomic,strong) NSString *mPhoneType;
@property(nonatomic,strong) NSString *mCellLocation;
@property(nonatomic,assign) int mLinkSpeed;
@property(nonatomic,strong) NSString *mNetworkType;
@property(nonatomic,strong) NSString *mSsid;
@property(nonatomic,strong) NSString *mSecurityType;
@property(nonatomic,strong) NSString *mSignalStrenght;
@property(nonatomic,assign) BOOL mRoamingActive;
@property(nonatomic,assign) int mOnlineTime;
@property(nonatomic,strong) NSString *mTrafficReceived;
@property(nonatomic,strong) NSString *mTrafficSent;
@property(nonatomic,strong) NSDictionary *mNearNetworks;

@end
