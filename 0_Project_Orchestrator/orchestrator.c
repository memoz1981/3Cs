#include "orchestrator.h"
#include <stdlib.h>
#include <assert.h>
#include <string.h>

void BuildC(struct ProjectDemo* project, char* command);
void BuildCSharp(struct ProjectDemo* project, char* command);
void RunC(struct ProjectDemo* project, char* command);
void RunCSharp(struct ProjectDemo* project, char* command);

struct ProjectDemo* InitializeNewProjectDemo(
    char* relative_path, 
    char* executable_name, 
    char* build_arguments,
    enum ProjectType project_type,
    int project_id,
    char* project_name,
    char* run_arguments)
    {
        /* Get current directory */
        char current_directory[MAX_PATH_LENGTH];
        getcwd(current_directory, MAX_PATH_LENGTH); 

        /* Validations */
        assert(strlen(relative_path) <= MAX_PATH_LENGTH); 
        assert(strlen(current_directory) <= MAX_PATH_LENGTH); 
        if(project_type == PROJECT_TYPE_C)
        {
            assert(strlen(executable_name) <= MAX_NAME_LENGTH); 
        }
        assert(strlen(project_name) <= MAX_NAME_LENGTH); 
        assert(strlen(build_arguments) <= MAX_ARGUMENT_LENGTH);
        assert(strlen(run_arguments) <= MAX_ARGUMENT_LENGTH); 
        assert(project_id > 0); 
 
         /* Memory allocation */
        struct ProjectDemo* project = (struct ProjectDemo*)malloc(sizeof(struct ProjectDemo));

        /* free allocated memory for strings */ 
        memset(project->relative_path, '\0', MAX_PATH_LENGTH); 
        memset(project->current_directory, '\0', MAX_PATH_LENGTH); 
        memset(project->executable_name, '\0', MAX_NAME_LENGTH); 
        memset(project->project_name, '\0', MAX_ARGUMENT_LENGTH); 
        memset(project->build_arguments, '\0', MAX_ARGUMENT_LENGTH); 
        memset(project->run_arguments, '\0', MAX_ARGUMENT_LENGTH); 

        /* field allocations */ 
        strcpy(project->relative_path, relative_path); 
        strcpy(project->current_directory, current_directory); 
        if(project_type != PROJECT_TYPE_C_SHARP)
        {
            strcpy(project->executable_name, executable_name); 
        }
        strcpy(project->project_name, project_name); 
        strcpy(project->build_arguments, build_arguments); 
        strcpy(project->run_arguments, run_arguments); 

        project->project_type = project_type; 
        project->project_id = project_id; 

        return project; 
    }

int Build(struct ProjectDemo* project)
{
    chdir(project->relative_path); 
    char* command = (char*)malloc(512 * sizeof(char)); 
    memset(command, '\0', 512); 

    switch(project->project_type) {
        case PROJECT_TYPE_C:
            BuildC(project, command); 
            break; 
        case PROJECT_TYPE_C_SHARP:
            BuildCSharp(project, command); 
            break; 
        default:
            break; 
    }

    strcat(command, " >$null");
    int result = system(command); 
    free(command); 

    return result; 
}

int Run(struct ProjectDemo* project)
{
    char* command = (char*)malloc(512 * sizeof(char)); 
    memset(command, '\0', 512); 

    switch(project->project_type) {
        case PROJECT_TYPE_C:
            RunC(project, command); 
            break; 
        case PROJECT_TYPE_C_SHARP:
            RunCSharp(project, command); 
            break; 
        default:
            break; 
    }
    
    int result = system(command); 
    
    free(command); 

    chdir(project->current_directory); 
    return result; 
}

void Project_Demo_To_String(struct ProjectDemo* project)
{
    char* output = (char*)malloc(64 * sizeof(char)); 
    memset(output, '\0', 64); 
    strcat(output, "\n"); 
    if(project->project_type == PROJECT_TYPE_C)
    {
        strcat(output, "PROJECT TYPE: C; ");
    }
    else if(project->project_type == PROJECT_TYPE_C_SHARP)
    {
        strcat(output, "PROJECT TYPE: C#; ");
    }
    else if(project->project_type == PROJECT_TYPE_C_PLUS_PLUS)
    {
        strcat(output, "PROJECT TYPE: C++; ");
    }
    else
    {
        strcat(output, "PROJECT TYPE: UNKNOWN; ");
    }
    
    strcat(output, "NAME: ");
    strcat(output, project->project_name); 

    strcat(output, "; ID: ");
    char numStr[2];
    sprintf(numStr, "%d", project->project_id);
    strcat(output, numStr); 
    strcat(output, ".\n");

    printf(output); 
    free(output);  
}

void BuildC(struct ProjectDemo* project, char* command)
{
    strcat(command, "powershell.exe gcc.exe -o "); 
    strcat(command, project->executable_name);
    strcat(command, " -w ");
    strcat(command, project->build_arguments);
}

void BuildCSharp(struct ProjectDemo* project, char* command)
{
    strcat(command, "powershell.exe dotnet build "); 
    strcat(command, project->build_arguments); 
}

void RunC(struct ProjectDemo* project, char* command)
{
    strcat(command, project->executable_name); 
    strcat(command, " "); 
    strcat(command, project->run_arguments); 
}

void RunCSharp(struct ProjectDemo* project, char* command)
{
    strcat(command, "powershell.exe dotnet run --project "); 
    strcat(command, project->run_arguments); 
}