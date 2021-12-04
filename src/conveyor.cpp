
#include "main.h"

pros::Motor conveyor(CONVEYOR_PORT, false);


void
set_conveyor(int input)  {
conveyor = input;
}


///
// Driver Control
//  - when R1 is pressed, run the conveyor in
//  - when R2 is pressed, run the conveyor out
///
void
conveyor_control() {

  if (master.get_digital(DIGITAL_R1))
    set_conveyor(FWD_RING_SPEED);

  else if (master.get_digital(DIGITAL_R2))
    set_conveyor(REV_RING_SPEED);

  else
    set_conveyor(0);
}
