//
//  SPAProjectBase.h
//  SPAToolkit
//
//  Created by Jokichi Oguri on 6/9/14.
//  Copyright (c) 2014 Snapfish Publisher Team. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import "SPAImage.h"
#import "SPAJsonSerializeProtocol.h"
#import "SPASurface.h"
#import "SPALayeredItem.h"
#import "SPASku.h"

#define SPA_DEFAULT_SURFACE_CATEGORY  @"inside page"
#define SPA_ORIENTATION_PORTRAIT  @"SPAOrientationPortrait"
#define SPA_ORIENTATION_LANDSCAPE  @"SPAOrientationLandscape"
#define SPA_ORIENTATION_SQUARE  @"SPAOrientationSquare"
#define SPA_ORIENTATION_NONE  @"SPAOrientationNone"

/**
 *  Base class for projects created in the toolkit SDK
 */
@interface SPAProjectBase : NSObject <SPAJsonSerializeProtocol>

@property (nonatomic, strong) SPAImage *productImage;
@property (nonatomic) long long skuId  __attribute__((deprecated));
@property (nonatomic, strong) NSString *sku;
@property (nonatomic, strong) SPASku *skuModel;
@property (nonatomic, strong) NSString *orientation;

/**
 * The client must give this id back to the sdk if they have it (from a project edit request for example) so we can 
 * link it to the existing server side project and not add a new line item.
 **/
@property (nonatomic, strong) NSString *serverProjectId;

-(id)initWithSkuId:(long long)skuId __attribute__((deprecated));
-(id)initWithSku:(NSString *)skuId ;


-(NSArray *) getSurfaceCategoryNames;
-(unsigned long) getSurfaceCount;
-(unsigned long) getSurfaceCountFromCategory:(NSString *)surfaceCategory;

-(void)addSurface:(SPASurface *)surface;
-(void)addSurface:(SPASurface *)surface toCategory:(NSString *)surfaceCategory;
-(SPASurface *) getSurface:(int)index;
-(SPASurface *) getSurface:(int)index fromCategory:(NSString *)surfaceCategory;

-(SPALayeredPhoto *)addPhoto:(SPAImage *)image onSurface:(SPASurface *)surface;
-(SPALayeredText *) addText:(NSArray *)text onSurface:(SPASurface *)surface;

-(void)addLayer:(SPALayeredItem *)layer onSurface:(SPASurface *)surface;
-(SPALayeredItem *) getLayer:(int)index ofSurface:(SPASurface *)surface;

-(void)setupSurfacesWithCompletionHandler:(void(^)(NSError *err))handler;

@end
