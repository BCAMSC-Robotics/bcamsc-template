/*******************************************************************************
 * @mainpage
 * This is the program for the BCAMSC Robotics Team 2581B 2014 competition
 * robot.
 *
 * @details
 * This program is the primary file for the BCAMSC Robotics Team 2581B program
 * for the 2014-2015 school year.
 *
 * This program is based on a template by James Pearman in his "C on Vex"
 * library, V 1.00.
 *
 * @author James Pearman
 * @author Michel Momeyer <strihawk1213@gmail.com>
 * @author Ethan Ruffing <ruffinge@mail.gvsu.edu>
 *
 * @since 2014-12-22
 ******************************************************************************/
#include <stdlib.h>
#include <math.h>
#include <string.h>

#include "ch.h"         // needs for all ChibiOS programs
#include "hal.h"        // hardware abstraction layer header
#include "vex.h"        // vex library header
#include "vexuser.h"    // function declarations
#include "apollo.h"     // the library that includes the apollo debug window in screen
#include "smartmotor.h" // the library for smart motors
#include "routines.c"   // contains a function for each autonomous or programming skills routine.

//Motors Declaration
#define BASE_SW  kVexMotor_2    //Back Left Drive Motor
#define BASE_NW  kVexMotor_3    //Front Left Drive Motor
#define BASE_NE  kVexMotor_4    //Front Right Drive Motor
#define BASE_SE  kVexMotor_5    //Back Right Drive Motor

#define LIFT_1   kVexMotor_6    //Front Left Lift Motor
#define LIFT_2   kVexMotor_7    //Front Right Lift Motor
#define LIFT_3   kVexMotor_8    //Upper Lift Motor

#define SHUTTLE  kVexMotor_10   //controls claw shuttle
#define CLAW     kVexMotor_9    //actuates claw

//Shuttle Buttons
#define BACK_BUTTON kVexMotor_9
#define FRONT_BUTTON kVexDigital_10

//Jumpers used for autonomous strategy selection
#define jump1 kVexDigital_9
#define jump2 kVexDigital_10
#define jump3 kVexDigital_11
#define jump4 kVexDigital_12

//Other Preprocessor Declaration

 #define PI (3.14159265359)
 #define wheelConstant (1)

// Digi IO configuration
static  vexDigiCfg  dConfig[kVexDigital_Num] = {
        { kVexDigital_1,    kVexSensorQuadEncoder,   kVexConfigQuadEnc1,    kVexQuadEncoder_1 },
        { kVexDigital_2,    kVexSensorQuadEncoder,   kVexConfigQuadEnc2,    kVexQuadEncoder_1 },
        { kVexDigital_3,    kVexSensorQuadEncoder,   kVexConfigQuadEnc1,    kVexQuadEncoder_2 },
        { kVexDigital_4,    kVexSensorQuadEncoder,   kVexConfigQuadEnc2,    kVexQuadEncoder_2 },
        { kVexDigital_5,    kVexSensorQuadEncoder,   kVexConfigQuadEnc1,    kVexQuadEncoder_3 },
        { kVexDigital_6,    kVexSensorQuadEncoder,   kVexConfigQuadEnc2,    kVexQuadEncoder_3 },
        { kVexDigital_7,    kVexSensorQuadEncoder,   kVexConfigQuadEnc1,    kVexQuadEncoder_4 },
        { kVexDigital_8,    kVexSensorQuadEncoder,   kVexConfigQuadEnc2,    kVexQuadEncoder_4 },
        { kVexDigital_9,    kVexSensorDigitalInput,  kVexConfigInput,       0 },
        { kVexDigital_10,   kVexSensorDigitalInput,  kVexConfigInput,       0 },
        { kVexDigital_11,   kVexSensorDigitalInput,  kVexConfigInput,       0 },
        { kVexDigital_12,   kVexSensorDigitalInput,  kVexConfigInput,       0 }
};

//Motor configuration
static  vexMotorCfg mConfig[kVexMotorNum] = {
        { kVexMotor_1,  kVexMotor393T,     kVexMotorNormal,       kVexSensorNone,               0 },
        { BASE_SW,      kVexMotor393T,     kVexMotorNormal,       kVexSensorQuadEncoder,        kVexQuadEncoder_1 },
        { BASE_NW,      kVexMotor393T,     kVexMotorNormal,       kVexSensorQuadEncoder,        kVexQuadEncoder_2 },
        { BASE_NE,      kVexMotor393T,     kVexMotorNormal,       kVexSensorQuadEncoder,        kVexQuadEncoder_3 },
        { BASE_SE,      kVexMotor393T,     kVexMotorReversed,     kVexSensorQuadEncoder,        kVexQuadEncoder_4 },
        { LIFT_1,       kVexMotor393T,     kVexMotorNormal,       kVexSensorIME,                0 },
        { LIFT_2,       kVexMotor393T,     kVexMotorReversed,     kVexSensorIME,                kImeChannel_1 },
        { LIFT_3,       kVexMotor393T,     kVexMotorReversed,     kVexSensorIME,                0 },
        { CLAW,         kVexMotor393T,     kVexMotorNormal,       kVexSensorNone,               0 },
        { SHUTTLE,      kVexMotor393T,     kVexMotorNormal,       kVexSensorNone,               0 }

};

//Pre-input variables - used for smooth transitioning between dead zone and active zone of controller
int jSCh1;
int jSCh2;    //Unused (right vertical joystick)
int jSCh3;
int jSCh4;

//Input variables
int vertical = 0;
int horizontal = 0;
int spin = 0;
int liftSpeed;
float precisionConstant = .33;
float spinPrecisionConstant = .33;

//Limits and Acceleration adjustments
int deadZone = 15;
int maxAVert = 10;
int maxAHoriz = 10;
int maxASpin = 10;

//Multipliers for precision control
float horizontalCoefficient, spinCoefficient, verticalCoefficient, liftCoefficient, shuttleCoefficient;

//Auton Segments
int autonSelect;    //Uses jumpers to select an auton routine

float inchesPerDegree = .14;

//Liam's auton variables for dealing with claw and shuttle in go(), which is optimized for smart motors
int clawPosition = 0;       //0 = open, 1 = closed
int shuttlePosition = 0;    //0 = in, 1 = out
int shuttlingTime = 150;    //This is the number of cycles through the while loop in go() that it takes to toggle the position of the shuttle. EDIT THIS

int accelerationIncrement = 1;
int minimumSpeedCap = 35;
int accelerationRatio;

//Autonomous Control Variables
bool driveDone = false;
bool liftDone = false;
bool shuttleDone = false;
bool done = false;

bool clawTogglePrevious = false;

//Autonomous Constants
int autonLiftHeight = 0;
const int autonShuttlingCounts = 500000;
int autonShuttleDirection = 0;
const float driveCountsPerInch = 1;//11.05;
const int liftCountsPerInch = 1;//25;

const float maximumSpeed = 127;
const float minimumSpeed = 25;

int motorPorts[] = {BASE_SW, BASE_NW, BASE_NE, BASE_SE};
int baseDistances[] = {0,0,0,0};
float baseSpeeds[] = {0,0,0,0};
float baseSpeedCap = 20;
const float straighteningAdjustment = 1.05;

const unsigned int STRAIGHTENED_VALUES[128] = 
{
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    2,  4,  6,  8,  10, 12, 14, 14, 14, 14,
    14, 14, 15, 15, 15, 15, 15, 15, 16, 16,
    16, 16, 16, 16, 17, 17, 17, 17, 17, 17,
    18, 18, 18, 18, 18, 18, 19, 19, 19, 19,
    19, 19, 20, 20, 20, 20, 21, 21, 21, 21,
    22, 22, 22, 22, 23, 23, 23, 23, 24, 24,
    24, 24, 25, 25, 25, 26, 26, 26, 27, 27,
    28, 28, 29, 29, 30, 30, 31, 31, 32, 32,
    33, 33, 34, 34, 35, 35, 36, 36, 37, 37,
    38, 38, 40, 41, 42, 43, 44, 45, 47, 48,
    50, 52, 54, 56, 58, 60, 63, 67, 71, 76,
    81, 87, 93, 100,107,117,127,127
};

/**
 * @brief User setup
 * @details
 *  The digital and motor ports can (should) be configured here.
 */
void vexUserSetup()
{
    vexDigitalConfigure(dConfig, DIG_CONFIG_SIZE( dConfig));
    vexMotorConfigure(mConfig, MOT_CONFIG_SIZE( mConfig));
}

/**
 * @brief User initialize
 * @details
 *  This function is called after all setup is complete and communication has
 *  been established with the master processor.
 *  Start other tasks and initialize user variables here
 */
void vexUserInit()
{
}

/**
 * @brief Autonomous
 * @details
 *  This thread is started when the autonomous period is started
 */
msg_t vexAutonomous(void *arg)
{
    (void)arg;

    // Must call this
    vexTaskRegister("auton");

    //Run the auton function
    testAuton();

    return (msg_t)0;
}

/**
 * @brief Driver Control
 *
 * @details
 * This thread is started when the driver control period is started
 */
msg_t vexOperator(void *arg)
{
    (void)arg;

    // Must call this
    vexTaskRegister("operator");

    //Driver Control Variables

    bool shuttleIn = false;
    bool shuttleOut = false;
    bool shuttleReachedBack = false;
    bool shuttleReachedFront = false;

    // Run until asked to terminate
    while(!chThdShouldTerminate())
    {
        //Takes in input from the controller and sets motors
        updateInput();
        
        //Sets the motors based on user input
        setBaseMotors(spin, vertical, horizontal);
        setLiftMotors(liftSpeed);

        //Shuttle
        shuttleIn = vexControllerGet(Btn5D);
        shuttleOut = vexControllerGet(Btn5U);
        shuttleReachedBack = vexDigitalPinGet(BACK_BUTTON);
        shuttleReachedFront = vexDigitalPinGet(FRONT_BUTTON);

        setShuttleMotors(shuttleIn, shuttleOut, shuttleReachedBack, shuttleReachedFront);

        //Claw
        setClawMotors(vexControllerGet(Btn6U));

        //Don't hog cpu
        vexSleep(25);
    }

    return (msg_t)0;
}

/*
 * This function converts driver input and modifies values for use.
 */
void updateInput(void)
{
    //TODO: CHANGE getPowerIncrement to handle input and oldValue as values from the table
    //      MAKE sure to get oldValues

    //Joystick values adjusted to create a dead zone
    jSCh1 = deadZoneAdjust(vexControllerGet(Ch1));
    jSCh2 = deadZoneAdjust(vexControllerGet(Ch2));
    jSCh3 = deadZoneAdjust(vexControllerGet(Ch3));
    jSCh4 = deadZoneAdjust(vexControllerGet(Ch4));

    //Sets precision coefficients based on user input
    if(vexControllerGet(Btn6D))
    {
        verticalCoefficient = horizontalCoefficient = spinCoefficient = liftCoefficient = shuttleCoefficient = precisionConstant;
    }
    else
    {
        verticalCoefficient = horizontalCoefficient = spinCoefficient = liftCoefficient = shuttleCoefficient = 1;
    }

    //Adjusts the motor values to be proportional to the acceleration of the joystick
    vertical = joystickAcceleration(vexControllerGet(Ch3));
    horizontal = joystickAcceleration(vexControllerGet(Ch4));
    spin = joystickAcceleration(vexControllerGet(Ch1));
/*
    //Adjust movement input and maximum acceleration 
    vertical += getPowerIncrement(vertical,jSCh3, maxAVert, verticalCoefficient);
    horizontal += getPowerIncrement(horizontal,jSCh4, maxAHoriz, horizontalCoefficient);
    spin += getPowerIncrement(spin,jSCh1,maxASpin, spinCoefficient);

*/
    liftSpeed = liftCoefficient * 127 * (vexControllerGet(Btn8U) - vexControllerGet(Btn8D));

    //Test Auton Functions
    
    if(vexControllerGet(Btn7R)) auton0();   //Red skyrise
    if(vexControllerGet(Btn7L)) auton1();   //Blue skyrise
    if(vexControllerGet(Btn8R)) auton2();   //Red post
    if(vexControllerGet(Btn8L)) auton3();   //Blue post
    
    if(vexControllerGet(Btn7U)) auton4();
}

/*
 * 
 */
int joystickAcceleration(int input)
{
    //Determines the direction of the joystick
    int direction = signOf(input);

    //Calculates the index of the STRAIGHTENED_VALUES array for the given input
    int index = abs(input);
    if(index > 127) index = 127;

    return STRAIGHTENED_VALUES[index] * direction;
}

/*
 * This function determines and returns an acceptable increment to the given 
 * power level based on user input.
 */
int getPowerIncrement(int oldValue, int input, int maxAcceleration, float coefficient)
{
    input *= coefficient;
    maxAcceleration *= coefficient;

    if(input > oldValue + maxAcceleration) 
    {
        return maxAcceleration;
    }
    else if(input < oldValue - maxAcceleration) 
    {
        return -maxAcceleration;
    }
    else
    {
        return input - oldValue;
    }
}

/*
 * Set the base drive motors.
 */
void setBaseMotors(int spin, int vertical, int horizontal)
{
    vexMotorSet(BASE_SW, spin + vertical - horizontal);
    vexMotorSet(BASE_NW, spin + vertical + horizontal);
    vexMotorSet(BASE_NE, spin - vertical + horizontal);
    vexMotorSet(BASE_SE, spin - vertical - horizontal);
}

/*
 * Set the lift motors.
 */
void setLiftMotors(int liftSpeed)
{
    vexMotorSet(LIFT_1,liftSpeed);
    vexMotorSet(LIFT_2,liftSpeed);
    vexMotorSet(LIFT_3,liftSpeed);
}

/*
 * Set the shuttle motors
 */
void setShuttleMotors(bool in, bool out, bool back, bool front)
{
    if(in && front)
    {
        vexMotorSet(SHUTTLE, 127 * shuttleCoefficient);
    }
    else if(out && back)
    {
        vexMotorSet(SHUTTLE, -127 * shuttleCoefficient);
    }
    else
    {
        vexMotorSet(SHUTTLE, 0);
    }

}

/*
 * Set the claw motors
 */
void setClawMotors(bool buttonPressed)
{
    if(buttonPressed)
    {
        vexMotorSet(CLAW, 127);
    }
    else
    {
        vexMotorSet(CLAW, -127);
    }
}

/*
 * This function autonomously controls the robot for given direction and distance.
 */
void go(void)
{
    //Reset autonomous control variables
    driveDone = false;
    liftDone = false;
    shuttleDone = false;

    baseSpeedCap = 45;

    //Reset all encoders
    int i;
    for(i = 0; i < 9; i++)
    {
        vexMotorPositionSet(i, 0);
    }

    //Initiate Motors
    vexMotorSet(SHUTTLE, 100 * autonShuttleDirection);

    done = false;
    while(!done && !vexControllerGet(Btn7D))
    {
        //Call autonomous motor functions
        if(!driveDone) driveControl();
        if(!liftDone) liftControl();
        if(!shuttleDone) shuttleControl(!vexDigitalPinGet(BACK_BUTTON), !vexDigitalPinGet(FRONT_BUTTON));

        //Determine whether everything is complete
        if(driveDone && liftDone && shuttleDone)
        {
            done = true;
        }
        //vexSleep(25);
    }
    //Reset variables for next time
    setBase(0,0,0);
    setLift(0);
    setShuttle(0);
}

//Controls the base drive motors
void driveControl()
{
    driveDone = true;

    //ADJUST base speed cap for acceleration and decceleration
    /*
    if(baseSpeedCap < 127)
    {
        baseSpeedCap += accelerationIncrement;

        if(baseSpeedCap >= 127)
        {
            accelerationIncrement = 0;
            accelerationRatio = 1 - getAverageComplete();
        }
        else if(baseSpeedCap <= minimumSpeedCap)
        {
            accelerationIncrement = 0;
        }
    }
    if(getAverageComplete() >= accelerationRatio)
    {
        accelerationIncrement = -1;
        if(baseSpeedCap == 127) baseSpeedCap = 126;

    }*/

    //Adjusts the maximum speed cap to control the acceleration and decceleration 
    float niceLittleShape = averageProportionComplete(-1) * (1 - averageProportionComplete(-1)) * 4;    //If we are near the beginning or end of the step, this value is very small.
    baseSpeedCap = minimumSpeed + niceLittleShape * (127 - minimumSpeed);   //Stretch between the minimum and maximum speeds

    int i;
    for(i = 0; i < 4; i++)
    {
        //ADJUST speed for straightening
        float currentProportionComplete = abs(vexMotorPositionGet(motorPorts[i]) / baseDistances[i]);

        if(currentProportionComplete < averageProportionComplete(i))
        {
            baseSpeeds[i] *= straighteningAdjustment;
        }
        else if(currentProportionComplete > averageProportionComplete(i))
        {
            baseSpeeds[i] /= straighteningAdjustment;
        }

        //Determining if complete
        if(abs(vexMotorPositionGet(motorPorts[i])) >= ((abs(baseDistances[i]) * driveCountsPerInch)))
        {
            baseSpeeds[i] = 0;
        }
        else
        {
            driveDone = false;
        }
    }

    //Scale power levels, set motors
    float maxSpeed = maxF(baseSpeeds);
    for(i = 0; i < 4; i++)
    {
        baseSpeeds[i] *= baseSpeedCap / abs(maxSpeed);
        vexMotorSet(motorPorts[i], baseSpeeds[i]);
    }
}

//Raises the lift to a liftHeight Variable
void liftControl()
{
    int speed = liftSpeed;
    //Put straightening code here if desired
    //Put acceleration adjusting code here if desired
    //etc...

    if(abs(vexMotorPositionGet(LIFT_2)) >= (abs(autonLiftHeight * liftCountsPerInch)))
    {
        speed = 0;
        liftDone = true;
    }
    vexMotorSet(LIFT_1, speed);
    vexMotorSet(LIFT_2, speed);
    vexMotorSet(LIFT_3, speed);
}

//pushes the shuttle in, out, or not at all
void shuttleControl(bool backButton, bool frontButton)
{
    if((autonShuttleDirection == 1 && frontButton == 1) || (autonShuttleDirection == -1 && backButton == 1) || (autonShuttleDirection == 0))
    {
        vexMotorSet(SHUTTLE, 0);
        shuttleDone = true;
    }
}

void setBase(int forward, int right, int spin)
{
    baseDistances[0] = ( forward - right + spin);
    baseDistances[1] = ( forward + right + spin);
    baseDistances[2] = (-forward + right + spin);
    baseDistances[3] = (-forward - right + spin);

    int i;
    for(i = 0; i < 4; i++)
    {
        baseSpeeds[i] = baseSpeedCap * baseDistances[i] / max(baseDistances);
    }
}

void setLift(int distance)
{
    autonLiftHeight = distance;
    liftSpeed = 127 * distance / abs(distance);
}

/*
 * This toggles the direction of the shuttle - in and out.
 */
void setShuttle(int direction)
{
   autonShuttleDirection = -direction;
}

void setClaw(int x)
{
    vexMotorSet(CLAW, 118 * x); //1 is open, -1 is closed
}

/*
 * This returns the maximum value in an array.
 */
int max(int a[4])
{
    int b[4];
    //Make all values positive
    int i;
    for(i = 0; i < 4; i++)
        b[i] = abs(a[i]);

    //Find and return the largest value
    if(b[0] > b[1] && b[0] > b[2] && b[0] > b[3])
        return b[0];
    else if(b[1] > b[2] && b[1] > b[3])
        return b[1];
    else if(b[2] > b[3])
        return b[2];
    else
        return b[3];
}

/*
 * This returns the maximum value in an array.
 */
float maxF(float a[4])
{
    float b[4];
    //Make all values positive
    int i;
    for(i = 0; i < 4; i++)
        b[i] = abs(a[i]);

    //Find and return the largest value
    if(b[0] > b[1] && b[0] > b[2] && b[0] > b[3])
        return b[0];
    else if(b[1] > b[2] && b[1] > b[3])
        return b[1];
    else if(b[2] > b[3])
        return b[2];
    else
        return b[3];
}

/*
 *
 */
int signOf(int x)
{
    if(x > 0) return 1;
    else return -1;
}

/*
 * This checks to make sure the inputted value isn't inside the deadZone.
 */
int deadZoneAdjust(int value)
{
    if(abs(value) >= deadZone)
    {
        return value;
    }
    else
    {
        return 0;
    }
}

/*
 * Finds the average ratio, among all the drive motors excluding index, of distance travelled to destination distance.
 */
float averageProportionComplete(int index)
{
    float average = 0;
    int i;
    int n = 0;
    for(i = 0; i < 4; i++)
    {
        if(i != index)
        {
            vexMotorSet(motorPorts[i],0);
            if(baseDistances[i])
            {
                average += abs(vexMotorPositionGet(motorPorts[i]) / (baseDistances[i] * driveCountsPerInch));
                n++;
            }
        }
    }
    average /= n;
    return average;
}

/*
 * Finds the average ratio of distance travelled to destination distance for all base drive motors.
 */
float getAverageComplete()
{
    float sumCompleted = 0;
    float sumTotal = 0;

    int i;
    for(i = 0; i < 4; i++)
    {
        sumCompleted += abs(vexMotorPositionGet(motorPorts[i]));
        sumTotal+= abs(baseDistances[i] * driveCountsPerInch);
    }
    return sumCompleted / sumTotal;
}
