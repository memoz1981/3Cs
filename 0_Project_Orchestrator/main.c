#include <stdio.h>
#include <stdlib.h>
#include "orchestrator.h"
#include <unistd.h>
#include <string.h>
#include "op_system_commands.h"

#define MAX_PROJECT_COUNT 50

void clear_screen(void); 
int orchestrate(struct project_demo** projects); 
struct project_demo** return_projects();

int main()
{
    int result; 
    struct project_demo** projects = return_projects(); 
    do
    {
        result = orchestrate(projects); 
    } while (result != -1);
    
    for(int i =0; i < MAX_PROJECT_COUNT; i++)
    {
        if(projects[i] == NULL)
            continue; 
        
        free(projects[i]); 
    }

    return 0; 
}

int orchestrate(struct project_demo** projects)
{
    printf("\nSelect project demo to run as below:\n");
    printf("[0] - To clear the screen.\n"); 
    
    char *current_directory = (char*)malloc(MAX_PATH_LENGTH * sizeof(char));
    *current_directory = '\0'; 
    getcwd(current_directory, MAX_PATH_LENGTH); 
    
    for(int i = 1; i <= MAX_PROJECT_COUNT ; i++)
    {
        if(projects[i-1] == NULL)
            continue; 

        printf("[%d] - To run project demo %s\n", i, projects[i-1]->project_name); 
    }

    printf("[-1] to exit.\n"); 
    
    int result; 
    int scanResult = scanf("%d", &result); 
    if(scanResult != 1)
    {
        printf("Invalid selection...\n"); 
        return -1; 
    }

    result--; 
    if(result >= 0 && result < MAX_PROJECT_COUNT && projects[result] != NULL)
    {
        printf("\n\n\n*************PROJECT DEMO OUTPUT*************\n\n\n"); 
        chdir(projects[result]->relative_path); 

        if(build_project(projects[result]))
        {
            printf("Failed to build...\n"); 
        }

        if(run_project(projects[result]))
        {
            printf("Failed to run...\n"); 
        }

        printf("\n\n\n***********END OF PROJECT DEMO OUTPUT***********\n\n\n"); 
        chdir(current_directory); 
        return 0; 
    }
    else if(result == -1)
    {
        clear_screen(); 
    }
    else if(result == -2)
    {
        return -1; 
    }
    else
        printf("Invalid selection..."); 
    
    return 0; 
}

void clear_screen(void)
{
        char clear_screen_command[10] = {0};
        strcpy(clear_screen_command, return_clear_screen_command()); 
        system(clear_screen_command);
}

struct project_demo** return_projects()
{
    struct project_demo** projects = (struct project_demo**)malloc(MAX_PROJECT_COUNT * sizeof(struct project_demo*)); 
    
    if(projects == NULL)
    {
        printf("Error during memory assignment for project_demo type.");
        exit(EXIT_FAILURE); 
    }

    for(int i = 0; i < MAX_PROJECT_COUNT; i++)
    {
        projects[i] = NULL; 
    }
    
    projects[0] = initialize_project(
        "../1_Hello_World/C/", PROJECT_TYPE_C, "hello_world", "Hello World (C)");

    projects[1] = initialize_project(
        "../1_Hello_World/C#/", PROJECT_TYPE_C_SHARP, "HelloWorldApp.csproj", "Hello World (C#)");

    projects[2] = initialize_project(
        "../2_Data_Structures/C", PROJECT_TYPE_C, "data_structures", "Data Structures (C)");

    projects[3] = initialize_project(
        "../2_Data_Structures/C#", PROJECT_TYPE_C_SHARP, "data_structures", "Data Structures (C#)");
    
    return projects;
}