Intel Cloud Services Plugin - Phonegap V >= 3.0
=====================

Installation
=================

<h3><b>Critical</b>: First of all, you need install node.js and configure phonegap. More info <a href='http://phonegap.com/install/'>here</a></h3>

- Create a new project with the following command: <b>phonegap create testing com.example.testing testing</b>

- You must install the <font color='green'>Android</font>/<font color='orangered'>iOS</font> platform in that project. The command: <b>phonegap build <font color='green'>android</font>/<font color='orangered'>ios</font></b>

- For install this plugin, you must execute the following command: <b>phonegap local plugin add https://github.com/intelcontextcloud/phonegap-plugin-cli</b>

<ul>
<li>In <font color='green'>Android</font>:</li>
        <ul><li>- You must import Cloud Intel SDK and Context Intel SDK libraries.</li></ul>
        <ul><li>- For use the context services, you need to edit the AndroidManifest.xml file. You must add the following permissions:</li></ul>
        <blockquote>
        	&lt;uses-permission android:name="android.permission.INTERNET" /&gt;<br />
		    &lt;uses-permission android:name="android.permission.WRITE_EXTERNAL_STORAGE" /&gt;<br />
		    &lt;uses-permission android:name="android.permission.ACCESS_NETWORK_STATE" /&gt;<br />
		    &lt;uses-permission android:name="android.permission.GET_TASKS" /&gt;<br />
		    &lt;uses-permission android:name="android.permission.READ_PHONE_STATE" /&gt;<br />
			&lt;uses-permission android:name="android.permission.READ_CALENDAR" /&gt;<br />
		    &lt;uses-permission android:name="android.permission.READ_CONTACTS" /&gt;<br />
		    &lt;uses-permission android:name="android.permission.ACCESS_FINE_LOCATION" /&gt;<br />
		    &lt;uses-permission android:name="android.permission.ACCESS_WIFI_STATE" /&gt;<br />
		    &lt;uses-permission android:name="android.permission.WAKE_LOCK" /&gt;<br />
		    &lt;uses-permission android:name="android.permission.CAMERA" /&gt;<br />
		    &lt;uses-permission android:name="android.permission.VIBRATE" /&gt;<br />
		    &lt;uses-permission android:name="android.permission.ACCESS_COARSE_LOCATION" /&gt;<br />
		    &lt;uses-permission android:name="android.permission.ACCESS_FINE_LOCATION" /&gt;<br />
		    &lt;uses-permission android:name="android.permission.ACCESS_LOCATION_EXTRA_COMMANDS" /&gt;<br />
		    &lt;uses-permission android:name="android.permission.INTERNET" /&gt;<br />
		    &lt;uses-permission android:name="android.permission.RECEIVE_SMS" /&gt;<br />
		    &lt;uses-permission android:name="android.permission.RECORD_AUDIO" /&gt;<br />
		    &lt;uses-permission android:name="android.permission.RECORD_VIDEO"/&gt;<br />
		    &lt;uses-permission android:name="android.permission.MODIFY_AUDIO_SETTINGS" /&gt;<br />
		    &lt;uses-permission android:name="android.permission.READ_CONTACTS" /&gt;<br />
		    &lt;uses-permission android:name="android.permission.WRITE_CONTACTS" /&gt;<br />
		    &lt;uses-permission android:name="android.permission.WRITE_EXTERNAL_STORAGE" /&gt;<br />
		    &lt;uses-permission android:name="android.permission.ACCESS_NETWORK_STATE" /&gt;<br />
		    &lt;uses-permission android:name="android.permission.GET_ACCOUNTS" /&gt;<br />&lt;uses-permission android:name="android.permission.BROADCAST_STICKY" /&gt;<br />
		    &lt;uses-permission android:name="android.permission.READ_PHONE_STATE"/&gt;<br />
		    &lt;uses-permission android:name="android.permission.GET_TASKS"/&gt;<br />
		    &lt;uses-permission android:name="android.permission.READ_SMS"/&gt;<br />
		    &lt;uses-permission android:name="android.permission.WRITE_SMS"/&gt;<br />
        </blockquote>
        <ul><li>- You also need to add the following activity and services:</li></ul>
        <blockquote>
        	&lt;activity<br />
	            android:name="com.intel.core.ui.LoginActivity"<br />
	            android:label="Intel services login"<br />
	            android:screenOrientation="portrait" &gt;<br />
	            &lt;intent-filter&gt;<br />
	                &lt;category android:name="android.intent.category.DEFAULT" /&gt;<br />
	            &lt;/intent-filter&gt;<br />
	        &lt;/activity&gt;<br />
	        
	        &lt;service android:name="com.intel.context.core.LocalService" /&gt;<br />
	    	&lt;service android:name="com.intel.internal.communication.ExecuteRequest" /&gt;<br />
        </blockquote>
        <hr />
     <li>In <font color='orangered'>iOS</font>:</li>
        <ul><li>- You must import only <b>Context SDK Library</b> and the following dependencies:</li></ul>

<ul>
    <ul>
        <li><i>MediaPlayer.framework</i></li>
        <li><i>CoreTelephony.framework</i></li>
        <li><i>AddressBook.framework</i></li>
        <li><i>EventKit.framework</i></li>
        <li><i>SystemConfiguration.framework</i></li>
        <li><i>libsqlite3.dylib</i></li>
    </ul>
</ul>
</ul>

- Done, now you can use the plugin.

Note for <font color='orangered'>iOS</font>
======

if you got a <b>whitelist error</b> when you try to login with your credentials, you need do the following:

In config.xml, add this line:

<blockquote>&lt;access origin="*intel*" /&gt;</blockquote>

just above

<blockquote>&lt;access origin="http://127.0.0.1*" /&gt;</blockquote>

Sample application
======

The sample application (Hydrogen) is available <a href='https://github.com/intelcontextcloud/phonegap-hydrogen-sample'>here</a>