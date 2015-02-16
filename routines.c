/*******************************************************************************
 * Implementable Strategies for Autonomous Control
 ******************************************************************************/

/**
 * autonomous strategy # 0
 * Start robot in short pole square
 * robot will push cube up and onto the short post
 */

void testAuton()
{
	setBase(400,0,0);
	go();
}

void auton0()
{
	//lift
	setBase (0,0,0);
	setLift (6);	//update
	go ();

	//down 
	setBase (0,0,0);
	setLift (-6);	//update
	go ();
}

/**
 * [autonomous or programming skills] strategy # 0
 * Start robot in red skyrise square, facing the auto-loader
 * [basic description]
 */

void auton1()
{
	//preload
	setBase (0,-3,0);
	setLift (0);
	go ();

	//back to start
	setBase (0,3,0);
	setLift (0);
	go ();

	//forward shuttle
	setBase (0,0,0);
	setLift (0);
	setShuttle (1);
	go ();

	//grab
	setBase (0,0,0);
	setLift (0);
	setShuttle (0);
	setClaw (-1);
	go ();

	//lift
	setBase (0,0,0);
	setLift (7);
	go ();

	//spin counterclockwise
	setBase (0,0,-90);
	setLift (0);
	go ();

	//lower
	setBase (0,0,0);
	setLift (-23);
	go ();

	//drop
	setBase (0,0,0);
	setLift (0);
	setClaw (1);
	go ();
}

/**
 * [autonomous or programming skills] strategy # 0
 * Start robot in either square, any direction
 * Robot will lift 12 inches and do a three-sixty
 */

void auton2()
{
	//drive forward 24"
	setBase(-100,0,0);
	go();

	//drive forward 24"
	setBase(100,0,0);
	go();

/*	//drive diagonally
	setBase(24,24,0);
	go();

	setBase(-8,-20,0);
	go();

	//shuttle out
	setShuttle(1);
	go();

	//shuttle out
	setShuttle(-1);
	go();

	//lift up 48"
	setLift(48);
	go();
*/}

/*
//Basic commands setBase(forward, right, spin) setLift(distance, speed) setShuttle() setClaw() go()
//Sign of distance determines direction, speed should always be positive

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

//Programming Skills strategy #1: ___
//Start robot in ___ square, facing ___.
void auton1()
{
	//Skills Strat 1
	//push cube onto skyrise base
	setBase(0,2,0);
	setLift(0);
	go();
	//Onward!!
	setBase(136,0,0);
	setLift(0);
	go();
	//left
	setBase(0,-20,0);
	setLift(0);
	go();
	//right
	setBase(0,40,0);
	setLift(0);
	go();
}

//
//Start robot in left square, facing in
void auton2()
{
	//Nudge preload onto skyrise base (right)
	setBase(0,6,0);
	go();
	//Move away in order to get a point for the preload cube (forward + left)
	//setBase(6,-6,0);
	//go();
}

*/
//Start robot in red skyrise square, facing skyrise
void auton3()
{
	setClaw(-1);
	setShuttle(1);
	go();

	setClaw(1);
	vexSleep(400);

	setLift(900);
	go();
	vexSleep(500);

	setBase(0, 0, -295);
	go();
	vexSleep(700);

	// setBase(30,0,0);
	// go();
	// vexSleep(500);

	setLift(-700);
	go();

	setClaw(-1);
	vexSleep(300);

	setShuttle(-1);
	go();
}

//
//Start robot in blue skyrise square, facing skyrise.
void auton4()
{
	setClaw(-1);
	setShuttle(1);
	go();

	setClaw(1);
	vexSleep(400);

	setLift(1200);
	go();
	vexSleep(500);

	setBase(0, 0, 290);
	go();
	vexSleep(700);

	// setBase(15,0,0);
	// go();
	// vexSleep(500);

	setLift(-900);
	go();

	setClaw(-1);
	vexSleep(300);
	
	setShuttle(-1);
	go();
}

//Start in blue low post square facing between short post and skyrise
void auton5()
{
	setLift(2000);
	go();
	vexSleep(400);

	setBase(0,0,152);
	go();

	setLift(-1700);
	go();
	vexSleep(400);

	setBase(-500,0,0);
	go();

}

//Start in red low post square facing between short post and skyrise
void auton6()
{
	setLift(2000);
	go();
	vexSleep(400);

	setBase(0,0,-152);
	go();

	setLift(-1700);
	go();
	vexSleep(400);

	setBase(-500,0,0);
	go();
}

//
//Start robot in ___ square, facing ___.
void auton7()
{
	
}

//lift 12"
void lift12()
{
	setLift(12);
}
