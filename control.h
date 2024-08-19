/*
 * control.h
 *
 *  Created on: Aug 18, 2024
 *      Author: Mariam
 */

#ifndef CONTROL_H_
#define CONTROL_H_


#define LIGHT_PIN 0
#define DOOR_PIN 1
#define ALARM_PIN 2


void control_light(int state);
void control_door(int state) ;
void activate_alarm();

#endif /* CONTROL_H_ */
