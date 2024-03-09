#include "orchestrator.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

ChangeDirectory(char* relative_path);
void BuildC(struct ProjectDemo* project, char* command);
void BuildCSharp(struct ProjectDemo* project, char* command);
void RunC(struct ProjectDemo* project, char* command);
void RunCSharp(struct ProjectDemo* project, char* command);

struct ProjectDemo* InitializeNewProjectDemo(
    char* relative_path, 
    char* executable_name, 
    char* arguments,
    enum ProjectType project_type)
    {
        /* Get current directory */
        char current_directory[1024];
        getcwd(current_directory, sizeof(current_directory)); 

        /* Validations */
        assert(strlen(relative_path)<=1024); 
        assert(strlen(current_directory)<=1024); 
        if(project_type == PROJECT_TYPE_C)
        {
            assert(strlen(executable_name)<=64); 
        }
        
        assert(strlen(arguments)<=256); 

        /* Memory allocation */
        struct ProjectDemo* project = (struct ProjectDemo*)malloc(sizeof(struct ProjectDemo));

        /* free allocated memory for strings */ 
        memset(project->relative_path, '\0', 1024); 
        memset(project->current_directory, '\0', 1024); 
        memset(project->executable_name, '\0', 64); 
        memset(project->arguments, '\0', 256); 

        /* field allocations */ 
        strcpy(project->relative_path, relative_path); 
        strcpy(project->current_directory, current_directory); 
        strcpy(project->arguments, arguments); 
        if(project_type != PROJECT_TYPE_C_SHARP)
        {
            strcpy(project->executable_name, executable_name); 
        }

        project->project_type = project_type; 
        return project; 
    }

ChangeDirectory(char* relative_path)
{
    chdir(relative_path); 
}

int Build(struct ProjectDemo* project)
{
    printf("Building..."); 
    ChangeDirectory(project->relative_path); 
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

    system(command); 
    free(command); 
    printf("Built"); 
}

int Run(struct ProjectDemo* project)
{
    printf("Running"); 
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

    system(command); 
    free(command); 

    chdir(project->current_directory); 
    printf("Ran..."); 
}

void BuildC(struct ProjectDemo* project, char* command)
{
    strcat(command, "powershell.exe gcc.exe -o "); 
    strcat(command, project->executable_name);
    strcat(command, " -w ");
    strcat(command, project->arguments);
}

void BuildCSharp(struct ProjectDemo* project, char* command)
{
    strcat(command, "powershell.exe dotnet build "); 
    strcat(command, project->arguments); 
}

void RunC(struct ProjectDemo* project, char* command)
{
    strcat(command, project->executable_name); 
}

void RunCSharp(struct ProjectDemo* project, char* command)
{
    strcat(command, "powershell.exe dotnet run --project "); 
    strcat(command, project->arguments); 
}