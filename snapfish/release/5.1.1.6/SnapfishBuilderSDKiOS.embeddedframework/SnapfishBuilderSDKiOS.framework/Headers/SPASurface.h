//
//  SPASurface.h
//  SPAToolkit
//
//  Created by Jokichi Oguri on 8/18/14.
//  Copyright (c) 2014 Snapfish Publisher Team. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SPASurface.h"
#import "SPAImage.h"
#import "SPAJsonSerializeProtocol.h"
#import "SPALayeredItem.h"

@interface SPASurface : NSObject<SPAJsonSerializeProtocol>

/**
 *  Array of SPALayeredItem objects
 */
@property (nonatomic, strong) NSArray *items;
@property (nonatomic, strong) SPALayeredContainer *container;
@property (nonatomic) NSInteger quantity;

-(NSArray *) getImagesToUpload;

-(void)addLayer:(SPALayeredItem *)layer;
-(void)removeLayer:(SPALayeredItem *)layer;

@end

@interface SPASimpleSurface : SPASurface

-(id)initWithImage:(SPAImage *)image;

@end

@interface SPACustomSurface : SPASurface

@end
