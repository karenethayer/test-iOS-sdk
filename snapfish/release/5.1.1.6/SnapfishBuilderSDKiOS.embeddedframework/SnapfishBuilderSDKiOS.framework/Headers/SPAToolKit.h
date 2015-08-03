//
//  SPAToolKit.h
//  SPAToolKit
//
//  Created by Jokichi Oguri on 5/16/14.
//  Copyright (c) 2014 Snapfish Publisher Team. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "SPAProjectBase.h"
#import "SPACredentials.h"
#import "SPACartManager.h"
#import "SPALoginManager.h"

// Constants for notifications
#define SPATOOLKIT_LOGIN_SUCCEEDED_NOTIFICATION @"com.snapfish.SPAToolKit.SPALoginWrapperDelegate.LoginSucceded"
#define SPATOOLKIT_ORDER_PLACED_NOTIFICATION @"com.snapfish.SPAToolKit.SPASession.OrderPlaced"
#define SPATOOLKIT_SESSION_CLOSED_NOTIFICATION @"com.snapfish.SPAToolKit.SPASession.WidgetClosed"

#define SPATOOLKIT_ORDER_PLACED_KEY_ORDER_ID @"orderId"
#define SPATOOLKIT_ORDER_PLACED_KEY_ORDER_DATE @"orderDate"
#define SPATOOLKIT_ORDER_PLACED_KEY_COUPON_CODE @"couponCode"
#define SPATOOLKIT_ORDER_PLACED_KEY_ACCOUNT_ID @"accountId"
#define SPATOOLKIT_ORDER_PLACED_KEY_SKUS @"skuList"

#define SPATOOLKIT_ORDER_PLACED_KEY_SUBTOTAL @"subtotal"
#define SPATOOLKIT_ORDER_PLACED_KEY_DISCOUNT @"discount"
#define SPATOOLKIT_ORDER_PLACED_KEY_SHIPPING @"shipping"

@interface SPAToolKit : NSObject

/**
 *  Init method for the toolkit
 *
 *  @param credentials Container class for app key, secret, and endpoint
 *  @param website     Not sure we need this
 *
 *  @return An instance of SPAToolkit
 */

- (id) initWithCredentials:(SPACredentials *)credentials;

- (id) initWithCredentials:(SPACredentials *)credentials
             andClientName:(NSString *)clientName;

- (id) initWithCredentials:(SPACredentials *)credentials
             andClientName:(NSString *)clientName
        withMixpanelOBject:(id)mixpanelObj;

/**
 *  Name used for tracking software
 */
@property (nonatomic, strong) NSString *clientName;

/**
 *  Locale setting. Defaults to device country
 */
@property (nonatomic, strong) NSString *locale;

/**
 *  Context setting. Defaults to /hp/sf/sf-us/snapfish-us
 */
@property (nonatomic, strong) NSString *context;

/**
 *  Asynchronous setup method
 *
 * @param handler   Completion handler to report results.
 *
 */
-(void) setupWithCompletionHandler:(void(^)(NSError *err))handler;

/**
 *  Enable/disable guest login
 *
 * @param enableGuestLogin  BOOL determines if guest login is enabled or disabled
 *
 */
-(void) enableGuestLogin:(BOOL)enableGuestLogin;

/**
 *  Factory method for LoginManager instance
 *
 *  @return SPALoginManager instance
 */
-(SPALoginManager *)loginManager;

/**
 *  Factory method for SPACartManager instance
 *
 *  @return SPACartManager instance
 */
-(SPACartManager *)cartManager;

/**
 * Returns version of the SDK
 */
+(NSString *)getVersion;


@end
