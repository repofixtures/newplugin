//
//  ListSchema.h
//  ios-sdk
//
//  Intel Cloud Services iOS SDK - 7/26/13.
//  Copyright (c) 2013 Intel ; Licensed MIT
//

#import <Foundation/Foundation.h>

@class Schema;
@class SchemaStructure;
@class PropertySchema;

@interface ListSchema : NSObject

@property (nonatomic,strong) NSString *kind;
@property (nonatomic,readonly) NSMutableArray *schemas;
@property (nonatomic,assign) int itemsPerPage;
@property (nonatomic,assign) int currentItemCount;
@property (nonatomic,assign) int totalItems;
@property (nonatomic,strong) NSString *nextLink;
@property (nonatomic,strong) NSString *previousLink;
@property (nonatomic,assign) int startIndex;
@property (nonatomic,strong) NSString *pagingLinkTemplate;

-(id)initFromDictionary:(NSDictionary *)data;

-(ListSchema*)addSchema:(Schema*)schema;

-(NSDictionary*)parseToDictionary;

-(NSData*)serialize;

@end

@interface Schema : NSObject

@property(nonatomic,strong) NSString *_id;
@property(nonatomic,strong) NSString *name;
@property(nonatomic,strong) NSString *serverModifiedTime;
@property(nonatomic,strong) NSString *owner;
@property(nonatomic,strong) NSString *link;
@property(nonatomic,strong) NSString *visibility;
@property(nonatomic,strong) SchemaStructure *schema;
@property(nonatomic,strong) NSArray *usedBy;
@property(nonatomic,strong) NSString *version;
@property(nonatomic,strong) NSString *schemaOrgVersion;
@property(nonatomic,assign) BOOL active;

+ (Schema*)createSchemaFromSchemaStructure:(SchemaStructure*)schemaStructure;

- (id)initFromDictionary:(NSDictionary*)data;

-(NSDictionary*)parseToDictionary;

@end

@interface SchemaStructure : NSObject

@property(nonatomic,strong) NSMutableArray *properties;

+ (SchemaStructure *)createSchemaStructure;

- (SchemaStructure *)addProperty:(PropertySchema *)property;

- (id)initFromDictionary:(NSDictionary *)data;

- (NSDictionary *)parseToDictionary;

- (NSData*)serialize;

@end

@interface PropertySchema : NSObject

@property(nonatomic,strong) NSString *property;
@property(nonatomic,assign) BOOL required;
@property(nonatomic,strong) NSString *type;

+ (PropertySchema *)createPropertySchemaWithName:(NSString*)property required:(BOOL)required type:(NSString*)type;

- (id)initFromDictionary:(NSDictionary *)dictionary;

- (NSDictionary*)parseToDictionary;

@end