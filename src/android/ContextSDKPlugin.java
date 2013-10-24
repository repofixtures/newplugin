package org.intel.phonegap;

import org.apache.cordova.CallbackContext;
import org.apache.cordova.CordovaPlugin;
import org.apache.cordova.PluginResult;
import org.apache.cordova.PluginResult.Status;
import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

import android.os.Bundle;
import android.util.Log;

import com.intel.context.*;
import com.intel.context.error.ContextError;
import com.intel.context.item.Item;

public class ContextSDKPlugin extends CordovaPlugin {
	
	private static final String GET_SERVICES_LIST = "getServicesList";
	private static final String INIT_SERVICES = "initWithServicesList";
	private static final String STOP_SERVICES = "stopServices";
	private static final String CHECK_STATUS = "checkStatus";
	private static boolean isInit = false;
	private JSONArray servicesList;
		
	public boolean execute(String action, JSONArray data, CallbackContext callbackContext) {
		
		PluginResult pluginResult = null;
		
		if(action.equals(GET_SERVICES_LIST)){
			pluginResult = getServicesList();
			callbackContext.sendPluginResult(pluginResult);
		}else if(action.equals(INIT_SERVICES)){
			pluginResult = initWithServicesList(data, callbackContext);
		}else if(action.equals(STOP_SERVICES)){
			pluginResult = stopServices(callbackContext);
		}else if(action.equals(CHECK_STATUS)){
			callbackContext.sendPluginResult(new PluginResult(Status.OK, isInit));
		}else{
			pluginResult = new PluginResult(Status.ERROR);
		}
		
		return ((pluginResult.getStatus() == Status.OK.ordinal()) ? true : false);
	}
	
	/**
	 * Get lists of services
	 * @return Plugin result for push to cordova
	 */
	public PluginResult getServicesList(){
		JSONArray arrTypes = new JSONArray();
		JSONObject typeToAdd = new JSONObject();
		Type type = null;
		PluginResult.Status status = null;
		
		try{
			//Location
			type = Type.LOCATION;
			typeToAdd.put("name", "Location");
			typeToAdd.put("urn", type.toString());
			typeToAdd.put("situationType", type.toSituationType());
			arrTypes.put(typeToAdd);
			
			//Call
			type = Type.CALL;
			typeToAdd = new JSONObject();
			typeToAdd.put("name", "Call");
			typeToAdd.put("urn", type.toString());
			typeToAdd.put("situationType", type.toSituationType());
			arrTypes.put(typeToAdd);
			
			//Current applications
			type = Type.APPS;
			typeToAdd = new JSONObject();
			typeToAdd.put("name", "Current applications");
			typeToAdd.put("urn", type.toString());
			typeToAdd.put("situationType", type.toSituationType());
			arrTypes.put(typeToAdd);
			
			//Battery
			type = Type.BATTERY;
			typeToAdd = new JSONObject();
			typeToAdd.put("name", "Battery");
			typeToAdd.put("urn", type.toString());
			typeToAdd.put("situationType", type.toSituationType());
			arrTypes.put(typeToAdd);
			
			//Music
			type = Type.MUSIC;
			typeToAdd = new JSONObject();
			typeToAdd.put("name", "Music");
			typeToAdd.put("urn", type.toString());
			typeToAdd.put("situationType", type.toSituationType());
			arrTypes.put(typeToAdd);
			
			//Contacts
			type = Type.CONTACTS;
			typeToAdd = new JSONObject();
			typeToAdd.put("name", "Contacts");
			typeToAdd.put("urn", type.toString());
			typeToAdd.put("situationType", type.toSituationType());
			arrTypes.put(typeToAdd);
			
			//Calendar
			type = Type.CALENDAR;
			typeToAdd = new JSONObject();
			typeToAdd.put("name", "Calendar");
			typeToAdd.put("urn", type.toString());
			typeToAdd.put("situationType", type.toSituationType());
			arrTypes.put(typeToAdd);
			
			//Network
			type = Type.NETWORK;
			typeToAdd = new JSONObject();
			typeToAdd.put("name", "Network");
			typeToAdd.put("urn", type.toString());
			typeToAdd.put("situationType", type.toSituationType());
			arrTypes.put(typeToAdd);
			
			//Installed apps
			type = Type.INSTALLED_APPS;
			typeToAdd = new JSONObject();
			typeToAdd.put("name", "Installed applications");
			typeToAdd.put("urn", type.toString());
			typeToAdd.put("situationType", type.toSituationType());
			arrTypes.put(typeToAdd);
			
			//Message
			type = Type.MESSAGE;
			typeToAdd = new JSONObject();
			typeToAdd.put("name", "Message");
			typeToAdd.put("urn", type.toString());
			typeToAdd.put("situationType", type.toSituationType());
			arrTypes.put(typeToAdd);
			
			//Device information
			type = Type.DEVICE_INFORMATION;
			typeToAdd = new JSONObject();
			typeToAdd.put("name", "Device information");
			typeToAdd.put("urn", type.toString());
			typeToAdd.put("situationType", type.toSituationType());
			arrTypes.put(typeToAdd);
			
			status = PluginResult.Status.OK;
		}catch(Exception ex){
			status = PluginResult.Status.ERROR;
		}
		
		return new PluginResult(status, arrTypes);
	}
	
	public PluginResult initWithServicesList(JSONArray servicesList, CallbackContext callbackContext){
		
		if(!isInit){
			Log.d("Debug", "Initializiting context library..");
			try {
				this.servicesList = servicesList.getJSONArray(0);
			} catch (JSONException e) {
				e.printStackTrace();
			}
			
			if(this.servicesList == null || this.servicesList.length() == 0){
				Log.d("Status", "The list of services is empty!");
				callbackContext.sendPluginResult(new PluginResult(Status.ERROR, "The list of services is empty."));
				return new PluginResult(Status.ERROR);
			}
			
			com.intel.context.Context.init(cordova.getActivity().getApplicationContext(), new SensingServiceCallback(callbackContext));
		} else {
			Log.d("Debug", "The context sensing has been already enabled..");
			callbackContext.sendPluginResult(new PluginResult(Status.ERROR, "The context sensing has been already enabled"));
			return new PluginResult(Status.ERROR);
		}

		return new PluginResult(PluginResult.Status.OK);
	}
	
	public PluginResult stopServices(CallbackContext callbackContext){
		PluginResult pluginResult = new PluginResult(Status.OK);
		if(isInit){
			try {
				Context.finish();
				isInit = false;
				callbackContext.sendPluginResult(pluginResult);
			} catch (Exception e) {
				pluginResult = new PluginResult(Status.ERROR, "Service not started");
				callbackContext.sendPluginResult(pluginResult);
			}
		}
		
		return pluginResult;
	}
	
	/******** */
	
	private class ListenerStatesCallback implements ListenerCallback {

		@Override
		public void onError(ContextError arg0) {
			Log.d("Error", "Error receiving item");
			webView.sendJavascript("context.onError('" + arg0.getMessage() + "');");
		}

		@Override
		public void onReceive(Item arg0) {
			Log.d("Update item", "Has been received an item of type " + arg0.getStateType().toString());
			webView.sendJavascript("context.onReceivedItem('','" + arg0.getStateType().toString() + "');");
		}
		
	}
	
	private class SensingServiceCallback implements OnStatusCallback {

		private CallbackContext callbackContext = null;
		
		public SensingServiceCallback(CallbackContext callback){
			this.callbackContext = callback;
		}
		
		@Override
		public void onSuccess() {
			Log.d("Status", "Success context init!");
						
			if(callbackContext != null){
				Log.d("Status", "Sending success status!");
				callbackContext.sendPluginResult(new PluginResult(Status.OK));
			}
			
			isInit = true;
			
			try{
				for(int m=0; m < servicesList.length(); m++){
					JSONObject object = servicesList.getJSONObject(m);
					String urn = object.getString("urn");

					Bundle bundle = null;
					
					if(urn.equals(Type.LOCATION.toString())){
						com.intel.context.Context.enableSensing(Type.LOCATION, bundle);
						com.intel.context.Context.addListener(Type.LOCATION, new ListenerStatesCallback());
					}else if(urn.equals(Type.CALL.toString())){
						com.intel.context.Context.enableSensing(Type.CALL, bundle);
						com.intel.context.Context.addListener(Type.CALL, new ListenerStatesCallback());
					}else if(urn.equals(Type.APPS.toString())){
						com.intel.context.Context.enableSensing(Type.APPS, bundle);
						com.intel.context.Context.addListener(Type.APPS, new ListenerStatesCallback());
					}else if(urn.equals(Type.BATTERY.toString())){
						com.intel.context.Context.enableSensing(Type.BATTERY, bundle);
						com.intel.context.Context.addListener(Type.BATTERY, new ListenerStatesCallback());
					}else if(urn.equals(Type.MUSIC.toString())){
						com.intel.context.Context.enableSensing(Type.MUSIC, bundle);
						com.intel.context.Context.addListener(Type.MUSIC, new ListenerStatesCallback());
					}else if(urn.equals(Type.CONTACTS.toString())){
						com.intel.context.Context.enableSensing(Type.CONTACTS, bundle);
						com.intel.context.Context.addListener(Type.CONTACTS, new ListenerStatesCallback());
					}else if(urn.equals(Type.CALENDAR.toString())){
						com.intel.context.Context.enableSensing(Type.CALENDAR, bundle);
						com.intel.context.Context.addListener(Type.CALENDAR, new ListenerStatesCallback());
					}else if(urn.equals(Type.NETWORK.toString())){
						com.intel.context.Context.enableSensing(Type.NETWORK, bundle);
						com.intel.context.Context.addListener(Type.NETWORK, new ListenerStatesCallback());
					}else if(urn.equals(Type.INSTALLED_APPS.toString())){
						com.intel.context.Context.enableSensing(Type.INSTALLED_APPS, bundle);
						com.intel.context.Context.addListener(Type.INSTALLED_APPS, new ListenerStatesCallback());
					}else if(urn.equals(Type.MESSAGE.toString())){
						com.intel.context.Context.enableSensing(Type.MESSAGE, bundle);
						com.intel.context.Context.addListener(Type.MESSAGE, new ListenerStatesCallback());
					}else if(urn.equals(Type.DEVICE_INFORMATION.toString())){
						com.intel.context.Context.enableSensing(Type.DEVICE_INFORMATION, bundle);
						webView.sendJavascript("context.onReceivedItem('','" + Type.DEVICE_INFORMATION.toString() + "');"); //Increment the counter 'cause this action will be executed once time
					}
				}
			} catch (Exception ex){
				if(callbackContext != null){
					callbackContext.sendPluginResult(new PluginResult(Status.ERROR, ex.getMessage()));
					Log.d("Status", "Sending error via callback: " + ex.getMessage());
				}
				else{
					Log.d("Status", "Sending error via javascript: " + ex.getMessage());
					webView.sendJavascript("context.onError('Exception: " + ex.getMessage() + "');");
				}
			}
		}

		@Override
		public void onError(ContextError error) {
			if(callbackContext != null){
				Log.d("Status", "Sending error via callback: " + error.getMessage());
				callbackContext.sendPluginResult(new PluginResult(Status.ERROR, error.getMessage()));
			} else {
				Log.d("Status", "Sending error via javascript: " + error.getMessage());
				webView.sendJavascript("context.onError('" + error.getMessage() + "');");
			}
		}
	}
}