/*
 *   Topic   :                                                     Pressure Alarm Tracer
 *   File    :                                                     __MAIN_C__
 *   Author  :                                                     abdelfattahzakariaelbadry@gmail.com
*/   

// Including Essential Sensors | Actuators | MC Header Files   
#include <stdint.h>
#include "driver.h" 
#include "pressure_sensor.h" 
#include "alarm.h"


// Include Common Operational Variables Aomng Differrent Components
extern vuint32_t pressure_value;  
extern vuint32_t threshold;  


// Define The Setup Function To Init Differrent Components Into Init | Startup | Power On State
void setup(void)
{
	// Enable | Init GPIO Target Port 
	GPIO_INITIALIZATION();
	
	// Init Pressure Sensor Into Init | Startup | Power On State
	Ptr_Pressure_Sensor_Func= State(INIT);
    Ptr_Pressure_Sensor_Func();
	
	// Init Alarm Actuator Into Init | Startup | Power On State
	Ptr_Alarm_Actuator_Func= State(ALARM_INIT);
	
	return; 
} 

 
int main(void)
{
	setup(); 
	
	while(True)
	{
		// Get Pressure Sensor Reads
		Ptr_Pressure_Sensor_Func(); 
		
		// Check Up Reads Aganist Tareget Threshold
		if(pressure_value >= threshold)
		{
			// Enable Alarm Actuator For A Time Period Then Turn OFF It
			// a: Assign Ptr_Alarm_Actuator_Func With Alarm On Function Address
			Ptr_Alarm_Actuator_Func= State(ALARM_ON);
			// b: Jump To Function Block Ins
			Ptr_Alarm_Actuator_Func();
		}
	}
	
	return 0;     
}         
  
  
 
            