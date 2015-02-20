#ifndef VEXUSER_H
#define VEXUSER_H

/**
 * This function determines and returns an acceptable change to the given power level based
 *     base on user input.
 * 
 * @author Liam Bohl <liambohl@gmail.com>
 * @author Michel Momeyer <strihawk1213@gmail.com>
 * @since 2014-12-29
 *
 * @param oldValue[in]
 *     the current value to be changed
 * @param channelInput[in]
 *     the user input from the controller
 * @param deadZone[in]
 *     the minimum input threshold that must be reached before changes are considered
 * @param maxAcceleration[in]
 *     the maximum change in power that can be added at an instant
 * @return 
 *     the acceptable change to the given power level
 */
int getPowerIncrement(int oldValue, int input, int maxAcceleration, float coefficient);

/**
 * This function takes the controller input and modify values for use.
 * 
 * @author Michel Momeyer <strihawk1213@gmail.com>
 * @since 2014-12-29
 */
void updateInput(void);

/**
 * This function sets all the motors for driver control based.
 * 
 * @author Michel Momeyer <strihawk1213@gmail.com>
 * @since 2014-12-29
 */
void setMotors(void);

/**
 * This function drives forward a certain distance autonomously.
 *
 * @author Michel Momeyer <strihawk1213@gmail.com>
 * @since 2015-01-10
 * @param dist[in]
 *     the distance to travel in feet
 * @param dist[in]
 *     the distance to travel in feet
 */
 void setAutonMotor(int motor, int dist, int speed);

 /**
  * Determines whether the given motor has reached the given distance converted to encoder counts using wheelFactor.
  * 
  * other stuff
  * 
  */
bool motorIsFinishedOrStopped(int motor, int distance);	//formerly motorHasReached

/**
 * Drives robot forward
 */
void forward(int distance, int speed);

/**
 * This function autonomously controls the robot for given direction and distance.
 */
void go(void);

/**
 * Functions to operate the three main parts of the robot - the base, lift, and shuttle
 */
void driveControl(void);

void liftControl(void);

void shuttleControl(bool backButton, bool frontButton);

/**
 * This function straightens the motor to ensure that it sticks to the plan. 
 */
//int getStraightenedPowerLevel(int encoderCount, int previousEncoderCount, int powerLevel);

/**
 * This function puts new values in powerLevels.
 */
//void setPowerLevels(int value1, int value2, int value3, int value4, int value5, int value6, int value7, int value8, int value9, int value10);

/**
 * This function puts new values in distances.
 */
//void setDistances(int value1, int value2, int value3, int value4, int value5, int value6, int value7, int value8, int value9, int value10);

/*
 * These functions make it more intuitive to edit the distances and powerLevels arrays for use in the go() function.
 */
void setBase(int forward, int right, int spin);

void setLift(int distance);

//direction 1 sets the shuttle forward, -1 backward, and 0 stationary.
void setShuttle(int direction);

void setClaw(int x);

/*
 * returns the largest value in an array of ints
 */
int max(int a[]);

/*
 * returns the largest value in an array of floats
 */
float maxF(float a[]);

/*
 * returns the smallest value in an array of floats
 */
float minF(float a[]);

/*
 * Returns the average value of an array of floats
 */
float averageF(float a[]);

/*
 * Returns the number of elements in an array of ints
 */
int length(int a[]);

/*
 * Returns the number of elements in an array of floats
 */
float lengthF(float a[]);

/*
 * Finds the average ratio, among all the drive motors excluding index, of distance travelled to destination distance
 */
float prop(int index);

/**
 * Returns the sign of an int. Returns 1 for a positive, -1 for a negative, and 0 for a zero x.
 */
//int sign(int x);

/**
 * These functions are responsible for all autonomous and programming skills strategies.
 */
void auton0(void);
void auton1(void);
void auton2(void);
void auton3(void);
void auton4(void);
void auton5(void);
void auton6(void);
void auton7(void);

void testAuton(void);

int cap(int x, int lBound, int uBound);
int deadZoneAdjust(int value);
int signOf(int x);

void setBaseMotors(int spin, int vertical, int horizontal);
void setLiftMotors(int liftSpeed);
void setShuttleMotors(bool in, bool out, bool back, bool front);
void setClawMotors(bool buttonPressed);

int joystickAcceleration(int input);

/*
 * Finds the average ratio of distance travelled to destination distance for all base drive motors.
 */
float getAverageComplete(void);

#endif // VEXUSER_H