#include "main.h"
#include "lemlib/api.hpp" // IWYU pragma: keep
#include "pros/imu.hpp"
#include "pros/rotation.hpp"
#include "autonomous.h"
#include "pros/rtos.hpp"
#include <cstddef>




// variable definitions
bool matchLoaderDown = false;
bool wingDescoreUp = false;
bool prevUpPressed = false;
bool prevR1Pressed = false;
bool prevAPressed = false;
bool middleGoalDown = false;
bool runAutonMode = false;
static volatile bool g_cancel = false;          // if true, active auton should bail

// helper macro used in the autonomous segments
#define CHECK_CANCEL() do { if (g_cancel) { chassis.cancelAllMotions(); return; } } while (0)






// Drivetrain configuration -----------------------------------------------------------------------


// drivetrain motor groups:
pros::MotorGroup leftMotors({-15, -20, -17}, pros::MotorGearset::blue); // left motors
pros::MotorGroup rightMotors({19, 12, 11}, pros::MotorGearset::blue); // right motors


// create the drivetrain object using the previously defined motors as well as other parameters:
lemlib::Drivetrain drivetrain(&leftMotors, &rightMotors, 13.25, lemlib::Omniwheel::NEW_275, 450, 5);



// Sensors/odom configuration ----------------------------------------------------------------------
pros::Imu inertialSensor(5); // define the inertial sensor on port 5



// tracking setup:
pros::Rotation trackingRotation(14); // define the rotation for the vertical tracking wheel, not reversed
lemlib::TrackingWheel verticalTrackingWheel(&trackingRotation, lemlib::Omniwheel::NEW_2, 0); // create the lemlib tracking wheel object with offset/wheel size


lemlib::OdomSensors sensors(&verticalTrackingWheel, // vertical tracking wheel 1, set to null
                            nullptr, // vertical tracking wheel 2, set to nullptr as we are using IMEs
                            nullptr, // horizontal tracking wheel 1
                            nullptr, // horizontal tracking wheel 2, set to nullptr as we don't have a second one
                            &inertialSensor // inertial sensor
);



// PID ---------------------------------------------------------------------------------------------
lemlib::ControllerSettings lateral_controller(11.5, 0, 44, 3, 1, 100, 3, 500, 20);
lemlib::ControllerSettings angular_controller(7, 0, 65, 3, 0.5, 250, 3, 500, 0);


// CREATE THE CHASSIS:
lemlib::Chassis chassis(drivetrain, lateral_controller, angular_controller, sensors);




// Scoring/game setup ------------------------------------------------------------------------------
pros::Controller controller(pros::E_CONTROLLER_MASTER); //define controller
pros::Motor intakeMotor(13, pros::v5::MotorGears::blue);
pros::Motor hoodMotor(18, pros::v5::MotorGears::blue);
pros::adi::DigitalOut matchLoader ('G');
pros::adi::DigitalOut wingDescore ('H');
pros::adi::DigitalOut middleGoal ('F');



// exponential joystick/joystick values
// input curve for throttle input during driver control
lemlib::ExpoDriveCurve throttle_curve(3, // joystick deadband out of 127
                                     10, // minimum output where drivetrain will move out of 127
                                     1.055    // expo curve gain
);


// input curve for steer input during driver control
lemlib::ExpoDriveCurve steer_curve(3, // joystick deadband out of 127
                                  10, // minimum output where drivetrain will move out of 127
                                  1.07 // expo curve gain
);



// task function to display pose
void poseDisplayTask(void*) {
    while (true) {
        lemlib::Pose pose = chassis.getPose(); // x, y in inches, theta in degrees (by default)


        pros::lcd::print(0, "X: %.2f", pose.x);
        pros::lcd::print(1, "Y: %.2f", pose.y);
        pros::lcd::print(2, "Theta: %.2f", pose.theta);


        pros::delay(50); // 20 Hz update
    }
}


void firstMatchloader(){
    chassis.setPose(0,0,0);
    matchLoader.set_value(true);
    chassis.moveToPoint(-0.3, 30.5, 3000, {}, true); //go to second matchloader async
    while (chassis.isInMotion() && !g_cancel) pros::delay(10);
    CHECK_CANCEL();
    intakeMotor.move(127);
    chassis.tank(-30, -30);
    pros::delay(50);
    CHECK_CANCEL();
    chassis.tank(35, 35);
    pros::delay(180);
    CHECK_CANCEL();
    hoodMotor.move(0);
    chassis.cancelAllMotions();
    chassis.tank(-40, -40);
    pros::delay(80);
    CHECK_CANCEL();
    chassis.tank(40, 40);
    pros::delay(100);
    CHECK_CANCEL();
    chassis.tank(-40, -40);
    pros::delay(80);
    CHECK_CANCEL();
    chassis.tank(40, 40);
    pros::delay(100);
    CHECK_CANCEL();
    chassis.tank(-40, -40);
    pros::delay(80);
    CHECK_CANCEL();
    chassis.tank(40, 40);
    pros::delay(100);
    CHECK_CANCEL();
    chassis.tank(-40, -40);
    pros::delay(80);
    CHECK_CANCEL();
    chassis.tank(40, 40); //matchloader 2 
    pros::delay(100);
    CHECK_CANCEL();
    chassis.tank(-40, -40);
    pros::delay(80);
    CHECK_CANCEL();
    chassis.tank(40, 40);
    pros::delay(100);
    CHECK_CANCEL();
    chassis.tank(-40, -40);
    pros::delay(80);
    CHECK_CANCEL();
    chassis.tank(40, 40);
    pros::delay(100);
    CHECK_CANCEL();
    chassis.cancelAllMotions();
    chassis.cancelMotion();
    chassis.tank(0,0);
    // chassis.setPose(0,0,0);
    // wingDescore.set_value(true);
    // chassis.moveToPoint(2, 30, 3000, {.maxSpeed = 80}, true); // async movement
    // while (chassis.isInMotion() && !g_cancel) pros::delay(10);
    // CHECK_CANCEL();
    // matchLoader.set_value(true);
    // intakeMotor.move(127);
    // chassis.turnToHeading(270, 4000, {.maxSpeed = 90, .earlyExitRange = 0.5}, true);
    // while (chassis.isInMotion() && !g_cancel) pros::delay(10);
    // CHECK_CANCEL();
    // chassis.moveToPoint(-3, 29 ,2000, {.maxSpeed = 80}, true);
    // while (chassis.isInMotion() && !g_cancel) pros::delay(10);
    // CHECK_CANCEL();
    // intakeMotor.move(127);
    // chassis.tank(-30, -30);
    // pros::delay(50);
    // CHECK_CANCEL();
    // chassis.tank(35, 35);
    // pros::delay(180);
    // CHECK_CANCEL();
    // hoodMotor.move(0);
    // chassis.cancelAllMotions();
    // chassis.tank(-40, -40); //matchloader 1
    // pros::delay(70);
    // CHECK_CANCEL();
    // chassis.tank(40, 40);
    // pros::delay(100);
    // CHECK_CANCEL();
    // chassis.tank(-40, -40);
    // pros::delay(70);
    // CHECK_CANCEL();
    // chassis.tank(40, 40);
    // pros::delay(100);
    // CHECK_CANCEL();
    // chassis.tank(-40, -40);
    // pros::delay(70);
    // CHECK_CANCEL();
    // chassis.tank(40, 40);
    // pros::delay(100);
    // CHECK_CANCEL();
    // chassis.tank(-40, -40);
    // pros::delay(70);
    // CHECK_CANCEL();
    // chassis.tank(40, 40);
    // pros::delay(100);
    // CHECK_CANCEL();
    // chassis.tank(-40, -40);
    // pros::delay(70);
    // CHECK_CANCEL();
    // chassis.tank(40, 40);
    // pros::delay(100);
    // CHECK_CANCEL();
    // chassis.cancelAllMotions();
    // chassis.cancelMotion();
    // chassis.tank(0,0);
    // pros::delay(800);
}


void secondMatchloader(){
    chassis.setPose(0,0,0);
    matchLoader.set_value(true);
    chassis.moveToPoint(0.4, 30.5, 3000, {}, true); //go to second matchloader async
    while (chassis.isInMotion() && !g_cancel) pros::delay(10);
    CHECK_CANCEL();
    intakeMotor.move(127);
    chassis.tank(-30, -30);
    pros::delay(50);
    CHECK_CANCEL();
    chassis.tank(35, 35);
    pros::delay(180);
    CHECK_CANCEL();
    hoodMotor.move(0);
    chassis.cancelAllMotions();
    chassis.tank(-40, -40);
    pros::delay(80);
    CHECK_CANCEL();
    chassis.tank(40, 40);
    pros::delay(100);
    CHECK_CANCEL();
    chassis.tank(-40, -40);
    pros::delay(80);
    CHECK_CANCEL();
    chassis.tank(40, 40);
    pros::delay(100);
    CHECK_CANCEL();
    chassis.tank(-40, -40);
    pros::delay(80);
    CHECK_CANCEL();
    chassis.tank(40, 40);
    pros::delay(100);
    CHECK_CANCEL();
    chassis.tank(-40, -40);
    pros::delay(80);
    CHECK_CANCEL();
    chassis.tank(40, 40); //matchloader 2 
    pros::delay(100);
    CHECK_CANCEL();
    chassis.tank(-40, -40);
    pros::delay(80);
    CHECK_CANCEL();
    chassis.tank(40, 40);
    pros::delay(100);
    CHECK_CANCEL();
    chassis.tank(-40, -40);
    pros::delay(80);
    CHECK_CANCEL();
    chassis.tank(40, 40);
    pros::delay(100);
    CHECK_CANCEL();
    chassis.cancelAllMotions();
    chassis.cancelMotion();
    chassis.tank(0,0);
}
void thirdMatchloader(){
    chassis.setPose(0,0,0);
    matchLoader.set_value(true);
    chassis.moveToPoint(0.4, 30.5, 3000, {}, true); //go to second matchloader async
    while (chassis.isInMotion() && !g_cancel) pros::delay(10);
    CHECK_CANCEL();
    intakeMotor.move(127);
    chassis.tank(-30, -30);
    pros::delay(50);
    CHECK_CANCEL();
    chassis.tank(35, 35);
    pros::delay(180);
    CHECK_CANCEL();
    hoodMotor.move(0);
    chassis.cancelAllMotions();
    chassis.tank(-40, -40);
    pros::delay(80);
    CHECK_CANCEL();
    chassis.tank(40, 40);
    pros::delay(100);
    CHECK_CANCEL();
    chassis.tank(-40, -40);
    pros::delay(80);
    CHECK_CANCEL();
    chassis.tank(40, 40);
    pros::delay(100);
    CHECK_CANCEL();
    chassis.tank(-40, -40);
    pros::delay(80);
    CHECK_CANCEL();
    chassis.tank(40, 40);
    pros::delay(100);
    CHECK_CANCEL();
    chassis.tank(-40, -40);
    pros::delay(80);
    CHECK_CANCEL();
    chassis.tank(40, 40); //matchloader 2 
    pros::delay(100);
    CHECK_CANCEL();
    chassis.tank(-40, -40);
    pros::delay(80);
    CHECK_CANCEL();
    chassis.tank(40, 40);
    pros::delay(100);
    CHECK_CANCEL();
    chassis.tank(-40, -40);
    pros::delay(80);
    CHECK_CANCEL();
    chassis.tank(40, 40);
    pros::delay(100);
    CHECK_CANCEL();
    chassis.cancelAllMotions();
    chassis.cancelMotion();
    chassis.tank(0,0);
}


void fourthMatchloader(){
    chassis.setPose(0,0,0);
    matchLoader.set_value(true);
    chassis.moveToPoint(0.4, 30.5, 3000, {}, true); //go to second matchloader async
    while (chassis.isInMotion() && !g_cancel) pros::delay(10);
    CHECK_CANCEL();
    intakeMotor.move(127);
    chassis.tank(-30, -30);
    pros::delay(50);
    CHECK_CANCEL();
    chassis.tank(35, 35);
    pros::delay(180);
    CHECK_CANCEL();
    hoodMotor.move(0);
    chassis.cancelAllMotions();
    chassis.tank(-40, -40);
    pros::delay(80);
    CHECK_CANCEL();
    chassis.tank(40, 40);
    pros::delay(100);
    CHECK_CANCEL();
    chassis.tank(-40, -40);
    pros::delay(80);
    CHECK_CANCEL();
    chassis.tank(40, 40);
    pros::delay(100);
    CHECK_CANCEL();
    chassis.tank(-40, -40);
    pros::delay(80);
    CHECK_CANCEL();
    chassis.tank(40, 40);
    pros::delay(100);
    CHECK_CANCEL();
    chassis.tank(-40, -40);
    pros::delay(80);
    CHECK_CANCEL();
    chassis.tank(40, 40); //matchloader 2 
    pros::delay(100);
    CHECK_CANCEL();
    chassis.tank(-40, -40);
    pros::delay(80);
    CHECK_CANCEL();
    chassis.tank(40, 40);
    pros::delay(100);
    CHECK_CANCEL();
    chassis.tank(-40, -40);
    pros::delay(80);
    CHECK_CANCEL();
    chassis.tank(40, 40);
    pros::delay(100);
    CHECK_CANCEL();
    chassis.cancelAllMotions();
    chassis.cancelMotion();
    chassis.tank(0,0);

}




int autonNumber = -1;
bool isAuto = false;


extern bool runAutonMode;  // in header


void macroTask(void* param) {
    bool prev = false;
    while (true) {
        bool down = controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_DOWN);
        if (down && !prev) {
            if (runAutonMode) {
                // cancel currently running section; the runner task will
                // notice g_cancel and exit quickly, but we also stop the
                // drivetrain immediately.
                g_cancel = true;
                chassis.cancelAllMotions();
                runAutonMode = false;
            } else {
                // schedule the next section in a separate task so this loop
                // stays responsive to further button presses
                runAutonMode = true;
                g_cancel = false;
                autonNumber = (autonNumber + 1) % 4;
                pros::Task([](void*) {
                    switch (autonNumber) {
                        case 0: firstMatchloader(); break;
                        case 1: secondMatchloader(); break;
                        case 2: thirdMatchloader(); break;
                        case 3: fourthMatchloader(); break;
                    }
                    runAutonMode = false;
                }, nullptr, "autonRunner");
            }
        }
        prev = down;
        pros::delay(20);
    }
}



/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
    pros::lcd::initialize();
    chassis.calibrate();

    while (inertialSensor.is_calibrating()) {
        pros::delay(10);
    }


    // start pose display task
    pros::Task poseTask(poseDisplayTask, (void*)nullptr, "Pose Display");
    pros::Task myTask(macroTask);
}



/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}


/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}


/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {
    pidTune();
}


/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() {
    while (true) {
        if (!runAutonMode) {


            const int kFull = 127;
            const int kSixty = 76; // 60% of 127


            int intakePower = 0;
            int hoodPower = 0;


            bool r1 = controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1);
            bool r2 = controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2);
            bool l1 = controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1);
            bool l2 = controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2);
            bool buttonA = controller.get_digital(pros::E_CONTROLLER_DIGITAL_A);
            bool buttonB = controller.get_digital(pros::E_CONTROLLER_DIGITAL_B);


            // R2 = intake forward, L2 = hood forward
            if (r2) intakePower = kFull;
            if (l2) hoodPower = kFull;
            
            // L1 = both motors backward
            if (l1) {
                intakePower = -kFull;
            }
            
            // Toggle match loader with R1
            if (r1 && !prevR1Pressed) {
                matchLoaderDown = !matchLoaderDown;
                matchLoader.set_value(matchLoaderDown);
            }
            prevR1Pressed = r1;
            
            // Toggle wing descore with A
            if (buttonA && !prevAPressed) {
                wingDescoreUp = !wingDescoreUp;
                wingDescore.set_value(wingDescoreUp);
            }
            prevAPressed = buttonA;


            // B = reverse hood motor
            if (buttonB) hoodPower = -kFull;


            // Toggle middle goal with UP arrow
            bool upPressed = controller.get_digital(pros::E_CONTROLLER_DIGITAL_UP);
            if (upPressed && !prevUpPressed) {
                middleGoalDown = !middleGoalDown;
                middleGoal.set_value(middleGoalDown);
            }
            prevUpPressed = upPressed;




            intakeMotor.move(intakePower);
            hoodMotor.move(hoodPower);


            chassis.arcade(controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y), 
                        controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X));



        }
        pros::delay(25);
    }
}