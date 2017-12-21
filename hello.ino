// newping.h is ultrasound sensor library
#include "NewPing.h"

// variable defination for ultrasound sensor
#define TRIGGER_PIN 10
#define ECHO_PIN 13
#define MAX_DISTANCE 400

// motor A
int in1 = 8;
int in2 = 7;

// motor B
int in3 = 5;
int in4 = 4;

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

float distance, duration;

int iterations = 10;

void scan() {
     
    duration = sonar.ping_median(iterations);

    distance = (duration / 2) * 0.0343;

    delay(200);

}

void moveforward (int t) {
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    delay(t);
}

void turnright (int t) {
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    delay(t);
}

void turnleft (int t) {
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    delay(t);
}

void stop (int t) {
    // motor control pins to LOW
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
    delay(t);
}


void setup() {

    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);
    pinMode(in3, OUTPUT);
    pinMode(in4, OUTPUT);

}

void loop() {
    
    scan();

    if (distance > 30)
    {
        moveforward(0);
        
    }
    else
    {

        stop(200);

        turnright(300);
        stop(100);
        scan();
        int d1 = distance;

        turnleft(600);
        stop(100);
        scan();
        int d2 = distance;

        if (d1 > d2)
        {
            turnright(600);
        }
        
    }
    moveforward(0);
    
}
