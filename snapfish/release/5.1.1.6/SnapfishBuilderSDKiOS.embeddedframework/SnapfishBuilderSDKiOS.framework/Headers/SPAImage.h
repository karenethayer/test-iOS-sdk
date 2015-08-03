//
//  SPAImage.h
//  SPAToolkit
//
//  Created by Jokichi Oguri on 6/10/14.
//  Copyright (c) 2014 Snapfish Publisher Team. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "SPAJsonSerializeProtocol.h"

/**
 @brief Wrapper for image data
 
 This object allows you to specify an image in one of 3 ways:
 
 @li Raw Image Data in the form of an NSData object
 @li UIImage object
 @li URL to an image in the form of an NSURL object
 
 The object will then return the image data for the photo through
 the imageData property.
 */
@interface SPAImage : NSObject <SPAJsonSerializeProtocol>

/**
 @brief Sets the image by specifying a Image object.
 
 Initializes the image with a image URL (can be device URL or http URL)
 */
-(id)initWithURL:(NSURL *)url;

/**
 @brief Sets the image by specifying raw image data.
 
 Initializes the image with the binary image data from a file or URL.
 */
-(id)initWithImageData:(NSData *)imgData;

/**
 * @brief Creates and returns a SPAImage object from URL
 */
+(id)imageFromURL:(NSURL *)url;

/**
 * @brief Creates and returns a SPAImage object from image data
 */
+(id)imageFromData:(NSData *)data;

/**
 * @brief Creates and returns a SPAImage object from a UIImage object
 */
+(id)imageFromUIImage:(UIImage *)obj;

/**
 @brief Sets the image by specifiying a UIImage object.
 
 Initializes the image with a UIImage object.
 */
-(id)initWithUIImage:(UIImage *)imgObj;

/**
 @brief Sets the image by specifying a URL that points to the image file.
 
 Initializes the image with a Snapfish Photo ID.
 ID must be in form of albumID;imageID
 */
-(id)initWithSnapfishId:(NSString *)snapfishId;

/**
 * @brief Creates and returns a SPAImage object from snapfish image ids
 */
+(id)imageFromSnapfishId:(NSString *)snapfishId;

/**
 * @brief Returns true if the SPAImage object contains URL information.
 **/
-(BOOL) hasURL;

/**
 * @brief Returns true if the SPAImage object contains device URL information.
 **/
-(BOOL) hasAssetURL;
/**
 * @brief Returns true if the SPAImage object contains raw image data.
 **/
-(BOOL) hasImageData;

/**
 * @brief Returns true if the SPAImage object contains a UIImage object.
 **/
-(BOOL) hasUIImage;

/**
 * @brief Returns true if the SPAImage object contains an image validation error.
 **/
-(BOOL) hasImageValidationError;

/**
 * Returns true if the SPAImage object contains a Snapfish ID
 **/
-(BOOL) hasSnapfishId;

/**
 @brief Will return or set the raw image data for the photo.
 
 @return If the object was not initialized with the image data, it will check
 if it was set with the UIImage object. If so, it will extract the data
 from the image object. If not, it will then check if the image was
 initialized with a NSURL object. If so it will attempt to read the
 photo file from the URL, and return the data if successful.
 */
@property (getter=getImageData, nonatomic, retain) NSData *imageData;

/**
 @brief Will return or set the NSURL object that references the photo file.
 */
@property (nonatomic, strong) NSURL *url;

/**
 @brief Will return or set the UIImage object for the photo.
 */
@property (getter=getUIImage, nonatomic, strong) UIImage *uiImage;

@property (nonatomic ,strong) NSError *imageValidationError;

/**
 @brief Will return or set the Snapfish ID for a photo.
 */
@property (nonatomic, strong) NSString *snapfishId;

@end
