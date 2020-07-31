
//  Include following libraries to access IR sensor
#include <IRremote.h>
#include <IRremoteInt.h>
#include <ESP8266WiFi.h>
 
const char* ssid = "SSID";//type your ssid
const char* password = "PASSWORD";//type your password

WiFiServer server(80);//Service Port
 

int RECV_PIN = 13;          //  The digital pin that the signal pin of the sensor is connected to
IRrecv receiver(RECV_PIN);  //  Create a new receiver object that would decode signals to key codes
decode_results results;     //  A varuable that would be used by receiver to put the key code into

void setup() {
  Serial.begin(115200);
  delay(10);
 
    // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
   
  WiFi.begin(ssid, password);
   
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
   
  // Start the server
  server.begin();
  Serial.println("Server started");
 
  // Print the IP address
  Serial.print("Use this URL to connect: ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");
  //  Setup serial port to send key codes to computer
  receiver.enableIRIn();    //  Enable receiver so that it would start processing infrared signals
}

void loop() {
  
  if(receiver.decode(&results)) {             //  Decode the button code and put it in "results" variable
    Serial.println(results.value, HEX);       //  Print the code as a hexadecimal value
    receiver.resume();                        //  Continue listening for new signals
  }
}
