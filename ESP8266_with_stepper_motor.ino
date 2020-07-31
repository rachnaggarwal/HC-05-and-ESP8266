/* Stepper Motor Control */

#include <Stepper.h>
#include <ESP8266WiFi.h>
 
const char* ssid = "SSID";//type your ssid
const char* password = "PASSWORD";//type your password
WiFiServer server(80);//Service Port

const int stepsPerRevolution = 90;
char data =0;
// change this to fit the number of steps per revolution
// for your motor
// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);

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
  
   // set the speed at 60 rpm:
   myStepper.setSpeed(5);
   // initialize the serial port:
   Serial.begin(9600);
}

void loop() {
   // step one revolution in one direction:
   if(Serial.available() > 0)
   {
    Serial.print("Enter C to rotate clockwise , A to rotate anticlockwise: ");
    data=Serial.read();
    Serial.println("/n");
     if (data =='C'){
     Serial.println("clockwise");
     myStepper.step(stepsPerRevolution);
     delay(500);
     }
     if (data=='A'){
     Serial.println("counterclockwise");
     myStepper.step(-stepsPerRevolution);
     delay(500);
     }
   }
}
