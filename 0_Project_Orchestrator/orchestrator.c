#include "orchestrator.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

char* GetCurrentDirectory();
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
        char* current_directory = GetCurrentDirectory();

        /* Validations */
        assert(strlen(relative_path)<=1024); 
        assert(strlen(current_directory)<=1024); 
        assert(strlen(executable_name)<=64); 
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
        strcpy(project->executable_name, executable_name); 
        strcpy(project->arguments, arguments); 

        return project; 
    }

/* private method to return running directory*/
char* GetCurrentDirectory()
{
    char cwd[1024];
    return getcwd(cwd, sizeof(cwd)); 
}

ChangeDirectory(char* relative_path)
{
    chdir(relative_path); 
}

int Build(struct ProjectDemo* project)
{
    ChangeDirectory(project->relative_path); 
    char* command = (char*)malloc(512 * sizeof(char)); 
    memset(command, '\0', 512); 

    switch(project->project_type) {
        case C:
            BuildC(project, command); 
            break; 
        case C_Sharp:
            BuildCSharp(project, command); 
            break; 
        default:
            break; 
    }

    system(command); 
    free(command); 
}

int Run(struct ProjectDemo* project)
{
    char* command = (char*)malloc(512 * sizeof(char)); 
    memset(command, '\0', 512); 

    switch(project->project_type) {
        case C:
            RunC(project, command); 
            break; 
        case C_Sharp:
            RunCSharp(project, command); 
            break; 
        default:
            break; 
    }

    system(command); 
    free(command); 

    chdir(project->current_directory); 
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