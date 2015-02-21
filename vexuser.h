#ifndef VEXUSER_H
#define VEXUSER_H

/**
 * This function determines and returns an acceptable change to the given power level based
 *		on user input.
 * 
 * @author Liam Bohl <liambohl@gmail.com>
 * @author Michel Momeyer <strihawk1213@gmail.com>
 * @since 2014-12-29
 *
 * @param oldValue[in]
 *		the robot's current speed in the direction in question
 * @param input[in]
 *		the user input from the controller
 * @param maxAcceleration[in]
 *		the maximum change in power that can be added at an instant
 * @param coefficient[in]
 *		current maximum speed, determined by whether precision is on or off
 * @return 
 *		the acceptable change to the given power level
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
 * @author Liam Bohl <liambohl@gmail.com>
 * @since 2014-12-29
 */
void liftControl(void);

/**
 * Operates the shuttle during autonomous.
 *
 * @author Michel Momeyer <strihawk1213@gmail.com>
 * @since 2014-12-29
 *
 * @param backButton[in]
 * 		the back bumper that controls the shuttle
 * @param frontButton[in]
 *		the front bumper that controls the shuttle
 */
void shuttleControl(bool backButton, bool frontButton);

/**
 * The following 3 functions make it more intuitive to edit the variables used in the go() function,
 *		namely determining the speed and distance each motor should move.
 */

/**
 * This function sets the speeds and distances for the robot to move in the next go() call.
 * 
 * @author Liam Bohl <liambohl@gmail.com>
 * @since 2014-12-29
 *
 * @param forward[in]
 *		distance in encoder counts to travel vertically - positive is forward, negative backward
 * @param right[in]
 *		distance in encoder counts to travel horizontally - positive is right, negative left
 * @param spin[in]
 *		distance in encoder counts to rotate
 */
void setBase(int forward, int right, int spin);

/**
 * This function sets the speed and distance for the lift to move in the next go() call.
 * 
 * @author Liam Bohl <liambohl@gmail.com>
 * @since 2014-12-29
 *
 * @param distance
 * 		distance in encoder counts to raise or lower the lift - positive is up, negative down
 */
void setLift(int distance);

/**
 * This function sets the direction for the shuttle to move in the next go() call.
 * 
 * @author Liam Bohl <liambohl@gmail.com>
 * @since 2014-12-29
 *
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
 * @author Liam Bohl <liambohl@gmail.com>
 * @since 2014-12-29
 *
 * @param x[in]
 * 		direction to open claw 
 *		1: open
 *	   -1: closed
 */
void setClaw(int x);

/**
 * This function returns the largest absolute value in a given array of integers.
 *
 * @author Liam Bohl <liambohl@gmail.com>
 * @since 2015-1-?
 *
 * @param a[in]
 *		the array for which the largest value is found
 * @return
 *		the largest absolute value of any element in the array
 */
int max(int a[]);

/**
 * This function returns the largest absolute value in a given array of floats.
 *
 * @author Michel Momeyer <strihawk1213@gmail.com>
 * @since 2015-1-?
 *
 * @param a[in]
 *		the array for which the largest value is found
 * @return
 *		the largest absolute value of any element in the array
 */
float maxF(float a[]);

/**
 * This function returns the smallest absolute value in a given array of floats.
 *
 * @author Liam Bohl <liambohl@gmail.com>
 * @since 2015-2-19
 */
float minF(float a[]);

/**
 * This function returns the average value of an array of floats.
 *
 * @author Liam Bohl <liambohl@gmail.com>
 * @since 2015-2-19
 */
float averageF(float a[]);

/**
 * This function returns the number of elements in an array of ints.
 *
 * @author Liam Bohl <liambohl@gmail.com>
 * @since 2015-2-19
 */
int length(int a[]);

/**
 * This function returns the number of elements in an array of floats.
 *
 * @author Liam Bohl <liambohl@gmail.com>
 * @since 2015-2-19
 */
float lengthF(float a[]);

/**
 * This function finds the average ratio, among all the drive motors excluding index, of distance travelled to destination distance.
 *		In other words, the proportion of the current move which the robot has completed.
 *
 * @author Liam Bohl <liambohl@gmail.com>
 * @since 2015-1-?
 *
 * @param index[in]
 *		the one motor to exclude from the calculation
 * @return
 *		the proportion of the current move which has been completed
 */
float prop(int index);

/**
 * The following functions are responsible for all autonomous and programming skills strategies.
 */

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

/**
 * Makes sure that a value is within boundaries.
 */
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

/**
 * Finds the average ratio of distance travelled to destination distance for all base drive motors.
 *
 * @author Michel Momeyer <strihawk1213@gmail.com>
 * @since 2015-1-?
 *
 * @return
 *		the proportion of the current autonomous move which has been completed
 */
float getAverageComplete(void);

#endif // VEXUSER_H