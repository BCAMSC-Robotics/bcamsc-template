/**
 * @file vexuser.h
 *
 * This file contains the functions called by the VEX field control system.
 */

#ifndef VEXUSER_H_
#define VEXUSER_H_

/**
 * @brief      User setup
 * @details
 *  The digital and motor ports can (should) be configured here.
 */
void vexUserSetup(void);

/**
 * @brief      User initialize
 * @details
 *  This function is called after all setup is complete and communication has
 *  been established with the master processor.
 *  Start other tasks and initialize user variables here
 */
void vexUserInit(void);

/**
 * @brief      Autonomous
 * @details
 *  This thread is started when the autonomous period is started
 */
msg_t vexAutonomous(void *arg);

/**
 * @brief      Driver control
 * @details
 *  This thread is started when the driver control period is started
 */
msg_t vexOperator(void *arg);

#endif /* VEXUSER_H_ */
