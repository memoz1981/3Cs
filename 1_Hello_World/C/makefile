ifdef WINDIR
	EXECUTABLE = hello_world.exe
else
	UNAME_S := $(shell uname -s)
	ifeq ($(UNAME_S),Linux)
		EXECUTABLE = hello_world.elf
	endif
endif

hello: main.c
	gcc -o $(EXECUTABLE) main.c >null 