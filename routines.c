/*******************************************************************************
 * Implementable Strategies for Autonomous Control
 ******************************************************************************/

/*
 * Basic commands:
 * setBase(forward, right, spin)	Positive = forward, right, or clockwise
 * setLift(distance)				Positive = up
 * setShuttle(direction)			1 = out, -1 = in
 * go()								Required at the end of any step involving any of the previous three
 * setClaw(direction)				1 = closed, -1 = open
 */

void testAuton()
{
	setShuttle(1);
	go();

	vexSleep(1000);

	setBase(400,0,0);
	go();
	
	vexSleep(1000);

	setBase(-400,0,0);
	go();
}

/*
//Auton Strategy #1: Skyrise and cubes
//Start robot in ___ square, facing ___.
void auton0()
{
	//push cube onto skyrise base
	setBase(0,2,0);
	setLift(0);
	go();
	//rotate bot to Skyrise autoload
	setBase(0,0,180);
	setLift(0);
	go();
	//lift and grab
	setBase(2,0,0);
	setLift(15);
	setClaw();
	go();
	//lift
	setBase(0,0,0);
	setLift(7);
	go();
	//return
	setBase(2,0,0);
	setLift(20);
	go();
	//spin
	setBase(0,0,90);
	setLift(0);
	go();
	//drop
	setBase(0,0,0);
	setLift(2);
	setClaw();
	go();
	//orient with cube
	setBase(0,0,40);
	setLift(0);
	setShuttle();
	go();
	//forward
	setBase(3,0,0);
	setLift(0);
	setClaw();
	go();
	//retract
	setBase(0,0,30);
	setLift(0);
	setShuttle();
	go();
	//spin
	setBase(0,0,40);
	setLift(0);
	go();
	//lift
	setBase(0,0,0);
	setLift(15);
	go();
	//drop
	setBase(0,0,0);
	setLift(0);
	setClaw();
	go();
	//rotate bot to Skyrise autoload
	setBase(0,0,90);
	setLift(0);
	go();
	//lift and grab
	setBase(2,0,0);
	setLift(15);
	setClaw();
	go();
	//lift
	setBase(0,0,0);
	setLift(7);
	go();
	//return
	setBase(2,0,0);
	setLift(0);
	go();
	//spin
	setBase(0,0,90);
	setLift(0);
	go();
	//drop
	setBase(0,0,0);
	setLift(0);
	setClaw();
	go();
	//orient with cube 2
	setBase(0,0,135);
	setLift(22);
	go();
	//move extend
	setBase(3,0,0);
	setLift(0);
	setShuttle();
	go();
	//grab
	setBase(0,0,0);
	setLift(0);
	setClaw();
	go();
	//move retract
	setBase(3,0,0);
	setLift(0);
	setShuttle();
	go();
	//rotate
	setBase(0,0,130);
	setLift(0);
	go();
	//lift
	setBase(0,0,0);
	setLift(35);
	go();
	//rotate
	setBase(0,0,5);
	setLift(0);
	go();
	//drop
	setBase(0,0,0);
	setLift(0);
	setClaw();
	go();
	//rotate
	setBase(0,0,45);
	setLift(35);
	go();
}
*/

//
//Start in red skyrise square, facing auto-loader
void auton0()
{
	//Nudge preload
	setBase(12,-12,0);
	go();
	vexSleep(300);

	//Open claw, reach for peg
	setClaw(-1);
	setShuttle(1);
	go();
	vexSleep(300);

	//Grab peg
	setClaw(1);
	vexSleep(300);

	//Lift peg out of auto-loader
	setLift(950);
	go();
	vexSleep(300);

	//Turn counter-clockwise to land over base
	setBase(0,0,-280);
	go();
	vexSleep(300);

	//Lower peg
	setLift(-750);
	go();
	vexSleep(300);
	
	//Drop peg
	setClaw(-1);
	vexSleep(300);

	//12-point only
	//	|	|	|
	//	V	V	V
	
	//Turn back around and retract shuttle
	setBase(0,0,280);
	setShuttle(-1);
	go();
	vexSleep(300);

	//Reach for new peg
	setShuttle(1);
	go();
	vexSleep(300);

	//Grab peg
	setClaw(1);
	vexSleep(300);

	//Lift peg out of auto-loader
	setLift(1000);
	go();
	vexSleep(300);

	//Turn counter-clockwise to land over base, lift peg a bit higher?
	setBase(0,0,-265);
	//setLift(500);
	go();
	vexSleep(300);

	//Lower peg
	setLift(-800);
	go();
	vexSleep(300);

	//Drop peg
	setClaw(-1);
	vexSleep(300);

	//	A	A	A
	//	|	|	|
	//12-point only

	//Back off (both 8- and 12-point)
	setShuttle(-1);
	go();
}

//
//Start in blue skyrise square, facing auto-loader
void auton1()
{
	//Nudge preload
	setBase(12,12,0);
	go();
	vexSleep(300);

	//Open claw, reach for peg
	setClaw(-1);
	setShuttle(1);
	go();
	vexSleep(300);

	//Grab peg
	setClaw(1);
	vexSleep(300);

	//Lift peg out of auto-loader
	setLift(950);
	go();
	vexSleep(300);

	//Turn clockwise to land over base
	setBase(0,0,280);
	go();
	vexSleep(300);

	//Lower peg
	setLift(-750);
	go();
	vexSleep(300);
	
	//Drop peg
	setClaw(-1);
	vexSleep(300);

	//12-point only
	//	|	|	|
	//	V	V	V
	
	//Turn back around and retract shuttle
	setBase(0,0,-280);
	setShuttle(-1);
	go();
	vexSleep(300);

	//Reach for new peg
	setShuttle(1);
	go();
	vexSleep(300);

	//Grab peg
	setClaw(1);
	vexSleep(300);

	//Lift peg out of auto-loader
	setLift(1000);
	go();
	vexSleep(300);

	//Turn clockwise to land over base, lift peg a bit higher?
	setBase(0,0,265);
	//setLift(500);
	go();
	vexSleep(300);

	//Lower peg
	setLift(-800);
	go();
	vexSleep(300);

	//Drop peg
	setClaw(-1);
	//vexSleep(300);

	//	A	A	A
	//	|	|	|
	//12-point only

	//Back off (both 8- and 12-point)
	setShuttle(-1);
	go();

	//Really back off
	setBase(-15,15,0);
	go();

}

//Start in red low post square facing between short post and skyrise
void auton2()
{
	//Lift preload cube to top of low post
	setLift(2000);
	go();
	vexSleep(300);

	//Turn to slightly overshoot the low post
	setBase(0,0,-170);
	go();
	vexSleep(300);

	//Orient above the post
	setBase(0,40,0);
	go();
	vexSleep(300);

	//Lift cube down onto post
	setLift(-1700);
	go();
	vexSleep(300);

	/*
	//4-point only
	//	|	|	|
	//	V	V	V
	
	//Back up
	setBase(-50,0,0);
	go();
	vexSleep(300);

	//Turn back to face red cube
	setBase(0,0,-420);
	go();
	vexSleep(300);

	//Move forward to red cube and put lift back down
	setBase(400,0,0);
	setLift(-290);
	go();
	vexSleep(300);

	//Pick up cube
	setLift(300);
	go();
	vexSleep(300);

	//Turn around
	setBase(0,0,660);
	go();
	vexSleep(300);

	//Drive back to tile to drop off cube
	setBase(500,0,0);
	go();
	vexSleep(300);

	//Set cube down
	setLift(-290);
	go();
	vexSleep(300);

	//	A	A	A
	//	|	|	|
	//4-point only
	*/

	//Back off (both 3- and 4-point)
	setBase(-150,0,0);
	go();
}

//Start in blue low post square facing between short post and skyrise
void auton3()
{
	setLift(2000);
	go();
	vexSleep(300);

	setBase(0,0,160);
	go();
	vexSleep(300);

	setBase(60,-30,0);
	go();
	vexSleep(300);

	setLift(-1700);
	go();
	vexSleep(300);

	setBase(-150,0,0);
	go();
}

//Start in red skyrise square, facing auto loader
void auton4()
{
	auton0();

	//Turn back for 3rd peg
	setBase(0,0,280);
	setShuttle(-1);
	go();
	vexSleep(300);

	//Reach for new peg
	setShuttle(1);
	go();
	vexSleep(300);

	//Grab peg
	setClaw(1);
	vexSleep(300);

	//Lift peg out of auto-loader
	setLift(1000);
	go();
	vexSleep(300);

	//Turn counter-clockwise to land over base, lift peg a bit higher
	setBase(0,0,-280);
	setLift(500);
	go();
	vexSleep(300);

	//Lower peg
	setLift(-1000);
	go();
	vexSleep(300);

	//Drop peg
	setClaw(-1);
	vexSleep(300);

	//Back off
	setShuttle(-1);
	go();

	//4th peg

	//Turn back and lower for new peg
	setBase(0,0,280);
	setLift(-500);
	setShuttle(-1);
	go();
	vexSleep(300);

	//Reach for new peg
	setShuttle(1);
	go();
	vexSleep(300);

	//Grab peg
	setClaw(1);
	vexSleep(300);

	//Lift peg out of auto-loader
	setLift(1500);
	go();
	vexSleep(300);

	//Turn counter-clockwise to land over base, lift peg a bit higher
	setBase(0,0,-280);
	setLift(500);
	go();
	vexSleep(300);

	//Lower peg
	setLift(-900);
	go();
	vexSleep(300);

	//Drop peg
	setClaw(-1);
	vexSleep(300);

	//Back off
	setShuttle(-1);
	go();

	//5th peg

	//Turn back and lower for new peg
	setBase(0,0,280);
	setLift(-1100);
	setShuttle(-1);
	go();
	vexSleep(300);

	//Reach for new peg
	setShuttle(1);
	go();
	vexSleep(300);

	//Grab peg
	setClaw(1);
	vexSleep(300);

	//Lift peg out of auto-loader
	setLift(2300);
	go();
	vexSleep(300);

	//Turn counter-clockwise to land over base, lift peg a bit higher
	setBase(0,0,-300);
	setLift(500);
	go();
	vexSleep(800);

	//Back up to adjust
	setBase(-15,0,0);
	go();
	vexSleep(300);

	//Lower peg
	setLift(-1000);
	go();
	vexSleep(300);

	//Drop peg
	setClaw(-1);
	vexSleep(300);

	//Back off
	setShuttle(-1);
	go();
}

//Start in ___ square, facing ___
void auton5()
{
	
}

//Start in ___ square, facing ___
void auton6()
{
	
}

//Start in ___ square, facing ___
void auton7()
{
	
}