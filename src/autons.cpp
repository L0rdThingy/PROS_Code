#include "main.h"

const int DRIVE_SPEED = 110; // This is 110/127 (around 87% of max speed).  We don't suggest making this 127.
                             // If this is 127 and the robot tries ot heading correct, it's only correcting by
                             // making one side slower.  When this is 87%, it's correcting by making one side
                             // faster and one side slower, giving better heading correction.
const int TURN_SPEED  = 90;
const int SWING_SPEED = 90;

///
// Constants
///

// Reset all constants to default (what's in setup.hpp is default)
void
reset_constants() {
  reset_slew_min_power();
  reset_slew_distance();
  reset_fw_drive_constants();
  reset_bw_drive_constants();
  reset_turn_constants();
  reset_turn_i_constants();
  reset_swing_constants();
}

// Functions to change constants
// (if the robot has different weight to it, sometimes we need to change constants)
/*
void
one_mogo_constants() {
  set_slew_min_power(80, 80);
  set_slew_distance(7, 7);
  set_fw_drive_constants(0.45, 5);
  set_bw_drive_constants(0.375, 4);
  set_turn_constants(5, 0.003, 35);
  set_turn_i_constants(15, 30);
  set_swing_constants(12, 35);
}

void
two_mogo_constants() {
  set_slew_min_power(80, 80);
  set_slew_distance(7, 7);
  set_fw_drive_constants(0.45, 5);
  set_bw_drive_constants(0.375, 4);
  set_turn_constants(5, 0.003, 35);
  set_turn_i_constants(15, 30);
  set_swing_constants(12, 35);
}
*/



// All drive movements use the "set_drive_pid" function
// the first parameter is the type of motion (drive, turn, r_swing, l_swing)
// below are example codes using each type


///
// Drive Example
///
void
left_tree_40() {
  // The second parameter is target inches
  // The third parameter is max speed the robot will drive at
  // The fourth parameter is a boolean (true or false) for enabling/disabling a slew at the start of drive motions
  // for slew, only enable it when the drive distance is greater then the slew distance + a few inches



}



///
// Turn Example
///
void
right_tree_40() {
  // The second parameter is target degrees
  // The third parameter is max speed the robot will drive at



}



///
// Combining Turn + Drive
///
void
left_lwp_29() {

  set_drive_pid(drive, 48, DRIVE_SPEED, true);
  wait_drive();

  claw_clamp(true);

  set_drive_pid(drive, -24, DRIVE_SPEED);
    wait_drive();

set_drive_pid(turn, -90, DRIVE_SPEED);
  wait_until(-80);
claw_open(true);
  wait_drive();

  set_drive_pid(drive, -12, DRIVE_SPEED);
    wait_drive();

  set_drive_pid(l_swing, 90, TURN_SPEED);

}



///
// Wait Until and Changing Max Speed
///
void
right_rwp_41() {
  // wait_until will wait until the robot gets to a desired position


  set_drive_pid(drive, 41, DRIVE_SPEED);
    wait_until(40);
  claw_clamp(true);
    wait_drive();

  set_drive_pid(drive, -32, DRIVE_SPEED);
    wait_drive();

  claw_open(true);

  set_drive_pid(drive, -20, DRIVE_SPEED);
    wait_drive();

  set_drive_pid(drive, 10, DRIVE_SPEED);
    wait_drive();

  set_drive_pid(turn, 35, TURN_SPEED);
    wait_drive();

  set_drive_pid(drive, 15, DRIVE_SPEED);
    wait_until(13);
  set_max_speed(55);
    wait_drive();

  dock_open();

  set_drive_pid(drive, 10, DRIVE_SPEED);
    wait_drive();

  set_drive_pid(turn, 0, TURN_SPEED);
    wait_drive();

  set_drive_pid(drive, 30, DRIVE_SPEED);
    wait_until(20);
  set_conveyor(127);
  set_max_speed(55);
    wait_drive();

  set_drive_pid(drive, -40, DRIVE_SPEED);
    wait_drive();
    
}



///
// Swing Example
///
void
solo_wp() {
  // The second parameter is target degrees
  // The third parameter is speed of the moving side of the drive

  set_drive_pid(l_swing, 45, SWING_SPEED);
  wait_drive();

  set_drive_pid(drive, 24, DRIVE_SPEED, true);
  wait_until(12);

  set_drive_pid(r_swing, 0, SWING_SPEED);
  wait_drive();
}



///
// Auto that tests everything
///
void
test_auton() {
  set_drive_pid(drive, 24, DRIVE_SPEED, true);
  wait_drive();

  set_drive_pid(turn, 45, TURN_SPEED);
  wait_drive();

  set_drive_pid(r_swing, -45, TURN_SPEED);
  wait_drive();

  set_drive_pid(turn, 0, TURN_SPEED);
  wait_drive();

  set_drive_pid(drive, -24, DRIVE_SPEED, true);
  wait_drive();
}



void
auto_6() {

}



void
auto_7() {

}



void
auto_8() {

}



void
auto_9() {

}



void
auto_10() {

}
