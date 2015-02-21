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
 * This function autonomously controls the robot for given direction and distance.
 * 
 * @author Michel Momeyer <strihawk1213@gmail.com>
 * @since 2014-12-29
 */
void go(void);

/**
 * Operates the base during autonomous.
 * 
 * @author Michel Momeyer <strihawk1213@gmail.com>
 * @since 2014-12-29
 */
void driveControl(void);

/**
 * Operates the lift during autonomous.
 *
 * @author Michel Momeyer <strihawk1213@gmail.com>
 * @since 2014-12-29
 */
void liftControl(void);

/**
 * Operates the shuttle during autonomous.
 *
 * @author Michel Momeyer <strihawk1213@gmail.com>
 * @since 2014-12-29
 * @param backButton[in]
 * 		the back bumper that controls the shuttle
 * @param frontButton[in]
 *		the front bumper that controls the shuttle
 */
void shuttleControl(bool backButton, bool frontButton);

/*
 * These functions make it more intuitive to edit the distances and powerLevels arrays for use in the go() function.
 */

/**
 * This functions sets the base drive values for the robot to reach in the next go() call.
 * 
 * @author Liam Bohl
 * @since 2014-12-29
 * @param forward[in]
 *		distance in encoder counts to travel vertically (or forward)
 * @param right[in]
 *		distance in encoder counts to travel horizontally (or right)
 * @param spin[in]
 *		distance in encoder counts to rotate (or spin)
 */
void setBase(int forward, int right, int spin);

/**
 * This functions sets the base drive values for the robot to reach in the next go() call.
 * 
 * @author Liam Bohl
 * @since 2014-12-29
 * @param distance
 * 		distance in encoder counts to raise or lower the lift
 */
void setLift(int distance);

//direction 1 sets the shuttle forward, -1 backward, and 0 stationary.
/**
 * This function sets the shuttle direction to travel.
 * 
 * @author Liam Bohl
 * @since 2014-12-29
 * @param direction[in]
 * 		direction that the shuttle travels 
 *		0 : stationary
 *		1 : forward
 *	   -1 : backwards
 */
void setShuttle(int direction);

/**
 * This function sets the claw to open[1] or close[-1].
 * 
 * @author Liam Bohl
 * @since 2014-12-29
 * @param x[in]
 * 		direction to open claw 
 *		1: open
 *	   -1: closed
 */
void setClaw(int x);

/*
 * This function returns the largest value in a given array of integers.
 *
 * @author Liam Bohl
 * @since 2015-
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
 * The robot knocks the preload cube onto the red skyrise base and places two skyrise sections on the base.
 *		Scores 12 points when executed perfectly.
 *
 * @author Liam Bohl <liambohl@gmail.com>
 * @author Faith Bosher
 * @since 2015-1-?
 */
void autonRedSkyrise(void);

/**
 * The robot knocks the preload cube onto the blue skyrise base and places two skyrise sections on the base.
 *		Scores 12 points when executed perfectly.
 *
 * @author Liam Bohl <liambohl@gmail.com>
 * @author Faith Bosher
 * @since 2015-1-?
 */
void autonBlueSkyrise(void);

/**
 * The robot lifts the preload cube onto the low post adjacent to the starting tile and backs away.
 *		Scores 3 points when executed perfectly.
 *
 * @author Liam Bohl <liambohl@gmail.com>
 * @since 2015-1-?
 */
void autonRedPost(void);

/**
 * The robot lifts the preload cube onto the low post adjacent to the starting tile and backs away.
 *		Scores 3 points when executed perfectly.
 *
 * @author Liam Bohl <liambohl@gmail.com>
 * @since 2015-1-?
 */
void autonBluePost(void);

/**
 * The robot knocks the preload cube onto the blue skyrise base and places five skyrise sections on the base.
 *		Scores 24 points when executed perfectly.
 *
 * @author Liam Bohl <liambohl@gmail.com>
 * @since 2015-2-19
 */
void programmingSkills(void);

/**
 * This function serves to test the autonomous code.
 *
 * @author Michel Momeyer <strihawk1213@gmail.com>
 * @since ?
 */
void testAuton(void);

int cap(int x, int lBound, int uBound);
/**
 * This function takes an input from the joystick and makes it zero if it is within the dead zone.
 *
 * @author Michel Momeyer <strihawk1213@gmail.com>
 * @author Liam Bohl <liambohl@gmail.com>
 * @since 2015-1-?
 *
 * @param value[in]
 *		the value taken from the joystick
 * @return
 *		the value adjusted to account for the dead zone
 */
int deadZoneAdjust(int value);

/**
 * This function returns the sign (positive or negative) of and integer.
 *
 * @author Michel Momeyer <strihawk1213@gmail.com>
 * @since 2015-1-?
 *
 * @param x[in]
 *		the value for which the sign is to be taken
 * @return
 *		1 or -1, depending on the sign of x
 */
int signOf(int x);

/**
 * The following four functions use the inputs determined in updateInput() to set the robot's various motors.
 */

/**
 * This function sets the power levels of the base motors
 *
 * @author Michel Momeyer <strihawk1213@gmail.com>
 * @since 2015-2-?
 *
 * @param spin[in]
 *		speed to turn clockwise (positive) or counter-clockwise (negative)
 * @param vertical[in]
 *		speed to move forward (positive) or backward (negative)
 * @param horizontal[in]
 *		speed to move right (positive) or left (negative)
 */
void setBaseMotors(int spin, int vertical, int horizontal);

/**
 * This function sets the power levels of the lift motors
 *
 * @author Michel Momeyer <strihawk1213@gmail.com>
 * @since 2015-2-?
 *
 * @param liftSpeed
 *		speed to move lift up (positive) or down (negative)
 */
void setLiftMotors(int liftSpeed);

/**
 * This function sets the power level of the shuttle motor
 *
 * @author Michel Momeyer <strihawk1213@gmail.com>
 * @since 2015-2-?
 *
 * @param in[in]
 *		is the "in" button pressed?
 * @param out[in]
 *		is the "out" button pressed?
 * @param back[in]
 *		is the back bumper switch depressed?
 * @param front[in]
 *		is the front bumper switch depressed?
 */
void setShuttleMotors(bool in, bool out, bool back, bool front);

/**
 * This function sets the position of the claw motor
 *
 * @author Michel Momeyer <strihawk1213@gmail.com>
 * @since 2015-2-?
 *
 * @param buttonPressed[in]
 *		is the claw button pressed?
 */
void setClawMotors(bool buttonPressed);

/**
 * This function takes input from one joystick channel and adjusts it to give more precise control of speed.
 *
 * @author Michel Momeyer <strihawk1213@gmail.com>
 * @since 2015-2-?
 * 
 * @param input[in]
 *		the value of the joystick channel to be adjusted
 * @return
 *		the adjusted value
 */
int joystickAcceleration(int input);

/*
 * Finds the average ratio of distance travelled to destination distance for all base drive motors.
 */
float getAverageComplete(void);

#endif // VEXUSER_H