//
//  MusicItem.h
//  Context
//
//  Created by Waldemar Krumrick on 9/25/13.
//  Copyright (c) 2013 Intel. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Item.h"

@interface MusicItem : Item

@property(nonatomic,strong) NSString *mTitle;
@property(nonatomic,strong) NSString *mAuthor;
@property(nonatomic,strong) NSString *mAlbum;
@property(nonatomic,strong) NSString *mType;

@end
