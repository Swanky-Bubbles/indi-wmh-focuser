#ifndef BYJ48MOTOR_H
#define BYJ48MOTOR_H

#include <chrono>
#include <thread>
#include <vector>

class BYJ48Motor {
public:
    BYJ48Motor(int pin1, int pin2, int pin3, int pin4);
    void step(int steps);
    void moveTo(int position);
    int getPosition() const;

private:
    void singleStep(int stepIndex);
    int pins[4];
    int currentStep;
    int position;
    int stepsPerRev;
    int stepDelayMs;
    std::vector<std::vector<int>> stepSequence;
};

#endif
