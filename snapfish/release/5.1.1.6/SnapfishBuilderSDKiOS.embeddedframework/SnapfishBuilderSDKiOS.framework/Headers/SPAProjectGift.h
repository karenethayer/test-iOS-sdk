//
//  SPAProjectGift.h
//  SPAToolkit
//
//  Created by Amith on 8/25/14.
//  Copyright (c) 2014 Snapfish Publisher Team. All rights reserved.
//

#import "SPAProjectBase.h"
#import "SPASurface.h"

@interface SPAProjectGift : SPAProjectBase

//@property (setter = setSurface:, getter = getSurface, nonatomic, retain) SPASurface  *surface;
@property (nonatomic, setter = setSurfaceList:, getter = getSurfaceList, retain) NSArray  *surfaceList;
@end
