ifdef WINDIR
	EXECUTABLE = orchestrate.exe
else
	UNAME_S := $(shell uname -s)
	ifeq ($(UNAME_S),Linux)
		EXECUTABLE = orchestrate.elf
	endif
endif

orchestrate: main.c orchestrator.c op_system_commands.c
	gcc -o $(EXECUTABLE) main.c orchestrator.c op_system_commands.c -I.2 >null