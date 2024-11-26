/*
 *   Topic   :                                                     Pressure Alarm Tracer
 *   File    :                                                     __ALARM_C__
 *   Author  :                                                     abdelfattahzakariaelbadry@gmail.com
*/


/* * This Header File Aims To Define The Alarm Actuator Prototype FunctiALARM_ONs Body*/


#include "alarm.h" 


// Define The Local File Static Variables
static vsint32_t count= 250;  

 
// Define A Pointer To A Alarm Actuator FunctiALARM_ON
void (*Ptr_Alarm_Actuator_Func) (void); 


// Define The Prototypes FunctiALARM_ONs Body
ST_define(ALARM_INIT)
{
	// Sate Id | Name: ALARM_INIT-->> 2
	ST_Alarm_Actuator_State= ALARM_INIT; 
	
	//Sate ActiALARM_ON: Assign Ptr_Alarm_Actuator_Func With The Address Of ALARM_IniTial | Startup | Power ALARM_ON Sate "ALARM_OFF": ST_define(ALARM_OFF) -->> ST_2
	Ptr_Alarm_Actuator_Func= State(ALARM_OFF);
	
	return;
}         

ST_define(ALARM_OFF)
{
    // Sate Id | Name: ALARM_OFF-->> 0
	ST_Alarm_Actuator_State= ALARM_OFF;  
	
	// State ActiALARM_ON: Diseable Alarm Actuator 
	// Using set_alarm_actuator API
	Set_Alarm_actuator(0); 
	
	// Assign Ptr_Alarm_Actuator_Func With Current State FunctiALARM_ON: ST_define(ALARM_OFF) -->> ST_0
	Ptr_Alarm_Actuator_Func= State(ALARM_OFF); 
	
	return;
}


ST_define(ALARM_ON)
{
	// Sate Id | Name: ALARM_ON-->> 1
	ST_Alarm_Actuator_State= ALARM_ON; 
	
	// State ActiALARM_ON: enable Alarm Actuator 
	// Using set_alarm_actuator API
	Set_Alarm_actuator(1); 

	// Making A Delay Using Delay Api
	Delay(count); 
	
	// Turn ALARM_OFF Alarm Actuator Again After The Delay Period
	// Using set_alarm_actuator API
	Set_Alarm_actuator(0); 
	
	// Assign Ptr_Alarm_Actuator_Func With Current State FunctiALARM_ON: ST_define(ALARM_OFF) -->> ST_0
	Ptr_Alarm_Actuator_Func= State(ALARM_OFF); 
	
    return;
} 
   
   

  
     