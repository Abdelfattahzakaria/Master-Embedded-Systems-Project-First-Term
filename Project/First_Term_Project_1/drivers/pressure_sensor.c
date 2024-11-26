/*
 *   Topic   :                                                     Pressure Alarm Tracer
 *   File    :                                                     __PRESSURE_C__
 *   Author  :                                                     abdelfattahzakariaelbadry@gmail.com
*/


/* * This Header File Aims To Define The Pressure Sensors Tracer Prototype Functions Body*/  


#include "pressure_sensor.h" 


// Define The Global Useable Variables Which Will Later Be Externed Into Main.c 
vuint32_t pressure_value= 0;  
vuint32_t threshold= 20;      

 
// Define A Pointer To A Pressure Sensor Function
void (*Ptr_Pressure_Sensor_Func) (void); 


// Define The Prototypes Functions Body
ST_define(INIT)
{
	// Sate Id | Name: INIT-->> 2
	ST_Preasure_Sensor_State= INIT; 
	
	//Sate Action: Assign Ptr_Pressure_Sensor_Func With The Address Of Initial | Startup | Power On Sate Function Whic Is "READING": ST_define(READING) -->> ST_1
    Ptr_Pressure_Sensor_Func= State(READING); 

    return; 	
}                
 

ST_define(WAITING)
{
	vsint32_t i; 
	
	// Sate Id | Name: -->> 0
	ST_Preasure_Sensor_State= WAITING;   
	
	// Sate Action: Making A Delay Using Custom Tradtional Empty Looping
	for(i= 500; i != 0; i--);

    return; 
}
  
 
ST_define(READING)
{
	// Sate Id | Name: INIT-->> 1
	ST_Preasure_Sensor_State= READING; 
	
	//Sate Action: Get Sensor Reads
	// Read Using get_pressure_val API
    pressure_value= getPressureVal();  
	
	// Making A Delay
	State_Call(WAITING);
	
	// Assign Ptr_Pressure_Sensor_Func With Current State Function: ST_define(WAITING) -->> ST_0
    Ptr_Pressure_Sensor_Func= State(READING);   

    return; 	
}    
  
   
 

  
    