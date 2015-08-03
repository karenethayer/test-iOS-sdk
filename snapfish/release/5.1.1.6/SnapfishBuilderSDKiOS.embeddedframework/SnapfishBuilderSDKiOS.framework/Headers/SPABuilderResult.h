//
//  SPABuilderResult.h
//  SPABuilder
//
//  Created by Jeffrey Wang on 3/9/15.
//  Copyright (c) 2015 Snapfish. All rights reserved.
//

#import <Foundation/Foundation.h>
//#import "SPABuilderProjectModel.h"

typedef enum {
    SPABuilderProjectSucceeded,
    SPABuilderProjectFailure,
    SPABuilderProjectCancelled,
} SPABuilderResultEnum;

#define SPABuilderResultEnumString(enum) [@[@"SPABuilderCheckoutSucceeded",@"SPABuilderCheckoutFailure",@"SPABuilderCheckoutCancelled" ] objectAtIndex:enum]

@interface SPABuilderResult : NSObject

@property (nonatomic) SPABuilderResultEnum result;
//@property (nonatomic, strong) SPABuilderProjectModel *project;

- (id) initWithResult:(SPABuilderResultEnum)result;

@end
