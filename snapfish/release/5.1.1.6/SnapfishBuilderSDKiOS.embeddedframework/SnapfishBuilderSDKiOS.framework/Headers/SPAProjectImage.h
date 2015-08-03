//
//  SPAProjectImage.h
//  SPAToolkit
//
//  Created by Jokichi Oguri on 6/10/14.
//  Copyright (c) 2014 Snapfish Publisher Team. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SPAImage.h"
#import "SPAJsonSerializeProtocol.h"

/**
 *  Information on an image in a Server Project.
 *  This object contains all of the information required to map an image 
 *  specified in the SPAImage object to a surface in the server project.
 */
@interface SPAProjectImage : NSObject <SPAJsonSerializeProtocol>

/**
 *  A reference to the image data
 */
@property (nonatomic, strong) SPAImage *image;

/**
 *  Path to the project attribute to change
 */
@property (nonatomic, strong) NSString *projectPath;

/**
 *  Substitution tag used in the project string
 */
@property (nonatomic, strong) NSString *tag;

@property (nonatomic, strong) NSString *type;

/**
 *  The value to substitute in place of the tag
 */
@property (nonatomic, strong) NSString *subString;

/**
 * For future use, if we need to set a non-string project attribute
 */
@property (nonatomic, strong) id value;

@end
