#include <Servo.h>

int messurePin = A0;
int servoPin = 9;
int sertoPin = 10;

int moveX;
int moveY;

// Lys sensor variabler er sett bakfra
int overstVenstre;
int overstHoyre;
int nederstVenstre;
int nederstHoyre;

int minPot = 0;
int maxLight = 1023;
int pot;
bool calibrated = false;

Servo myservo;
Servo myserto;


void servomove(){
    
    if((overstHoyre < nederstHoyre)&&(overstVenstre < nederstVenstre)){
        moveY++;
    }
}
void setup(){
    pinMode(messurePin,INPUT);
    Serial.begin(9600);
    myservo.attach(servoPin);
    myservo.attach(sertoPin);
}

void loop(){


}