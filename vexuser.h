#ifndef VEXUSER_H
#define VEXUSER_H

/*-----------------------------------------------------------------------------*/
/** @brief      User setup                                                     */
/*-----------------------------------------------------------------------------*/
/**
 * @brief      User setup
 * @details
 *  The digital and motor ports can (should) be configured here.
 */
void vexUserSetup();

/**
 * @brief      User initialize
 * @details
 *  This function is called after all setup is complete and communication has
 *  been established with the master processor.
 *  Start other tasks and initialize user variables here
 */
void vexUserInit();

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

#endif // VEXUSER_H
