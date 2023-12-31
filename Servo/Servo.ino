#include <Servo.h>

int messurePin = A0;
int servoPin = 9;
int sertoPin = 11;
int topHoy = A0;
int topVen = A1;
int bunHoy = A2;
int bunVen = A3;

int moveX = 90;
int moveY = 90;

// Lys sensor variabler er sett bakfra
int overstVenstre;
int overstHoyre;
int nederstVenstre;
int nederstHoyre;


bool calibrated = false;

Servo myservo;
Servo myserto;

//Leser lys sensorene
void readLight(){
    overstHoyre = analogRead(topHoy);
    overstVenstre = analogRead(topVen);
    nederstHoyre = analogRead(bunHoy);
    nederstVenstre = analogRead(bunVen);
}

//Bestemmer hvor/ hvor mye servoen skal flytte
void servomove(){
    //hvis lyset er sterkere over skal den bevege seg opp
    if((nederstVenstre + nederstHoyre >= overstHoyre + overstVenstre)&&(moveY < 180)){
        moveY++;
    }
    //hvis lyset er sterkere nederst skal den bevege seg ned
    else if((overstHoyre + overstVenstre >= nederstVenstre + nederstHoyre)&&(moveY > 0)){
        moveY--;
    }
    //hvis lyset er sterkere på høyre side skal den bevege seg til høyre
    else if(((overstHoyre + nederstHoyre <= nederstVenstre + overstVenstre)&&(moveX > 0))){
        moveX--;
    }
    //hvis lyset er sterkere på venstre side skal den bevege seg til venstre
    else if((overstHoyre + nederstHoyre >= nederstVenstre + overstVenstre)&&(moveX < 180)){
        moveX++;
    }
}
void setup(){
    pinMode(messurePin,INPUT);
    pinMode(topHoy,INPUT);
    pinMode(topVen,INPUT);
    pinMode(bunHoy, INPUT);
    pinMode(bunVen,INPUT);
    Serial.begin(9600);
    myservo.attach(servoPin);
    myserto.attach(sertoPin);
}

void loop(){
    readLight();
    servomove();
    //Beveger servo
    myservo.write(moveY);
    myserto.write(moveX);
}