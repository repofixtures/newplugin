//
//  CurationService.h
//  ios-sdk
//
//  Intel Cloud Services iOS SDK - 5/23/13.
//  Copyright (c) 2013 Intel ; Licensed MIT
//

#import "ListCuration.h"
#import "ListItemsCatalog.h"
#import "QueryItem.h"
#import "Common.h"
#import "Services.h"


@class Services;

FOUNDATION_EXPORT NSString *const CALL_LIST_CURATION_ERROR_DOMAIN;
FOUNDATION_EXPORT NSString *const CALL_ITEM_CURATION_ERROR_DOMAIN;

typedef void (^ListCurationCallback)(ListCuration*);

typedef void (^CollectionListCurationCallback)(CollectionList*);

typedef void (^ItemCurationCallback)(ItemCuration*);

typedef void (^NSArrayCallback)(NSArray*);

/**
 *Resolves all calls to Couration Services.
 */
@interface CurationService : Services{
    
}

/**
 Pushes a new item to the current list.
 @param listId The unique identifier of the list
 @param itemCatalog Object representing an item from Catalog.
 @param comment The comment for this item
 @throw AuthInitException Thrown if the Auth class is not correctly initialized or if the login method was not executed.
 @return Item curation uploaded.
 *<br/><b>Sample code</b><br/>
 *@snippet CurationSample uploadItem
 */
- (void)uploadItem:(ItemCurationCallback)callback errorCallback:(ErrorCallback)errorCallback listId:(NSString*)listId itemCatalog:(ItemCatalog*)itemCatalog comment:(NSString*)comment;

/**
 Gets items from the specified list.
 @param listId The unique identifier of the list
 @param query Object containing the query options.
 @throw AuthInitException Thrown if the Auth class is not correctly initialized or if the login method was not executed.
 @return ListCuration List of curation items
 @return The items curation's list. If items were not found, returns nil.
 *<br/><b>Sample code</b><br/>
 *@snippet CurationSample getItemsQuery
 */
- (void)getItems:(ListCurationCallback)callback errorCallback:(ErrorCallback)errorCallback listId:(NSString*)listId query:(QueryItem*)query;

/**
 Gets items from the specified list.
 @param listId The unique identifier of the list
 @throw AuthInitException Thrown if the Auth class is not correctly initialized or if the login method was not executed.
 @return ListCuration List of curation items
 @return The items curation's list. If items were not found, returns nil.
 *<br/><b>Sample code</b><br/>
 *@snippet CurationSample getItems
 */
- (void)getItems:(ListCurationCallback)callback errorCallback:(ErrorCallback)errorCallback listId:(NSString*)listId;

/**
 Retrieves the listing next page of items from a specified list
 @param metadata Metadata object instance (nextLink attribute cannot be nil)
 @throw PaginationException If the nextLink attribute from metadata is nil.
 @throw AuthInitException Thrown if the Auth class is not correctly initialized or if the login method was not executed.
 @return The items curation's list. If items were not found, returns nil.
 */
-(void)getNextItemsList:(ListCurationCallback)callback errorCallback:(ErrorCallback)errorCallback metadata:(Metadata*)metadata;

/**
 Retrieves the listing next page of items from a specified list
 @param metadata Metadata object instance (previousLink attribute cannot be nil)
 @throw PaginationException If the previousLink attribute from metadata is nil.
 @throw AuthInitException Thrown if the Auth class is not correctly initialized or if the login method was not executed.
 @return The items curation's list. If items were not found, returns nil.
 */
-(void)getPreviousItemsList:(ListCurationCallback)callback errorCallback:(ErrorCallback)errorCallback metadata:(Metadata*)metadata;

/**
 Gets public items of a particular List
 @param userId The unique identifier for the user as represented by the metadata. Hashed as an alphanumerical string of characters
 @param listId The unique identifier of the list
 @throw AuthInitException Thrown if the Auth class is not correctly initialized or if the login method was not executed.
 @return The list of public items founded. If public items were not found in this list, returns nil.
 *<br/><b>Sample code</b><br/>
 *@snippet CurationSample getPublicItems
 */
- (void)getPublicItems:(ListCurationCallback)callback errorCallback:(ErrorCallback)errorCallback userId:(NSString*)userId listId:(NSString*)listId;

/**
 Deletes an item from the list.
 @param listId The unique identifier of the list
 @param itemId The item ID
 @throw AuthInitException Thrown if the Auth class is not correctly initialized or if the login method was not executed.
 @return TRUE If the item was deleted successfully.
 @return FALSE If an error occurs deleting item.
 *<br/><b>Sample code</b><br/>
 *@snippet CurationSample deleteItem
 */
- (void)deleteItem:(OkCallback)callback errorCallback:(ErrorCallback)errorCallback listId:(NSString*)listId itemId:(NSString*)itemId;

/**
 Creates a curated list to manage Catalog items, associated with a user.
 @param listCuration List to be created. This list may have setted the name, fields and access to a list (isPublic attribute)
 @throw AuthInitException Thrown if the Auth class is not correctly initialized or if the login method was not executed.
 @return ListCuration Created curation list
 @return If the list was not be created, returns nil.
 *<br/><b>Sample code</b><br/>
 *@snippet CurationSample createList
 */
- (void)createList:(ListCurationCallback)callback errorCallback:(ErrorCallback)errorCallback listCuration:(ListCuration*)listCuration;

/**
 Gets the last version of all lists available for a user.
 @throw AuthInitException Thrown if the Auth class is not correctly initialized or if the login method was not executed.
 @return CollectionList List of collections
 @return nil if occurs an error
 *<br/><b>Sample code</b><br/>
 *@snippet CurationSample getLists
 */
- (void)getLists:(CollectionListCurationCallback)callback errorCallback:(ErrorCallback)errorCallback;

/**
 Retrieves the listing next page of available lists
 @param metadata Metadata object instance (nextLink attribute cannot be nil)
 @throw PaginationException If the nextLink attribute from metadata is nil.
 @throw AuthInitException Thrown if the Auth class is not correctly initialized or if the login method was not executed.
 */
-(void)getNextLists:(CollectionListCurationCallback)callback errorCallback:(ErrorCallback)errorCallback metadata:(Metadata*)metadata;

/**
 Retrieves the listing next page of available lists
 @param metadata Metadata object instance (previousLink attribute cannot be nil)
 @throw PaginationException If the previousLink attribute from metadata is nil.
 @throw AuthInitException Thrown if the Auth class is not correctly initialized or if the login method was not executed.
 */
-(void)getPreviousLists:(CollectionListCurationCallback)callback errorCallback:(ErrorCallback)errorCallback metadata:(Metadata*)metadata;

/**
 Gets a list by ID.
 @param listId The unique identifier of the list
 @throw AuthInitException Thrown if the Auth class is not correctly initialized or if the login method was not executed.
 @return ListCuration List of items
 @return nil if list not founded at given id
 *<br/><b>Sample code</b><br/>
 *@snippet CurationSample getListById
 */
- (void)getListById:(ListCurationCallback)callback errorCallback:(ErrorCallback)errorCallback listId:(NSString*)listId;

/**
 Gets a list of available versions.
 @param listId The unique identifier of the list
 @throw AuthInitException Thrown if the Auth class is not correctly initialized or if the login method was not executed.
 @return NSArray An array containing the version numbers
 @return nil if there were no available versions
 *<br/><b>Sample code</b><br/>
 *@snippet CurationSample getVersions
 */
- (void)getVersions:(NSArrayCallback)callback errorCallback:(ErrorCallback)errorCallback listId:(NSString*)listId;

/**
 Gets medatada of a list for a particular version.
 @param listId The unique identifier of the list
 @param version Number of version to get
 @throw AuthInitException Thrown if the Auth class is not correctly initialized or if the login method was not executed.
 @return ListCuration List of curation items including metadata
 @return nil if specified version of list not exists.
 *<br/><b>Sample code</b><br/>
 *@snippet CurationSample getMetadata
 */
- (void)getMetadata:(ListCurationCallback)callback errorCallback:(ErrorCallback)errorCallback listId:(NSString*)listId version:(NSNumber*)version;

/**
 Gets the list items for a particular version.
 @param listId The unique identifier of the list
 @param version Number of version to get
 @throw AuthInitException Thrown if the Auth class is not correctly initialized or if the login method was not executed.
 @return ListCuration List of curation items
 @return nil if specified version of list not exists.
 *<br/><b>Sample code</b><br/>
 *@snippet CurationSample getItemsByVersion
 */
- (void)getItemsByVersion:(ListCurationCallback)callback errorCallback:(ErrorCallback)errorCallback listId:(NSString*)listId version:(NSNumber*)version;

/**
 Deletes the specified list.
 @param listId The unique identifier of the list
 @throw AuthInitException Thrown if the Auth class is not correctly initialized or if the login method was not executed.
 @return true (or yes) if the all versions of the specified list was deleted successfully, otherwise returns false (or no).
 *<br/><b>Sample code</b><br/>
 *@snippet CurationSample deleteList
 */
- (void)deleteList:(OkCallback)callback errorCallback:(ErrorCallback)errorCallback listId:(NSString*)listId;

/**
 Pushes new fields to the current list.
 @param listId The unique identifier of the list
 @param fields Dictionary containing any metadata to be included to the list.
 @throw AuthInitException Thrown if the Auth class is not correctly initialized or if the login method was not executed.
 @return true (or yes) if the fields was added to the list successfully, otherwise returns false (or no).
 *<br/><b>Sample code</b><br/>
 *@snippet CurationSample addFields
 */
- (void)addFields:(OkCallback)callback errorCallback:(ErrorCallback)errorCallback listId:(NSString*)listId fields:(NSDictionary*)fields;

/**
 Renames the list.
 @param listId The unique identifier of the list
 @param newName The new name for the list.
 @throw AuthInitException Thrown if the Auth class is not correctly initialized or if the login method was not executed.
 @return true (or yes) if the name was changed successfully, otherwise returns false (or no).
 *<br/><b>Sample code</b><br/>
 *@snippet CurationSample renameList
 */
- (void)renameList:(OkCallback)callback errorCallback:(ErrorCallback)errorCallback listId:(NSString*)listId newName:(NSString*)newName;

/**
 Changes the order of list items.
 @param sortedList Array containing curation items in order.
 @param listId The unique identifier of the list
 @throw AuthInitException Thrown if the Auth class is not correctly initialized or if the login method was not executed.
 @return true (or yes) if the items was ordered successfully, otherwise returns false (or no).
 */
- (void)reorderItems:(OkCallback)callback errorCallback:(ErrorCallback)errorCallback listId:(NSString*)listId sortedList:(NSArray*)sortedList;

@end