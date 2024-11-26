/*
 *   Topic   :                                                     Pressure Alarm Tracer
 *   File    :                                                     __ALARM_H__
 *   Author  :                                                     abdelfattahzakariaelbadry@gmail.com
*/


/* * This Header File Aims To Decleare The Alarm Actuator Prototype Functions And There Associated Structure*/


// Header Protection
#ifndef __ALARM_H__ 
#define __ALARM_H__

#include "state.h" 
  

enum
{
	ALARM_OFF , 
	ALARM_ON ,
	ALARM_INIT
}ST_Alarm_Actuator_State; 


// Decleare A Pointer To A Alarm Actuator Function
void (*Ptr_Alarm_Actuator_Func) (void); 


// Define The Essential Function Associated With Alarm Actuator Jop Using A Smart Macro
ST_define(ALARM_INIT); 
// void ST_2()

ST_define(ALARM_OFF);
// void ST_0()

ST_define(ALARM_ON);
// void ST_1()


#endif 
  
   
 

        