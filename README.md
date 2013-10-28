Intel Cloud Services Plugin - Phonegap
=====================

Documentation
=====================

Intel functions
=====================

<center><h2>intel.initialize(clientId, secretId, scopes, redirectUrl, isLogged)</h2></center>

Initialize the credentials for login. This function receives the following parameters:

- </b>clientId</b>: developer's client ID obtained from Developer Portal.
- </b>secretId</b>: developer's client secret associated with the client ID.
- </b>scope</b>: scope/s required for the application.
- </b>redirectUri</b>: redirect URI you configured in your Developer Account for login success.
- </b>isLogged</b>: callback function. This callback function returns one parameter suggesting if the user is already logged in.

<center><h2>intel.login(callback, errorCallback)</h2></center>

Authenticates users with the Intel Identity Services using an Intel account.

- <b>callback</b>: This function will be executed if the user has been logged successful.
- <b>errorCallback</b>: This function returns one parameter suggesting the produced error when the user was logging in.

<center><h2>intel.logout(callback, errorCallback)</h2></center>

Logs a user out of the services by removing the token from the current session.

- <b>callback</b>: This function will be executed if the session has been closed successful.
- <b>errorCallback</b>: This function returns one parameter suggesting the produced error when the user was closing the session.

Context functions
=====================

<center><h2>context.service</h2></center>

This object contains the following properties: <i>name</i> and </i>urn</i> 

<center><h2>context.initCallbacks(onReceivedItem, onError)</h2></center>

Initialize the callbacks for context services. This function receives the following parameters:

- <b>onReceivedItem</b>: This parameter is a function defined by one parameter: <i>type</i>. This last parameter will contain the urn (in string format) of the item received on context services (for example, contacts or battery types).

- <b>onError</b>: This parameter is a function defined by one parameter: <i>error</i>. This last parameter will contain all errors received from context services api.

<center><h2>getServices(services, errorCallback)</h2></center>

This function returns the allowed services for the current platform. For example, in android the "messages service" is allowed, but not on iOS.

- <b>callback</b>: Collection of services objects. Each object contains "name" and "urn" properties.

Note: In the context.init method, must be specified "context.services" objects. The collection received by parameter in this function is not the same as context.services objects.

- <b>errorCallback</b>: This parameter is a function defined by one parameter: <i>error</i>. This last parameter will contain the produced error

<center><h2>init(services, callback, errorCallback)</h2></center>

This function initializes the list of services passed by the first parameter (must be a collection of context.services objects). If the context service has been initialized properly then function callback will be executed. Otherwise, the errorCallback function will be executed. The errorCallback function returns the error as parameter.