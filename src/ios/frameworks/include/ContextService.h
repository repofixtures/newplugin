//
//  ContextService.h
//  ios-sdk
//
//  Intel Cloud Services iOS SDK - 5/23/13.
//  Copyright (c) 2013 Intel ; Licensed MIT
//

#import "Services.h"
#import "ListState.h"
#import "SensingStates.h"

@class User;
@class Services;
@class ResourcesType;
@class QueryItem;
@class Watch;
@class Watches;
@class Place;
@class ItemContext;
@class ListItems;
@class PointsOfInterestBehavior;
@class DestinationBehavior;
@class ListStates;


FOUNDATION_EXPORT NSString *const CALL_DATATYPES_CONTEXT_ERROR_DOMAIN;
FOUNDATION_EXPORT NSString *const CALL_ITEMS_CONTEXT_ERROR_DOMAIN;
FOUNDATION_EXPORT NSString *const CALL_WATCHES_CONTEXT_ERROR_DOMAIN;
FOUNDATION_EXPORT NSString *const CALL_BEHAVIOR_MODEL_CONTEXT_ERROR_DOMAIN;

typedef void (^ResourceTypeCallback)(ResourcesType*);

typedef void (^ListItemsCallback)(ListItems*);

typedef void (^ItemContextCallback)(ItemContext*);

typedef void (^QueryItemCallback)(QueryItem*);

typedef void (^WatchesCallback)(Watches*);

typedef void (^WatchCallback)(Watch*);

typedef void (^PredictActivityCallback)(NSString*);

typedef void (^PlaceCallback)(Place*);

typedef void (^POICallback)(NSArray*);

typedef void (^DestinationCallback)(NSArray*);

typedef void (^ResourcesTypeCallback)(NSDictionary*);

typedef void (^ListStatesCallback)(ListStates*);
/**
 *Resolves all calls to Context Services.
 */
@interface ContextService : Services{
    
}

/**
 Gets the name of the class from the specific context.
 @param context The name of the context used to get the class name.
 @return Class’s object name.
 */
+ (Class)findClassByContext:(NSString*)context;

/**
 Gets the name of the class from the specific context state.
 @param type The state's type.
 @return Class’s object name.
 */
+ (Class)findStateClassByType:(NSString*)type;

/**
 Obtains the supported types, including schemas, descriptions, and documentation.
 @throw AuthInitException Thrown if the Auth class is not correctly initialized or if the login method was not executed.
 @return ResourcesType instance that contains all resources. 
 *<br/><b>Sample code</b><br/>
 *@snippet ContextSample getSupportedTypes
 */
- (void)getSupportedTypes:(ResourcesTypeCallback)callback errorCallback:(ErrorCallback)errorCallback;

/**
 Uploads data to the Context Services by posting a set of ContextItem structures to the items collection. On successful upload, the response is the completely specified object for each of the newly stored items, including a unique ID, server time stamps, and more. On successful upload, the response is the completely specified object for each of the newly stored items, including a unique ID, server time stamps, and more.
 @param List The list of context items to be uploaded to the server.
 @throw ParameterException Thrown if the list of items is null or empty.
 @throw AuthInitException Thrown if the Auth class is not correctly initialized or if the login method was not executed.
 @return List of context items returned.
 @return nil if no items were returned.
 *<br/><b>Sample code</b><br/>
 *@snippet ContextSample setHistoricalItems
 */
- (void)setHistoricalItems:(ListItemsCallback)callback errorCallback:(ErrorCallback)errorCallback listItems:(ListItems*)listItems;

/**
 Gets the context information about a specific item, such as the item's context type, owner, ID, and times that the item was created on the client and server.
 @param itemContextId The ID from the context item you want to get.
 @throw ParameterException Thrown if the itemContextId parameter is null or empty.
 @throw AuthInitException Thrown if the Auth class is not correctly initialized or if the login method was not executed.
 @return ItemContext instance that includes the following set properties: ID, owner, type, and client and server created times.
 @return nil if the item context with that ID was not found.
 *<br/><b>Sample code</b><br/>
 *@snippet ContextSample getItemById
 */
- (void)getItemById:(ItemContextCallback)callback errorCallback:(ErrorCallback)errorCallback itemContextId:(NSString*)itemContextId;

/**
 Deletes one or more specific items using the each item's ID.
 @param itemContextId The ID of the context item that you want to delete.
 @throw ParameterException Thrown if the itemContextId parameter is null or empty.
 @throw AuthInitException Thrown if the Auth class is not correctly initialized or if the login method was not executed.
 @return TRUE if the context item exists and was deleted successfully.
 @return FALSE if an error occurs getting the context item with that ID.
 *<br/><b>Sample code</b><br/>
 *@snippet ContextSample deleteItemById
 */
- (void)deleteItemById:(OkCallback)callback errorCallback:(ErrorCallback)errorCallback itemContextId:(NSString*)itemContextId;

/**
 Querying /items returns results filtered by the specified query filter.
 @param query Object containing the query options.
 @throw AuthInitException Thrown if the Auth class is not correctly initialized or if the login method was not executed.
 @return List of items returned.
 @return nil if no items were returned.
 *<br/><b>Sample code</b><br/>
 *@snippet ContextSample getHistoricalItems
 */
- (void)getHistoricalItems:(ListItemsCallback)callback errorCallback:(ErrorCallback)errorCallback query:(QueryItem*)query;

/**
 Removes all CONTEXT_TYPE_APPLICATION_SPECIFIED_DATA items that match the query parameters.
 @param query Object containing the query options.
 @throw AuthInitException Thrown if the Auth class is not correctly initialized or if the login method was not executed.
 @return TRUE if the results were deleted successfully.
 @return FALSE if an error occurred during the delete process.
 *<br/><b>Sample code</b><br/>
 *@snippet ContextSample removePrivateHistoricalItems
 */
- (void)removePrivateHistoricalItems:(OkCallback)callback errorCallback:(ErrorCallback)errorCallback;

/**
 Returns the set of watch objects associated with the calling application. Each object represents a filter that will generate a notification to the caller.
 @throw AuthInitException Thrown if the class is not correctly initialized or if the login method was not executed.
 @return Watch collection with the ID, contextType, owner, provider and callbackUrl elements.
 @return nil if watches weren't returned.
 *<br/><b>Sample code</b><br/>
 *@snippet ContextSample getWatches
 */
- (void)getWatches:(WatchesCallback)callback errorCallback:(ErrorCallback)errorCallback;

/**
 Uses a watch ID to get new context information for a specific watch.
 @param watchId The ID of the watch to get.
 @throw ParameterException Thrown if the watchId parameter is null or empty.
 @throw AuthInitException Thrown if the Auth class is not correctly initialized or if the login method did was not executed.
 @return Watch result.
 @return nil if no results were found.
 *<br/><b>Sample code</b><br/>
 *@snippet ContextSample getWatchById
 */
- (void)getWatchById:(WatchCallback)callback errorCallback:(ErrorCallback)errorCallback watchId:(NSString*)watchId;

/**
 Deletes a specific watch.
 @param watchId The ID from the watch you want to delete.
 @throw ParameterException Thrown if the watchId parameter is null or empty.
 @throw AuthInitException Thrown if the Auth class is not correctly initialized or if the login method was not executed.
 @return TRUE if the watch was deleted successfully.
 @return FALSE if an error occurred while the watch was being deleted.
 *<br/><b>Sample code</b><br/>
 *@snippet ContextSample deleteWatchById
 */
- (void)deleteWatchById:(OkCallback)callback errorCallback:(ErrorCallback)errorCallback watchId:(NSString*)watchId;

/**
 Creates a watch associated with the calling application. You can only create one watch by calling this URL. You only need to provide the contextType, owner, and provider.
 @param Watch The watch instance result.
 @throw ParameterException Thrown if the watch parameter is null.
 @throw AuthInitException Thrown if the Auth class is not correctly initialized or if the login method was not executed.
 @return TRUE if the watch was deleted successfully.
 @return FALSE if an error occurred while the watch was being deleted watch.
 *<br/><b>Sample code</b><br/>
 *@snippet ContextSample createWatch
 */
- (void)createWatch:(WatchCallback)callback errorCallback:(ErrorCallback)errorCallback watch:(Watch*)watch;

/**
 Predicts whether the user is sleeping or working based on the time of day.
 @param timestamp The timestamp that includes the date, time, seconds, and time zone.
 @throw ParameterException Thrown if the date parameter is null or empty.
 @throw AuthInitException Thrown if the Auth class is not correctly initialized or if the login method was not executed.
 @return Predicts either sleeping or working.
 *<br/><b>Sample code</b><br/>
 *@snippet ContextSample getPredictActivity
 */
- (void)getPredictActivity:(PredictActivityCallback)callback errorCallback:(ErrorCallback)errorCallback date:(NSDate*)date;

/**
 Predicts where the user is based on the user's current location or route.
 @param place The allowed values are PLACE_HOME or PLACE_WORK.
 @throw ParameterException Thrown if the place parameter 'place' is null or empty.
 @throw AuthInitException Thrown if the Auth class is not correctly initialized or if the login method was not executed.
 @return Place instance
 @return nil if an access denied error occurs.
 *<br/><b>Sample code</b><br/>
 *@snippet ContextSample getPlace
 */
- (void)getPlace:(PlaceCallback)callback errorCallback:(ErrorCallback)errorCallback place:(NSString*)place;

/**
 Queries the model for point of interest attributes, particularly related to cuisine. Time and location parameters are optional, but including them improves the quality of the prediction.
 @throw AuthInitException Thrown if the Auth class is not correctly initialized or if the login method was not executed.
 @return PointsOfInterest instance
 @return nil if an access denied error occurs or if points of interest attributes are not found.
 *<br/><b>Sample code</b><br/>
 *@snippet ContextSample getPointOfInterestWeights
 */
- (void)getPointOfInterestWeights:(POICallback)callback errorCallback:(ErrorCallback)errorCallback;

/**
 Queries the model for point of interest attributes, particularly related to cuisine. Time and location parameters are optional, but including them improves the quality of the prediction.
 @param latitude The latitude in degrees of the location for which you want points of interest (POI).
 @param longitude The longitude in degrees of the location for which you want POI.
 @param datetime The time of day when you want the weighted points of interest suggestions.
 @throw ParameterException Thrown if the latitude isn't between -90.0 and 90.0, or if the longitude isn't between -180.0 and 180.0
 @throw ParameterException Thrown if datetime parameter is empty (nil).
 @throw AuthInitException Thrown if the Auth class is not correctly initialized or if the login method was not executed.
 @return PointsOfInterest instance
 @return nil if an access denied error occurs or if available points of interest are not found.
 *<br/><b>Sample code</b><br/>
 *@snippet ContextSample getPointOfInterestWeights
 */
- (void)getPointOfInterestWeights:(POICallback)callback errorCallback:(ErrorCallback)errorCallback latitude:(double)latitude longitude:(double)longitude datetime:(NSDate*)datetime;

/**
 Lists the next possible location that the user might go to by analyzing context information that was gathered about that user.
 @param latitude The latitude in degrees of the starting location.
 @param longitude The longitude in degrees of the starting location.
 @param datetime The time when the event begins.
 @throw ParameterException Thrown if the latitude isn't between -90.0 and 90.0, or if the longitude isn't between -180.0 and 180.0
 @throw ParameterException Thrown if datetime parameter is empty (nil).
 @throw AuthInitException Thrown if the Auth class is not correctly initialized or if the login method was not executed.
 @return Destination instance
 @return nil if an access denied error occurs or if available destinations are not found.
 *<br/><b>Sample code</b><br/>
 *@snippet ContextSample getPossibleNextDestinations
 */
- (void)getPossibleNextDestinations:(DestinationCallback)callback errorCallback:(ErrorCallback)errorCallback latitude:(double)latitude longitude:(double)longitude datetime:(NSDate*)datetime;

/**
 Allows the user to update his or her current states.
 @param state The user's state.
 @throw AuthInitException Thrown if the Auth class is not correctly initialized or if the login method did was not executed.
 @return true (or yes) if the state was updated successfully.
 @return false (or no) if the state was not updated successfully.
 *<br/><b>Sample code</b><br/>
 *@snippet ContextSample updateUserState
 */
- (void)updateUserState:(OkCallback)callback errorCallback:(ErrorCallback)errorCallback state:(State*)state;

/**
 Allows the user to update his or her current state.
 @param state The user's state
 @throw AuthInitException Thrown if the Auth class is not correctly initialized or if the login method was not executed.
 @return true (or yes) if the state was updated successfully.
 @return false (or no) if the state was not updated successfully.
 *<br/><b>Sample code</b><br/>
 *@snippet ContextSample updateMultiplesUserStates
 */
- (void)updateUserState:(OkCallback)callback errorCallback:(ErrorCallback)errorCallback listStates:(ListStates*)listStates;

/**
 Update user to sensing demo.
 URL: http://choices-dev2-1670937596.us-east-1.elb.amazonaws.com/context/v1/states
 */
- (void)updateUserStateToSensingDemo:(OkCallback)callback errorCallback:(ErrorCallback)errorCallback state:(State *)state user:(User *)user;

/**
 Allows the user to retrieve his or her current states.
 @throw AuthInitException Thrown if the Auth class is not correctly initialized or if the login method was not executed.
 @return List of states
 */
- (void)getUserState:(ListStatesCallback)callback errorCallback:(ErrorCallback)errorCallback;

/**
 Allows the user to retrieve his or her current state by query.
 @param query The query allows the results to be filtered the results by types, devices and activities.
 @throw AuthInitException Thrown if the Auth class is not correctly initialized or if the login method was not executed.
 @return true (or yes) if the state was updated successfully.
 @return false (or no) if the state was not updated successfully.
 *<br/><b>Sample code</b><br/>
 *@snippet ContextSample getUserState
 */
- (void)getUserState:(ListStatesCallback)callback errorCallback:(ErrorCallback)errorCallback query:(QueryItem*)query;

@end