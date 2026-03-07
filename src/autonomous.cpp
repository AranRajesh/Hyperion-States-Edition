#include "autonomous.h"
#include "globals.h"


// Write your autonomous routines here




void pidTune() {
    chassis.setPose(0,0,0);
    wingDescore.set_value(true);
    chassis.moveToPoint(2, 30, 3000, {.maxSpeed = 80});
    chassis.waitUntilDone();
    matchLoader.set_value(true);
    intakeMotor.move_voltage(12000);
    chassis.turnToHeading(270, 4000, {.maxSpeed = 90, .earlyExitRange = 0.5});
    chassis.moveToPoint(-3.5, 29 ,2000, {.maxSpeed = 70, .minSpeed = 65});
    chassis.waitUntilDone();
    intakeMotor.move_voltage(12000);
    chassis.tank(-30, -30);
    pros::delay(100);
    chassis.tank(25, 25);
    pros::delay(250);
    hoodMotor.move(0);
    chassis.tank(-15, -15); //matchloader 1
    pros::delay(150);
    chassis.tank(20, 20);
    pros::delay(400);
    chassis.tank(-15, -15);
    pros::delay(100);
    chassis.tank(20, 20);
    pros::delay(500);
    chassis.tank(-10, -10);
    pros::delay(150);
    pros::delay(500);
    chassis.tank(-10, -10);
    pros::delay(150);
    chassis.tank(15, 15);
    pros::delay(800);
    chassis.tank(0, 0);
    chassis.moveToPoint(15, 19.25, 2500, {.forwards = false});
    chassis.waitUntilDone();
    chassis.moveToPoint(95, 19.25, 4000, {.forwards = false, .minSpeed = 127, .earlyExitRange = 1});
    matchLoader.set_value(true);
    chassis.moveToPoint(95, 36, 4000, {.forwards = false}); //move to the goal and align
    chassis.turnToHeading(90, 2000);
    chassis.moveToPoint(80, 36, 1000, {.forwards = false});
    chassis.waitUntilDone();
    chassis.tank(80, 80);
    pros::delay(150);
    chassis.tank(0,0);
    pros::delay(50);
    chassis.tank(-127, -127);
    pros::delay(300);
    chassis.tank(-20, -20);
    intakeMotor.move(-127);
    hoodMotor.move(-127);
    pros::delay(25);
    intakeMotor.move(-127);
    pros::delay(200);
    intakeMotor.move_voltage(12000);
    hoodMotor.move(127);
    pros::delay(3500);
    chassis.waitUntilDone();
    chassis.tank(0, 0);
    chassis.cancelAllMotions();
    chassis.waitUntilDone();
    chassis.setPose(0,0,0);
    matchLoader.set_value(true);
    chassis.moveToPoint(0, 31, 3000, {.maxSpeed = 80}); //go to second matchloader
    chassis.waitUntilDone();
    intakeMotor.move_voltage(12000);
    chassis.tank(-30, -30);
    pros::delay(100);
    chassis.tank(25, 25);
    pros::delay(250);
    hoodMotor.move(0);
    chassis.tank(-15, -15); //matchloader 1
    pros::delay(150);
    chassis.tank(20, 20);
    pros::delay(400);
    chassis.tank(-15, -15);
    pros::delay(100);
    chassis.tank(20, 20);
    chassis.tank(20, 20);
    pros::delay(500);
    chassis.tank(-10, -10);
    pros::delay(150);
    pros::delay(500);
    chassis.tank(-10, -10);
    pros::delay(150);
    chassis.tank(15, 15);
    pros::delay(700);
    chassis.tank(10,10);
    pros::delay(800);
    chassis.tank(0, 0);
    chassis.cancelAllMotions();
    chassis.cancelMotion();
    chassis.tank(0,0);
    chassis.moveToPoint(0, -2, 2500, {.forwards = false});
    chassis.waitUntilDone();
    chassis.tank(80, 80);
    pros::delay(150);
    chassis.tank(0,0);
    pros::delay(50);
    chassis.tank(-127, -127);
    pros::delay(100);
    intakeMotor.move_voltage(12000);
    hoodMotor.move(127);
    pros::delay(300);
    chassis.tank(-20, -20);
    
    pros::delay(3500);
    chassis.waitUntilDone();
    chassis.tank(0,0);
    chassis.cancelAllMotions();
    chassis.waitUntilDone();
    chassis.setPose(0,0,0);
    hoodMotor.move(0);
    chassis.moveToPoint(0, 10, 4000);

    matchLoader.set_value(false);
    chassis.turnToHeading( 90,4000);
    chassis.moveToPoint(18, -2, 5000, {.minSpeed = 15, .earlyExitRange = 2});
    chassis.moveToPoint(50, 13, 5000, {.minSpeed = 15, .earlyExitRange = 1});

    chassis.moveToPoint(100, 13, 5000);
    chassis.turnToHeading(0, 2000);
    intakeMotor.move_voltage(12000);
    chassis.moveToPoint(103, -11, 1450, {.forwards= false});
    chassis.waitUntilDone();
    hoodMotor.move(127);
    pros::delay(1750);
    hoodMotor.move(0);
    pros::delay(50);
    chassis.waitUntilDone();
    chassis.setPose(100, 0, chassis.getPose().theta);
    matchLoader.set_value(true);
    chassis.moveToPoint(100, 30.5, 3000, {.maxSpeed = 60});
    chassis.waitUntil(30);
    hoodMotor.move(0);
    chassis.waitUntilDone();
    chassis.tank(-30, -30);
    pros::delay(100);
    chassis.tank(25, 25);
    pros::delay(250);
    hoodMotor.move(0);
    chassis.tank(-15, -15); //matchloader 3
    pros::delay(150);
    chassis.tank(20, 20);
    pros::delay(400);
    chassis.tank(-15, -15);
    pros::delay(100);
    chassis.tank(20, 20);
    pros::delay(500);
    chassis.tank(-10, -10);
    chassis.tank(20, 20);
    pros::delay(500);
    chassis.tank(-10, -10);
    pros::delay(150);
    pros::delay(150);
    chassis.tank(15, 15);
    pros::delay(700);
    chassis.tank(10,10);
    pros::delay(800);
    chassis.tank(0, 0);
    chassis.moveToPoint(83, 9, 3000, {.forwards=false, .minSpeed = 80, .earlyExitRange = 2});
    intakeMotor.move_voltage(12000);
    chassis.turnToHeading(0, 2000);
    chassis.moveToPoint(84, -70, 5000, {.forwards = false, .earlyExitRange = 3});
    chassis.moveToPoint(104, -74, 3000, {.forwards = false, .earlyExitRange = 1});
    chassis.turnToHeading(180, 1500);
    chassis.moveToPoint(104, -56, 1500, {.forwards = false, .maxSpeed = 80}); // go to long goal 2
    chassis.waitUntilDone();
    chassis.tank(80, 80);
    pros::delay(150);
    chassis.tank(0,0);
    pros::delay(50);
    chassis.tank(-127, -127);
    pros::delay(300);
    chassis.tank(-20, -20);
    chassis.waitUntilDone();
    intakeMotor.move_voltage(12000);
    hoodMotor.move(127);
    pros::delay(3000);
    chassis.waitUntilDone();
    chassis.setPose(0,0,chassis.getPose().theta + 180);
    matchLoader.set_value(true);
    chassis.moveToPoint(1, 30, 3000);
    chassis.waitUntilDone();
    hoodMotor.move(0);
    chassis.tank(-30, -30);
    pros::delay(100);
    chassis.tank(25, 25);
    pros::delay(250);
    hoodMotor.move(0);
    chassis.tank(-15, -15); //matchloader 4
    pros::delay(150);
    chassis.tank(20, 20);
    pros::delay(400);
    chassis.tank(-15, -15);
    pros::delay(100);
    chassis.tank(20, 20);
    pros::delay(500);
    chassis.tank(-10, -10);
    pros::delay(150);
    chassis.tank(20, 20);
    pros::delay(500);
    chassis.tank(-10, -10);
    pros::delay(150);
    chassis.tank(15, 15);
    pros::delay(700);
    chassis.tank(0, 0);
    chassis.moveToPoint(0, 0, 2500, {.forwards = false});
    chassis.waitUntilDone();
    chassis.tank(-50, -50);
    intakeMotor.move_voltage(12000);
    hoodMotor.move(127);
    pros::delay(2700);
    chassis.tank(0,0);
    chassis.waitUntilDone();
    chassis.setPose(0,0,0);
    hoodMotor.move(0);
    wingDescore.set_value(true);
    intakeMotor.move_voltage(12000);
    matchLoader.set_value(false);
    matchLoader.set_value(false);
    chassis.moveToPoint(0,10, 2000, {.minSpeed = 92, .earlyExitRange = 5});
    chassis.moveToPoint(51, 10, 2500, {.earlyExitRange = 3});
    chassis.turnToHeading(180, 2000, {.minSpeed = 90});
    chassis.waitUntilDone();
    chassis.tank(-127, -127);
    pros::delay(3500);
    chassis.tank(0, 0);


}


void regLeft() {
    chassis.setPose(0, 0, 0);
    wingDescore.set_value(true);
    matchLoader.set_value(true);
    chassis.moveToPoint(-4, 31, 3000, {.maxSpeed = 100});
    chassis.waitUntilDone();
    intakeMotor.move(127);
    chassis.turnToHeading(90, 4000, {.earlyExitRange = 0.5});
    chassis.moveToPoint(5, 31 ,2000);
    chassis.waitUntilDone();
    intakeMotor.move(127);
    chassis.tank(-30, -30);
    pros::delay(50);
    chassis.tank(35, 35);
    pros::delay(180);
    hoodMotor.move(0);
    chassis.cancelAllMotions();
    chassis.tank(-40, -40); //matchloader 1
    pros::delay(70);
    chassis.tank(40, 40);
    pros::delay(100);
    chassis.tank(-40, -40);
    chassis.cancelAllMotions();
    chassis.cancelMotion();
    chassis.tank(0,0);
    chassis.moveToPoint(-28, 30,1600, {.forwards = false});
    matchLoader.set_value(false);
    chassis.waitUntilDone();
    intakeMotor.move(127);
    hoodMotor.move(127);
    pros::delay(2300);
    chassis.setPose(0,0,0);
    chassis.moveToPoint(0, 10, 2000, {.earlyExitRange=2});
    hoodMotor.move(0);
    chassis.moveToPoint(27, -2, 3000, {.earlyExitRange = 2});
    chassis.moveToPoint(29, -5, 2000, {.maxSpeed = 90});
    chassis.moveToPose(75, -3, 90, 3500);
    chassis.turnToHeading(45, 2000, {.earlyExitRange = 6});
    chassis.moveToPoint(67, -17, 2500, {.forwards = false});
    chassis.turnToHeading(45,2000);    
    // wingDescore.set_value(true);
    // chassis.moveToPoint(-2, 29, 3000, {.maxSpeed = 80});
    // chassis.waitUntilDone();
    // matchLoader.set_value(true);
    // intakeMotor.move(127);
    // chassis.turnToHeading(0, 4000, {.maxSpeed = 60});
    // chassis.moveToPoint(12, 28,2000, {.maxSpeed = 80});
    // chassis.waitUntilDone();
    // chassis.tank(-30, -30);
    // pros::delay(200);
    // chassis.tank(35, 35);
    // pros::delay(500);
    // chassis.waitUntilDone();
    // intakeMotor.move(127);
    // chassis.moveToPoint(-28, 33,1600, {.forwards = false, .maxSpeed = 80});
    // matchLoader.set_value(false);
    // chassis.waitUntilDone();
    // intakeMotor.move(-127);
    // hoodMotor.move(-127);
    // pros::delay(300);
    // intakeMotor.move(127);
    // hoodMotor.move(127);
    // pros::delay(2000);
    // chassis.setPose(0,0,0);
    // // END OF SCORING
    // intakeMotor.move(0);
    // chassis.moveToPoint(0, 17, 3000, {.forwards = true, .maxSpeed = 90});
    // chassis.turnToHeading(130, 3000, {.maxSpeed = 70});
    // hoodMotor.move(0);
    // intakeMotor.move(127);
    // chassis.moveToPoint(39, -17, 3000, {.maxSpeed = 70, .earlyExitRange = 6});
    // chassis.waitUntilDone();
    // intakeMotor.move(-127);
    // hoodMotor.move(-127);
    // chassis.tank(-40, 40);
    // pros::delay(80);
    // chassis.cancelAllMotions();
    // chassis.tank(40, -40);
    // pros::delay(80);
    // chassis.cancelAllMotions();
    // chassis.tank(-40, 40);
    // pros::delay(80);
    // chassis.cancelAllMotions();
    // chassis.tank(40, -40);
    // pros::delay(80);
    // chassis.cancelAllMotions();
    // chassis.tank(-40, 40);
    // pros::delay(80);
    // chassis.cancelAllMotions();
    // chassis.tank(40, -40);
    // pros::delay(80);
    // chassis.cancelAllMotions();
    // chassis.tank(-40, 40);
    // pros::delay(80);
    // chassis.tank(40, -40);
    // pros::delay(80);
    // chassis.cancelAllMotions();
    // chassis.tank(-40, 40);
    // pros::delay(80);
    // chassis.cancelAllMotions();
    // chassis.tank(40, -40);
    // pros::delay(80);
    // chassis.cancelAllMotions();
    // chassis.tank(-40, 40);
    // pros::delay(80);
    // chassis.tank(40, -40);
    // pros::delay(80);
    // chassis.cancelAllMotions();
    // chassis.tank(-40, 40);
    // pros::delay(80);
    // chassis.cancelAllMotions();
    // chassis.tank(40, -40);
    // pros::delay(80);
    // chassis.cancelAllMotions();
    // chassis.tank(-40, 40);
    // pros::delay(80);
    // chassis.cancelAllMotions();

    // chassis.moveToPoint(-8,26, 4000, {.forwards = false,.maxSpeed = 100});
    // chassis.turnToHeading(0, 4000);
}

void skillsPark() {
    // Your code here
    chassis.setPose(0,0,0);
    intakeMotor.move(-127);
    hoodMotor.move(-127);
    chassis.tank(127,127);
    pros::delay(2000);
    chassis.cancelAllMotions();
}

void wingRush() {
    // Your code here
    chassis.setPose(0, 0, 0);
    wingDescore.set_value(true);
    intakeMotor.move(127);
    chassis.moveToPoint(0, 29,2000, {.maxSpeed = 70});
    chassis.waitUntilDone();
    wingDescore.set_value(false);
    chassis.moveToPoint(0, 16, 4000, {.forwards = false});
    chassis.moveToPoint(-18, 24, 3000, {.forwards = false});
    chassis.moveToPoint(-20, 36, 3600, {.forwards = false});
    chassis.waitUntilDone();
    intakeMotor.move(127);
    hoodMotor.move(127);
    pros::delay(1900);
    intakeMotor.move(0);
    hoodMotor.move(0);
    chassis.setPose(0,0,0);
    chassis.moveToPoint(0, 14, 2000);
    chassis.turnToHeading(270, 2000);
    chassis.moveToPoint(10, 10, 800, {.forwards = false, .maxSpeed = 70, .earlyExitRange = 2});
    chassis.moveToPoint(16, -18, 1800, {.forwards = false, .maxSpeed = 80});
    pros::delay(1200);
    



}
