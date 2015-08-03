//
//  SPALayeredItem.h
//  SPAToolkit
//
//  Created by Jokichi Oguri on 8/18/14.
//  Copyright (c) 2014 Snapfish Publisher Team. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SPAImage.h"

@interface SPALayeredContainer : NSObject <NSCoding, NSCopying>

@property (nonatomic, strong, setter=setX:) NSString *x;
@property (nonatomic, strong, setter=setY:) NSString *y;
@property (nonatomic, strong, setter=setW:) NSString *w;
@property (nonatomic, strong, setter=setH:) NSString *h;
@property (nonatomic, strong, setter=setRot:) NSString *rot;

@property (nonatomic, setter=setXVal:)   double xVal;
@property (nonatomic, setter=setYVal:)   double yVal;
@property (nonatomic, setter=setHVal:)   double hVal;
@property (nonatomic, setter=setWVal:)   double wVal;
@property (nonatomic, setter=setRotVal:) double rotVal;

@property (nonatomic, strong) NSString *valueFormat;


+ (instancetype)modelObjectWithDictionary:(NSDictionary *)dict;
- (instancetype)initWithDictionary:(NSDictionary *)dict;
- (NSDictionary *)dictionaryRepresentation;
+ (SPALayeredContainer *) containerFromX:(double)x y:(double)y w:(double)w h:(double)h rot:(double)rot;

@end


@interface SPALayeredItem : NSObject <SPAJsonSerializeProtocol>

@property (nonatomic, strong) SPALayeredContainer *container;
@property (nonatomic, strong) NSString *type;

 /**
  * userEditable: True if the user can edit this layer.. if it comes
  * from a Central Design template, they can't.
  * This may be unecessary if "type" takes care of this condition.
  **/
@property (nonatomic) BOOL *userEditable;

+(id)fromJson:(NSDictionary *)json withError:(NSError **)error;
-(NSDictionary *)toJson;
-(instancetype)initWithDictionary:(NSDictionary *)dict;

@end

/**
 * SPALayeredPhoto contains all of the parameters required to place a photo on a surface
 *
 **/
@interface SPALayeredPhoto : SPALayeredItem <SPAJsonSerializeProtocol>

@property (nonatomic, strong) SPAImage *image;

@property (nonatomic, strong) SPALayeredContainer *photoPosition;
@property (nonatomic, strong) NSString *userAssetId;
//@property (nonatomic, strong) SPASpecialHandling *specialHandling;

-(id) initWithImage:(SPAImage *)img AndContainer:(SPALayeredContainer *)container AndPhotoPosition:(SPALayeredContainer *)photoPosition;
-(id) initWithImage:(SPAImage *)img __attribute__((deprecated));

@end

/**
 * SPALayeredText contains all of the parameters required to place text on a surface
 **/
@interface SPALayeredText : SPALayeredItem <SPAJsonSerializeProtocol>

@property (nonatomic, strong) NSArray *linesOfText;
@property (nonatomic, strong) NSString *font;
@property (nonatomic) double pointSize;
@property (nonatomic, strong) NSString *color;
@property (nonatomic, strong) NSString *fillColor;
@property (nonatomic, strong) NSString *url;
@property (nonatomic) double alignmentAnchor;

-(id) initWithContainer:(SPALayeredContainer *)container AndLinesOfText:(NSArray *)linesOfText;
-(id) initWithText:(NSString *)text __attribute__((deprecated));

@end
