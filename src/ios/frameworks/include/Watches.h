//
//  Watches.h
//  ios-sdk
//
//  Intel Cloud Services iOS SDK - 5/27/13.
//  Copyright (c) 2013 Intel ; Licensed MIT
//

#import <Foundation/Foundation.h>

@class ItemContext;
@class Watch;
@class ListItems;

typedef void (^ListItemsWatchCallback)(ListItems*);

@interface Watches : NSObject

@property (nonatomic, strong) NSMutableArray *watches;

-(id)initFromDictionary:(NSDictionary*)data;

-(id)initFromNSArray:(NSArray*)data;

-(id)init;

-(void)addWatch:(Watch*)watch;

-(void)deleteWatch:(Watch*)watch;

-(Watch*)getWatchById:(NSString*)watchId;

-(Watches*)getWatchesByContextType:(NSString*)contextType;

-(NSDictionary*)parseToDictionary;

@end

@interface Watch : NSObject{
    NSTimer *_timer;
    ListItemsWatchCallback _watchCallback;
    ErrorCallback _errorCallback;
}

@property (nonatomic, strong) NSString *watchId;
@property (nonatomic, strong) NSString *contextType;
@property (nonatomic, strong) NSString *owner;
@property (nonatomic, strong) NSString *provider;
@property (nonatomic, strong) NSString *callbackUrl;

+(Watch*)createWatchWithContextType:(NSString*)contextType;

-(id)initFromDictionary:(NSDictionary*)data;

-(id)init;

-(void)activate:(ListItemsWatchCallback)callback errorCallback:(ErrorCallback)errorCallback secsPolling:(double)secsPolling;

-(void)deactivate;

-(NSDictionary*)parseToDictionary;

-(NSData*)serialize;

-(NSData*)serializeWatchForCreate;

@end