//
//  QueryItem.h
//  ios-sdk
//
//  Intel Cloud Services iOS SDK - 5/24/13.
//  Copyright (c) 2013 Intel ; Licensed MIT
//

#import <Foundation/Foundation.h>


//Comparison operators
FOUNDATION_EXPORT NSString *const COMPARISON_ALL;
FOUNDATION_EXPORT NSString *const COMPARISON_GREATER_THAN;
FOUNDATION_EXPORT NSString *const COMPARISON_GREATER_THAN_EQUAL;
FOUNDATION_EXPORT NSString *const COMPARISON_LESS_THAN;
FOUNDATION_EXPORT NSString *const COMPARISON_LESS_THAN_EQUAL;
FOUNDATION_EXPORT NSString *const COMPARISON_IN;
FOUNDATION_EXPORT NSString *const COMPARISON_NOT_IN;
FOUNDATION_EXPORT NSString *const COMPARISON_EQUAL;
FOUNDATION_EXPORT NSString *const COMPARISON_NOT_EQUAL;

//Logical operators
FOUNDATION_EXPORT NSString *const LOGICAL_AND;
FOUNDATION_EXPORT NSString *const LOGICAL_NOR;
FOUNDATION_EXPORT NSString *const LOGICAL_NOT;
FOUNDATION_EXPORT NSString *const LOGICAL_OR;

//Elements operators
FOUNDATION_EXPORT NSString *const ELEMENT_EXISTS;
FOUNDATION_EXPORT NSString *const ELEMENT_MOD;

//Array operators
FOUNDATION_EXPORT NSString *const ARRAY_ELEMENT_MATCH;
FOUNDATION_EXPORT NSString *const ARRAY_SIZE;

//Geospatial operators
FOUNDATION_EXPORT NSString *const GEOSPATIAL_OPERATOR_WITHIN_BOX;
FOUNDATION_EXPORT NSString *const GEOSPATIAL_OPERATOR_WITHIN;
FOUNDATION_EXPORT NSString *const GEOSPATIAL_OPERATOR_WITHIN_POLYGON;
FOUNDATION_EXPORT NSString *const GEOSPATIAL_OPERATOR_WITHIN_CENTER_SPHERE;
FOUNDATION_EXPORT NSString *const GEOSPATIAL_OPERATOR_WITHIN_CENTER;
FOUNDATION_EXPORT NSString *const GEOSPATIAL_LIMIT_MAX_DISTANCE;
FOUNDATION_EXPORT NSString *const GEOSPATIAL_OPERATOR_NEAR_SPHERE;
FOUNDATION_EXPORT NSString *const GEOSPATIAL_OPERATOR_NEAR;
FOUNDATION_EXPORT NSString *const GEOSPATIAL_UNIQUE_DOCS;
FOUNDATION_EXPORT NSString *const GEOSPATIAL_SHAPE_TYPE_POINT;
FOUNDATION_EXPORT NSString *const GEOSPATIAL_SHAPE_TYPE_POLYGON;

//Javascript operators
FOUNDATION_EXPORT NSString *const JAVASCRIPT_REGEX;

//Order by types
FOUNDATION_EXPORT NSString *const ORDER_BY_ASC;
FOUNDATION_EXPORT NSString *const ORDER_BY_DESC;

@class FilterQuery;
@class Condition;
@class ExpressionIn;
@class Expression;
@class ANDCondition;
@class ORCondition;
@class GEONear;
@class GEONearSphere;
@class GEOWithIn;
@class GEOBox;
@class GEOCenter;
@class GEOCenterSphere;
@class GEOPolygon;
@class Coordinate2D;

@protocol ConditionSerializable <NSObject>

-(NSDictionary*)serialize;

@end

@interface QueryItem : NSObject

@property (nonatomic, strong) NSMutableArray *ids;
@property (nonatomic, strong) NSMutableArray *owners;
@property (nonatomic, strong) NSMutableArray *contextTypes;
@property (nonatomic, strong) NSMutableArray *providers;
@property (nonatomic, strong) NSString *clientCreatedTimeBefore;
@property (nonatomic, strong) NSString *clientCreatedTimeAfter;
@property (nonatomic, strong) NSString *serverCreatedTimeBefore;
@property (nonatomic, strong) NSString *serverCreatedTimeAfter;
@property (nonatomic, strong) NSString *serverModifiedTimeBefore;
@property (nonatomic, strong) NSString *serverModifiedTimeAfter;
@property (nonatomic, strong) FilterQuery *filter;
@property (nonatomic, strong) NSMutableArray *fields;
@property (nonatomic, strong) NSString *limit;
@property (nonatomic, strong) NSString *offset;
@property (nonatomic, strong) NSString *orderBy;

+(QueryItem*)createQueryItem;

-(id)init;

/**
 Adds an id to be fetched. You can add unlimited filters of this type.
 @param itemId The unique identifier from item for add to list.
 @return the same object with ID added
 */
-(QueryItem*)addId:(NSString*) itemId;

/**
 Adds an owner to be fetched. You can add unlimited filters of this type.
 @param owner The owner for add to list.
 @return the same object with owner added
 */
-(QueryItem*)addOwner:(NSString*) owner;

/**
 Adds a context type to be fetched. You can add unlimited filters of this type.
 @param contextType Type of context for add to list.
 @return the same object with contextType added
 */
-(QueryItem*)addContextType:(NSString*) contextType;

/**
 Adds a provider to be fetched. You can add unlimited filters of this type.
 @param provider Provider for add to list.
 @return the same object with provider added
 */
-(QueryItem*)addProvider:(NSString*) provider;

/**
 Adds a field to be fetched. You can add unlimited filters of this type.
 @param field The field to be obtained
 @return the same object with field added
 */
-(QueryItem*)addField:(NSString*) field;

/**
 Adds a filter to the query. Can be only one established filter.
 @param filterQuery FilterQuery instance with filters added.
 @return the same object with filter added
 */
-(QueryItem*)addFilter:(FilterQuery*) filterQuery;

/**
 Adds an ordering clause by fields. Can be only one established ordering clause.
 @param field The field to be order.
 @param orderType The type of order. This parameter can be ORDER_BY_ASC or ORDER_BY_DESC
 @return the same object with established ordering clause.
 */
-(QueryItem*)addOrderBy:(NSString *)field orderType:(NSString*)orderType;

/**
 Adds a limit to the number of records to obtain. Can be only one established limit.
 @param limit The limit number
 @return the same object with established limit.
 */
-(QueryItem*)addLimit:(int)limit;

/**
 Indicates the number of items returned to skip (from the first). Can be only one established offset.
 @param offset The number of items to skip
 @return the same object with established offset.
 */
-(QueryItem*)addOffSet:(int)offset;

/**
 Once structured query, it generates the corresponding query with their respective parameters.
 @return the parameters to be added to the original URL.
 */
-(NSString*)buildQueryUrl;

@end

@interface FilterQuery : NSObject

@property(nonatomic,assign) id<ConditionSerializable> condition;

/**
 Creates a new FilterQuery instance. This filter query contains a condition instance to be setted.
 @returns Created filter query instance
 */
+(FilterQuery*)createFilterQuery;

@end

@interface Condition : NSObject

@property(nonatomic, strong) NSMutableArray *expressions;
@property(nonatomic, strong) NSMutableArray *conditions;

-(id)init;

/**
 Adds a expression into condition.
 @param expression The expression to be added into condition.
 */
-(void)addExpression:(Expression*)expression;

/**
 Adds a condition into condition. We will use this method, for example, if you want to add an AND condition in an OR condition.
 @param condition The condition to be added into condition.
 */
-(void)addCondition:(id<ConditionSerializable>)condition;

-(NSArray*)serializeToArray;

@end

@interface Expression : Condition <ConditionSerializable>

@property(nonatomic,strong) NSString *field;
@property(nonatomic,strong) NSString *comparisionOperator;
@property(nonatomic,strong) NSObject *value;
@property(nonatomic,strong) NSNumber *exists;

/**
 Creates an expression considering the field, the comparison operator and value.
 @param field The field to be compared
 @param comparisonOperator The comparison operator. This parameter can be: COMPARISON_ALL, COMPARISON_GREATHER_THAN, COMPARISON_GREATER_THAN_EQUAL, COMPARISON_LESS_THAN, COMPARISON_LESS_THAN_EQUAL, COMPARISON_IN, COMPARISON_NOT_IN, COMPARISON_EQUAL or COMPARISON_NOT_EQUAL.
 @param value The value to be compared. The value must be casted to the corresponding data type.
 @return the created expression.
 */
+(Expression*)createExpressionWithField:(NSString*)field comparisonOperator:(NSString*)comparisonOperator value:(NSObject*)value;

/**
 Creates an expression considering the field, the comparison operator and string value. This method is the same of 'createExpression:(NSString*)field comparisonOperator:(NSString*)comparisonOperator value:(NSObject*)value' but only allows string values.
 @param field The field to be compared
 @param comparisonOperator The comparison operator. This parameter can be: COMPARISON_ALL, COMPARISON_GREATHER_THAN, COMPARISON_GREATER_THAN_EQUAL, COMPARISON_LESS_THAN, COMPARISON_LESS_THAN_EQUAL, COMPARISON_IN, COMPARISON_NOT_IN, COMPARISON_EQUAL or COMPARISON_NOT_EQUAL.
 @param The string value to be compared.
 @return the created expression.
 */
+(Expression*)createExpressionWithField:(NSString*)field comparisonOperator:(NSString*)comparisonOperator valueString:(NSString*)valueString;

/**
 Creates an expression considering the field, the comparison operator and array value. This method is the same of 'createExpression:(NSString*)field comparisonOperator:(NSString*)comparisonOperator value:(NSObject*)value' but only allows array value.
 @param field The field to be compared
 @param comparisonOperator The comparison operator. This parameter can be: COMPARISON_ALL, COMPARISON_IN or COMPARISON_NOT_IN.
 @param The string value to be compared.
 @return the created expression.
 */
+(Expression*)createExpressionWithField:(NSString*)field comparisonOperator:(NSString*)comparisonOperator valueArray:(NSArray*)valueArray;

/**
 Creates an expression considering the field, the comparison operator and array value. This method is the same of 'createExpression:(NSString*)field comparisonOperator:(NSString*)comparisonOperator value:(NSObject*)value' but only allows numeric value.
 @param field The field to be compared
 @param comparisonOperator The comparison operator. This parameter can be: COMPARISON_ALL, COMPARISON_GREATHER_THAN, COMPARISON_GREATER_THAN_EQUAL, COMPARISON_LESS_THAN, COMPARISON_LESS_THAN_EQUAL, COMPARISON_IN, COMPARISON_NOT_IN, COMPARISON_EQUAL or COMPARISON_NOT_EQUAL.
 @param The string value to be compared.
 @return the created expression.
 */
+(Expression*)createExpressionWithField:(NSString*)field comparisonOperator:(NSString*)comparisonOperator valueNumber:(NSNumber*)valueNumber;

/**
 Creates an expression considering the field, the comparison operator and object value. If the parameter exists is true, the final query will return records that contain the field. Otherwise, the final query return records not having that field.
 @param field The field to be compared.
 @param comparisonOperator The comparison operator. This parameter can be: COMPARISON_ALL, COMPARISON_GREATHER_THAN, COMPARISON_GREATER_THAN_EQUAL, COMPARISON_LESS_THAN, COMPARISON_LESS_THAN_EQUAL, COMPARISON_IN, COMPARISON_NOT_IN, COMPARISON_EQUAL or COMPARISON_NOT_EQUAL.
 @param value The value to be compared. This parameter can be an array, numeric, string, and other data types.
 @param exists Determinates if the returned records must contain the field.
 @return the created exists expression.
 */
+(Expression*)createExistsExpressionWithField:(NSString*)field comparisonOperator:(NSString*)comparisonOperator value:(NSObject*)value exists:(BOOL)exists;

/**
 Creates an expression considering the field, the divisor and the remainder. The final query will return records where the field value divided by the divisor parameter has the specified remeainder.
 @param field The field to be compared.
 @param divisor Divisor
 @param remainder Remainder
 @return the created mod expression.
 */
+(Expression*)createModExpressionWithField:(NSString*)field divisor:(double)divisor remainder:(double)remainder;

/**
 Creates an array size expression. The final query return records where matches any array with the number of elements specified by the parameter.
 @param field This field can be only array data type.
 @param size Number of elements to be contain the field
 @return the created array size expression.
 */
+(Expression*)createArraySizeExpressionWithField:(NSString*)field size:(int)size;

/**
 Creates a regex expression. The final query return records where matches coincidences with pattern specified by the parameter.
 @param field The field to be compared.
 @param regex Regular expression. It must be PERL regular expression.
 @param options The options flag. It can be: 'i' (toggles case sensitive), 'm' (toggles multiline regular expression) and 'x' (toggle
 @return the created regex expression.
 */
+(Expression*)createRegexExpressionWithField:(NSString*)field regex:(NSString*)regex options:(NSString*)options;

-(NSDictionary*)serialize;

@end

@interface ANDCondition : Condition <ConditionSerializable>

-(NSDictionary*)serialize;

@end

@interface ORCondition : Condition <ConditionSerializable>

-(NSDictionary*)serialize;

@end

@interface NORCondition : Condition <ConditionSerializable>

-(NSDictionary*)serialize;

@end

@interface GEOSpatial : Expression

@property(nonatomic,strong) NSString *field;
@property(nonatomic,strong) NSString *operatorGeo;
@property(nonatomic,strong) NSString *type;

-(id)initWithField:(NSString*)field operatorGeo:(NSString*)operatorGeo shapeType:(NSString*)shapeType;

-(NSDictionary*)serialize:(NSDictionary*)geometry;

@end

@interface GEONear : GEOSpatial

@property(nonatomic,strong) Coordinate2D *coordinatesPoint;
@property(nonatomic,assign) double maxDistance;

/**
 Creates a new near expression. The final query returns records where given location field within a maximum distance of a point.
 @param coordinatesPoint Point defined by coordinate pairs (latitude and longitude).
 @param maxDistance The maximum distance of a point (in meters)
 @return the created GEONear expression.
 */
+(GEONear*)createGEONearWithField:(NSString*)field coordinatesPoint:(Coordinate2D*)coordinatesPoint maxDistance:(double)maxDistance;

/**
 Creates a new near expression. The final query returns records where given location field is proximity to a point.
 @param coordinatesPoint Point defined by coordinate pairs (latitude and longitude).
 @return the created GEONear expression.
 */
+(GEONear*)createGEONearWithField:(NSString*)field coordinatesPoint:(Coordinate2D*)coordinatesPoint;

-(NSDictionary*)serialize;

@end

@interface GEONearSphere : GEOSpatial

@property(nonatomic,strong) Coordinate2D *coordinatesPoint;
@property(nonatomic,assign) double maxDistance;

/**
 Creates a new near sphere expression. The final query returns records where given location field is proximity to a point on a sphere.
 @param coordinatesPoint Point defined by coordinate pairs (latitude and longitude).
 @return the created GEONearSphere expression.
 */
+(GEONearSphere*)createGEONearSphereWithField:(NSString*)field coordinatesPoint:(Coordinate2D*)coordinatesPoint;

/**
 Creates a new near sphere expression. The final query returns records where given location field that is proximity to a point on a sphere within a maximum distance of a point.
 @param coordinatesPoint Point defined by coordinate pairs (latitude and longitude).
 @param maxDistance The maximum distance of a point (in meters)
 @return the created GEONearSphere expression.
 */
+(GEONearSphere*)createGEONearSphereWithField:(NSString*)field coordinatesPoint:(Coordinate2D*)coordinatesPoint maxDistance:(double)maxDistance;

-(NSDictionary*)serialize;

@end

@interface GEOWithIn : GEOSpatial

@property(nonatomic,strong) NSArray *coordinatesList;

/**
 Creates a new within (based on polygon with only an exterior ring) expression. The final query returns points where given location field within the bounds of the polygon.
 @param coordinates NSArray must contain Coordinate2D instances.
 @return the created GEOWithIn expression.
 */
+(GEOWithIn*)createGEOWithInWithField:(NSString*)field coordinates:(NSArray*)coordinates;

-(NSDictionary*)serialize;

@end

@interface GEOBox : GEOSpatial

@property(nonatomic,strong) Coordinate2D *bottomLeftCoordinates;
@property(nonatomic,strong) Coordinate2D *upperRightCoordinates;

/**
 Creates a new box (based on rectangle) expression. The final query returns records where given location field within the bounds of the rectangle.
 @param bottomLeftCoordinates Coordinates from the bottom-left rectangle point.
 @param upperRightCoordinates Coordinates from the upper-right rectangle point.
 @return the created GEOBox expression.
 */
+(GEOBox*)createGEOBoxWithField:(NSString*)field bottomLeftCoordinates:(Coordinate2D*)bottomLeftCoordinates upperRightCoordinates:(Coordinate2D*)upperRightCoordinates;

-(NSDictionary*)serialize;

@end

@interface GEOPolygon : GEOSpatial

@property(nonatomic,strong) NSArray *coordinatesList;

/**
 Creates a new within (based on polygon with an exterior and interior ring) expression. The final query returns points where given location field within the bounds of the polygon.
 @param coordinates NSArray must contain Coordinate2D instances.
 @return the created GEOWithIn expression.
 */
+(GEOPolygon*)createGEOPolygonWithField:(NSString*)field coordinates:(NSArray*)coordinates;

-(NSDictionary*)serialize;

@end

@interface GEOCenter : GEOSpatial

@property(nonatomic,strong) Coordinate2D *coordinate;
@property(nonatomic,assign) double radio;

/**
 Creates a new circle (based on center point and radio of circle) expression. The final query returns points where given location field within the circle.
 @param coordinate Point defined by coordinate pairs (latitude and longitude).
 @param radio The radio for the circle
 @return the created GEOCenter expression.
 */
+(GEOCenter*)createGEOCenterWithField:(NSString*)field coordinate:(Coordinate2D*)coordinate radio:(double)radio;

-(NSDictionary*)serialize;

@end

@interface GEOCenterSphere : GEOSpatial

@property(nonatomic,strong) Coordinate2D *coordinate;
@property(nonatomic,assign) double radio;

/**
 Creates a new circle (based on center point and radio of circle) on a sphere expression. The final query returns points where given location field within the circle.
 @param coordinate Point defined by coordinate pairs (latitude and longitude).
 @param radio The radio for the circle
 @return the created GEOCenterSphere expression.
 */
+(GEOCenterSphere*)createGEOCenterSphereWithField:(NSString*)field coordinate:(Coordinate2D*)coordinate radio:(double)radio;

-(NSDictionary*)serialize;

@end

@interface Coordinate2D : NSObject

@property(nonatomic,assign) double latitude;
@property(nonatomic,assign) double longitude;

/**
 Create a new coordinate pair.
 @param latitude The latitude for the coordinate pair
 @param longitude The longitude for the coordinate pair
 @return Coordinate2D instance with latitude & longitude setted.
 */
+(Coordinate2D*)createCoordinate2DWithLatitude:(double)latitude longitude:(double)longitude;

-(NSArray*)coordinateToArray;

@end