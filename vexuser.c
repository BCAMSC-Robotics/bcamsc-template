/**
 * This file contains the definitions of functions called by the VEX field
 * control system.
 */
#include <stdlib.h>
#include <math.h>
#include <string.h>

#include "ch.h"         // needs for all ChibiOS programs
#include "hal.h"        // hardware abstraction layer header
#include "vex.h"        // vex library header
#include "vexuser.h"    // function declarations
#include "smartmotor.h" // the library for smart motors

#if DEBUG
#include "apollo.h"     // the library that includes the apollo debug window in screen
#endif /* DEBUG */

// Digi IO configuration
static vexDigiCfg dConfig[kVexDigital_Num] = { { kVexDigital_1,
		kVexSensorDigitalOutput, kVexConfigOutput, 0 }, { kVexDigital_2,
		kVexSensorDigitalOutput, kVexConfigOutput, 0 }, { kVexDigital_3,
		kVexSensorDigitalInput, kVexConfigInput, 0 }, { kVexDigital_4,
		kVexSensorDigitalInput, kVexConfigInput, 0 }, { kVexDigital_5,
		kVexSensorDigitalInput, kVexConfigInput, 0 }, { kVexDigital_6,
		kVexSensorDigitalInput, kVexConfigInput, 0 }, { kVexDigital_7,
		kVexSensorDigitalInput, kVexConfigInput, 0 }, { kVexDigital_8,
		kVexSensorDigitalInput, kVexConfigInput, 0 }, { kVexDigital_9,
		kVexSensorDigitalInput, kVexConfigInput, 0 }, { kVexDigital_10,
		kVexSensorDigitalInput, kVexConfigInput, 0 }, { kVexDigital_11,
		kVexSensorDigitalInput, kVexConfigInput, 0 }, { kVexDigital_12,
		kVexSensorDigitalInput, kVexConfigInput, 0 } };

static vexMotorCfg mConfig[kVexMotorNum] = { { kVexMotor_1, kVexMotor393T,
		kVexMotorNormal, kVexSensorIME, kImeChannel_1 }, { kVexMotor_2,
		kVexMotorUndefined, kVexMotorNormal, kVexSensorNone, 0 }, { kVexMotor_3,
		kVexMotorUndefined, kVexMotorNormal, kVexSensorNone, 0 }, { kVexMotor_4,
		kVexMotorUndefined, kVexMotorNormal, kVexSensorNone, 0 }, { kVexMotor_5,
		kVexMotorUndefined, kVexMotorNormal, kVexSensorNone, 0 }, { kVexMotor_6,
		kVexMotorUndefined, kVexMotorNormal, kVexSensorNone, 0 }, { kVexMotor_7,
		kVexMotorUndefined, kVexMotorNormal, kVexSensorNone, 0 }, { kVexMotor_8,
		kVexMotorUndefined, kVexMotorNormal, kVexSensorNone, 0 }, { kVexMotor_9,
		kVexMotorUndefined, kVexMotorNormal, kVexSensorNone, 0 }, {
		kVexMotor_10, kVexMotor393T, kVexMotorNormal, kVexSensorIME,
		kImeChannel_2 } };

void vexUserSetup() {
	vexDigitalConfigure(dConfig, DIG_CONFIG_SIZE(dConfig));
	vexMotorConfigure(mConfig, MOT_CONFIG_SIZE(mConfig));
}

void vexUserInit() {

}

msg_t vexAutonomous(void *arg) {
	(void) arg;

	// Must call this
	vexTaskRegister("auton");

	while (1) {
		// Don't hog cpu
		vexSleep(25);
	}

	return (msg_t) 0;
}

#define MotorDriveL     kVexMotor_1
#define MotorDriveR     kVexMotor_10

msg_t vexOperator(void *arg) {
	int16_t blink = 0;

	(void) arg;

	// Must call this
	vexTaskRegister("operator");

	// Run until asked to terminate
	while (!chThdShouldTerminate()) {
		// flash led/digi out
		vexDigitalPinSet(kVexDigital_1, (blink++ >> 3) & 1);

		// status on LCD of encoder and sonar
		vexLcdPrintf( VEX_LCD_DISPLAY_2, VEX_LCD_LINE_1, "%4.2fV   %8.1f",
				vexSpiGetMainBattery() / 1000.0, chTimeNow() / 1000.0);
		vexLcdPrintf( VEX_LCD_DISPLAY_2, VEX_LCD_LINE_2, "L %3d R %3d",
				vexMotorGet( MotorDriveL), vexMotorGet( MotorDriveR));

		// Tank drive
		// left drive
		vexMotorSet( MotorDriveL, vexControllerGet(Ch3));

		// right drive
		vexMotorSet( MotorDriveR, vexControllerGet(Ch2));

		// Don't hog cpu
		vexSleep(25);
	}

	return (msg_t) 0;
}

