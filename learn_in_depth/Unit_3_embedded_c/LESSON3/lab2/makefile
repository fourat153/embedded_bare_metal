CC= arm-none-eabi-
CFLAGS = -mcpu=cortex-m3 -gdwarf-2
INCS= -I .
LIBS = 
SRC = $(wildcard *.c) 
OBJ =$(SRC:.c=.o)
As = $(wildcard *.s) 
AsOBJ =$(As:.s=.o)
all : result_code.hex
%.o : %.s 
	$(CC)as.exe  $(CFLAGS)    $< -o $@
%.o : %.c 
	$(CC)gcc.exe   $(CFLAGS)	$(INCS) -c  $< 	-o $@
result_code.elf:$(OBJ) $(AsOBJ)
	$(CC)ld.exe  -T linker_script.ld  $(LIBS) $(OBJ) $(AsOBJ) -o $@  -Map=Map_file.map	
result_code.hex : result_code.elf
	 $(CC)objcopy.exe  -O binary  $<   $@

clean : 
	rm -rf *.o ~* *.elf *.hex
	@echo "everything cleared" 