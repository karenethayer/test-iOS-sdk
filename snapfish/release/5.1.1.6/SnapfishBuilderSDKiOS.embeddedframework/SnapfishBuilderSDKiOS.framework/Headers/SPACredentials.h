//
//  SPACredentials.h
//  SPAToolkit
//
//  Created by Jokichi Oguri on 6/9/14.
//  Copyright (c) 2014 Snapfish Publisher Team. All rights reserved.
//

#import <Foundation/Foundation.h>
static NSString *const SPA_ENVIRONMENT_QA = @"qa";
static NSString *const SPA_ENVIRONMENT_STAGING = @"stg";
static NSString *const SPA_ENVIRONMENT_PRODUCTION = @"prod";


@interface SPACredentials : NSObject

/**
 *  Container for OAuth2 information
 *
 *  @param appKey   Application key (aka client id)
 *  @param secret   Application Secret (aka client secret)
 *  @param env      Environment to be used
 *  @param context  Context to be used
 *
 *  @return Instance of SPACredentials initialized with the parameters
 */
-(id) initWithAppKey:(NSString *)appKey secret:(NSString *)secret env:(NSString *)env;
-(id) initWithAppKey:(NSString *)appKey secret:(NSString *)secret env:(NSString *)env context:(NSString *)context;

@property (nonatomic, strong, readonly) NSString *appKey;
@property (nonatomic, strong, readonly) NSString *secret;
@property (nonatomic, strong, readonly) NSString *env;
@property (nonatomic, strong, readonly) NSString *context;

@end
