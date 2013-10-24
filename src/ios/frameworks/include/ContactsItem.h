//
//  ContactsItem.h
//  Context
//
//  Created by Waldemar Krumrick on 9/17/13.
//  Copyright (c) 2013 Intel. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Item.h"

@class ContactAddress;

@interface ContactsItem : Item

@property(nonatomic,strong) NSArray *contacts;

- (id)initWithArray:(NSArray*)contactsArray;

@end

@interface Contact : NSObject

@property (nonatomic, strong) NSString *firstName;
@property (nonatomic, strong) NSString *lastName;
@property (nonatomic, strong) NSString *fullName;
@property (nonatomic, strong) NSDictionary *numbers;
@property (nonatomic, strong) NSDictionary *emails;
@property (nonatomic, strong) ContactAddress *addressInformation;
@property (nonatomic, strong) NSDate *birthdayDate;

@end

@interface ContactAddress : NSObject

@property(nonatomic,strong) NSString *country;
@property(nonatomic,strong) NSString *zipCode;
@property(nonatomic,strong) NSString *countryCode;
@property(nonatomic,strong) NSString *city;
@property(nonatomic,strong) NSString *street;
@property(nonatomic,strong) NSString *state;

@end