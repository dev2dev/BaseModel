//
//  BaseModel.h
//
//  Version 1.0
//
//  Created by Nick Lockwood on 25/06/2011.
//  Copyright 2011 Charcoal Design. All rights reserved.
//
//  Get the latest version of BaseModel from either of these locations:
//
//  http://charcoaldesign.co.uk/source/cocoa#basemodel
//  https://github.com/demosthenese/BaseModel
//
//  This software is provided 'as-is', without any express or implied
//  warranty.  In no event will the authors be held liable for any damages
//  arising from the use of this software.
//
//  Permission is granted to anyone to use this software for any purpose,
//  including commercial applications, and to alter it and redistribute it
//  freely, subject to the following restrictions:
//
//  1. The origin of this software must not be misrepresented; you must not
//  claim that you wrote the original software. If you use this software
//  in a product, an acknowledgment in the product documentation would be
//  appreciated but is not required.
//
//  2. Altered source versions must be plainly marked as such, and must not be
//  misrepresented as being the original software.
//
//  3. This notice may not be removed or altered from any source distribution.
//

#import <Foundation/Foundation.h>


//use the BaseModel class as the base class for any of your
//model objects. BaseModels can be standalone object, or
//act as sub-properties of a larger object

@interface BaseModel : NSObject <NSCoding>

//default constructors (all other constructors should call these)
+ (id)instance;
- (id)init;

//loading from a dictionary or array, e.g. from a plist or json
+ (id)instanceWithDict:(NSDictionary *)dict;
+ (id)instanceWithArray:(NSArray *)array;
- (id)initWithDict:(NSDictionary *)dict;
- (id)initWithArray:(NSArray *)array;

@end


//use the document extensions for any top-level model
//objects that map directly to one or more files on disk, e.g.
//a word processor document, or a cachable entity such
//as a downloaded html page or json response.

@interface BaseModel(Documents)

//file management utility functions
+ (NSString *)applicationDocumentsFolder;
- (BOOL)fileExistsAtPath:(NSString *)filePath;
- (void)removeFileAtPath:(NSString *)filePath;
- (void)writeObject:(id)object toFile:(NSString *)filePath;
- (id)objectWithContentsofFile:(NSString *)filePath;

//loading and saving the model from a plist file
+ (id)instanceWithContentsOfFile:(NSString *)filePath;
- (id)initWithContentsOfFile:(NSString *)filePath;
- (void)writeToFile:(NSString *)filePath;

@end


//use the singleton extensions for root models that have
//only a single instance in the application. the singleton
//category provides handy methods to load and save the file
//without needing to specify the filename each time

@interface BaseModel(Singletons)

//configuration
+ (NSString *)resourceFile;
+ (NSString *)documentFile;

//singleton behaviour
+ (id)sharedInstance;
+ (void)reload;
+ (void)save;

@end