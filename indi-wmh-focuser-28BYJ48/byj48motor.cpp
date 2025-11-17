#include "byj48motor.h"
#include <wiringPi.h>
#include <iostream>

BYJ48Motor::BYJ48Motor(int pin1_, int pin2_, int pin3_, int pin4_)
{
    pins[0] = pin1_;
    pins[1] = pin2_;
    pins[2] = pin3_;
    pins[3] = pin4_;

    wiringPiSetupGpio();
    for (int i = 0; i < 4; i++) {
        pinMode(pins[i], OUTPUT);
        digitalWrite(pins[i], 0);
    }

    currentStep = 0;
    position = 0;
    stepsPerRev = 2048;
    stepDelayMs = 5;

    stepSequence = {
        {1,0,0,0},
        {1,1,0,0},
        {0,1,0,0},
        {0,1,1,0},
        {0,0,1,0},
        {0,0,1,1},
        {0,0,0,1},
        {1,0,0,1}
    };
}

void BYJ48Motor::singleStep(int stepIndex)
{
    for (int i = 0; i < 4; i++)
        digitalWrite(pins[i], stepSequence[stepIndex][i]);
    std::this_thread::sleep_for(std::chrono::milliseconds(stepDelayMs));
}

void BYJ48Motor::step(int steps)
{
    int direction = (steps > 0) ? 1 : -1;
    steps = abs(steps);
    for (int i = 0; i < steps; i++) {
        currentStep = (currentStep + direction + 8) % 8;
        position += direction;
        singleStep(currentStep);
    }
}

void BYJ48Motor::moveTo(int pos)
{
    int diff = pos - position;
    step(diff);
}

int BYJ48Motor::getPosition() const
{
    return position;
}
