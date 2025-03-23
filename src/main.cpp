// // #include <Arduino.h>
// // #include <WiFi.h>
// // #include <HTTPClient.h>
// // #include <ArduinoJson.h> // For handling JSON data

// // const char* ssid = "SimonD@19";
// // const char* password = "Kowsilla$55$66";

// // #define FCM_SERVER_KEY "AIzaSyCOQ4BxYrVS5wCLf5K8o_uAzmC-RcRbsWI"
// // #define SENDER_ID "816230794155"


// // void setup() {
// //   // put your setup code here, to run once:
// //   Serial.begin(115200);
//   // WiFi.begin(ssid, password);
// //   while (WiFi.status() != WL_CONNECTED) {
// //     delay(1000);
// //     Serial.println("Connecting to WiFi..");
// //   }
// //   Serial.println("Connected to the WiFi network");
// // }

// // void loop() {
// //   // put your main code here, to run repeatedly:
// //   if(WiFi.status() == WL_CONNECTED){
// //     HTTPClient http;
// //     http.begin("https://fcm.googleapis.com/v1/projects/beatai-bc460/messages:send");
// //     http.addHeader("Authorization", "Bearer " + String(FCM_SERVER_KEY));
// //     http.addHeader("Content-Type", "application/json");
// //     http.addHeader("project_id", SENDER_ID);  // Add Sender ID here

// //   }
// // }


// // #include <Arduino.h>
// // #include "ArduinoJson.h"
// // #include <WiFi.h>
// // #include "Firebase_ESP_Client.h"

// // // Provide the token generation process info.
// // #include <addons/TokenHelper.h>

// // #define output 15
// // #define lowMinus 2
// // #define lowPlus 4

// // #define SSID "SimonD@19"
// // #define PASSWORD "Kowsilla$55$66"

// // #define resource "https://beatai-bc460-default-rtdb.firebaseio.com"
// // #define API_KEY "AIzaSyCOQ4BxYrVS5wCLf5K8o_uAzmC-RcRbsWI"
// // #define FIREBASE_CLIENT_EMAIL "dlbalzora@gmail.com"
// // #define FIREBASE_PROJECT_ID "beatai-bc460"
// // #define DEVICE_REGISTRATION_ID_TOKEN "816230794155"


// // FirebaseData fbdo;
// // FirebaseAuth auth;
// // FirebaseConfig config;
// // FirebaseJson json;
// // int count =0;

// // void sendMessage()
// // {

// //     Serial.print("Send Firebase Cloud Messaging... ");

// //     // Read more details about HTTP v1 API here https://firebase.google.com/docs/reference/fcm/rest/v1/projects.messages
// //     FCM_HTTPv1_JSON_Message msg;

// //     msg.token = DEVICE_REGISTRATION_ID_TOKEN;

// //     msg.notification.body = "Notification body";
// //     msg.notification.title = "Notification title";

// //     // For the usage of FirebaseJson, see examples/FirebaseJson/BasicUsage/Create.ino
// //     FirebaseJson payload;

// //     // all data key-values should be string
// //     payload.add("temp", "28");
// //     payload.add("unit", "celsius");
// //     payload.add("timestamp", "1609815454");
// //     msg.data = payload.raw();

// //     if (Firebase.FCM.send(&fbdo, &msg)) // send message to recipient
// //         Serial.printf("ok\n%s\n\n", Firebase.FCM.payload(&fbdo).c_str());
// //     else
// //         Serial.println(fbdo.errorReason());

// //     count++;
// // }

// // void setup(){
// //   Serial.begin(115200);
// //   Serial.print("EKG demo");
// //   pinMode(lowMinus, INPUT);
// //   pinMode(lowPlus, INPUT);

// //   WiFi.begin(SSID, PASSWORD);
// //   while (WiFi.status() != WL_CONNECTED) {
// //     delay(1000);
// //     Serial.println("Connecting to WiFi..");
// //   }
// //   Serial.println("Connected to the WiFi network");

// //   config.service_account.data.client_email = FIREBASE_CLIENT_EMAIL;
// //   config.service_account.data.project_id = FIREBASE_PROJECT_ID;
// //   config.service_account.data.private_key = API_KEY;

// //       /* Assign the callback function for the long running token generation task */
// //       config.token_status_callback = tokenStatusCallback; // see addons/TokenHelper.h

// //       // Comment or pass false value when WiFi reconnection will control by your code or third party library e.g. WiFiManager
// //       Firebase.reconnectNetwork(true);
  
// //       // Since v4.4.x, BearSSL engine was used, the SSL buffer need to be set.
// //       // Large data transmission may require larger RX buffer, otherwise connection issue or data read time out can be occurred.
// //       fbdo.setBSSLBufferSize(4096 /* Rx buffer size in bytes from 512 - 16384 */, 1024 /* Tx buffer size in bytes from 512 - 16384 */);
  
// //       Firebase.begin(&config, &auth);

// // }


// // void loop(){

// //       // Firebase.ready() should be called repeatedly to handle authentication tasks.
// //       int lastTime = millis();
// //       while (Firebase.ready() && (millis() - lastTime > 2 * 1000 || lastTime == 0))
// //       {
// //           lastTime = millis();
  
// //       }
// //       sendMessage();

// //     // collect for 10 seconds
// //     // int startTime = millis();
// //     // int index = 0;
// //     // while(millis() - startTime < 10000) {
// //     //   // float voltage = analogRead(34) * (3.3 / 4095.0); // Assuming 3.3V ref
// //     //   float voltage = 1.0; // Placeholder
// //     //   int timestamp = millis()-startTime;
      
// //     //   // Add to JSON array
// //     //   FirebaseJson entry;
// //     //   entry.set("voltage", voltage);
// //     //   entry.set("time", timestamp);
      
// //     //   String path = "ekg/session1/data/" + index; // ekg/session1/data/0, 1, 2...
// //     //   Firebase.RTDB.setJSON(&fbdo, path, &entry);
// //     //   index++;
  
// //     //   delay(100);
// //     // }
// //     //   Serial.println("Finished 10 seconds");
// //     //   delay(5000);
// //   }
  

// //   // StaticJsonDocument<2048> doc;
// //   // // float data[400][2];   //[voltage value][time]
// //   // // int start = millis();
// //   // // int i = 0;
// //   // // while(millis() - start < 10000){
// //   // //   if((digitalRead(lowMinus) == 1)||(digitalRead(lowPlus) == 1)){
// //   // //     data[i][0] = 0;
// //   // //     data[i][1] = millis() - start;
// //   // //   }
// //   // //   else{
// //   // //     // send the value of analog input 0:
// //   // //     data[i][0] = analogRead(output) * (3.3 / 4095.0);
// //   // //     data[i][1] = millis() - start;
// //   // //   }
// //   // //   delay(25);
// //   // // }
// //   // // for(int j = 0; j < 400; j++){
// //   // //   doc["data"][j]["voltage"] = data[j][0];
// //   // //   doc["data"][j]["time"] = data[j][1];
// //   // // }
// //   // for(int i = 0; i < 400; i++){
// //   //   doc["data"][i]["voltage"] = 1;
// //   //   doc["data"][i]["time"] = millis();
// //   // }
// //   // String buffer = "";
// //   // serializeJson(doc, buffer);
  
// //   // if(WiFi.status() == WL_CONNECTED){
// //   //   FirebaseData fbdo;
// //   //   FirebaseAuth auth;
// //   //   FirebaseConfig config;

// //   //   HTTPClient http;
// //   //   http.begin(resource);
// //   //   http.addHeader("Content-Type", "application/json");
// //   //   http.addHeader("User-Agent", "curl/7.47.0");
// //   //   http.addHeader("Cache-Control", "no-cache");
// //   //   http.addHeader("Accept", "*/*");
// //   //   int httpCode = http.POST(buffer);
// //   //   if(httpCode > 0){
// //   //     String payload = http.getString();
// //   //     Serial.println(httpCode);
// //   //     Serial.println(payload);
// //   //   }
// //   //   else{
// //   //     Serial.println("Error on HTTP request");
// //   //   }
// //   //   http.end();
// //   // }
// //   // delay(5000);


// // // /**
// // //  * Created by K. Suwatchai (Mobizt)
// // //  *
// // //  * Email: k_suwatchai@hotmail.com
// // //  *
// // //  * Github: https://github.com/mobizt/Firebase-ESP-Client
// // //  *
// // //  * Copyright (c) 2023 mobizt
// // //  *
// // //  */

// // // // This example shows how to send JSON payload FCM to a recipient via HTTPv1 API.
// // // // This new API requires OAuth2.0 authentication.

// // // // Library allows your ESP device to interact with FCM server through FCM Server protocols.
// // // // https://firebase.google.com/docs/cloud-messaging/server#choose

// // // // This means your device now is not a FCM app client and unable to get the notification messages.

// // // // The device registration tokens used in this example were taken from the FCM mobile app (Android or iOS)
// // // // or web app that athenticated to your project.

// // // // For FCM client app quick start
// // // // https://github.com/firebase/quickstart-android/tree/master/messaging
// // // // https://github.com/firebase/quickstart-ios
// // // // https://github.com/firebase/quickstart-js

// #include <Arduino.h>
// #if defined(ESP32) || defined(ARDUINO_RASPBERRY_PI_PICO_W)
// #include <WiFi.h>
// #elif defined(ESP8266)
// #include <ESP8266WiFi.h>
// #elif __has_include(<WiFiNINA.h>)
// #include <WiFiNINA.h>
// #elif __has_include(<WiFi101.h>)
// #include <WiFi101.h>
// #elif __has_include(<WiFiS3.h>)
// #include <WiFiS3.h>
// #endif

// #include <Firebase_ESP_Client.h>

// // Provide the token generation process info.
// #include <addons/TokenHelper.h>

// /* 1. Define the WiFi credentials */
// // #define WIFI_SSID "WIFI_AP"
// // #define WIFI_PASSWORD "WIFI_PASSWORD"
// #define WIFI_SSID "SimonD@19"
// #define WIFI_PASSWORD "Kowsilla$55$66"

// // /** 2. Define the Service Account credentials (required for token generation)
// //  *
// //  * This information can be taken from the service account JSON file.
// //  *
// //  * To download service account file, from the Firebase console, goto project settings,
// //  * select "Service accounts" tab and click at "Generate new private key" button
// //  * 
// //  * 
// //  */

// #define resource "https://beatai-bc460-default-rtdb.firebaseio.com"
// #define API_KEY "AIzaSyCOQ4BxYrVS5wCLf5K8o_uAzmC-RcRbsWI"
// // #define FIREBASE_CLIENT_EMAIL "dlbalzora@gmail.com"
// // #define FIREBASE_PROJECT_ID "beatai-bc460"
// // #define DEVICE_REGISTRATION_ID_TOKEN "816230794155"

// #define FIREBASE_PROJECT_ID "beatai-bc460"
// #define FIREBASE_CLIENT_EMAIL "firebase-adminsdk-fbsvc@beatai-bc460.iam.gserviceaccount.com"
// const char PRIVATE_KEY[] PROGMEM = "-----BEGIN PRIVATE KEY-----\nMIIEvAIBADANBgkqhkiG9w0BAQEFAASCBKYwggSiAgEAAoIBAQCl3mjCmXV/1Oyd\nP6Commra0k5BHaSJ6rEh4AqMEo85mWFXLPJgZfMdYRW9+Q2eMEste0rqWFN9lE+h\nxo+CkRZxd2Q03SB4d6dhXnEuX9CKVfAi3eYxfMuGMaGop97x9GBJACxDmxopoSId\n5BvUmbCOLSSKOvsIecP3C8es1biV9Ok9B7IHrlZczK/Kcfpgf/OZ37WAQUF5fxak\nne4v0OZShVM+WsOj0P7p7eGss3E0EoCrMHUO5VYVA5CzArD35sRFeFgdvGG51HdC\ntBqnwIITH5mZ9QuZpAQH5TDnlozoFFkboTVOlni4sptOVNEHGLtyqhNo+k+O9LA7\nWHM7vw+DAgMBAAECggEAAXPGDqLrU9gyAVpz3KYL3Q8BHzIHcitIEiTbbGIi0OOv\n5eR/c5EEJOcbTdOAmmvDBleEm2Xa+hSyi2PcQ83Jy+qHFq0AKMd1A4KhLEFe53P2\nXnr7SSzV8PHXf+a59y8nKXYP7SbOS6Kc7g530+lLxQlOJZh7zciX8T5jXCo7q7LU\nOVyLC2UcVZiN6gef0wdvl2RdKQcFaF5TBGTbo02A4Xt3sS6GQl5STvDYSiLMaIUi\nthErr/KHdCHED17qVF31DU18iMoD6w/ksoar4ysXfkNfbxKzX9+H43QvkG38ep6A\nPtBLbs++Qe7ANAOVJ/tPhf8pMCD4+oKsK+Ipuzqt2QKBgQDhM1t4q4cx3IhXar6X\n3a3epi/5IKNFZH81xa+UvJz5Zz/BpNz/Uo5PgvFiu0AWumeuX0zWq9NPAyZSEt+9\nwhCN7UbEkA/bCWrWFx0ut4uE03BGFvShhkHhVlcbF49HmufeCfUNjSTslCzAf6mK\nNkixQnUj9SrF8Wn1skDC7y+UxwKBgQC8jb9RCJCN7EjYyE4sl6xq9PSkdrxld4oa\nA6kA86Fq6vAZHhRHcZH54ZvYt4BRDaKZMDEATvyF1oSNzPDY8KUgooyp073gxs3a\nRMQntFfZwWU45px0tKnkr48PBjaDlNWKz8IsnaxRqdQMb0nwuZVHnqKx2AiB55Rr\nDS6GXVS7ZQKBgGQ8KbCSGEC3OfA+0MpjnuoE6kFmp4VRb9WNQdNgCDZyIEyehscW\nBcWaMLqTQblcCp3wSREbtZfrfPj28aNSZ2/kdqUywfvqOyVDcHfEtlLOkaCAwy3J\nxjT36xlh6SIj7qRDplD7y72JTkn4CIw+ESjkvaLdksY757+2MWESeQktAoGAeqtJ\ndaG50euQdSDT4yUGMkuNQdZRuT2tJkGNWSYntRSGAgFUtipICybhKnwvygux5jG5\nH3dDyJsIf+x+INVmyLWYCADOvob4c/FbIG2u3ed5QCygSzkicrpYuzCSlMZmqzmB\nHV+zNSnk3/YjR66lVQP62vMujb0pDQB1bUsZDhUCgYBkfHNq8xJxeZHUFtS/IyF7\nwvPYHsRNnm5XBTkl6pjA5/o3u9Ko97aNOgt+QA0QEVukxDWYcqtV8oXKN/gHlLNZ\nmPPQ4NpeN+fSPUxYPrT9d2VBTo2VUX3vd1wN6gOUImfoixOCLsRkIK4MdrB8LX9D\nRigo3bM7NmJKHjX8+za7Hg==\n-----END PRIVATE KEY-----\n";

// /* 3. Define the ID token for client or device to send the message */
// //Firebase_ESP_Client Firebase;
// String DEVICE_REGISTRATION_ID_TOKEN = "YkvdQ4ShfKQxacbFY4SHZjwsLzT2";

// /* 4. Define the Firebase Data object */
// FirebaseData fbdo;

// /* 5. Define the FirebaseAuth data for authentication data */
// FirebaseAuth auth;

// /* 6. Define the FirebaseConfig data for config data */
// FirebaseConfig config;

// unsigned long lastTime = 0;

// int count = 0;

// #if defined(ARDUINO_RASPBERRY_PI_PICO_W)
// WiFiMulti multi;
// #endif

// void sendMessage();

// void setup()
// {

//     Serial.begin(115200);

// #if defined(ARDUINO_RASPBERRY_PI_PICO_W)
//     multi.addAP(WIFI_SSID, WIFI_PASSWORD);
//     multi.run();
// #else
//     WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
// #endif

//     Serial.print("Connecting to Wi-Fi");
//     unsigned long ms = millis();
//     while (WiFi.status() != WL_CONNECTED)
//     {
//         Serial.print(".");
//         delay(300);
// #if defined(ARDUINO_RASPBERRY_PI_PICO_W)
//         if (millis() - ms > 10000)
//             break;
// #endif
//     }
//     Serial.println();
//     Serial.print("Connected with IP: ");
//     Serial.println(WiFi.localIP());
//     Serial.println();

//     Serial.printf("Firebase Client v%s\n\n", FIREBASE_CLIENT_VERSION);

   

//     /* Assign the sevice account credentials and private key (required) */
//     // config.service_account.data.client_email = FIREBASE_CLIENT_EMAIL;
//     // config.service_account.data.project_id = FIREBASE_PROJECT_ID;
//     //config.service_account.data.private_key = PRIVATE_KEY;
//     config.api_key = API_KEY;

//     auth.user.email = "nathan.anthony49@gmail.com"  ;
//     auth.user.password = "Godisgood11";

//     //config.database_url = resource;
//     // auth.token.uid = DEVICE_REGISTRATION_ID_TOKEN;
//     config.database_url = resource;
//     config.token_status_callback = tokenStatusCallback;
//     /* Assign the callback function for the long running token generation task */

//     /** Assign the maximum retry of token generation */
//     config.max_token_generation_retry = 5;
//     config.signer.test_mode = true;
 


//     // The WiFi credentials are required for Pico W
//     // due to it does not have reconnect feature.
// #if defined(ARDUINO_RASPBERRY_PI_PICO_W)
//     config.wifi.clearAP();
//     config.wifi.addAP(WIFI_SSID, WIFI_PASSWORD);
// #endif

//     /* Assign the callback function for the long running token generation task */
//     config.token_status_callback = tokenStatusCallback; // see addons/TokenHelper.h

//     // Comment or pass false value when WiFi reconnection will control by your code or third party library e.g. WiFiManager
//     Firebase.reconnectNetwork(true);

//     // Since v4.4.x, BearSSL engine was used, the SSL buffer need to be set.
//     // Large data transmission may require larger RX buffer, otherwise connection issue or data read time out can be occurred.
//     fbdo.setBSSLBufferSize(4096 /* Rx buffer size in bytes from 512 - 16384 */, 1024 /* Tx buffer size in bytes from 512 - 16384 */);
//     // Firebase.signUp(&config, &auth, , "");
//     // Serial.println("Signed up");
//     Firebase.begin(&config, &auth);
//     Serial.println("Firebase begin");
// }

// void loop()
// {

  
//   if(Firebase.authenticated()){
//     Serial.println("I am authenticated");
//   } else {
//     Serial.println("Well I AM NOT???");
//   }

//     // Firebase.ready() should be called repeatedly to handle authentication tasks.

//     if (Firebase.ready() && (millis() - lastTime > 5 * 1000 || lastTime == 0))
//     {
//       if (Firebase.RTDB.setInt(&fbdo, "/heart_risk/session/heart_rate", count)){
//         Serial.println("PASSED");
//       }
//     else {
//       Serial.println("FAILED");
//     }
//       count++;
//       //lastTime = millis();

//         //sendMessage();
//     }
// }

// void sendMessage()
// {

//     Serial.print("Send Firebase Cloud Messaging... ");

//     // Read more details about HTTP v1 API here https://firebase.google.com/docs/reference/fcm/rest/v1/projects.messages
//     FCM_HTTPv1_JSON_Message msg;

//     msg.token = DEVICE_REGISTRATION_ID_TOKEN;
//     msg.notification.body = "Notification body";
//     msg.notification.title = "Notification title";

//     // For the usage of FirebaseJson, see examples/FirebaseJson/BasicUsage/Create.ino
//     FirebaseJson payload;

//     // all data key-values should be string
//     payload.add("temp", "28");
//     payload.add("unit", "celsius");
//     payload.add("timestamp", "1609815454");
//     msg.data = payload.raw();

//     if (Firebase.RTDB.pushJSON(&fbdo, "/heart_risk/session/heart_rate", &payload)) // send message to recipient
//         Serial.printf("ok\n%s\n\n", Firebase.RTDB.get(&fbdo, "/heart_risk/session/heart_rate"));
//     else
//         Serial.println(fbdo.errorReason());

//     count++;
// }


// // // // #include "Arduino.h"
// // // // #include <WiFi.h>
// // // // #include <HTTPClient.h>
// // // // #include <ArduinoJson.h> // For handling JSON data

// // // // const char* ssid = "SimonD@19";
// // // // const char* password = "Kowsilla$55$66";
// // // // const char* server_token = "YOUR_FCM_SERVER_TOKEN"; // From Firebase project settings
// // // // const char* registration_token = "YOUR_DEVICE_REGISTRATION_TOKEN"; // From your app
// // // // const char* fcm_url = "https://fcm.googleapis.com/fcm/send";

// // // // /* 1. Define the WiFi credentials */
// // // // // #define WIFI_SSID "WIFI_AP"
// // // // // #define WIFI_PASSWORD "WIFI_PASSWORD"
// // // // #define WIFI_SSID "SimonD@19"
// // // // #define WIFI_PASSWORD "Kowsilla$55$66"

// // // // // // /** 2. Define the Service Account credentials (required for token generation)
// // // // // //  *
// // // // // //  * This information can be taken from the service account JSON file.
// // // // // //  *
// // // // // //  * To download service account file, from the Firebase console, goto project settings,
// // // // // //  * select "Service accounts" tab and click at "Generate new private key" button
// // // // // //  * 
// // // // // //  * 
// // // // // //  */

// // // // // #define resource "https://beatai-bc460-default-rtdb.firebaseio.com"
// // // // // #define API_KEY "AIzaSyCOQ4BxYrVS5wCLf5K8o_uAzmC-RcRbsWI"
// // // // #define FIREBASE_CLIENT_EMAIL "dlbalzora@gmail.com"
// // // // #define FIREBASE_PROJECT_ID "beatai-bc460"
// // // // #define DEVICE_REGISTRATION_ID_TOKEN "816230794155"

// // // // #define FIREBASE_PROJECT_ID "beatai-bc460"
// // // // #define FIREBASE_CLIENT_EMAIL "firebase-adminsdk-fbsvc@beatai-bc460.iam.gserviceaccount.com"
// // // // const char PRIVATE_KEY[] PROGMEM = "-----BEGIN PRIVATE KEY-----\nMIIEvAIBADANBgkqhkiG9w0BAQEFAASCBKYwggSiAgEAAoIBAQCl3mjCmXV/1Oyd\nP6Commra0k5BHaSJ6rEh4AqMEo85mWFXLPJgZfMdYRW9+Q2eMEste0rqWFN9lE+h\nxo+CkRZxd2Q03SB4d6dhXnEuX9CKVfAi3eYxfMuGMaGop97x9GBJACxDmxopoSId\n5BvUmbCOLSSKOvsIecP3C8es1biV9Ok9B7IHrlZczK/Kcfpgf/OZ37WAQUF5fxak\nne4v0OZShVM+WsOj0P7p7eGss3E0EoCrMHUO5VYVA5CzArD35sRFeFgdvGG51HdC\ntBqnwIITH5mZ9QuZpAQH5TDnlozoFFkboTVOlni4sptOVNEHGLtyqhNo+k+O9LA7\nWHM7vw+DAgMBAAECggEAAXPGDqLrU9gyAVpz3KYL3Q8BHzIHcitIEiTbbGIi0OOv\n5eR/c5EEJOcbTdOAmmvDBleEm2Xa+hSyi2PcQ83Jy+qHFq0AKMd1A4KhLEFe53P2\nXnr7SSzV8PHXf+a59y8nKXYP7SbOS6Kc7g530+lLxQlOJZh7zciX8T5jXCo7q7LU\nOVyLC2UcVZiN6gef0wdvl2RdKQcFaF5TBGTbo02A4Xt3sS6GQl5STvDYSiLMaIUi\nthErr/KHdCHED17qVF31DU18iMoD6w/ksoar4ysXfkNfbxKzX9+H43QvkG38ep6A\nPtBLbs++Qe7ANAOVJ/tPhf8pMCD4+oKsK+Ipuzqt2QKBgQDhM1t4q4cx3IhXar6X\n3a3epi/5IKNFZH81xa+UvJz5Zz/BpNz/Uo5PgvFiu0AWumeuX0zWq9NPAyZSEt+9\nwhCN7UbEkA/bCWrWFx0ut4uE03BGFvShhkHhVlcbF49HmufeCfUNjSTslCzAf6mK\nNkixQnUj9SrF8Wn1skDC7y+UxwKBgQC8jb9RCJCN7EjYyE4sl6xq9PSkdrxld4oa\nA6kA86Fq6vAZHhRHcZH54ZvYt4BRDaKZMDEATvyF1oSNzPDY8KUgooyp073gxs3a\nRMQntFfZwWU45px0tKnkr48PBjaDlNWKz8IsnaxRqdQMb0nwuZVHnqKx2AiB55Rr\nDS6GXVS7ZQKBgGQ8KbCSGEC3OfA+0MpjnuoE6kFmp4VRb9WNQdNgCDZyIEyehscW\nBcWaMLqTQblcCp3wSREbtZfrfPj28aNSZ2/kdqUywfvqOyVDcHfEtlLOkaCAwy3J\nxjT36xlh6SIj7qRDplD7y72JTkn4CIw+ESjkvaLdksY757+2MWESeQktAoGAeqtJ\ndaG50euQdSDT4yUGMkuNQdZRuT2tJkGNWSYntRSGAgFUtipICybhKnwvygux5jG5\nH3dDyJsIf+x+INVmyLWYCADOvob4c/FbIG2u3ed5QCygSzkicrpYuzCSlMZmqzmB\nHV+zNSnk3/YjR66lVQP62vMujb0pDQB1bUsZDhUCgYBkfHNq8xJxeZHUFtS/IyF7\nwvPYHsRNnm5XBTkl6pjA5/o3u9Ko97aNOgt+QA0QEVukxDWYcqtV8oXKN/gHlLNZ\nmPPQ4NpeN+fSPUxYPrT9d2VBTo2VUX3vd1wN6gOUImfoixOCLsRkIK4MdrB8LX9D\nRigo3bM7NmJKHjX8+za7Hg==\n-----END PRIVATE KEY-----\n";

// // // // /* 3. Define the ID token for client or device to send the message */
// // // // String DEVICE_REGISTRATION_ID_TOKEN = Firebase.getToken();