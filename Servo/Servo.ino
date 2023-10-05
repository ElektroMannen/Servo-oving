#include <Servo.h>

int messurePin = A0;
int servoPin = 9;
int sertoPin = 10;
int topHoy = A0;
int topVen = A1;
int bunHoy = A2;
int bunVen = A3;

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


void readLight(){
    overstHoyre = analogRead(topHoy);
    overstVenstre = analogRead(topVen);
    nederstHoyre = analogRead(bunHoy);
    nederstVenstre = analogRead(bunVen);
}

void servomove(){
    //hvis lyset er sterkere over skal den bevege seg opp
    if((nederstVenstre + nederstHoyre > overstHoyre + overstVenstre)&&(moveY < 180)){
        moveY++;
    }
    //hvis lyset er sterkere nederst skal den bevege seg ned
    else if((overstHoyre + overstVenstre > nederstVenstre + nederstHoyre)&&(moveY > 0)){
        moveY--;
    }
    //hvis lyset er sterkere på høyre side skal den bevege seg til høyre
    else if((overstHoyre > overstVenstre)&&(nederstHoyre > nederstVenstre)&&(moveX < 180)){
        moveX++;
    }
    //hvis lyset er sterkere på venstre side skal den bevege seg til venstre
    else if((overstHoyre < overstVenstre)&&(nederstHoyre < nederstVenstre)&&(moveX > 0)){
        moveX--;
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
    myservo.attach(sertoPin);
}

void loop(){
    readLight();
    servomove();
    myservo.write(moveX);
    myserto.write(moveY);
}