#include "main.h"

#define DIGITAL_SENSOR_PORT 'H'


pros::ADIDigitalOut claw (DIGITAL_SENSOR_PORT);


// claw driver control variables
bool claw_up = false;
int claw_lock = 0;



void
claw_clamp (bool hold) {
// sets the claw to clamp a mogo
  claw.set_value(OPEN);

  if (hold) {
    claw_up = true;
  }
}




void
claw_open (bool hold){
// sets the claw to open
  claw.set_value(CLOSE);

  if (hold) {
    claw_up = false;
  }
}





void
claw_control() {
  // Toggle for the claw
  if (master.get_digital(DIGITAL_RIGHT) && claw_lock==0) {
    claw_up = !claw_up;
      claw_lock = 1;
  }
  else if (!master.get_digital(DIGITAL_RIGHT)) {
    claw_lock = 0;
  }
    if(claw_up)
      claw_clamp();
    else
      claw_open();
}
