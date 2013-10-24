//
//  CatalogService.h
//  ios-sdk
//
//  Intel Cloud Services iOS SDK - 5/23/13.
//  Copyright (c) 2013 Intel ; Licensed MIT
//

#import "Services.h"

@class Services;
@class ListDataset;
@class Schema;
@class SchemaStructure;
@class Dataset;
@class ListCollection;
@class Collection;
@class ListItemsCatalog;
@class ListSchema;
@class ItemCatalog;
@class QueryItem;
@class PointOfInterest;
@class Coordinate2D;
@class Results;

FOUNDATION_EXPORT NSString *const CALL_DATASET_CATALOG_ERROR_DOMAIN;
FOUNDATION_EXPORT NSString *const CALL_COLLECTION_CATALOG_ERROR_DOMAIN;
FOUNDATION_EXPORT NSString *const CALL_ITEM_CATALOG_ERROR_DOMAIN;

FOUNDATION_EXPORT NSString *const VISIBILITY_PRIVATE;
FOUNDATION_EXPORT NSString *const VISIBILITY_PUBLIC;

typedef void (^ListSchemaCallback)(ListSchema*);

typedef void (^ListDatasetCallback)(ListDataset*);

typedef void (^ListCollectionCallback)(ListCollection*);

typedef void (^ListItemsCatalogCallback)(ListItemsCatalog*);

typedef void (^SchemaCallback)(Schema*);

typedef void (^DatasetCallback)(Dataset*);

typedef void (^CollectionCallback)(Collection*);

typedef void (^ItemCatalogCallback)(ItemCatalog*);

typedef void (^InformationCatalogCallback)(NSDictionary*);

typedef void (^PointOfInterestCallback)(PointOfInterest*);

typedef void (^POICollectionCallback)(NSArray*);

typedef void (^ResultsCallback)(Results*);

/**
 *Resolves all calls to Catalog Services.
 */
@interface CatalogService : Services{
    
}

/**
 Creates a new schema in the developer's schemas collection. If there is a schema with the same name, then that schema is updated. If the visibility option is omitted, then "private" is the default value.
 @param schema A valid schema to be created. Defines visibility as private or public. Default is 'private'
 @param name Name of the schema (without spaces).
 @return Created schema successfully.
 *<br/><b>Sample code</b><br/>
 *@snippet CatalogSample createPrivateSchema
 */
- (void)createPrivateSchema:(SchemaCallback)callback errorCallback:(ErrorCallback)errorCallback schema:(SchemaStructure*)schema name:(NSString*)name;

/**
 Retrieves private schemas.
 @return List of private schemas.
 *<br/><b>Sample code</b><br/>
 *@snippet CatalogSample getSchemas
 */
- (void)getSchemas:(ListSchemaCallback)callback errorCallback:(ErrorCallback)errorCallback;

/**
 Retrieves the active schema for a given schema name. In case there are available versions for that schema, but they are all inactive then it returns resource not found.
 @return The schema with the specified name
 *<br/><b>Sample code</b><br/>
 *@snippet CatalogSample viewPrivateSchema
 */
- (void)viewPrivateSchema:(SchemaCallback)callback errorCallback:(ErrorCallback)errorCallback name:(NSString*)name;

/**
 Updates a schema. If the schema name does not exist, a new schema is created. If the schema name exists and the UsedBy attribute is empty (or the associated collections do not have items) the schema is updated. If the schema has the same schemaName, but the schema is used for non-empty collections, the service will create a new version of the schema.
 @param nameSchema name of the schema to be updated (or created).
 @param schemaUpdated New or updated schema.
 @param visibility Defines schema attribute as private or public.
 @return The updated/created schema.
 *<br/><b>Sample code</b><br/>
 *@snippet CatalogSample updatePrivateSchema
 */
- (void)updatePrivateSchema:(SchemaCallback)callback errorCallback:(ErrorCallback)errorCallback nameSchema:(NSString*)nameSchema schemaUpdated:(SchemaStructure*)schemaUpdated visibility:(NSString *)visibility;

/**
 Update a schema and if the schema_name does not exist a new schema is created. If the schema_name exists and the UsedBy attribute is nil (or the associated collections do not have items) the schema is updated. If the schema has the same schema_name, but the schema is used for non-empty collections, the service will create a new version of the schema
 @param nameSchema The name of schema to update
 @param schemaUpdated The schema updated
 @return The schema updated/created.
 */
- (void)updatePrivateSchema:(SchemaCallback)callback errorCallback:(ErrorCallback)errorCallback nameSchema:(NSString*)nameSchema schemaUpdated:(SchemaStructure*)schemaUpdated;

/**
 Deletes the schema based on the schema name.
 @param nameSchema Name of the schema (without spaces) to be removed.
 @return true (or yes) if the schema was deleted successfully, otherwise returns false (or no).
 *<br/><b>Sample code</b><br/>
 *@snippet CatalogSample removePrivateSchemaByName
 */
- (void)removePrivateSchemaByName:(OkCallback)callback errorCallback:(ErrorCallback)errorCallback nameSchema:(NSString*)nameSchema;

/**
 Delete a schema if the schema field 'UsedBy' is nil. In other case it sets 'active' field to false.
 @param schema The schema to delete.
 @return true (or yes) if the schema was deleted successfully, otherwise returns false (or no).
 */
- (void)removePrivateSchema:(OkCallback)callback errorCallback:(ErrorCallback)errorCallback schema:(Schema*)schema;

/**
 Retrieves all versions of a private schema for a given schema name.
 @param name The name of schema
 @return The list of schemas with each version of it.
 *<br/><b>Sample code</b><br/>
 *@snippet CatalogSample getPrivateSchemaVersions
 */
- (void)getPrivateSchemaVersions:(ListSchemaCallback)callback errorCallback:(ErrorCallback)errorCallback name:(NSString*)name;

/**
 Retrieves a specific version of a private schema for a given schema name.
 @param name The name of schema
 @param version The version of schema to get
 @return The schema in the specified version
 *<br/><b>Sample code</b><br/>
 *@snippet CatalogSample viewPrivateSchemaVersion
 */
- (void)viewPrivateSchemaVersion:(SchemaCallback)callback errorCallback:(ErrorCallback)errorCallback name:(NSString*)name version:(NSNumber*)version;

/**
 Retrieves all versions of a private schema for a given schema name.
 @param provider The allowed providers are: PROVIDER_AUTH_FACEBOOK, PROVIDER_AUTH_GOOGLE, PROVIDER_AUTH_INTEL and PROVIDER_AUTH_YAHOO.
 @return The list of public schemas for the specified provider
 *<br/><b>Sample code</b><br/>
 *@snippet CatalogSample getPublicSchemaList
 */
- (void)getPublicSchemaList:(ListSchemaCallback)callback errorCallback:(ErrorCallback)errorCallback provider:(NSString*)provider;

/**
 Retrieves a public schema.
 @param provider The allowed providers are: PROVIDER_AUTH_FACEBOOK, PROVIDER_AUTH_GOOGLE, PROVIDER_AUTH_INTEL and PROVIDER_AUTH_YAHOO.
 @param schemaName The name of public schema to get
 @return The public schema with the specified name.
 *<br/><b>Sample code</b><br/>
 *@snippet CatalogSample viewPublicSchema
 */
- (void)viewPublicSchema:(SchemaCallback)callback errorCallback:(ErrorCallback)errorCallback provider:(NSString *)provider schemaName:(NSString*)schemaName;

/**
 Retrieves all versions of a public schema for a given schema name.
 @param name The name of public schema to get versions
 @return The list of public schema's with the specified name.
 *<br/><b>Sample code</b><br/>
 *@snippet CatalogSample getPublicSchemaVersions
 */
- (void)getPublicSchemaVersions:(ListSchemaCallback)callback errorCallback:(ErrorCallback)errorCallback name:(NSString*)name;

/**
 Retrieves a specific version of a public schema for a given schema name.
 @param name The name of public schema to get
 @param version The version of the schema to get
 @return The public schema with the specified name and version.
 *<br/><b>Sample code</b><br/>
 *@snippet CatalogSample viewPublicSchemaVersion
 */
- (void)viewPublicSchemaVersion:(SchemaCallback)callback errorCallback:(ErrorCallback)errorCallback name:(NSString *)name version:(int)version;

/**
 Creates a new dataset with the options passed as parameters.
 @param datasetName Name of the dataset to be created.
 @throw AuthInitException Thrown if the Auth class is not correctly initialized or if the login method was not executed.
 @return Created dataset
 *<br/><b>Sample code</b><br/>
 *@snippet CatalogSample createDataset
 */
- (void)createDataset:(DatasetCallback)callback errorCallback:(ErrorCallback)errorCallback datasetName:(NSString*)datasetName;

/**
 Gets a single dataset based on the datasetId passed as parameter. Dataset is returned as a single object (not an array).
 @param datasetId The ID of the dataset to be retrieved.
 @throw AuthInitException Thrown if the Auth class is not correctly initialized or if the login method was not executed.
 @return The dataset with that id. If it was not found, returns nil.
 *<br/><b>Sample code</b><br/>
 *@snippet CatalogSample getDatasetById
 */
- (void)getDatasetById:(DatasetCallback)callback errorCallback:(ErrorCallback)errorCallback datasetId:(NSString*)datasetId;

/**
 Retrieves a list of datasets. Datasets are returned in a list.
 @throw AuthInitException Thrown if the Auth class is not correctly initialized or if the login method was not executed.
 @return List of datasets. If datasets were not found, returns nil.
 *<br/><b>Sample code</b><br/>
 *@snippet CatalogSample getDatasets
 */
- (void)getDatasets:(ListDatasetCallback)callback errorCallback:(ErrorCallback)errorCallback;

/**
 Retrieves the listing next page of datasets
 @param listDataset List of datasets objects instance (The nextLink attribute from this list cannot be nil)
 @throw PaginationException If the nextLink attribute from metadata is nil.
 @throw AuthInitException Thrown if the Auth class is not correctly initialized or if the login method was not executed.
 */
-(void)getNextDatasets:(ListDatasetCallback)callback errorCallback:(ErrorCallback)errorCallback listDataset:(ListDataset*)listDataset;

/**
 Retrieves the listing next page of datasets
 @param listDataset List of datasets objects instance (The previousLink attribute from this list cannot be nil)
 @throw PaginationException If the previousLink attribute from metadata is nil.
 @throw AuthInitException Thrown if the Auth class is not correctly initialized or if the login method was not executed.
 */
-(void)getPreviousDatasets:(ListDatasetCallback)callback errorCallback:(ErrorCallback)errorCallback listDataset:(ListDataset*)listDataset;

/**
 Removes a dataset.
 @param datasetId ID from dataset to delete
 @throw AuthInitException Thrown if the Auth class is not correctly initialized or if the login method was not executed.
 @return true (or yes) if the dataset was deleted successfully, otherwise returns false (or no).
 *<br/><b>Sample code</b><br/>
 *@snippet CatalogSample removeDataset
 */
- (void)removeDatasetById:(OkCallback)callback errorCallback:(ErrorCallback)errorCallback datasetId:(NSString*)datasetId;

/**
 Removes a dataset.
 @param dataset Dataset object instance
 @throw AuthInitException Thrown if the Auth class is not correctly initialized or if the login method was not executed.
 @return true (or yes) if the dataset was deleted successfully, otherwise returns false (or no).
 */
- (void)removeDatasetById:(OkCallback)callback errorCallback:(ErrorCallback)errorCallback dataset:(Dataset*)dataset;

/**
 Creates a new collection inside a given dataset.
 @param datasetId The dataset ID where the collection will be created.
 @param collectionName The collection name.
 @throw AuthInitException Thrown if the Auth class is not correctly initialized or if the login method was not executed.
 @return Created collection
 *<br/><b>Sample code</b><br/>
 *@snippet CatalogSample createCollection
 */
- (void)createCollection:(CollectionCallback)callback errorCallback:(ErrorCallback)errorCallback datasetId:(NSString *)datasetId collectionName:(NSString*)collectionName;

/**
 Gets the collection specified by the collection ID. It returns the collection as a single object.
 @param datasetId The dataset ID of the desired collection.
 @param collectionId The collection ID of the desired collection.
 @throw AuthInitException Thrown if the Auth class is not correctly initialized or if the login method was not executed.
 @return Single collection with the specified ID. If it was not found, returns nil.
 *<br/><b>Sample code</b><br/>
 *@snippet CatalogSample getCollectionById
 */
- (void)getCollectionById:(CollectionCallback)callback errorCallback:(ErrorCallback)errorCallback datasetId:(NSString*)datasetId collectionId:(NSString*)collectionId;

/**
 Gets all collections. This method returns a list of Collection objects.
 @param datasetId The dataset ID where the collection is located.
 @throw AuthInitException Thrown if the Auth class is not correctly initialized or if the login method was not executed.
 @return List of collections. If collections were not found, returns nil.
 *<br/><b>Sample code</b><br/>
 *@snippet CatalogSample getCollections
 */
- (void)getCollections:(ListCollectionCallback)callback errorCallback:(ErrorCallback)errorCallback datasetId:(NSString*)datasetId;

/**
 Returns all collections for the specified dataset.
 @param dataset Dataset object instance
 @throw AuthInitException Thrown if the Auth class is not correctly initialized or if the login method was not executed.
 @return List of collections. If not found, returns nil.
 */
- (void)getCollections:(ListCollectionCallback)callback errorCallback:(ErrorCallback)errorCallback dataset:(Dataset *)dataset;

/**
 Retrieves the listing next page of collections
 @param listCollection List of collections objects instance (The nextLink attribute from this list cannot be nil)
 @throw PaginationException If the nextLink attribute from metadata is nil.
 @throw AuthInitException Thrown if the Auth class is not correctly initialized or if the login method was not executed.
 */
-(void)getNextCollections:(ListCollectionCallback)callback errorCallback:(ErrorCallback)errorCallback listCollection:(ListCollection*)listCollection;

/**
 Retrieves the listing previous page of collections
 @param listCollection List of collections objects instance (The previousLink attribute from this list cannot be nil)
 @throw PaginationException If the previousLink attribute from metadata is nil.
 @throw AuthInitException Thrown if the Auth class is not correctly initialized or if the login method was not executed.
 */
-(void)getPreviousCollections:(ListCollectionCallback)callback errorCallback:(ErrorCallback)errorCallback listCollection:(ListCollection*)listCollection;

/**
 Removes a collection from the dataset specified by collection ID.
 @param datasetId The dataset ID of the collection to be deleted.
 @param collectionId The collection ID associated with the collection to be deleted.
 @throw AuthInitException Thrown if the Auth class is not correctly initialized or if the login method was not executed.
 @return true (or yes) if the collection was deleted successfully, otherwise returns false (or no).
 *<br/><b>Sample code</b><br/>
 *@snippet CatalogSample removeCollectionById
 */
- (void)removeCollectionById:(OkCallback)callback errorCallback:(ErrorCallback)errorCallback datasetId:(NSString*)datasetId collectionId:(NSString*)collectionId;

/**
 Removes a collection from the dataset specified by collection ID.
 @param collection Collection object instance to delete
 @throw AuthInitException Thrown if the Auth class is not correctly initialized or if the login method was not executed.
 @return true (or yes) if the collection was deleted successfully, otherwise returns false (or no).
 */
- (void)removeCollectionById:(OkCallback)callback errorCallback:(ErrorCallback)errorCallback collection:(Collection*)collection;

/**
 Update properties in a Catalog Services collection.
 @param originalCollection The collection to modify
 @param modifiedCollection The collection modified
 @throw AuthInitException Thrown if the Auth class is not correctly initialized or if the login method was not executed.
 @return true (or yes) if the collection was updated successfully, otherwise returns false (or no).
 *<br/><b>Sample code</b><br/>
 *@snippet CatalogSample updateCollection
 */
- (void)updateCollection:(CollectionCallback)callback errorCallback:(ErrorCallback)errorCallback originalCollection:(Collection*)originalCollection modifiedCollection:(Collection*)modifiedCollection;

/**
 Uploads an item inside a dataset-collection.
 @param item (Optional) Item to be created.
 @param datasetId The unique identifier of the dataset.
 @param collectionId The unique identifier of the collection.
 @throw AuthInitException Thrown if the Auth class is not correctly initialized or if the login method was not executed.
 @return The created item. if an error occurred while the item was being uploaded, returns nil.
 *<br/><b>Sample code</b><br/>
 *@snippet CatalogSample uploadItem
 */
- (void)uploadItem:(ResultsCallback)callback errorCallback:(ErrorCallback)errorCallback datasetId:(NSString*)datasetId collectionId:(NSString*)collectionId item:(ItemCatalog*)item;

/**
 Uploads an item inside a dataset-collection.
 @param collection Collection object instance
 @param item Item catalog object instance to be uploaded
 @throw AuthInitException Thrown if the Auth class is not correctly initialized or if the login method was not executed.
 @return The created item. If an error occurred while the item was being created, returns nil.
 */
- (void)uploadItem:(ResultsCallback)callback errorCallback:(ErrorCallback)errorCallback collection:(Collection *)collection item:(ItemCatalog*)item;

/**
 Uploads multiple items inside a dataset-collection.
 @param datasetId The unique identifier for the dataset.
 @param collectionId The unique identifier for the collection.
 @param items List of items to create
 @throw AuthInitException Thrown if the Auth class is not correctly initialized or if the login method was not executed.
 @return created item. If occurs an error creating item, return nil.
 *<br/><b>Sample code</b><br/>
 *@snippet CatalogSample uploadItems
 */
- (void)uploadItems:(ResultsCallback)callback errorCallback:(ErrorCallback)errorCallback datasetId:(NSString*)datasetId collectionId:(NSString*)collectionId items:(ListItemsCatalog*)items;

/**
 Returns a single item as an object (not a list).
 @param datasetId The dataset ID  of the desired collection.
 @param collectionId The collection ID.
 @param itemId The item ID of the single item to be retrieved.
 @throw AuthInitException Thrown if the Auth class is not correctly initialized or if the login method was not executed.
 @return item in ItemCatalog object. If it was not found, returns nil.
 *<br/><b>Sample code</b><br/>
 *@snippet CatalogSample getItemById
 */
- (void)getItemById:(ItemCatalogCallback)callback errorCallback:(ErrorCallback)errorCallback datasetId:(NSString*)datasetId collectionId:(NSString*)collectionId itemId:(NSString*)itemId;

/**
 Returns a single item as an object.
 @param itemCatalog Item Catalog object instance to get
 @throw AuthInitException Thrown if the Auth class is not correctly initialized or if the login method was not executed.
 @return item in ItemCatalog instance. If it was not found, returns nil.
 */
- (void)getItemById:(ItemCatalogCallback)callback errorCallback:(ErrorCallback)errorCallback itemCatalog:(ItemCatalog *)itemCatalog;

/**
 Returns a list of navigable items.
 @param datasetId The unique identifier of the dataset.
 @param collectionId The unique identifier of the dataset.
 @throw AuthInitException Thrown if the Auth class is not correctly initialized or if the login method was not executed.
 @return List of items. If the items were not found, returns nil.
 *<br/><b>Sample code</b><br/>
 *@snippet CatalogSample getItems
 */
- (void)getItems:(ListItemsCatalogCallback)callback errorCallback:(ErrorCallback)errorCallback datasetId:(NSString*)datasetId collectionId:(NSString*)collectionId;

/**
 List all items for the specified dataset and collection id
 @param collection Collection object instance
 @throw AuthInitException Thrown if the Auth class is not correctly initialized or if the login method was not executed.
 @return list of items. If was not found items, returns nil.
 */
- (void)getItems:(ListItemsCatalogCallback)callback errorCallback:(ErrorCallback)errorCallback collection:(Collection *)collection;

/**
 Retrieves the listing next page of catalog items
 @param listItemsCatalog List of items objects instance (The nextLink attribute from this list cannot be nil)
 @throw PaginationException If the nextLink attribute from metadata is nil.
 @throw AuthInitException Thrown if the Auth class is not correctly initialized or if the login method was not executed.
 */
-(void)getNextItems:(ListItemsCatalogCallback)callback errorCallback:(ErrorCallback)errorCallback listItemsCatalog:(ListItemsCatalog *)listItemsCatalog;

/**
 Retrieves the listing previous page of catalog items
 @param listItemsCatalog List of items objects instance (The nextLink attribute from this list cannot be nil)
 @throw PaginationException If the previousLink attribute from metadata is nil.
 @throw AuthInitException Thrown if the Auth class is not correctly initialized or if the login method was not executed.
 */
-(void)getPreviousItems:(ListItemsCatalogCallback)callback errorCallback:(ErrorCallback)errorCallback listItemsCatalog:(ListItemsCatalog *)listItemsCatalog;

/**
 Updates properties of single item.
 @param datasetId The unique identifier for the dataset.
 @param collectionId The unique identifier for the collection.
 @param itemId The unique identifier for the original item.
 @param itemWithChanges Updated item.
 @throw AuthInitException Thrown if the Auth class is not correctly initialized or if the login method was not executed.
 @return true (or yes) if the item was updated successfully, otherwise returns false (or no).
 *<br/><b>Sample code</b><br/>
 *@snippet CatalogSample updateItem
 */
- (void)updateItem:(ItemCatalogCallback)callback errorCallback:(ErrorCallback)errorCallback datasetId:(NSString *)datasetId collectionId:(NSString *)collectionId itemId:(NSString*)itemId itemWithChanges:(ItemCatalog *)itemWithChanges;

/**
 Updates properties of single item.
 @param itemForUpdate The original item to update.
 @param itemWithChanges Updated item.
 @throw AuthInitException Thrown if the Auth class is not correctly initialized or if the login method was not executed.
 @return true (or yes) if the item was updated successfully, otherwise returns false (or no).
 */
- (void)updateItem:(ItemCatalogCallback)callback errorCallback:(ErrorCallback)errorCallback itemForUpdate:(ItemCatalog *)itemForUpdate itemWithChanges:(ItemCatalog *)itemWithChanges;

/**
 Updates properties of multiple items in a single call. For each item its ID should be provided in the request:
    • If the ID is not provided for an item an error is shown.
    • If the ID provided exists on the DB the item shall be updated.
    • If the ID provided does not exist  then the item shall be created using the ID.
 @param listItems The list of items to be updated
 @throw ParameterException If the list is empty
 @return Results instance with the results of the query.
 */

- (void)updateItems:(ResultsCallback)callback errorCallback:(ErrorCallback)errorCallback dataset:(Dataset*)dataset collection:(Collection*)collection listItems:(ListItemsCatalog*)listItems;

/**
 Removes a single item by ID.
 @param datasetId The unique identifier of the dataset.
 @param collectionId The unique identifier of the collection.
 @param itemId The item ID of the item to be deleted.
 @throw AuthInitException Thrown if the Auth class is not correctly initialized or if the login method was not executed.
 @return true (or yes) if the item was deleted successfully, otherwise returns false (or no).
 *<br/><b>Sample code</b><br/>
 *@snippet CatalogSample removeItemById
 */
- (void)removeItemById:(OkCallback)callback errorCallback:(ErrorCallback)errorCallback datasetId:(NSString*)datasetId collectionId:(NSString*)collectionId itemId:(NSString*)itemId;

/**
 Removes a single item by object instance.
 @param itemCatalog The item catalog object instance to be deleted
 @throw AuthInitException Thrown if the Auth class is not correctly initialized or if the login method was not executed.
 @return true (or yes) if the item was deleted successfully, otherwise returns false (or no).
 */
- (void)removeItemById:(OkCallback)callback errorCallback:(ErrorCallback)errorCallback itemCatalog:(ItemCatalog *)itemCatalog;

/**
 Removes a single item or multiple items from a dataset-collection.
 @param items A list of items to be deleted. Each item must have the "itemId" attribute set.
 @throw AuthInitException Thrown if the Auth class is not correctly initialized or if the login method was not executed.
 @throw ParameterException If any item has not id attribute.
 @return Results instance with the results of the query.
 */
- (void)removeItems:(ResultsCallback)callback errorCallback:(ErrorCallback)errorCallback dataset:(Dataset*)dataset collection:(Collection*)collection items:(ListItemsCatalog*)items;

/**
 Returns an array of navigable items. Queries are filtered passing a query.filter object in the query. If the query object is empty, all items are retrieved.
 @param datasetId The unique identifier for the dataset.
 @param collectionId The unique identifier for the collection.
 @param query Object containing the query options.
 @throw AuthInitException Thrown if the Auth class is not correctly initialized or if the login method was not executed.
 @return List of items. If items were not found, returns nil.
 *<br/><b>Sample code</b><br/>
 *@snippet CatalogSample getItems
 */
- (void)getItems:(ListItemsCatalogCallback)callback errorCallback:(ErrorCallback)errorCallback datasetId:(NSString*)datasetId collectionId:(NSString*)collectionId query:(QueryItem*)query;

/**
 Returns an array of navigable items. Queries are filtered passing a query object in the query. If the query object is empty, all items are retrieved.
 @param collection Collection object instance
 @param query Object containing the query options.
 @throw AuthInitException Thrown if the Auth class is not correctly initialized or if the login method was not executed.
 @return List of items. If items were not found, returns nil.
 */
- (void)getItems:(ListItemsCatalogCallback)callback errorCallback:(ErrorCallback)errorCallback collection:(Collection*)collection query:(QueryItem*)query;

/**
 Return a list of nearby points of interest for the given location.
 @param coordinates The coordinates containing the latitude and longitude of the location.
 @param radius The radius defines the distance (in meters) within which to return poi results. Minimum allowed radius is 1 meter, if a value lesser that this is used, then 1 meter will be used instead. Maximum allowed radius is 100000 meters (100 Km), if a value greater that this is used, then 100 Km will be used instead. If no value is provided, service will choose a default based on query. (Optional parameter. Default: 1)
 @param timeHint Date and time hint in ISO8601 format (e.g. 2012-05-11T22:43:35Z) to be used to do the search. If none is provided, no date and time information is used (Optional parameter)
 @param categories The array containing the categories to get. The categories can be: CATEGORY_GAS_STATIONS, CATEGORY_HOTELS and CATEGORY_RESTAURANTS (located on PointOfInterest class) (Optional parameter)
 @param name The name of point of interest. (Optional parameter)
 @throw AuthInitException Thrown if the Auth class is not correctly initialized or if the login method was not executed.
 @throw ParameterException If the radius is less than 1 or greater than 10000. If the latitude or longitude is out of range. If the categories aren't valid.
 @return NSArray containing the points of interest. If not found points of interest, returns nil.
 *<br/><b>Sample code</b><br/>
 *@snippet CatalogSample getPointsOfInterest
 */
- (void)getPointsOfInterest:(POICollectionCallback)callback errorCallback:(ErrorCallback)errorCallback coordinates:(Coordinate2D*)coordinates radius:(int)radius timeHint:(NSDate*)timeHint categories:(NSArray*)categories name:(NSString *)name;

/**
 Return a point of interest with the given id.
 @param poi_id The unique identifier for the point of interest.
 @return The point of interest founded. If not found point of interest, returns nil.
 *<br/><b>Sample code</b><br/>
 *@snippet CatalogSample getPointOfInterest
 */
- (void)getPointOfInterestById:(PointOfInterestCallback)callback errorCallback:(ErrorCallback)errorCallback poi_id:(NSString*)poi_id;

@end