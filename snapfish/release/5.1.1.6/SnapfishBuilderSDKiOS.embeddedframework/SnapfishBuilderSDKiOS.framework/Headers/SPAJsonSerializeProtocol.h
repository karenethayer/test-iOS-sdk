//
//  SPASerialize.h
//  SPAToolKit
//
//  Created by Karen Thayer on 6/2/14.
//  Copyright (c) 2014 Snapfish Publisher Team. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol SPAJsonSerializeProtocol <NSObject>

+(id)fromJson:(NSDictionary *)json withError:(NSError **)error;

@optional
-(NSDictionary *)toJson;
-(instancetype)initWithDictionary:(NSDictionary *)dict;

@end
