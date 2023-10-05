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


bool calibrated = false;

Servo myservo;
Servo myserto;


void servomove(){
    //hvis lyset er sterkere over skal den bevege seg opp
    if((overstHoyre < nederstHoyre)&&(overstVenstre < nederstVenstre)&&(moveY < 180)){
        moveY++;
    }
        //hvis lyset er sterkere nederst skal den bevege seg ned
    if((overstHoyre > nederstHoyre)&&(overstVenstre > nederstVenstre)&&(moveY>0)){
        moveY--;
    }
        //hvis lyset er sterkere over skal den bevege seg opp
    if((overstHoyre > overstVenstre)&&(nederstHoyre > nederstVenstre)&&(moveX < 180)){
        moveX++;
    }
    if((overstHoyre < overstVenstre)&&(nederstHoyre < nederstVenstre)&&(moveX > 0)){
        moveX--;
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