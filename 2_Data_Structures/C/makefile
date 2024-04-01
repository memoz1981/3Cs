ifdef WINDIR
	EXECUTABLE = data_structures.exe
else
	UNAME_S := $(shell uname -s)
	ifeq ($(UNAME_S),Linux)
		EXECUTABLE = data_structures.elf
	endif
endif

data_structures: main.c hashset.c linkedlist.c list.c queue.c stack.c tree.c
	gcc -o $(EXECUTABLE) main.c hashset.c linkedlist.c list.c queue.c stack.c tree.c >null 