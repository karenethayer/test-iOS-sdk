//
//  SPACartManager.h
//  SPAToolkit
//
//  Created by Jokichi Oguri on 6/9/14.
//  Copyright (c) 2014 Snapfish Publisher Team. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "SPAProjectBase.h"
#import "SPACartResult.h"
#import "SPASku.h"

/**
 *  Manages items in a cart, and the UI component to invoke the checkout process
 *  in the application.
 */
@interface SPACartManager : NSObject

@property (nonatomic, readonly, getter = getLineItemsCount) long itemCount;

/**
 *  Adds a project to the current order
 *
 *  @param project A SPAProjectBase object to add to the cart
 *  @param handler The callback that will be invoked when the addCart operation is complete
 */
- (void) addToCart:(SPAProjectBase *)project withCompletionHandler:(void(^)(NSError *err))handler;

/**
 *  Removes a project from the current order
 *
 *  @param project A SPAProjectBase object to remove from the cart
 *  @param handler The callback that will be invoked when the removeCart operation is complete
 */
- (void) removeFromCart:(SPAProjectBase *)project withCompletionHandler:(void(^)(NSError *err))handler;

/**
 *  Removes all projects from shipbin
 *
 */
- (void) emptyCartWithCompletionHandler:(void(^)(NSError *err))handler;

/**
 *  Returns a view controller that, when presented, will start the 
 *  user checkout flow.
 *
 *  @return A UIViewController used to start the checkout process.
 */
- (void) startCheckoutFlowWithCompletionHandler:(void(^)(SPACartResult *result,  NSError *err))handler;
- (void) startCheckoutFlow:(UIViewController *)parent withCompletionHandler:(void(^)(SPACartResult *result, NSError *err))handler __attribute__((deprecated));


/**
 *  Returns a view controller that, when presented, will start the
 *  order history flow.
 *
 *  @return A UIViewController used to start order history.
 */
- (void) showOrderHistoryUIWithQueryLimit:(NSString *)queryLimit withCompletionHandler:(void(^)(NSError *error))handler;
- (void) showOrderHistoryUIWithParent:(UIViewController *)parent queryLimit:(NSString *)queryLimit withCompletionHandler:(void(^)(NSError *error))handler __attribute__((deprecated));


- (void) showOrderHistoryUIWithOrderId:(NSString *)orderId withCompletionHandler:(void (^)(NSError *))handler;


/**
 *  Will grant the specified promotion to the currently logged in user.
 *
 *  If there is no currently logged in user, this will return without error, and
 *   the pending flag in the handler will be set to true, indicating that the next user that logs in will
 *   recieve the promotion. To cancel this, call clearPendingPromotion.
 *
 *  If an error was encountered, the error object will be set with details about the failure.
 */
- (void) grantPromotion:(NSString *)promotionIdentifier withCompletionHandler:(void(^)(BOOL pending, NSError *err))handler;
- (void) grantPromotion:(NSString *)promotionIdentifier update:(BOOL)update withCompletionHandler:(void(^)(BOOL pending, NSError *err))handler;

/**
 *  Will clear the pending promotion state for the next login.
 *
 */
-(void) clearPendingPromotion;

/**
 * Display promotion wallet
 */
-(void) showPromotionWalletWithCompletionHandler:(void(^)(NSError *err))handler;


/**
 * Get a list of products (SPASku) from the Snapfish
 **/
-(void) getSku:(NSString *)skuId  withCompletionHandler:(void(^)(SPASku *sku, NSError *error))handler;

/**
 * Get a specified product information object (SPASku) from the Snapfish
 *
 *  @param sourceGroup The sourceGroup to use for getting products
 **/
-(void) getSkusForSourceGroup:(NSString *)sourceGroup withCompletionHandler:(void(^)(NSArray *skus, NSError *error))handler;

@end
