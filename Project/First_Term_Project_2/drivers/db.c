/*
 *   Topic   :                                                     Student Data Base
 *   File    :                                                     __DB_C__
 *   Author  :                                                     abdelfattahzakariaelbadry@gmail.com
*/


/* *This Header File Aims To Define Required Body For Each Functions Prototypes For Students DB*/


#include "db.h" 


/*Define The Global Variables That Will Be Externed Into Main.c*/ 
vuint32_t db_length= 50;   
   

EDB_Status_t init_db                                           (SDB_t *db , SStudent_Info_t *data_arr)
{
	if(!data_arr)
	{
		DPrintf("\n[Erorr]: Initialize db with an empty data");
		return DB_NULL;
	}
	
	db->base= data_arr; 
	db->head= data_arr;
	db->tail= db->base;
	db->students_count= 0; 
	
	return DB_NO_ERROR;
} 


EDB_Status_t db_is_null                                        (SDB_t *db)
{
	if(db == NULL)
		return DB_NULL;		
	if(db->base || db->head || db->tail)    
        return DB_NO_ERROR;    
               
	return DB_NULL;            
}      
    

EDB_Status_t db_is_empty                                       (SDB_t *db)
{
	if(db->head == db-> base)
		return DB_EMPTY; 
	
	return DB_NO_ERROR;
}


EDB_Status_t db_is_full                                        (SDB_t *db)
{
	if(db->head == (db->base + db_length))   
		return DB_FULL; 
	
	return DB_NO_ERROR;
}


vuint8_t db_roll_exist_or_not                              (SDB_t *db , vuint32_t roll)
{
	SStudent_Info_t *temp= db->tail; 
	while(temp < db->head)
	{
		if(temp->roll == roll)
			return True; 
		
		temp++;
	}
	
	return False; 
}    
        
EDB_Status_t add_student_manully                               (SDB_t *db)
{
	if(db_is_null(db) == DB_NULL)
	{
		DPrintf("\n[Error]: Null DB");
		return DB_NULL;
	}
	
	if(db_is_full(db) == DB_FULL)
	{
		DPrintf("\n[Error]: DB Is Full");
		return DB_FULL;
	}
	
	vuint32_t roll; 
	DPrintf("\n\tEnter Student Roll: ");
	scanf("%u" , &roll); 
	
	if(db_roll_exist_or_not(db , roll))
	{
		DPrintf("\n[Error]: Student Record Is Already Exsited");
		return DB_ERROR;
	}
	
	db->head->roll= roll;
	
	DPrintf("\n\tEnter Student First Name: ");
	gets(db->head->first_name);
	
	DPrintf("\n\tEnter Student Second Name: ");
	gets(db->head->second_name);
	
	DPrintf("\n\tEnter Student GPA: ");
	scanf("%f" , &(db->head->gpa));
	
	for(vuint8_t i= 0; i <= 3; i++)
	{
		DPrintf("\n\tEnter Course %u Id Associated With Student: " , i + 1);
     	scanf("%u" , &(db->head->cid[i]));
	}
	
	db->students_count++; 
	
	db->head++; 
	
	DPrintf("\n[Success] New Student Is Recorded Successfully");
	
	DPrintf("\n[Info] Total Number Of Students Within DB: %u" , db->students_count);
	DPrintf("\n[Info] You Can Add New Records Till: %u" , db_length - db->students_count);
	
	
	return DB_NO_ERROR;
}


EDB_Status_t add_student_from_file                             (SDB_t *db)
{
	if(db_is_null(db) == DB_NULL)
	{
		DPrintf("\n[Error]: Null DB");
		return DB_NULL;
	}
	
	if(db_is_full(db) == DB_FULL)
	{
		DPrintf("\n[Error]: DB Is Full");
		return DB_FULL;
	}
	
	FILE *Ptr_Studends_File= fopen("students.txt" , "r");  
		
	while(!feof(Ptr_Studends_File))
	{
		fscanf(Ptr_Studends_File , "%u %s %s %f %u %u %u %u" , 
				&(db->head->roll) , db->head->first_name , db->head->second_name , &(db->head->gpa) , 
				&(db->head->cid[0]) , &(db->head->cid[1]) , &(db->head->cid[2]) , &(db->head->cid[3])); 
		
		if(!db_roll_exist_or_not(db , db->head->roll))
		{
			DPrintf("\n[Success] Successfully Add New Student Recorded With Roll Id: %u" , db->head->roll); 
			db->head++; 
			db->students_count++; 
		}
	}   
	
	DPrintf("\n[Success] New Students Are Recorded Successfully");
	DPrintf("\n[Info] Total Number Of Students Within DB: %u" , db->students_count);
	DPrintf("\n[Info] You Can Add New Records Till: %u" , db_length - db->students_count);
	
	fclose(Ptr_Studends_File);
	
	return DB_NO_ERROR;
}         
          


EDB_Status_t show_all_students                                 (SDB_t *db)
{
	if(db_is_null(db) == DB_NULL)
	{
		DPrintf("\n[Error]: Null DB");
		return DB_NULL;
	}
	
	if(db_is_empty(db) == DB_EMPTY)
	{
		DPrintf("\n[Error]: DB Is Empty");
		return DB_FULL;
	}
	
	SStudent_Info_t *temp= db->tail;  
    vuint32_t index= 1; 
	
	while(temp < db->head)
	{
		DPrintf("\nFor Student Number %u Info Are:" , index); 
		
		DPrintf("\n\tFirst Name  : %s" , temp->first_name);
		DPrintf("\n\tSecond Name : %s" , temp->second_name); 
		DPrintf("\n\tRoll : %u" , temp->roll);
		DPrintf("\n\tGPA  : %f" , temp->gpa);     
		DPrintf("\n\tCourses Id Entrolled By Student Are: "); 
        for(vuint8_t i= 0; i <= 3; i++)
			DPrintf("\n\t\tCourse Number %u Id: %u " , i + 1 , temp->cid[i]);
	    
		index++; 
		temp++;
	}
	 
	DPrintf("\n[Success] Successfully Displayed All Students");
	DPrintf("\n[Info] Total Number Of Students Within DB: %u" , db->students_count);
	DPrintf("\n[Info] You Can Add New Records Till: %u" , db_length - db->students_count);
    
	return DB_NO_ERROR;
}


EDB_Status_t find_by_fname                                     (SDB_t *db)
{
	if(db_is_null(db) == DB_NULL)
	{
		DPrintf("\n[Error]: Null DB");
		return DB_NULL;
	}
	
	if(db_is_empty(db) == DB_EMPTY)
	{
		DPrintf("\n[Error]: DB Is Empty");
		return DB_FULL;
	}
	
	SStudent_Info_t *temp= db->tail;  
    vuint32_t count= 0;
	vuint8_t temp_fname[30];
	
	DPrintf("\n\tEnter Student First Name: ");
	gets(temp_fname);  
	
	while(temp < db->head)
	{
		if(!stricmp(temp->first_name , temp_fname))
		{
			count++; 
			DPrintf("\n[Success-Found]Found One Match , Student Details Are");
			DPrintf("\n\tFirst Name  : %s" , temp->first_name);
		    DPrintf("\n\tSecond Name : %s" , temp->second_name); 
		    DPrintf("\n\tRoll : %u" , temp->roll);
		    DPrintf("\n\tGPA  : %u" , temp->gpa);
		    DPrintf("\n\tCourses Id Entrolled By Student Are: "); 
            for(vuint8_t i= 0; i <= 3; i++)
				DPrintf("\n\t\tCourse Number %u Id: %u " , i + 1 , temp->cid[i]);
		}
		
		temp++; 
	}
	
	if(!count)
	{
		DPrintf("\n[Can-Not-Found] There Are No Matched Students");
		DPrintf("\n[Info] Total Number Of Matched Students Within DB: %u" , count);
		
		return DB_ERROR;
	}
     
	DPrintf("\n[Success] Successfully Displayed All Matched Students");
	DPrintf("\n[Info] Total Number Of Matched Students Within DB: %u" , count);
		
	return DB_NO_ERROR;
}


EDB_Status_t find_by_roll                                      (SDB_t *db)
{
	if(db_is_null(db) == DB_NULL)
	{
		DPrintf("\n[Error]: Null DB");
		return DB_NULL;
	}
	
	if(db_is_empty(db) == DB_EMPTY)
	{
		DPrintf("\n[Error]: DB Is Empty");
		return DB_FULL;
	}
	
	SStudent_Info_t *temp= db->tail;  
	vuint32_t temp_roll;
	vuint8_t flag= 0; 
	
	DPrintf("\n\tEnter Student Roll: ");
	scanf("%u" , &temp_roll);  
	
	while(temp < db->head)
	{
		if(temp->roll == temp_roll)
		{
			flag= 1; 
			
			DPrintf("\n[Success-Found]Found One Match , Student Details Are");
			DPrintf("\n\tFirst Name  : %s" , temp->first_name);
		    DPrintf("\n\tSecond Name : %s" , temp->second_name); 
		    DPrintf("\n\tRoll : %u" , temp->roll);
		    DPrintf("\n\tGPA  : %u" , temp->gpa);
		    DPrintf("\n\tCourses Id Entrolled By Student Are: "); 
            for(vuint8_t i= 0; i <= 3; i++)
				DPrintf("\n\t\tCourse Number %u Id: %u " , i + 1 , temp->cid[i]);
			break;
		}
		
		temp++; 
	}
	
	if(!flag)
	{
		DPrintf("\n[Can-Not-Found] There Are No Matched Students");		
		return DB_ERROR;
	}
     
	DPrintf("\n[Success] Successfully Displayed Matched Student");
		
	return DB_NO_ERROR;
}


EDB_Status_t find_total_count                                  (SDB_t *db)
{
	if(db_is_null(db) == DB_NULL)
	{
		DPrintf("\n[Error]: Null DB");
		return DB_NULL;
	}
	
	if(db_is_empty(db) == DB_EMPTY)
	{
		DPrintf("\n[Error]: DB Is Empty");
		return DB_FULL;
	}
	
	DPrintf("\n[Success] Successfully Count All Students");
	DPrintf("\n[Info] Total Number Of Students Within DB: %u" , db->students_count);
	DPrintf("\n[Info] You Can Add New Records Till: %u" , db_length - db->students_count);
    
	return DB_NO_ERROR;
}


EDB_Status_t update_student_record                             (SDB_t *db)
{
    if(db_is_null(db) == DB_NULL)
	{
		DPrintf("\n[Error]: Null DB");
		return DB_NULL;
	}
	
	if(db_is_empty(db) == DB_EMPTY)
	{
		DPrintf("\n[Error]: DB Is Empty");
		return DB_FULL;
	}
	
	SStudent_Info_t *temp= db->tail;  
	vuint32_t temp_roll;
	vuint8_t flag= 0; 
	
	DPrintf("\n\tEnter Student Roll: ");
	scanf("%u" , &temp_roll);  
	
	while(temp < db->head)
	{
		if(temp->roll == temp_roll)
		{
			flag= 1; 
			
			vuint8_t choice;
			DPrintf("\n========================================");
			DPrintf("\nSelect Your Target Option");
			DPrintf("\n\t1: Update Roll");
			DPrintf("\n\t2: Update First Name");
			DPrintf("\n\t3: Update Second Name");
			DPrintf("\n\t4: Update GPA");
			DPrintf("\n\t5: Update Course Id");
			DPrintf("\n\tEnter Your Choice: ");
			scanf("%u" , &choice);  
			DPrintf("\n========================================");
			
			switch(choice)
			{
				case 1: 
				{
					vuint32_t new_temp_roll; 
					DPrintf("\n\tEnter New Roll: ");
					scanf("%u" , &new_temp_roll);
					  
					if(db_roll_exist_or_not(db , new_temp_roll))
	                {
		                DPrintf("\n[Error]: Student Record Is Already Exsited");
		                return DB_ERROR;
	                }
					
		            temp->roll= new_temp_roll;
					break;
				}
				case 2: 
				{
					DPrintf("\n\tEnter Student First Name: ");
	                gets(temp->first_name);
					break;
				}
				case 3: 
				{
					DPrintf("\n\tEnter Student Second Name: ");
	                gets(temp->second_name);
					break;
				}
				case 4: 
				{
	                DPrintf("\n\tEnter Student GPA: ");
	                scanf("%f" , &(temp->gpa));
					break;
				}
				case 5: 
				{
					vuint32_t cindex , cid;
	                DPrintf("\n\tEnter Course Index: ");
					scanf("%u" , &cindex);
					DPrintf("\n\tEnter Course Id: ");
					scanf("%u" , &cid);
	                if(cindex - 1 >= 4)
					{
						DPrintf("\n[ERROR] Index Out Of Range");
						return DB_ERROR;
					}				
                    temp->cid[cindex]= cid;     					
				   break;
				}
			} 
			
			DPrintf("\n[Success-Update]Sucessfully Update Student Record , Student Details Are");
			DPrintf("\n\tFirst Name  : %s" , temp->first_name);
		    DPrintf("\n\tSecond Name : %s" , temp->second_name); 
		    DPrintf("\n\tRoll : %u" , temp->roll);
		    DPrintf("\n\tGPA  : %f" , temp->gpa);    
		    DPrintf("\n\tCourses Id Entrolled By Student Are: "); 
            for(vuint8_t i= 0; i <= 3; i++)
				DPrintf("\n\t\tCourse Number %u Id: %u " , i + 1 , temp->cid[i]);
			
			break;
		}
		
		temp++; 
	}
	
	if(!flag)
	{
		DPrintf("\n[Can-Not-Found] There Are No Matched Students");		
		return DB_ERROR;
	}
     
	DPrintf("\n[Success] Successfully Updateed Matched Student");
		
	return DB_NO_ERROR;
}


EDB_Status_t number_course_students                            (SDB_t *db)
{
	if(db_is_null(db) == DB_NULL)
	{
		DPrintf("\n[Error]: Null DB");
		return DB_NULL;
	}
	
	if(db_is_empty(db) == DB_EMPTY)
	{
		DPrintf("\n[Error]: DB Is Empty");
		return DB_FULL;
	}
	
	SStudent_Info_t *temp= db->tail;  
	vuint32_t cid;
    vuint8_t count= 0; 
	DPrintf("\n\tEnter Course Id: ");
	scanf("%u" , &cid); 
	
	while(temp < db->head)
	{
		for(vuint8_t i= 0; i <= 3; i++)
		{
			if(temp->cid[i] == cid)
			{
				count++;
				break;
			}				
		}
		
		temp++; 
	}
	
	if(!count)
	{
		DPrintf("\n[Can-Not-Found] There Are No Students Enrolled Target Course");		
		return DB_ERROR;
	}
	
	
	DPrintf("\n[Success] Successfully Count All Students");
	DPrintf("\n[Info] Total Number Of Students Within Target Course Are: %u" , count);
	DPrintf("\n[Info] %u Students Of %u Students Are Enrolled This Course" , count , db->students_count);
    
	return DB_NO_ERROR;
} 


void override_records(SDB_t *db , SStudent_Info_t *current_record)
{
	SStudent_Info_t *next_record= current_record + 1; 
	while(next_record < db->head)
	{
		*current_record= *next_record; 
		current_record= next_record; 
		next_record++;  
	}
	
	return; 
}          

EDB_Status_t delete_student                                    (SDB_t *db)
{
	if(db_is_null(db) == DB_NULL)
	{
		DPrintf("\n[Error]: Null DB");
		return DB_NULL;
	}
	
	if(db_is_empty(db) == DB_EMPTY)
	{
		DPrintf("\n[Error]: DB Is Empty");
		return DB_FULL;
	}
	
	SStudent_Info_t *temp= db->tail;  
	vuint32_t temp_roll;
	vuint8_t flag= 0; 
	
	DPrintf("\n\tEnter Student Roll: "); 
	scanf("%u" , &temp_roll);       
	
	while(temp < db->head)
	{
		if(temp->roll == temp_roll)
		{
			flag= 1; 
			break;
		}
		
		temp++; 
	}       
	 
	if(!flag)
	{
		DPrintf("\n[Can-Not-Found] There Are No Students With Target Roll");		
		return DB_ERROR;
	}
	
	override_records(db , temp); 
	
	db->head--;   
	db->students_count--; 
	
	DPrintf("\n[Success] Successfully Delete Student With Roll: %u" , temp_roll);
	DPrintf("\n[Info] Total Number Of Students Within Target Course Are: %u" , db->students_count);
	DPrintf("\n[Info] You Can Add New Records Till: %u" , db_length - db->students_count);
    
	return DB_NO_ERROR;
}





