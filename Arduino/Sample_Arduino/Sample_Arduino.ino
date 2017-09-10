/*
CODE HERE
Array of HC-SR04 ultrasonic sensors
*/


//Sonar 1
int echoPin1 =12;
int initPin1 =11;
int distance1 =0;

//Sonar 2
int echoPin2 =2;
int initPin2 =3;
int distance2 =0;

//Sonar 3
int echoPin3 =4;
int initPin3 =5;
int distance3 =0;

//Sonar 4
int echoPin4 =7;
int initPin4 =6;
int distance4 =0;

//Sonor 5
int echoPin5 = 9;
int initPin5 = 8;
int distance5 =0;

//Sonor 6
int echoPin6 = 11;
int initPin6 = 10;
int distance6 =0;
 

void setup() {
  
  pinMode(initPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(initPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(initPin3, OUTPUT);
  pinMode(echoPin3, INPUT);
  pinMode(initPin4, OUTPUT);
  pinMode(echoPin4, INPUT);
  pinMode(initPin5, OUTPUT);
  pinMode(echoPin5, INPUT);
  pinMode(initPin6, OUTPUT);
  pinMode(echoPin6, INPUT);
  Serial.begin(9600);
  
}

void loop() {
  
  distance1 = getDistance(initPin1, echoPin1);
  printDistance(1, distance1);
  delay(150);
  
  distance2 = getDistance(initPin2, echoPin2);
  printDistance(2, distance2);
  delay(150);
  
  distance3 = getDistance(initPin3, echoPin3);
  printDistance(3, distance3);
  delay(150);
  
  distance4 = getDistance(initPin4, echoPin4);
  printDistance(4, distance4);

  delay(500);
  
  distance5 = getDistance(initPin5, echoPin5);
  printDistance(5, distance5);

  delay(500);
  
  distance6 = getDistance(initPin6, echoPin6);
  printDistance(6, distance6);

  delay(500);    
}

int getDistance (int initPin, int echoPin){

 digitalWrite(initPin, HIGH);
 delayMicroseconds(10); 
 digitalWrite(initPin, LOW); 
 unsigned long pulseTime = pulseIn(echoPin, HIGH); 
 int distance = pulseTime/58;
 return distance;
 
}

void printDistance(int id, int dist){
  Serial.print("Sensor");
  Serial.print(id);
  if (dist >= 120 || dist <= 0 ){
    Serial.println(":Out of range");
  }else {
    Serial.print(":");
    Serial.println(dist, DEC);
  }
}

