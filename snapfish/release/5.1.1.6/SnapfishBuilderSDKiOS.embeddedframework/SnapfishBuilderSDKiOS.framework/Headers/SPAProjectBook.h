//
//  SPAProjectBooks.h
//  SPALib
//
//  Created by Anupam Jindal on 5/29/13.
//  Copyright (c) 2013 HP. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SPAProjectBase.h"
#import "SPASurface.h"

static NSString const* SPA_BOOK_PRINTMODE_SIMPLEX = @"simplex";
static NSString const* SPA_BOOK_PRINTMODE_DUPLEX = @"duplex";

/**
 * @brief The model for creating books order from a set of photos.
 *
 * @example sample_books.m
 *
 */
@interface SPAProjectBook : SPAProjectBase {
    
}

/**
 * @brief The images to appear on the front cover of the book. Array should only contain SPAImage object
 **/
@property (setter = setFrontCover:, nonatomic, retain) SPASurface  *frontCover;

/**
 * @brief The images to appear on the back cover of the book. Array should only contain SPAImage object
 **/
@property (setter = setBackCover:, nonatomic, retain) SPASurface  *backCover;

/**
 * @brief Ordered images to appear inside the book. Array should only contain SPASurface object. These surface objects should be sorted
 **/
@property (setter = setInsidePageImagesArray:, nonatomic, retain) NSArray  *insidePageImagesArray;

/**
 * @brief Print mode of book.
 **/
@property (setter=setPrintMode:, nonatomic, retain) NSString *printMode;

@end
