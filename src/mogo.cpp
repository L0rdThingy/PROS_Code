#include "main.h"

#define DIGITAL_SENSOR_PORT 'G'


pros::ADIDigitalOut mogo (DIGITAL_SENSOR_PORT);

// Small Four-Bar


// Mogo driver control variables
bool mogo_down = false;
int mogo_lock = 0;



void
mogo_out (bool hold) {
// sets the mogo position to out
  mogo.set_value(OPEN);

  if (hold) {
    mogo_down = true;
  }
}




void
mogo_in (bool hold){
// sets the mogo position to in
  mogo.set_value(CLOSE);

  if (hold) {
    mogo_down = false;
  }
}





void
mogo_control() {
  // Toggle for the Small Four-Bar
  if (master.get_digital(DIGITAL_DOWN) && mogo_lock==0) {
    mogo_down = !mogo_down;
      mogo_lock = 1;
  }
  else if (!master.get_digital(DIGITAL_DOWN)) {
    mogo_lock = 0;
  }
    if(mogo_down)
      mogo_out();
    else
      mogo_in();
}
