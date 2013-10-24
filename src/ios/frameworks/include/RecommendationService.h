//
//  RecommendationService.h
//  ios-sdk
//
//  Intel Cloud Services iOS SDK - 5/23/13.
//  Copyright (c) 2013 Intel ; Licensed MIT
//

#import "Services.h"

@class QueryItem;
@class ListActionType;
@class AverageRate;
@class ContextUser;
@class ItemCatalog;
@class PurchaseList;
@class RateList;
@class ReviewList;
@class ListRecommendation;
@class Metadata;

typedef void (^EstimatedRatePreferenceCallback)(double);
typedef void (^ListActionTypesCallback)(ListActionType*);
typedef void (^AverageRateCallback)(AverageRate*);
typedef void (^PurchaseListCallback)(PurchaseList*);
typedef void (^RateListCallback)(RateList*);
typedef void (^ReviewListCallback)(ReviewList*);
typedef void (^InformationCallback)(NSDictionary*);
typedef void (^SimilarItems)(ListRecommendation*);

FOUNDATION_EXPORT NSString *const CALL_RECOMMENDATION_SERVICES_ERROR_DOMAIN;
FOUNDATION_EXPORT NSString *const CALL_FEEDBACK_SERVICES_ERROR_DOMAIN;

FOUNDATION_EXPORT NSString *const RELATIONSHIP_TYPE_SIMILARS;
FOUNDATION_EXPORT NSString *const RELATIONSHIP_TYPE_CROSS_SELL;
FOUNDATION_EXPORT NSString *const RELATIONSHIP_TYPE_UP_SALE;

/**
 *Resolves all calls to Recommendation Services.
 */
@interface RecommendationService : Services{
    
}

/** Recommendation services methods **/

/**
 Gets recommended items based on a seed item
 @param itemCatalog Object representing an item from Catalog.
 @throw AuthInitException Thrown if the Auth class is not correctly initialized or if the login method was not executed.
 */
-(void)getSimilarItems:(SimilarItems)callback errorCallback:(ErrorCallback)errorCallback itemCatalog:(ItemCatalog*)itemCatalog;

/**
 Recommended items will be those most similar to the seed item.
 @param itemCatalog Object representing an item from Catalog.
 @param query Object containing the query options.
 @throw AuthInitException Thrown if the Auth class is not correctly initialized or if the login method was not executed.
 */
-(void)getSimilarItems:(SimilarItems)callback errorCallback:(ErrorCallback)errorCallback itemCatalog:(ItemCatalog*)itemCatalog query:(QueryItem*)query;

/**
 Recommended items will be those most similar to the seed item.
 @param itemId The itemId of item catalog
 @throw AuthInitException Thrown if the Auth class is not correctly initialized or if the login method was not executed.
 */
-(void)getSimilarItems:(SimilarItems)callback errorCallback:(ErrorCallback)errorCallback itemId:(NSString*)itemId;

/**
 Recommended items will be those most similar to the seed item.
 @param itemId The unique identifier from catalog item.
 @param query Object containing the query options.
 @throw AuthInitException Thrown if the Auth class is not correctly initialized or if the login method was not executed.
 */
-(void)getSimilarItems:(SimilarItems)callback errorCallback:(ErrorCallback)errorCallback itemId:(NSString*)itemId query:(QueryItem*)query;

/**
 Retrieves the listing next page of similar items
 @param metadata Metadata object instance (nextLink attribute cannot be nil)
 @throw PaginationException If the nextLink attribute from metadata is nil.
 @throw AuthInitException Thrown if the Auth class is not correctly initialized or if the login method was not executed.
 */
-(void)getNextSimilarItems:(SimilarItems)callback errorCallback:(ErrorCallback)errorCallback metadata:(Metadata*)metadata;

/**
 Retrieves the listing previous page of similar items
 @param metadata Metadata object instance (previousLink attribute cannot be nil)
 @throw PaginationException If the previousLink attribute from metadata is nil.
 @throw AuthInitException Thrown if the Auth class is not correctly initialized or if the login method was not executed.
 */
-(void)getPreviousSimilarItems:(SimilarItems)callback errorCallback:(ErrorCallback)errorCallback metadata:(Metadata*)metadata;

/**
 Estimates the preference of a specified user for a specified item.
 @param itemCatalog Object representing an item from Catalog.
 @throw AuthInitException Thrown if the Auth class is not correctly initialized or if the login method was not executed.
 @return Number that represents the preference for that item
 */
-(void)getUserEstimation:(EstimatedRatePreferenceCallback)callback errorCallback:(ErrorCallback)errorCallback itemCatalog:(ItemCatalog*)itemCatalog;

/**
 Estimates the preference of a specified user for a specified item id.
 @param itemId The unique identifier from the item.
 @throw AuthInitException Thrown if the Auth class is not correctly initialized or if the login method was not executed.
 @return Number that represents the preference for that item
 */
-(void)getUserEstimation:(EstimatedRatePreferenceCallback)callback errorCallback:(ErrorCallback)errorCallback itemId:(NSString*)itemId;

/**
 Gets recommended items for the user associated with the token.
 */
-(void)getUserRecommendation:(InformationCallback)callback errorCallback:(ErrorCallback)errorCallback; //Change callback

/**
 Gets recommended items for the user associated with the token.
 @param contextUser Object containing the context properties
 @param query Object containing the query options.
 @throw AuthInitException Thrown if the Auth class is not correctly initialized or if the login method was not executed.
 */
-(void)getUserRecommendation:(InformationCallback)callback errorCallback:(ErrorCallback)errorCallback query:(QueryItem*)query contextUser:(ContextUser*)contextUser; //Change callback

/**
 Gets recommended items similar to another item that is aligned to the personal taste of a user.
 @param itemId The unique identifier of catalog item.
 */
-(void)getUserSimilarItems:(InformationCallback)callback errorCallback:(ErrorCallback)errorCallback itemId:(NSString*)itemId; //Change callback

/**
 Recommends items similar to another item that are aligned to the personal taste of a user.
 @param itemCatalog Object representing an item from Catalog.
 @throw AuthInitException Thrown if the Auth class is not correctly initialized or if the login method was not executed.
 */
-(void)getUserSimilarItems:(InformationCallback)callback errorCallback:(ErrorCallback)errorCallback itemCatalog:(ItemCatalog*)itemCatalog; //Change callback

/**
 Recommends items similar to another item that are aligned to the personal taste of a user.
 @param itemCatalog Object representing an item from Catalog.
 @param query Object containing the query options.
 @throw AuthInitException Thrown if the Auth class is not correctly initialized or if the login method was not executed.
 */
-(void)getUserSimilarItems:(InformationCallback)callback errorCallback:(ErrorCallback)errorCallback itemCatalog:(ItemCatalog*)itemCatalog query:(QueryItem*)query; //Change callback

/**
 Recommends items similar to another item that are aligned to the personal taste of a user. The query will filter the search.
 @param itemId The unique identifier from catalog item.
 @param query Object containing the query options.
 @throw AuthInitException Thrown if the Auth class is not correctly initialized or if the login method was not executed.
 */
-(void)getUserSimilarItems:(InformationCallback)callback errorCallback:(ErrorCallback)errorCallback itemId:(NSString*)itemId query:(QueryItem*)query; //Change callback

/** Feedback services methods **/

/**
 Registers a new custom action type.
 @param actionType The new generic action to be created.
 @throw ParameterException If the action type parameter is nil or empty.
 @throw AuthInitException Thrown if the Auth class is not correctly initialized or if the login method was not executed.
 @return TRUE If the action type has been created successfully.
 @return FALSE If an error occurs creating the action type.
 *<br/><b>Sample code</b><br/>
 *@snippet RecommendationSample createActionType
 */
-(void)createActionType:(OkCallback)callback errorCallback:(ErrorCallback)errorCallback actionType:(NSString*)actionType;

/**
 Retrieves the list of reviews the users have given as feedback. It also retrieves the default action types.
 @throw AuthInitException Thrown if the Auth class is not correctly initialized or if the login method was not executed.
 @return the list of existing action types.
 *<br/><b>Sample code</b><br/>
 *@snippet RecommendationSample getActionTypes
 */
-(void)getActionTypes:(ListActionTypesCallback)callback errorCallback:(ErrorCallback)errorCallback;

/**
 Deletes a custom action type.
 Note: The next generics action types cannot be deleted: PURCHASE, RATE, REVIEW, VISIT, ACCEPT_REC, REJECT_REC, IGNORE_ITEM, ADDTOCURATION.
 @param actionType The action type to be deleted.
 @throw ParameterException If the action type parameter is nil or empty.
 @throw AuthInitException Thrown if the Auth class is not correctly initialized or if the login method was not executed.
 @return TRUE If the action type was deleted successfully.
 @return FALSE If an error occurs deleting the action type.
 *<br/><b>Sample code</b><br/>
 *@snippet RecommendationSample deleteActionType
 */
-(void)deleteActionType:(OkCallback)callback errorCallback:(ErrorCallback)errorCallback actionType:(NSString*)actionType;

/**
 Adds an item to the blacklist so it will not be recommended. The blacklisted item does not impact recommendations to related items.
 Note: The blacklisted item does not impact on recommendations to related items.
 @param itemId The item ID
 @throw ParameterException If the item id parameter is nil or empty.
 @throw AuthInitException Thrown if the Auth class is not correctly initialized or if the login method was not executed.
 @return TRUE If the item was added to blacklist successfully.
 @return FALSE If an error occurs adding item to blacklist.
 *<br/><b>Sample code</b><br/>
 *@snippet RecommendationSample addItemToBlacklist
 */
-(void)addItemToBlacklist:(OkCallback)callback errorCallback:(ErrorCallback)errorCallback itemId:(NSString*)itemId;

/**
 Adds an item to the blacklist so it will not be recommended. The blacklisted item does not impact recommendations to related items.
 Note: The blacklisted item does not impact on recommendations to related items.
 @param itemCatalog Object representing an item from Catalog.
 @throw ParameterException If the item id parameter is nil or empty.
 @throw AuthInitException Thrown if the Auth class is not correctly initialized or if the login method was not executed.
 @return TRUE If the item was added to blacklist successfully.
 @return FALSE If an error occurs adding item to blacklist.
 */
-(void)addItemToBlacklist:(OkCallback)callback errorCallback:(ErrorCallback)errorCallback itemCatalog:(ItemCatalog*)itemCatalog;

/**
 Removes an item from the blacklist so it will be recommended again.
 @param itemId The unique identifier of the catalog item.
 @throw ParameterException If the item id parameter is nil or empty.
 @throw AuthInitException Thrown if the Auth class is not correctly initialized or if the login method was not executed.
 @return TRUE If the item was removed from blacklist successfully.
 @return FALSE If an error occurs removing item from blacklist.
 *<br/><b>Sample code</b><br/>
 *@snippet RecommendationSample removeItemFromBlacklist
 */
-(void)removeItemFromBlacklist:(OkCallback)callback errorCallback:(ErrorCallback)errorCallback itemId:(NSString*)itemId;

/**
 Removes an item from the blacklist so it will be recommended again.
 @param itemCatalog Object representing an item from Catalog.
 @throw ParameterException If the item id parameter is nil or empty.
 @throw AuthInitException Thrown if the Auth class is not correctly initialized or if the login method was not executed.
 @return TRUE If the item was removed from blacklist successfully.
 @return FALSE If an error occurs removing item from blacklist.
 */
-(void)removeItemFromBlacklist:(OkCallback)callback errorCallback:(ErrorCallback)errorCallback itemCatalog:(ItemCatalog*)itemCatalog;

/**
 Retrieves the average rate of an Item. The average is calculated based in all users received feedback for that specific item.
 @param itemId The item catalog ID.
 @throw ParameterException If the item id parameter is nil or empty.
 @throw AuthInitException Thrown if the Auth class is not correctly initialized or if the login method was not executed.
 @return AverageRate instance. It contains: average rate and total rates attributes.
 *<br/><b>Sample code</b><br/>
 *@snippet RecommendationSample getAverageRate
 */
-(void)getAverageRate:(AverageRateCallback)callback errorCallback:(ErrorCallback)errorCallback itemId:(NSString*)itemId;

/**
 Retrieves the average rate of an Item. The average is calculated based on the feedback received by all users for that specific item.
 @param itemCatalog Object representing an item from Catalog.
 @throw ParameterException If the item id parameter is nil or empty.
 @throw AuthInitException Thrown if the Auth class is not correctly initialized or if the login method was not executed.
 @return AverageRate instance. It contain: average rate and total rates attributes.
 */
-(void)getAverageRate:(AverageRateCallback)callback errorCallback:(ErrorCallback)errorCallback itemCatalog:(ItemCatalog*)itemCatalog;

/**
 Registers an explicit purchase or subscription of one user to a specific item.
 @param itemCatalog Object representing an item from Catalog.
 @throw ParameterException If the item catalog is nil.
 @throw AuthInitException Thrown if the Auth class is not correctly initialized or if the login method was not executed.
 @return TRUE If the item was registered as a purchase successfully.
 @return FALSE If an error occurs registering item as a purchase.
 *<br/><b>Sample code</b><br/>
 *@snippet RecommendationSample registerPurchase
 */
-(void)registerPurchase:(OkCallback)callback errorCallback:(ErrorCallback)errorCallback itemCatalog:(ItemCatalog*)itemCatalog;

/**
 Registers an explicit purchase or subscription of a user to a specific item.
 @param itemCatalog Object representing an item from Catalog.
 @param contextUser The context user to be updated.
 @throw ParameterException If the item catalog parameter is nil.
 @throw AuthInitException Thrown if the Auth class is not correctly initialized or if the login method was not executed.
 @return TRUE If the item was registered as a purchase successfully.
 @return FALSE If an error occurs registering item as a purchase.
 *<br/><b>Sample code</b><br/>
 *@snippet RecommendationSample registerPurchase
 */
-(void)registerPurchase:(OkCallback)callback errorCallback:(ErrorCallback)errorCallback itemCatalog:(ItemCatalog*)itemCatalog contextUser:(ContextUser*)contextUser;

/**
 Retrieves the list of purchase performed as feedback.
 @throw AuthInitException Thrown if the Auth class is not correctly initialized or if the login method was not executed.
 @return a list of registered purchases
 *<br/><b>Sample code</b><br/>
 *@snippet RecommendationSample getPurchaseHistory
 */
-(void)getPurchaseHistory:(PurchaseListCallback)callback errorCallback:(ErrorCallback)errorCallback;

/**
 Retrieves the listing next page of purchase items
 @param metadata Metadata object instance (nextLink attribute cannot be nil)
 @throw PaginationException If the nextLink attribute from metadata is nil.
 @throw AuthInitException Thrown if the Auth class is not correctly initialized or if the login method was not executed.
 */
-(void)getNextPurchaseItems:(PurchaseListCallback)callback errorCallback:(ErrorCallback)errorCallback metadata:(Metadata*)metadata;

/**
 Retrieves the listing previous page of purchase items
 @param metadata Metadata object instance (previousLink attribute cannot be nil)
 @throw PaginationException If the previousLink attribute from metadata is nil.
 @throw AuthInitException Thrown if the Auth class is not correctly initialized or if the login method was not executed.
 */
-(void)getPreviousPurchaseItems:(PurchaseListCallback)callback errorCallback:(ErrorCallback)errorCallback metadata:(Metadata*)metadata;

/**
 Registers an explicit preference of a UserID.
 @param itemCatalog Object representing an item from Catalog.
 @param rate A rate value between 1-5..
 @param contextUser (Optional) Context to be updated.
 @throw ParameterException If the itemCatalog is nil. If the rate parameter isn't between 1 and 5.
 @throw AuthInitException Thrown if the Auth class is not correctly initialized or if the login method was not executed.
 @return TRUE If the item was rated successfully.
 @return FALSE If an error occurs rating item.
 *<br/><b>Sample code</b><br/>
 *@snippet RecommendationSample rateItem
 */
-(void)rateItem:(OkCallback)callback errorCallback:(ErrorCallback)errorCallback itemCatalog:(ItemCatalog*)itemCatalog rate:(NSNumber*)rate contextUser:(ContextUser*)contextUser;

/**
 Retrieves the list of rate the user has given as feedback.
 @throw AuthInitException Thrown if the Auth class is not correctly initialized or if the login method was not executed.
 @return The list of all rates.
 *<br/><b>Sample code</b><br/>
 *@snippet RecommendationSample getRateHistory
 */
-(void)getRateHistory:(RateListCallback)callback errorCallback:(ErrorCallback)errorCallback;

/**
 Retrieves the next list of rate the user has given as feedback.
 @param metadata Metadata object instance (nextLink attribute cannot be nil)
 @throw PaginationException If the nextLink attribute from metadata is nil.
 @throw AuthInitException Thrown if the Auth class is not correctly initialized or if the login method was not executed.
 */
-(void)getNextRateItems:(RateListCallback)callback errorCallback:(ErrorCallback)errorCallback metadata:(Metadata*)metadata;

/**
 Retrieves the previous list of rate the user has given as feedback.
 @param metadata Metadata object instance (previousLink attribute cannot be nil)
 @throw PaginationException If the previousLink attribute from metadata is nil.
 @throw AuthInitException Thrown if the Auth class is not correctly initialized or if the login method was not executed.
 */
-(void)getPreviousRateItems:(RateListCallback)callback errorCallback:(ErrorCallback)errorCallback metadata:(Metadata*)metadata;

/**
 Registers a user's review on an item.
 @param itemCatalog Object representing an item from Catalog.
 @param review Review for this item.
 @param contextUser (Optional) The context user to be updated.
 @throw ParameterException If the item catalog is nil. If the review parameter is nil or empty.
 @throw AuthInitException Thrown if the Auth class is not correctly initialized or if the login method was not executed.
 @return TRUE If the item was reviewed successfully.
 @return FALSE If an error occurs reviewing item.
 *<br/><b>Sample code</b><br/>
 *@snippet RecommendationSample reviewItem
 */
-(void)reviewItem:(OkCallback)callback errorCallback:(ErrorCallback)errorCallback itemCatalog:(ItemCatalog*)itemCatalog review:(NSString*)review contextUser:(ContextUser*)contextUser;

/**
 Retrieves the list of reviews the users have given as feedback to a particular item.
 @param itemCatalog Object representing an item from Catalog.
 @throw ParameterException If the item id parameter is nil or empty.
 @throw AuthInitException Thrown if the Auth class is not correctly initialized or if the login method was not executed.
 @return The list of all reviews for this item.
 */
-(void)getReviewHistory:(ReviewListCallback)callback errorCallback:(ErrorCallback)errorCallback itemCatalog:(ItemCatalog*)itemCatalog;

/**
 Retrieves the list of reviews the users have given as feedback to a particular item.
 @param itemId The unique identifier for item catalog
 @throw ParameterException If the item id parameter is nil or empty.
 @throw AuthInitException Thrown if the Auth class is not correctly initialized or if the login method was not executed.
 @return The list of all reviews for this item.
 *<br/><b>Sample code</b><br/>
 *@snippet RecommendationSample getReviewHistory
 */
-(void)getReviewHistory:(ReviewListCallback)callback errorCallback:(ErrorCallback)errorCallback itemId:(NSString*)itemId;

/**
 Retrieves the next list of review the user has given as feedback.
 @param metadata Metadata object instance (nextLink attribute cannot be nil)
 @throw PaginationException If the nextLink attribute from metadata is nil.
 @throw AuthInitException Thrown if the Auth class is not correctly initialized or if the login method was not executed.
 */
-(void)getNextReviewsItem:(ReviewListCallback)callback errorCallback:(ErrorCallback)errorCallback metadata:(Metadata*)metadata;

/**
 Retrieves the previous list of review the user has given as feedback.
 @param metadata Metadata object instance (previousLink attribute cannot be nil)
 @throw PaginationException If the previousLink attribute from metadata is nil.
 @throw AuthInitException Thrown if the Auth class is not correctly initialized or if the login method was not executed.
 */
-(void)getPreviousReviewsItem:(ReviewListCallback)callback errorCallback:(ErrorCallback)errorCallback metadata:(Metadata*)metadata;

/**
 Registers a user's event specific to the tenant.
 @param action_type The action type name where register the feedback.
 @param itemCatalog Object representing an item from Catalog.
 @throw ParameterException If the action type parameter is nil or empty. If the item catalog is nil
 @throw AuthInitException Thrown if the Auth class is not correctly initialized or if the login method was not executed.
 @return TRUE If the item was registered as user event successfully.
 @return FALSE If an error occurs registering item as user event.
 *<br/><b>Sample code</b><br/>
 *@snippet RecommendationSample registerUserEvent
 */
-(void)registerUserEvent:(OkCallback)callback errorCallback:(ErrorCallback)errorCallback action_type:(NSString*)action_type itemCatalog:(ItemCatalog*)itemCatalog;

/**
 Registers a visit or implicit preference of a particular user to an item.
 @param itemCatalog Object representing an item from Catalog.
 @throw ParameterException If the item catalog is nil.
 @throw AuthInitException Thrown if the Auth class is not correctly initialized or if the login method was not executed.
 @return TRUE If the item was registered as visit successfully.
 @return FALSE If an error occurs registering item as visit.
 *<br/><b>Sample code</b><br/>
 *@snippet RecommendationSample registerVisit
 */
-(void)registerVisit:(OkCallback)callback errorCallback:(ErrorCallback)errorCallback itemCatalog:(ItemCatalog*)itemCatalog;

/**
 Updates user status (user mood, location, current activity, etc.).
 @param contextUser The ContextUser instance must contain the mood, current location and current activity from the user.
 @throw ParameterException If the contextUser is nil.
 @throw AuthInitException Thrown if the Auth class is not correctly initialized or if the login method was not executed.
 @return TRUE If the user's status was updated successfully.
 @return FALSE If an error occurs updating user's state.
 *<br/><b>Sample code</b><br/>
 *@snippet RecommendationSample updateUserStatus
 */
-(void)updateUserStatus:(OkCallback)callback errorCallback:(ErrorCallback)errorCallback contextUser:(ContextUser*)contextUser;

@end