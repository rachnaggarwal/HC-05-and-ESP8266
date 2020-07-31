#include <ESP8266WiFi.h>
 
const char* ssid = "SSID";//type your ssid
const char* password = "PASSWORD";//type your password

WiFiServer server(80);//Service Port
 
const int trigPin = 7;
const int echoPin = 6;
int data =0;
float duration, distance;

void setup() {
  pinMode(13, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
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
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration*.0343)/2;
  Serial.print("Distance: ");
  Serial.println(distance);
  if(Serial.available>0){
    Serial.print(" Enter the distance at which you want alarm to activate in cm: ");
    data = Serial.read();
    Serial.println();
    if(distance<=data){
    digitalWrite(13, HIGH);
    }else{
    digitalWrite(13,LOW);
   }
  }
}
