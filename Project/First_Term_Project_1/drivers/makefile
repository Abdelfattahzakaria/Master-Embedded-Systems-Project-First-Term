#  
#                                             A Smart Makefile To Automate The Building Process 
#                                             -----> Makefiles require tabs (not spaces) to indicate the start of a command under a target
#
C-TC-MC= arm-none-eabi-
COM-FLAGS= -mcpu=cortex-m3 -mthumb -gdwarf-2
H-INCS= -I .
S-LIBS-INCS= 
CSRC= $(wildcard *.c)
COBJ= $(CSRC:.c=.o)  
ASSRC= $(wildcard *.s)
ASOBJ= $(ASSRC:.s=.o)  
PROJECT-NAME= Pressure_Tracer
                

all: $(PROJECT-NAME).bin  
	@echo "--------------Sucess: Building Is Done After Call $(PROJECT-NAME).bin-" 
 

$(PROJECT-NAME).bin: $(PROJECT-NAME).elf            
	$(C-TC-MC)objcopy.exe -O binary $< $@  

	@echo "--------------Sucess: building operation is done----------------------------------------" 
	
	        
$(PROJECT-NAME).elf: $(COBJ) $(ASOBJ)          
	$(C-TC-MC)ld.exe -T linker_script.ld $(S-LIBS-INCS) $(ASOBJ) $(COBJ) -o $@ -Map=Map_file.map                   
      
	@echo "--------------Sucess: Linking operation is done-----------------------------------------"
	    
	
%.o: %.s                    
	$(C-TC-MC)as.exe $(COM-FLAGS) $< -o $@
  
	@echo "--------------Sucess: Assmebling operation For .o File is done--------------------------" 
	
	          
%.o: %.c  
	$(C-TC-MC)gcc.exe $(COM-FLAGS) $(H-INCS) -c $< -o $@

	@echo "--------------Sucess: Compling & Assmebling operations For .c File is done--------------"
                
     
clean-all: 
	rm *.o *.elf *.map *.bin    
	
	@echo "--------------Sucess: all files are deleted---------------------------------------------"
	
clean-o: 
	rm *.o 
	
	@echo "--------------Sucess: all .o files are deleted------------------------------------------"
	
clean-elf: 
	rm *.elf *.map *.bin
   
	@echo "--------------Sucess: all .elf files are deleted & bin files as a result of it----------"
  
            
	     		  
                                                                                                               