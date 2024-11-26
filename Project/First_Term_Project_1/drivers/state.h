/*
 *   Topic   :                                                     Pressure Alarm Tracer
 *   File    :                                                     __STATE_H__
 *   Author  :                                                     abdelfattahzakariaelbadry@gmail.com
*/


/* * This Header File Aims To Define Smart Prototype Functions Macro For Differrent Useable Functions Names*/

// Header Protection
#ifndef __STATE_H__ 
#define __STATE_H__ 


#include "datatype.h"

/* *Smart Prototype Functions Macros*/ 
#define ST_define(_stateFunc_)                                    void ST_##_stateFunc_()
// Macro To Generate | Get Only The Function To Assigin It To A Pointer To Func
#define State(_stateFunc_)                                        ST_##_stateFunc_ 
// Macro To Call A Function
#define State_Call(_stateFunc_)                                    ST_##_stateFunc_() 


/* *Driver.h Useable API Interfaces*/
void Delay(int nCount);
int getPressureVal();
void Set_Alarm_actuator(int i);
void GPIO_INITIALIZATION (); 


#endif 
 
     
    
            