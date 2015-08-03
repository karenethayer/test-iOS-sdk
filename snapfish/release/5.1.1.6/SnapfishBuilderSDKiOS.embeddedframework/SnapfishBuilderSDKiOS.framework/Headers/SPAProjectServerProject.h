//
//  SPAProjectServerProject.h
//  SPAToolkit
//
//  Created by Jokichi Oguri on 6/10/14.
//  Copyright (c) 2014 Snapfish Publisher Team. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SPAProjectBase.h"
#import "SPAImage.h"

static NSString *const SPA_HIGHRES_URL_TYPE = @"highres";
static NSString *const SPA_USER_ASSET_ID_TYPE = @"assetId";
static NSString *const SPA_SIZE_TYPE = @"bytes";
static NSString *const SPA_MD5_SUM_TYPE = @"md5sum";

/**
 *  Represents a project created on the Snapfish server
 */
@interface SPAProjectServerProject : SPAProjectBase

// ForLater: rename this as projectId
// ForLater: init with projectId, throw excpetion for init
-(id)initWithServerId:(NSString *)serverProjectId;

/**
 *  Will add an image and mapping information to the image map list
 *
 *  Adding the same image add a new mapping to the list (mappingArray), but will not re-add the image to the list
 *  of images (imageArray).
 *
 *  @param img  the SPAImage to add mapping information
 *  @param path the project path (JSON node path) to update
 *  @param tag  the substitution tag used in the project
 *  @param type The type of substitution value to set (SPA_HIGHRES_URL_TYPE or SPA_USER_ASSET_ID_TYPE)
 */

//Later: prevent calls to this while in the checkout flow
-(void) addProjectImageMapping:(SPAImage *)img inPath:(NSString *)path withTag:(NSString *)tag ofType:(NSString *)type;

/**
 *  Will remove an image mapping from the image map list
 *
 *  This will remove all image maps for the given image (all path/tag/type combinations)
 *
 *  @param img img description
 */
//ForLater: prevent calls to this while in the checkout flow
-(void)removeProjectImageMapping:(SPAImage *)img;


//ForLater: prevent calls to this while in the checkout flow
-(void)removeAllProjectImagesMapping;

-(void)clearResponseForImage:(NSString *)imgKey;

@end
