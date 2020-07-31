
const int trigPin = 7;
const int echoPin = 6;
int data =0;
float duration, distance;

void setup() {
  pinMode(13, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
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
