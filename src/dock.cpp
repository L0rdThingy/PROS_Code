#include "main.h"

#define DIGITAL_SENSOR_PORT 'F'


pros::ADIDigitalOut dock (DIGITAL_SENSOR_PORT);


// dock driver control variables
bool dock_up = true;
int dock_lock = 0;



void
dock_clamp (bool hold) {
// sets the dock position to clamp a mogo
  dock.set_value(OPEN);

  if (hold) {
    dock_up = true;
  }
}




void
dock_open (bool hold){
// sets the dock position to release mogo
  dock.set_value(CLOSE);

  if (hold) {
    dock_up = false;
  }
}





void
dock_control() {
  // Toggle for the dock
  if (master.get_digital(DIGITAL_Y) && dock_lock==0) {
    dock_up = !dock_up;
      dock_lock = 1;
  }
  else if (!master.get_digital(DIGITAL_Y)) {
    dock_lock = 0;
  }
    if(dock_up)
      dock_clamp();
    else
      dock_open();
}
