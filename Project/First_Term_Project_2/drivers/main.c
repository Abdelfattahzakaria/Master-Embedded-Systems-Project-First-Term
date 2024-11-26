/*
 *   Topic   :                                                     Student Data Base
 *   File    :                                                     __MAIN_C__
 *   Author  :                                                     abdelfattahzakariaelbadry@gmail.com
*/


#include "db.h"


/*Include The Required Common Variables Among Files*/
extern vuint32_t db_length; 


int main(void)
{
	SDB_t db;   
	SStudent_Info_t students_data[db_length]; 
	vuint8_t choice;
	
	init_db(&db , students_data);   
	
	while(True)
	{
		DPrintf("\n==============================================================================================");
		DPrintf("\n==============================================================================================");
		DPrintf("\nSelect Your Target Option");
		DPrintf("\n 1: Add Student Details Manually");
		DPrintf("\n 2: Add Student Details From File");
		DPrintf("\n 3: Delete Student");
		DPrintf("\n 4: Show All Students Details");
		DPrintf("\n 5: Find Students By First Name");
		DPrintf("\n 6: Find Students By Roll Number");
		DPrintf("\n 7: Find Total Number OF Students");
		DPrintf("\n 8: Update Student Record");
		DPrintf("\n 9: Number Of Course Students");
		DPrintf("\n 10: Exist");
		DPrintf("\nEnter Your Choice: "); 		
		scanf("%u" , &choice);    
		DPrintf("\n==============================================================================================");
		DPrintf("\n==============================================================================================");		
		
		switch(choice)
		{
			case 1: 
			{
				add_student_manully(&db);
				break;
			}
			case 2: 
			{
				add_student_from_file(&db);
				break;
			}
			case 3: 
			{
				delete_student(&db);
				break;
			}    
			case 4: 
			{
				show_all_students(&db);
				break;
			}
			case 5: 
			{
				find_by_fname(&db);
				break;
			}
			case 6: 
			{
				find_by_roll(&db);
				break;
			}
			case 7: 
			{
				find_total_count(&db);
				break;
			}
			case 8: 
			{
				update_student_record(&db);
				break;
			}
			case 9: 
			{
				number_course_students(&db);
				break;
			}
			case 10: 
				exit(True);   
			default: 
			{
				DPrintf("\n\t[Error]: Invalid Option");
				break; 
			}
		}
		
	}
	
	return 0;
} 
  
 
 
         
		 
		       