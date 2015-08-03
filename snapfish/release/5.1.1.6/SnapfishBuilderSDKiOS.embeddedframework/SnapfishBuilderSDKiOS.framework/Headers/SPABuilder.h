//
//  SPABuilder.h
//  SPABuilder
//
//  Created by Jeffrey Wang on 2/17/15.
//  Copyright (c) 2015 Snapfish. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <SnapfishBuilderSDKiOS/SPAToolKit.h>
#import <SnapfishBuilderSDKiOS/SPACredentials.h>
#import "SPABuilderResult.h"

typedef void (^PickerHandler)(id result, NSError *error);

@interface SPABuilder : NSObject

@property (nonatomic, strong, readonly) SPAToolKit *toolKit;
@property (nonatomic, strong) NSString *configFileName;
@property (nonatomic, strong) NSString *locale;
@property NSDictionary *categoryDict;

- (id) init __attribute__((unavailable("Must use initWithCredentials: instead.")));

/**
 * Initialization with application credentials and a client name.
 * 
 **/
- (id) initWithCredentials:(SPACredentials *)credentials
             andClientName:(NSString *)clientName;

/**
 *  Asynchronous setup method
 *
 * @param handler   Completion handler to report results.
 *
 */
-(void) setupWithCompletionHandler:(void(^)(NSError *err))handler;

/**
 *  Optional setting for UI styling
 *
 *  @param skinFile The name of the .plist file containing the skin settings
 */
-(void) setUISkin:(NSString *)skinFile;

/**
 *  Enable/disable guest login
 *
 * @param enableGuestLogin  BOOL determines if guest login is enabled or disabled
 *
 */
-(void) enableGuestLogin:(BOOL)enableGuestLogin;

/**
 *  Returns a view controller that, when presented, will start the
 *  user checkout flow.
 *
 *  @return A UIViewController used to start the checkout process.
 */
-(void)launchWithCompletionHandler:(void(^)(SPABuilderResult *result, SPAProjectBase *project, NSError *err))handler;
-(void)launchWithSkuId:(NSString *)skuId andCompletionHandler:(void(^)(SPABuilderResult *result, SPAProjectBase *project, NSError *err))handler;
-(void)launchWithSkuId:(NSString *)skuId images:(NSArray *)spaImages andCompletionHandler:(void(^)(SPABuilderResult *result, SPAProjectBase *project, NSError *err))handler;
-(void)launchWithImages:(NSArray *)spaImages andCompletionHandler:(void(^)(SPABuilderResult *result, SPAProjectBase *project, NSError *err))handler;

-(void)selectImagesWithCompletionHandler:(PickerHandler)handler;
-(void)selectProductWithCompletionHandler:(PickerHandler)handler;

@end
