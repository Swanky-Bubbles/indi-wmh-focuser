#include "byj48motor.h"
#include <indi/indidevapi.h>
#include <indi/base/indicom.h>

BYJ48Motor motor(17,18,27,22); // GPIO pins example

void moveFocuserAbs(int target)
{
    motor.moveTo(target);
    // Use IUUpdateNumber for INDI 2.1.6+
    IUUpdateNumber(&FocusAbsPosNP, 0, motor.getPosition());
}

void moveFocuserRel(int steps)
{
    motor.step(steps);
    IUUpdateNumber(&FocusRelPosNP, 0, motor.getPosition());
}