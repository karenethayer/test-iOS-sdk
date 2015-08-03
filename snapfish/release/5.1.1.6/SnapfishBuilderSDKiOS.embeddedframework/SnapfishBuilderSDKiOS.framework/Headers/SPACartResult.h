//
//  SPACartResult.h
//  SPAToolKit
//
//  Created by Karen Thayer on 9/18/14.
//  Copyright (c) 2014 Snapfish Publisher Team. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SPAProjectBase.h"

typedef enum {
    SPACartCheckoutSucceeded,
    SPACartCheckoutFailure,
    SPACartCheckoutCancelled,
    SPACartCheckoutUploadInProgress,
    SPACartCheckoutUploadFailed,
    SPACartCheckoutProjectEdit,
    SPACartCheckoutSucceededWithPromotionClicked
}SPACartResultEnum;

#define SPACartResultEnumString(enum) [@[@"SPACartCheckoutSucceeded",@"SPACartCheckoutFailure",@"SPACartCheckoutCancelled", @"SPACartCheckoutUploadInProgress", @"SPACartCheckoutUploadFailed", @"SPACartCheckoutProjectEdit", @"SPACartCheckoutSucceededWithPromotionClicked" ] objectAtIndex:enum]

@interface SPACartResult : NSObject

@property SPACartResultEnum result;
@property (strong, nonatomic) SPAProjectBase *project;
@property (strong, nonatomic) NSDictionary *promotionInfo;

- (id) initWithResult:(SPACartResultEnum)result;


@end
