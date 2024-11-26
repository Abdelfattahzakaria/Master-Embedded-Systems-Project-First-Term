/*
 *   Topic   :                                                     Pressure Alarm Tracer
 *   File    :                                                     __PRESSURE_H__
 *   Author  :                                                     abdelfattahzakariaelbadry@gmail.com
*/


/* * This Header File Aims To Decleare The Pressure Sensors Tracer Prototype Functions And There Associated Structure*/

// Header Protection
#ifndef __PRESSURE_H__ 
#define __PRESSURE_H__


#include "state.h" 


enum
{
	WAITING , 
	READING ,
	INIT 
}ST_Preasure_Sensor_State; 


// Decleare A Pointer To A Pressure Sensor Function
void (*Ptr_Pressure_Sensor_Func) (void); 


// Define The Essential Function Associated With Pressure Sensor Jop Using A Smart Macro
ST_define(INIT); 
// void ST_2()

ST_define(WAITING);
// void ST_0()

ST_define(READING);
// void ST_1()


#endif  

   
   

  


