//
//  SPAToolKit+Private.h
//  SPAToolkit
//
//  Created by Jokichi Oguri on 6/9/14.
//  Copyright (c) 2014 Snapfish Publisher Team. All rights reserved.
//

#ifndef SPAToolkit_SPAToolKit_Private_h
#define SPAToolkit_SPAToolKit_Private_h

@class SPAEndPointModel;

/**
 *  Private interface for SPAToolkit
 */
@interface SPAToolKit ()

/**
 *  Currently selected cobrand. It will default to "snapfish"
 */
@property (nonatomic, strong) NSString *cobrand;

/**
 *  Currently selected locale. It will default to the user's device setting.
 */
@property (nonatomic, strong) NSString *globalLocale;

/**
 *  Will show retail pickup options for delivery
 */
@property (nonatomic) BOOL showRetail;

/**
 *  CartManager instance
 */
@property (nonatomic, strong, readonly) SPACartManager *cartManager;

/**
 *  LoginManager instance
 */
@property (nonatomic, strong, readonly) SPALoginManager *loginManager;

/**
 *  Flag to enable/disable order persistence
 */
@property (nonatomic, setter=setEnableOrderPersistence:, getter=getEnableOrderPersistence) BOOL enableOrderPersistence;

/**
 *  Optional setting for UI styling
 *
 *  @param skinFile The name of the .plist file containing the skin settings
 */
- (void) setUISkin:(NSString *)skinFile;

/**
 *  Retrieves endpoint information from the discovery service
 *
 *  @param serviceName  The name of the service defined by the discovery service. 
 *
 */
- (SPAEndPointModel *) endPointForService:(NSString *)serviceName;

/**
 *  Returns email address of currently logged in user
 *
 *  @return Email address
 */
-(NSString *) getEmailAddress;

/**
 *  Logs to SPLUNK
 *
 *  @param log Message to write to SPLUNK.
 *
 */
-(void) logToSplunk:(NSString *)log;

/**
 *  Logs to SPLUNK and has flag to determine if logs should be flushed and sent to server right away.
 *
 *  @param log Message to write to SPLUNK.
 *  @param flush Flag to send logs to the server right away.
 *
 */
-(void) logToSplunk:(NSString *)log flush:(BOOL) flush;

/**
 *  Logs events to SPLUNK. Events are categorized as significant user actions.
 *
 *  @param event To write to SPLUNK.
 *
 */
-(void) logEventToSplunk:(NSString *)event;

/**
 *  Logs events to SPLUNK. Events are categorized as significant user actions. Has flag to determine if logs should be flushed and sent to server right away.
 *
 *  @param event To write to SPLUNK.
 *  @param flush Flag to send logs to the server right away.
 *
 */
-(void) logEventToSplunk:(NSString *)event flush:(BOOL) flush;
@end


#endif
