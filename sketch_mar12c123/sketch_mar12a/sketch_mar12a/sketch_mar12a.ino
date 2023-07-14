#include<Servo.h>
#include <SoftwareSerial.h>


// constants won't change
const int ENA_PIN = 7; // the Arduino pin connected to the EN1 pin L298N
const int IN1_PIN = 6; // the Arduino pin connected to the IN1 pin L298N
const int IN2_PIN = 5; // the Arduino pin connected to the IN2 pin L298N
const int ENB_PIN = 4;
int level = 700;
//SoftwareSerial BTSerial(0, 1);

//IR Sensor
const int signalPin = 10;
int signal;

//// Trigger Pin of Ultrasonic Sensor


// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pins as outputs.
  pinMode(ENA_PIN, OUTPUT);
  pinMode(IN1_PIN, OUTPUT);
  pinMode(IN2_PIN, OUTPUT);
  pinMode(ENB_PIN, OUTPUT);

  Serial.begin(9600);
  pinMode(signalPin, INPUT);

  Serial.begin(9600);
  //BTSerial.begin(9600);
  
}

// the loop function runs over and over again forever
void loop() {
    /*if (BTSerial.available()) {
     char c = BTSerial.read();
     Serial.write(c);
     }
   if (Serial.available()) {
     char c = Serial.read();
     BTSerial.write(c);
   }
   */
  // digitalWrite(IN1_PIN, HIGH); // control motor A spins clockwise
  // digitalWrite(IN2_PIN, HIGH);  // control motor A spins clockwise

  // for (int speed = 0; speed <= 255; speed++) {
  //   analogWrite(ENA_PIN, speed); // control the speed
  //   analogWrite(ENB_PIN, speed);
  //   delay(10);
  // }

  // delay(500); // rotate at maximum speed 1 seconds in in clockwise direction

  // change direction
//   digitalWrite(IN1_PIN, LOW);   // control motor A spins anti-clockwise
//   digitalWrite(IN2_PIN, LOW);  // control motor A spins anti-clockwise

//   delay(1000); // rotate at maximum speed 1 seconds in in anti-clockwise direction

//   for (int speed = 255; speed >= 0; speed--) {
//     analogWrite(ENA_PIN, speed); // control the speed
//     delay(10);
//   }

  // delay(1000); // stop motor 1 second

  signal = digitalRead(signalPin);
  
  Serial.print("digital is ");
  Serial.println(signal);
  digitalWrite(IN1_PIN, LOW); // control motor A spins clockwise
  digitalWrite(IN2_PIN, LOW);
  delay(500);

  if (signal == 0){//white
    digitalWrite(IN1_PIN, HIGH); // control motor A spins clockwise
    digitalWrite(IN2_PIN, LOW);

    for (int i = 0; i <= 3; i++) {
      analogWrite(ENA_PIN, 0.1); // control the speed
      // analogWrite(ENB_PIN, 0.5);
      delay(10);
    }
    for (int i = 0; i <= 0; i++) {
      // analogWrite(ENA_PIN, 0.5); // control the speed
      analogWrite(ENB_PIN, 0.3);
      delay(10);
    }
  }
  else {
    digitalWrite(IN1_PIN, LOW); // control motor A spins clockwise
    digitalWrite(IN2_PIN, HIGH);

    for (int i = 0; i <= 5; i++) {
      analogWrite(ENA_PIN, 0.1); // control the speed
      // analogWrite(ENB_PIN, 0.5);
      delay(10);
    }
    // for (int i = 0; i <= 250; i++) {
    //   // analogWrite(ENA_PIN, 0.5); // control the speed
    //   analogWrite(ENB_PIN, 0.5);
      // delay(5);
    // }
  }
  // if(signal == 1){
  //   digitalWrite(IN1_PIN, HIGH); // control motor A spins clockwise
  //   digitalWrite(IN2_PIN, HIGH);  // control motor A spins clockwise

  //   // signal = digitalRead(signalPin);
  
  //   // Serial.print("digital is ");
  //   // Serial.println(signal);
  //   // delay(100);

  //   for (int i = 0; i <= 50; i++) {
  //     analogWrite(ENA_PIN, 0.5); // control the speed
  //     analogWrite(ENB_PIN, 0.5);
  //     delay(5);
  //   }

  //   delay(5);
  // }
  // else{
  //   digitalWrite(IN1_PIN, HIGH); // control motor A spins clockwise
  //   digitalWrite(IN2_PIN, HIGH);  // control motor A spins clockwise

  //   // signal = digitalRead(signalPin);
  
  //   // Serial.print("digital is ");
  //   // Serial.println(signal);
  //   // delay(100);

  //   for (int i = 0; i <= 100; i++) {
  //     analogWrite(ENA_PIN, 0.5); // control the speed
  //     // analogWrite(ENB_PIN, 0.1);
  //     delay(5);
  //     int signal_1 = digitalRead(signalPin);
  //     if(signal_1 == 1){
  //       break;
  //     }
  //   }
  //   for (int i = 0; i <= 200; i++) {
  //     // analogWrite(ENA_PIN, 0.5); // control the speed
  //     analogWrite(ENB_PIN, 0.5);
  //     delay(5);
  //     int signal_1 = digitalRead(signalPin);
  //     if(signal_1 == 1){
  //       break;
  //     }
  //   }
  //   delay(5);

    
  
}