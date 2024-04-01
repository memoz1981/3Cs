#include "op_system_commands.h"
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>

char* return_clear_screen_command()
{
    #ifdef _WIN32
        return "cls";
    #elif __linux__
        return "clear";
    #else
        return ""; 
    #endif

}

char* return_c_project_run_command(char* proj_name)
{
    assert((int)strlen(proj_name) < MAX_COMMAND_LENGTH - 4); //.exe or .elf will be added to proj.name
    char* command = (char*)malloc(MAX_COMMAND_LENGTH * sizeof(char)); 
    memset(command, '\0', MAX_COMMAND_LENGTH); 
    
    strcat(command, "./"); 
        strcat(command, proj_name); 

    #ifdef _WIN32
        strcat(command, ".exe"); 
    #elif __linux__
        strcat(command, ".elf"); 
    #else
        return ""; 
    #endif

    return command; 
}