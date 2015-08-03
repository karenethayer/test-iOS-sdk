//
//  SPALoginManager.h
//  SPAToolkit
//
//  Created by Jokichi Oguri on 6/9/14.
//  Copyright (c) 2014 Snapfish Publisher Team. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "SPACredentials.h"

// NOTE: SPALoginNotLoggedIn is returned only for changeUserTONewCountryWithCredentials.
// This means that the country changed, but no user was logged in, so the login state
// did not change.
//
typedef enum {
    SPALoginUserSuccess,
    SPALoginUserFailure,
    SPALoginTempUserSuccess,
    SPALoginTempUserFailed,
    SPALoginCancelled,
    SPALoginLoggedOut,
  }SPALoginResult;

typedef enum {
    SPARegisterUserSuccess,
    SPARegisterUserFailure,
    SPARegisterTempUserSuccess,
    SPARegisterTempUserFailed,
    SPARegisterCancelled,
}SPARegisterResult;

typedef enum {
    SPALoginStateLoggedOut,
    SPALoginStateUserLoggedIn,
    SPALoginStateDummyLoggedIn,
}SPALoginState;

// ForLater: Declare delegate protocol

/**
 *  Interface for user management features
 */
@interface SPALoginManager : NSObject


-(id) initWithCredentials:(SPACredentials *)credentials;

/**
 * @depricated Use loginAndAllowUI:useDummyAccount:withCompletionHandler: instead.
 *
 * Case of signature doesn't conform to the common ObjC conventions.
 */
- (void) loginAndAllowUI:(BOOL)allowUI useDummyAccount:(BOOL)useDummy withCompletionHandler:(void(^)(SPALoginResult result, NSError *err))handler;

/**
 *  Logs a user into a Snapfish account, or a temporary account
 *
 *  @param allowUI  If set to true, it will prompt the user with the Login screen.
 *  @param useDummy If set to true, it will log in as a temporary user (you can't process an order as this user)
 *  @param handler  the callback method to be called when the login succeeds or fails
 */
- (void) loginAndAllowUI:(BOOL)allowUI AndUseDummyAccount:(BOOL)useDummy withCompletionHandler:(void(^)(SPALoginResult result, NSError *err))handler __attribute__((deprecated));

- (void) changeUserToNewCountryWithCredentials:(SPACredentials *)cred useDummyAccount:(BOOL)useDummy withCompletionHandler:(void(^)(SPALoginResult result, NSError *err))handler __attribute__((deprecated));
- (void) changeUserToNewCountryWithCredentials:(SPACredentials *)cred withLocale:(NSString *)locale useDummyAccount:(BOOL)useDummy withCompletionHandler:(void(^)(SPALoginResult result, NSError *err))handler __attribute__((deprecated));
- (void) changeUserToNewCountryWithCredentials:(SPACredentials *)cred withLocale:(NSString *)locale withCompletionHandler:(void(^)(SPALoginResult result, NSError *err))handler;

+(void)logOut;

+(int) currentLoggedInState;

@end
