package org.intel.phonegap;

import org.apache.cordova.CallbackContext;
import org.apache.cordova.PluginResult;
import org.apache.cordova.PluginResult.Status;
import org.json.JSONArray;
import org.json.JSONException;

import android.widget.Toast;

import com.intel.api.Intel;
import com.intel.common.Error;
import com.intel.common.Error.Code;
import com.intel.common.Settings.Environment;
import com.intel.core.Callback;
import com.intel.core.auth.LogoutCallback;
import com.intel.core.auth.Auth.Action;

public class IntelSDKPlugin extends org.apache.cordova.CordovaPlugin {

	private String clientId, secretId, scopes, redirectUrl;

	private static final String LOGIN_ACTION = "login";
	private static final String INITIALIZE_ACTION = "init";
	private static final String LOGOUT_ACTION = "logout";

	public boolean execute(String action, JSONArray data, CallbackContext callbackContext) {

		if (action.equals(INITIALIZE_ACTION)) { // Init login
			try {
				clientId = data.getString(0);
				secretId = data.getString(1);
				scopes = data.getString(2);
                                redirectUrl = data.getString(3);

				if(Intel.auth.isLoggedIn(cordova.getActivity().getApplicationContext())){
					callbackContext.sendPluginResult(new PluginResult(Status.OK, true));
				} else {
					callbackContext.sendPluginResult(new PluginResult(Status.OK, false));
				}
			} catch (JSONException e) {
				callbackContext.sendPluginResult(new PluginResult(Status.ERROR, e.getMessage()));
			}
		} else if (action.equals(LOGIN_ACTION) && clientId != null
				&& secretId != null) {
			// Login
			login(callbackContext);
		} else if (action.equals(LOGOUT_ACTION)){
			// Logout
			logout(callbackContext);
		}

		return true;
	}

	public void login(CallbackContext callbackContext) {
		if (!Intel.auth.isLoggedIn(cordova.getActivity()
				.getApplicationContext())) {
			
			final CallbackContext callback = callbackContext;
			
			// Control scopes
			if (scopes == null || scopes == "null") {
				scopes = "user:details user:scope profile:full profile:basic profile:full:write location:basic location:enhanced context:developer-specific context:location:detailed context:post:location:detailed context:geolocation:detailed context:time:detailed context:device:applications:running context:post:device:applications:running context:device:telephony context:post:device:telephony context:device:calendar context:post:device:calendar context:device:status:battery context:post:device:status:battery context:media:consumption context:post:media:consumption";
			}
			
			Intel.auth.login(cordova.getActivity().getApplicationContext(),
				    Environment.PROD, "en-us", clientId, secretId, scopes,
				    null, redirectUrl, Action.SIGN_IN,
					new Callback() {
						public void onFail(Error arg0) {
							if (arg0.getCode().equals(Code.SERVICE_UNAVAILABLE)) {
								callback.sendPluginResult(new PluginResult(Status.ERROR, "Login Error: Identity Service unavailable, check Internet connection"));
							} else {
								callback.sendPluginResult(new PluginResult(Status.ERROR, "Login Error: " + arg0.getDescription()));
							}
						}

						public void onSuccess(Object arg0) {
							callback.sendPluginResult(new PluginResult(Status.OK));
						}
			});
		}
	}
	
	public void logout(CallbackContext callbackContext){
		if (Intel.auth.isLoggedIn(cordova.getActivity()
				.getApplicationContext())) {
			
			final CallbackContext callback = callbackContext;
			
			Intel.auth.logout(cordova.getActivity().getApplicationContext(), new LogoutCallback() {
				
				@Override
				public void onSuccess() {
					callback.sendPluginResult(new PluginResult(Status.OK));
				}
				
				@Override
				public void onFail(Error arg0) {
					callback.sendPluginResult(new PluginResult(Status.ERROR, arg0.getDescription()));
				}
			});
		}
	}
	
}