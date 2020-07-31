
#include <Servo.h> 
#include <ESP8266WiFi.h>
 
const char* ssid = "SSID";//type your ssid
const char* password = "PASSWORD";//type your password
WiFiServer server(80);//Service Port
String data1=0; //for taking value of servo motor
String data2=0; //for taking value of angle at which it should be rotated
char ans=0;// for rotating again
char response=0;// for command the system that you want to rotatw the motor


int servoPin1 = 3;
int servoPin2 = 4;
int servoPin3 = 5;
int servoPin4 = 6;

Servo Servo1;
Servo Servo2;
Servo Servo3;
Servo Servo4;

void setup() {
  Serial.begin(115200);
  delay(10);
  // We need to attach the servo to the used pin number
  Servo1.attach(servoPin1);
  Servo2.attach(servoPin2);
  Servo3.attach(servoPin3);
  Servo4.attach(servoPin4);
  
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


void loop(){
  Serial.print("Type R to rotate the motor: ")
  response=Serial.read();
  Serial.println("/n");
  if(response=='R')
      {
       rotate(); 
      }
}

//function for rotating the servo motor
void rotate()
{
  //if voltage is HIGH
  if(Serial.available()>0)
  {
  Serial.print("Enter the servo motor you want to move: S1,S2,S3,S4:  ");
  data1 =Serial.read();
  Serial.println("/n");
  
  //for rotating servo motor 1
  if(data1 == "S1")
  {
    Serial.print("Angle at which you want to rotate S1:  ");
    data2 = Serial.read();
    Serial.println("/n");
    //for 0 degree rotation
    if(data2=="0")
       Servo1.write(0);
       
    if(data2=="45")
       Servo1.write(45);
       
    if(data2=="90")
       Servo1.write(90);
 
    if(data2=="135")
       Servo1.write(135);
       
    if(data2=="180")
       Servo1.write(180);
    }
    
    //for rotating servo motor 2
    if(data1 == "S2")
    {
    Serial.print("Angle at which you want to rotate S2:  ");
    data2=Serial.read();
    Serial.println("/n");
    //for 0 degree rotation
    if(data2=="0")
       Servo2.write(0);
        
    if(data2=="45")
       Servo2.write(45);
         
    if(data2=="90")
       Servo2.write(90);
        
    if(data2=="135")
       Servo2.write(135);
       
    if(data2=="180")
       Servo2.write(180);
    }
    //for rotating servo motor 3
    if(data1 == "S3")
    {
    Serial.print("Angle at which you want to rotate S3:  ");
    data2=Serial.read();
    Serial.println("/n");
    //for 0 degree rotation
    if(data2=="0")
       Servo3.write(0);
       
    if(data2=="45")
       Servo3.write(45);
       
    if(data2=="90")
       Servo3.write(90);
        
    if(data2=="135")
       Servo3.write(135);
       
    if(data2=="180")
       Servo3.write(180);
    }
    //for rotating servo motor 4
    if(data1 == "S4")
    {
    Serial.print("Angle at which you want to rotate S4: ");
    data2=Serial.read();
    Serial.println("/n");
    //for 0 degree rotation
    if(data2=="0")
       Servo4.write(0);
       
    if(data2=="45")
       Servo4.write(45);
       
    if(data2=="90")
       Servo4.write(90);
        
    if(data2=="135")
       Servo4.write(135);
        
    if(data2=="180")
      Servo4.write(180);  
  
    } 
    Serial.print("Do you want to rotate the motor?y/n: ");
    ans=Serial.read();
    Serial.println("/n");
    if(ans=='y')
    rotate(); 
  
  }
}
