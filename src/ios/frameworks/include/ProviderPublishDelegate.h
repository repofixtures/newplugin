//
//  ProviderPublishDelegate.h
//  ContextSDK
//
//  Created by Waldemar Krumrick on 9/10/13.
//  Copyright (c) 2013 Intel. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Types.h"
#import "Item.h"

@protocol ProviderPublishDelegate <NSObject>

- (void)updateState:(Type*)type data:(Item*)data;

@end
