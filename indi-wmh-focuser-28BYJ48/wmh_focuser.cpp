#include "byj48motor.h"
#include <indi/indidevapi.h>
#include <indi/base/indicom.h>

// Replace existing INDI driver logic as needed
// Example: absolute/relative moves

BYJ48Motor motor(17,18,27,22); // GPIO pins example

void moveFocuserAbs(int target)
{
    motor.moveTo(target);
    IUUpdateNumber(nullptr, 0, motor.getPosition());
}

void moveFocuserRel(int steps)
{
    motor.step(steps);
    IUUpdateNumber(nullptr, 0, motor.getPosition());
}
