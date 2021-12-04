#include "main.h"

pros::Motor lift(LIFT_PORT, MOTOR_GEARSET_36, true, MOTOR_ENCODER_DEGREES);

int output;

void
set_lift(int input) {
  output = input;
  lift.move_velocity(output);
}



void
set_lift_position(int input, int speed) {
  output = input;
  lift.move_relative(output, speed);
}



void
lift_control(){

 if (master.get_digital(DIGITAL_L1))
  set_lift(UP_LIFT_SPEED);

 else if (master.get_digital(DIGITAL_L2))
   set_lift(DOWN_LIFT_SPEED);

 else
  set_lift(0);

}

void lift_brake_type(){ lift.set_brake_mode(MOTOR_BRAKE_HOLD); }
