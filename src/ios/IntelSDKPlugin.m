//
//  IntelSDK.m
//  Hydrogen
//
//  Created by Waldemar Krumrick on 9/30/13.
//
//

#import "IntelSDKPlugin.h"

@interface IntelSDKPlugin(){
    AccessToken *resultToken;
    BOOL isCheckedInitialization;
    BOOL isLogged;
    NSString *lastCallbackId;
}

@end

@implementation IntelSDKPlugin

- (void)init:(CDVInvokedUrlCommand *)command{
    
    NSString *clientId = [command.arguments objectAtIndex:0];
    NSString *secretId = [command.arguments objectAtIndex:1];
    NSString *scopes = [command.arguments objectAtIndex:2];
    NSString *redirectUrl = [command.arguments objectAtIndex:3];
    
    NSArray *scopeList = nil;
    
    @try{
        scopeList = [scopes componentsSeparatedByString:@" "];
    }@catch (NSException *exception) {
        scopeList = [Auth getAllScopes];
    }
    
    //REDIRECT_URI = @"54.245.105.150/oauth2callback2.html";
    if([redirectUrl rangeOfString:@"http://"].location != NSNotFound){
        redirectUrl = [redirectUrl stringByReplacingOccurrencesOfString:@"http://" withString:@""];
    } else if([redirectUrl rangeOfString:@"https://"].location != NSNotFound){
        redirectUrl = [redirectUrl stringByReplacingOccurrencesOfString:@"https://" withString:@""];
    }
    
    REDIRECT_URI = redirectUrl;
    [IntelCloudServicesPlatformSDK initWithAction:ACTION_LOGIN
                                      environment:ENVIRONMENT_PRODUCTION
                                         clientId:clientId
                                        secretKey:secretId
                                            scope:scopeList delegate:self];
    
    lastCallbackId = command.callbackId;
    
    if(isCheckedInitialization){
        if(resultToken){
            [self.commandDelegate sendPluginResult:[CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsBool:YES] callbackId:command.callbackId];
        } else {
            [self.commandDelegate sendPluginResult:[CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsBool:NO] callbackId:command.callbackId];
        }
    }
}

- (void)error:(NSError*)error{
    UIAlertView *alert = [[UIAlertView alloc]initWithTitle:@"Error" message:[[error userInfo]objectForKey:@"message"] delegate:nil cancelButtonTitle:@"Accept" otherButtonTitles:nil];
    [alert show];
}

- (void)resultToken:(AccessToken*)result{
    isCheckedInitialization = YES;
    if(result == nil){
        return;
    } else if(!isLogged) {
        resultToken = result;
    }
    
    [self.commandDelegate sendPluginResult:[CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsBool:YES] callbackId:lastCallbackId];
}

- (void)login:(CDVInvokedUrlCommand *)command{
    [[IntelCloudServicesPlatformSDK getAuth] login:^(AccessToken *token){
        isLogged = YES;
        [[IntelCloudServicesPlatformSDK getUser] getUserBasicDetail:^(User *user){ //Obtain user for push states to sensing demo
            CDVPluginResult *response = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK];
            [self.commandDelegate sendPluginResult:response callbackId:command.callbackId];
        }errorCallback:^(NSError *errorCallback){
            NSString *error = [NSString stringWithFormat:@"%@", [[errorCallback userInfo] objectForKey:@"message"]];
            CDVPluginResult *response = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:error];
            [self.commandDelegate sendPluginResult:response callbackId:command.callbackId];
        }];
    }errorCallBack:^(NSError *errorCallback){
        isLogged = NO;
        NSString *error = [NSString stringWithFormat:@"%@", [[errorCallback userInfo] objectForKey:@"message"]];
        CDVPluginResult *response = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:error];
        [self.commandDelegate sendPluginResult:response callbackId:command.callbackId];
    }];
}

- (void)getUserDetails:(CDVInvokedUrlCommand *)command{
    if([[IntelCloudServicesPlatformSDK getAuth] isInit] && [[IntelCloudServicesPlatformSDK getAuth] isLogin]){
        
    }
}

- (void)logout:(CDVInvokedUrlCommand *)command{
    [[IntelCloudServicesPlatformSDK getAuth] logout:^(){
        isLogged = NO;
        CDVPluginResult *response = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK];
        [self.commandDelegate sendPluginResult:response callbackId:command.callbackId];
    }];
}

@end
