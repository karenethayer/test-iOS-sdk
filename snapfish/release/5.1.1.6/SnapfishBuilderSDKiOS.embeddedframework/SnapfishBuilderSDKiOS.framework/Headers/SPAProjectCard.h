//
//  SPAProjectCard.h
//  SPAToolkit
//
//  Created by Jokichi Oguri on 8/18/14.
//  Copyright (c) 2014 Snapfish Publisher Team. All rights reserved.
//

#import "SPAProjectBase.h"
#import "SPASurface.h"

/**
 * @brief The model for creating card order from a set of photos.
 *
 * @example sample_cards.m
 *
 */
@interface SPAProjectCard : SPAProjectBase

/**
 * @brief The image to appear on the front of the card.
 **/
@property (setter = setFront:, nonatomic, retain) SPASurface  *front;

/*
 * @brief The image to appear on the first inside surface. To be used only for folded cards only
 */
@property (nonatomic, retain) SPASurface  *inside1;

/*
 * @brief The image to appear on the second inside surface. To be used only for folded cards only
 */
@property (nonatomic, retain) SPASurface  *inside2;

/*
 * @brief The image to appear on the back surface. To be used for folded cards and flat stationary cards.
 */
@property (nonatomic, retain) SPASurface  *back;

@end
