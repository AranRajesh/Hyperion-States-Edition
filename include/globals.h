#pragma once

#include "main.h"
#include "lemlib/api.hpp" // provides lemlib::Chassis, Drivetrain, TrackingWheel, etc.
#include "pros/imu.hpp"
#include "pros/rotation.hpp"

// Declarations for globals defined in src/main.cpp
extern pros::MotorGroup leftMotors;
extern pros::MotorGroup rightMotors;
extern lemlib::Drivetrain drivetrain;
extern lemlib::Chassis chassis;

extern pros::Imu inertialSensor;
extern pros::Rotation trackingRotation;
extern lemlib::TrackingWheel verticalTrackingWheel;
extern lemlib::OdomSensors sensors;

extern pros::Controller controller;
extern pros::Motor intakeMotor;
extern pros::Motor hoodMotor;
extern pros::adi::DigitalOut matchLoader;
extern pros::adi::DigitalOut wingDescore;
extern pros::adi::DigitalOut middleGoal;
