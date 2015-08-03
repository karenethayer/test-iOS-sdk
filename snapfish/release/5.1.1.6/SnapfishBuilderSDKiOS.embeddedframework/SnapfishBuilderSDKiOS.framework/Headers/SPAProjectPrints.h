//
//  SPAProjectPrints.h
//  SPAToolkit
//
//  Created by Jokichi Oguri on 8/18/14.
//  Copyright (c) 2014 Snapfish Publisher Team. All rights reserved.
//

#import "SPAToolKit.h"
#import "SPAProjectBase.h"


static NSString *const SPAProjectPrintsPaperType = @"glossy";

/**
 * @brief The model for creating a set of prints from a group of photos.
 *
 * @example sample_prints.m
 *
 */
@interface SPAProjectPrints:SPAProjectBase

// ForLater: check if needed
/** @brief The number of images in the project. */
@property (getter=getImageCount, nonatomic) int imageCount;

/** @brief The list of SPASurface objects used in the project. */
@property (nonatomic, setter = setSurfaceList:, getter = getSurfaceList, retain) NSArray  *surfaceList;

@end
