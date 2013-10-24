//
//  ContextError.h
//  context
//
//  Created by Waldemar Krumrick on 9/10/13.
//  Copyright (c) 2013 Intel. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ContextError : NSError

+ (ContextError*)contextErrorWithMessage:(NSString*)details code:(NSNumber*)code;

@end
