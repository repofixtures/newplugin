//
//  ContextSDKPlugin.m
//  Hydrogen
//
//  Created by Waldemar Krumrick on 10/1/13.
//
//

#import "ContextSDKPlugin.h"
#import "ListenerCallback.h"
#import "Item.h"
#import "Types.h"
#import "Common.h"
#import "IntelCloudServicesPlatformSDK.h"

static bool isStart = NO;

@implementation ContextSDKPlugin
@synthesize callbackId = _callbackId;

- (void)initWithServicesList:(CDVInvokedUrlCommand *)command{
    
    CDVPluginResult *result = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:@"The service is already initialized."];
    
    if(!isStart){
        
        isStart = YES;
        
        ListenerCallback *genericListener = nil;
        
        [ContextSDK initialize:self];

        //Save callback id
        _callbackId = command.callbackId;
        
        BOOL isService = NO;
        
        for(NSDictionary *urn_service in [command.arguments objectAtIndex:0]){
            if([[urn_service objectForKey:@"urn"] isEqualToString:[NetworkType getNetworkType].urn]){
                NSMutableDictionary *options = [NSMutableDictionary dictionaryWithObject:[NSNumber numberWithInt:120] forKey:OPTION_MONITOR_INTERVAL];
                genericListener = [[ListenerCallback alloc] initWithSelector:@selector(onReceivedItem:) selectorError:@selector(onError:) listenerObject:self];
                [ContextSDK addListener:[Type getNetworkType] listener:genericListener options:nil];
                [ContextSDK enableProvider:[Type getNetworkType] options:options];
                isService = YES;
            }else if([[urn_service objectForKey:@"urn"] isEqualToString:[LocationType getLocationType].urn]){
                genericListener = [[ListenerCallback alloc] initWithSelector:@selector(onReceivedItem:) selectorError:@selector(onError:) listenerObject:self];
                [ContextSDK addListener:[Type getLocationType] listener:genericListener options:nil];
                [ContextSDK enableProvider:[Type getLocationType] options:nil];
                isService = YES;
            } else if([[urn_service objectForKey:@"urn"] isEqualToString:[BatteryType getBatteryType].urn]){
                NSMutableDictionary *options = [NSMutableDictionary dictionaryWithObject:[NSNumber numberWithInt:10] forKey:OPTION_MONITOR_INTERVAL];
                genericListener = [[ListenerCallback alloc] initWithSelector:@selector(onReceivedItem:) selectorError:@selector(onError:) listenerObject:self];
                [ContextSDK addListener:[Type getBatteryType] listener:genericListener options:nil];
                [ContextSDK enableProvider:[Type getBatteryType] options:options];
                isService = YES;
            } else if([[urn_service objectForKey:@"urn"] isEqualToString:[ContactsType getContactsType].urn]){
                genericListener = [[ListenerCallback alloc] initWithSelector:@selector(onReceivedItem:) selectorError:@selector(onError:) listenerObject:self];
                [ContextSDK addListener:[Type getContactsType] listener:genericListener options:nil];
                [ContextSDK enableProvider:[Type getContactsType] options:nil];
                isService = YES;
            } else if([[urn_service objectForKey:@"urn"] isEqualToString:[CallType getCallType].urn]){
                genericListener = [[ListenerCallback alloc] initWithSelector:@selector(onReceivedItem:) selectorError:@selector(onError:) listenerObject:self];
                [ContextSDK addListener:[Type getCallType] listener:genericListener options:nil];
                [ContextSDK enableProvider:[Type getCallType] options:nil];
                isService = YES;
            } else if([[urn_service objectForKey:@"urn"] isEqualToString:[MusicType getMusicType].urn]){
                genericListener = [[ListenerCallback alloc] initWithSelector:@selector(onReceivedItem:) selectorError:@selector(onError:) listenerObject:self];
                [ContextSDK addListener:[Type getMusicType] listener:genericListener options:nil];
                [ContextSDK enableProvider:[Type getMusicType] options:nil];
                isService = YES;
            } else if([[urn_service objectForKey:@"urn"] isEqualToString:[InformationType getInformationType].urn]){
                genericListener = [[ListenerCallback alloc] initWithSelector:@selector(onReceivedItem:) selectorError:@selector(onError:) listenerObject:self];
                [ContextSDK addListener:[Type getInformationType] listener:genericListener options:nil];
                [ContextSDK enableProvider:[Type getInformationType] options:nil];
                isService = YES;
            } else if([[urn_service objectForKey:@"urn"] isEqualToString:[CalendarType getCalendarType].urn]){
                genericListener = [[ListenerCallback alloc] initWithSelector:@selector(onReceivedItem:) selectorError:@selector(onError:) listenerObject:self];
                [ContextSDK addListener:[Type getCalendarType] listener:genericListener options:nil];
                [ContextSDK enableProvider:[Type getCalendarType] options:nil];
                isService = YES;
            }
        }
        
        if(isService){
            result = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsInt:1];
        } else {
            result = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:@"The list of services is empty."];
        }
    }

    [self.commandDelegate sendPluginResult:result callbackId:command.callbackId];
}

- (void)getServicesList:(CDVInvokedUrlCommand *)command{
    
    NSMutableArray *arrTypes = [NSMutableArray array];
    
    NSMutableDictionary *aux = [NSMutableDictionary dictionary];
    aux = [[Type getLocationType] parseToDictionary];
    [aux setObject:@"Location" forKey:@"name"];
    [arrTypes addObject:aux];
    
    aux = [[Type getBatteryType] parseToDictionary];
    [aux setObject:@"Battery" forKey:@"name"];
    [arrTypes addObject:aux];
    
    aux = [[Type getCalendarType] parseToDictionary];
    [aux setObject:@"Calendar" forKey:@"name"];
    [arrTypes addObject:aux];
    
    aux = [[Type getCallType] parseToDictionary];
    [aux setObject:@"Call" forKey:@"name"];
    [arrTypes addObject:aux];
    
    aux = [[Type getContactsType] parseToDictionary];
    [aux setObject:@"Contacts" forKey:@"name"];
    [arrTypes addObject:aux];
    
    aux = [[Type getInformationType] parseToDictionary];
    [aux setObject:@"Information" forKey:@"name"];
    [arrTypes addObject:aux];
    
    aux = [[Type getMusicType] parseToDictionary];
    [aux setObject:@"Music" forKey:@"name"];
    [arrTypes addObject:aux];
    
    aux = [[Type getNetworkType] parseToDictionary];
    [aux setObject:@"Network" forKey:@"name"];
    [arrTypes addObject:aux];
    
    //Send array
    CDVPluginResult *result = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsArray:arrTypes];
    [self.commandDelegate sendPluginResult:result callbackId:command.callbackId];
}

- (void)onReceivedItem:(Item *)item{
    NSLog(@"Received an item.");
    [self performSelectorOnMainThread:@selector(writeItem:) withObject:item waitUntilDone:NO];
}

- (void)writeItem:(Item *)item{
    NSString *dict = [Common dictionaryToJsonString:[item toDictionary]];
    [super writeJavascript:[NSString stringWithFormat:@"context.onReceivedItem(%@,'%@');", dict, item.getStateType.urn]];
}

- (void)onReceivedInitACK{
    NSLog(@"The harvester has been initializated successful!");
}

- (void)onReceivedInitError{
    NSLog(@"Error initializating harvester!");
}

- (void)onError:(NSError *)error{
    [self performSelectorOnMainThread:@selector(writeError:) withObject:error waitUntilDone:NO];
}

- (void)writeError:(NSError *)error{
    NSString *errorString = [[error userInfo] objectForKey:@"message"];
    [super writeJavascript:[NSString stringWithFormat:@"context.onError('%@');", errorString]];
}

- (void)writeException:(NSException *)exception{
    NSString *errorString = [exception reason];
    [super writeJavascript:[NSString stringWithFormat:@"context.onError('%@');", errorString]];
}

- (void)stopServices:(CDVInvokedUrlCommand *)command{
    @try{
        if([ContextSDK isInit] && isStart){
            [ContextSDK stopService];
            isStart = NO;
        }
        
        CDVPluginResult *result = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsInt:1];
        [self.commandDelegate sendPluginResult:result callbackId:command.callbackId];
    }@catch (NSException *exception) {
        [self performSelectorOnMainThread:@selector(writeException:) withObject:exception waitUntilDone:NO];
    }
}

- (void)checkStatus:(CDVInvokedUrlCommand *)command{
    CDVPluginResult *result = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsBool:isStart];
    [self.commandDelegate sendPluginResult:result callbackId:command.callbackId];
}

@end