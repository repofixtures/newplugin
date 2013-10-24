//
//  DeviceInformationItem.h
//  Context
//
//  Created by Waldemar Krumrick on 9/25/13.
//  Copyright (c) 2013 Intel. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Item.h"

@interface DeviceInformationItem : Item

// Device Information.
@property(nonatomic,strong) NSString *mManufacturer;
@property(nonatomic,strong) NSString *mModel;
@property(nonatomic,strong) NSString *mProductName;
@property(nonatomic,strong) NSString *mBrand;
@property(nonatomic,strong) NSString *mPhoneNumber;
// Hardware Information
@property(nonatomic,assign) double mTotalStorageSize;
@property(nonatomic,strong) NSString *mCpu;
@property(nonatomic,assign) double mTotalRamSize;
@property(nonatomic,strong) NSString *mHardwareName;
@property(nonatomic,strong) NSString *mBoard;
@property(nonatomic,assign) BOOL mHasExternalMemory;
// Software Information
@property(nonatomic,strong) NSString *mOsType;
@property(nonatomic,strong) NSString *mOsVersion;
// Display Information
@property(nonatomic,strong) NSString *mNaturalOrientation;
@property(nonatomic,assign) int mHeight;
@property(nonatomic,assign) int mDensity;
@property(nonatomic,assign) float mSize;
@property(nonatomic,assign) int mWidth;
// Sensors Information
@property(nonatomic,strong) NSDictionary *mSensorsInformation;

@end
