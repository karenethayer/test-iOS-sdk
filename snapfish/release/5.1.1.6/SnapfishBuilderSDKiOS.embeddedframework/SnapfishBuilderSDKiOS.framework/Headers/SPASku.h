//
//  SPASku.h
//  SPAToolkit
//
//  Created by Jokichi Oguri on 3/22/15.
//  Copyright (c) 2015 Snapfish Publisher Team. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface SPASku : NSObject

@property (nonatomic,strong) NSString *id;
@property (nonatomic,strong) NSString *name;
@property (nonatomic,strong) NSString *shortTitle;
@property (nonatomic,strong) NSString *longTitle;
@property (nonatomic,strong) NSString *longDescription;
@property (nonatomic,strong) NSString *skuCategory;
@property (nonatomic,strong) NSString *coBrandComerceAvailabilityStatus;
@property (nonatomic,strong) NSNumber *price;
@property (nonatomic,strong) NSString *mobileStoreTile;
@property (nonatomic,strong) NSString *primaryImage;


@property (nonatomic,strong) NSString *productCategory;
@property (nonatomic) int pixelWidth;
@property (nonatomic) int pixelHeight;
@property (nonatomic) double previewHeightRatio;
@property (nonatomic) double previewWidthRatio;
@property (nonatomic) double printResolution;

@property (nonatomic, strong) NSString *landscapeAlignmentPoints;
@property (nonatomic, strong) NSString *portraitAlignmentPoints;
@property (nonatomic, strong) NSString *builderImagePortrait;
@property (nonatomic, strong) NSString *builderImageLandscape;
@property (nonatomic, strong) NSString *builderOverlayPortrait;
@property (nonatomic, strong) NSString *builderOverlayLandscape;
@property (nonatomic, strong) NSString *orientationString;
@property (nonatomic, strong) NSString *mobileBuilderProductCategory;
@property (nonatomic) double minimumResolution;

@property (nonatomic,strong) NSDictionary *attributes;

@end
