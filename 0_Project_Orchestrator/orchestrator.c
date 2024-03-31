#include "orchestrator.h"
#include "op_system_commands.h"
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdio.h>

void build_project_c(struct project_demo* project, char* command);
void build_project_c_sharp(struct project_demo* project, char* command);
void run_project_c(struct project_demo* project, char* command);
void run_project_c_sharp(struct project_demo* project, char* command);

struct project_demo* initialize_project(
    char* relative_path, 
    enum project_type project_type,
    char* executable_name, 
    char* project_name)
    {
        // Assertions
        assert(strlen(relative_path) <= MAX_PATH_LENGTH); 
        assert(strlen(executable_name) <= MAX_PATH_LENGTH); 
        assert(strlen(project_name) <= MAX_PATH_LENGTH); 
        
         /* Memory allocation */
        struct project_demo* project = (struct project_demo*)malloc(sizeof(struct project_demo));

        /* free allocated memory for strings */
        project->relative_path = (char*)malloc(MAX_PATH_LENGTH * sizeof(char));
        project->relative_path = '\0'; 

        project->executable_name = (char*)malloc(MAX_NAME_LENGTH * sizeof(char));
        project->executable_name = '\0';

        project->project_name = (char*)malloc(MAX_PATH_LENGTH * sizeof(char));
        project->project_name = '\0'; 

        /* field allocations */ 
        project->relative_path = relative_path; 
        project->executable_name = executable_name; 
        project->project_name = project_name; 

        project->project_type = project_type; 

        printf("Initialized project: path: %s, executable: %s, name: %s, type: %d\n",
            project->relative_path, project->executable_name, project->project_name, project->project_type); 

        return project; 
    }

int build_project(struct project_demo* project)
{
    char* command = (char*)malloc(512 * sizeof(char)); 
    command = '\0'; 

    switch(project->project_type) {
        case PROJECT_TYPE_C:
            build_project_c(project, command); 
            break; 
        case PROJECT_TYPE_C_SHARP:
            build_project_c_sharp(project, command); 
            break; 
        default:
            break; 
    }

    strcat(command, " >$null");
    int result = system(command); 
    free(command); 

    return result; 
}

int run_project(struct project_demo* project)
{
    char* command = (char*)malloc(512 * sizeof(char)); 
    command = 0; 

    switch(project->project_type) {
        case PROJECT_TYPE_C:
            run_project_c(project, command); 
            break; 
        case PROJECT_TYPE_C_SHARP:
            run_project_c_sharp(project, command); 
            break; 
        default:
            break; 
    }
    
    int result = system(command); 
    
    free(command); 

    return result; 
}

void build_project_c(struct project_demo* project, char* command)
{
    strcat(command, "make"); 
}

void build_project_c_sharp(struct project_demo* project, char* command)
{
    strcat(command, "powershell.exe dotnet build "); 
}

void run_project_c(struct project_demo* project, char* command)
{
    strcat(command, project->executable_name); 
    strcat(command, " "); 
}

void run_project_c_sharp(struct project_demo* project, char* command)
{
    strcat(command, "powershell.exe dotnet run --project "); 
}