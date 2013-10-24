//
//  LoginDialogDelegate.h
//  ios-sdk
//
//  Intel Cloud Services iOS SDK - 31/05/13.
//  Copyright (c) 2013 Intel ; Licensed MIT
//

#import <Foundation/Foundation.h>

@protocol LoginDialogDelegate <NSObject>

- (void)resultLogin;

/**
 Subclasses must implement this method to get the code and the state from the identity service
 @param code Authorization Code
 @param state State Code
 
 */
- (void)resultLogin:(NSString*)code state:(NSString*)state;

/**
 Subclasses must implement this method to receive errors in the login popup.
 @param errors Errors in the login process
 
 */
- (void)notLogin:(NSError*)errors;

/**
 * Subclasses may override to perform actions just prior to showing the dialog.
 */
- (void)dialogWillAppear;

/**
 * Subclasses may override to perform actions just after the dialog is hidden.
 */
- (void)dialogWillDisappear;


@end

