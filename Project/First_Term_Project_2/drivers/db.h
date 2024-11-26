/*
 *   Topic   :                                                     Student Data Base
 *   File    :                                                     __DB_H__
 *   Author  :                                                     abdelfattahzakariaelbadry@gmail.com
*/


/* *This Header File Aims To Define Required Functions Prototypes For Students DB*/

/*Header Protection*/
#ifndef __DB_H__
#define __DB_H__


/*Including Libs*/
#include <stdio.h>
#include <string.h> 
#include "datatype.h"  


/*Macros*/ 
#define  DPrintf(...)                                            {printf(__VA_ARGS__);\
                                                                  fflush(stdin);\
																  fflush(stdout);}   
																  
																  
/*Define Required Structures*/ 
typedef struct
{
	vuint8_t first_name[30];
	vuint8_t second_name[30];
    vuint32_t roll; 
    vfloat32_t gpa;
    vuint32_t cid[4]; 	
}SStudent_Info_t; 

typedef struct
{
	SStudent_Info_t *base; 
	SStudent_Info_t *head; 
	SStudent_Info_t *tail; 
    vuint32_t students_count; 	
}SDB_t;

typedef enum
{
	DB_NULL ,
	DB_EMPTY ,
	DB_ERROR , 
	DB_FULL ,
	DB_NO_ERROR
}EDB_Status_t;


/*Required Functions Prototypes*/
/*                        DB                                                                         */
EDB_Status_t init_db                                           (SDB_t *db , SStudent_Info_t *data_arr);
EDB_Status_t db_is_null                                        (SDB_t *db);
EDB_Status_t db_is_empty                                       (SDB_t *db);
EDB_Status_t db_is_full                                        (SDB_t *db);
vuint8_t db_roll_exist_or_not                                  (SDB_t *db , vuint32_t roll);
/*                        Students                                                                    */
EDB_Status_t add_student_manully                               (SDB_t *db); 
EDB_Status_t add_student_from_file                             (SDB_t *db); 
EDB_Status_t delete_student                                    (SDB_t *db); 
EDB_Status_t show_all_students                                 (SDB_t *db); 
EDB_Status_t find_by_fname                                     (SDB_t *db); 
EDB_Status_t find_by_roll                                      (SDB_t *db); 
EDB_Status_t find_total_count                                  (SDB_t *db); 
EDB_Status_t update_student_record                             (SDB_t *db);
/*                        Courses                                                                    */ 
EDB_Status_t number_course_students                            (SDB_t *db);  


#endif


          
		    