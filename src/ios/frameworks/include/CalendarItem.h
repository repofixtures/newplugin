//
//  CalendarItem.h
//  Context
//
//  Created by Waldemar Krumrick on 9/26/13.
//  Copyright (c) 2013 Intel. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Item.h"

@interface CalendarItem : Item

@property(nonatomic,strong) NSMutableArray *events;

+ (CalendarItem *)createCalendarWithEvents:(NSMutableArray *)arrEvents;

- (NSDictionary *)toDictionary;

@end

@interface Event : NSObject

@property(nonatomic,strong) NSString *startDate;
@property(nonatomic,strong) NSString *duration;
@property(nonatomic,strong) NSString *endDate;
@property(nonatomic,strong) NSString *title;
@property(nonatomic,strong) NSString *description;
@property(nonatomic,strong) NSString *location;
@property(nonatomic,strong) NSString *timeZone;

+ (Event *)createEventWithStartDate:(NSString *)startDate duration:(NSString *)duration endDate:(NSString *)endDate title:(NSString *)title description:(NSString *)description location:(NSString *)location timeZone:(NSString *)timeZone;

- (NSDictionary *)toDictionary;

@end
