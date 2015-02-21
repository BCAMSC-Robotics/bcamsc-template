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