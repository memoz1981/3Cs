#include <stdio.h>
#include <stdlib.h>
#include "orchestrator.h"

#define PROJECT_COUNT 2

/*
gcc.exe -o main.exe -w main.c orchestrator.c
.\main.exe
*/

struct ProjectDemo** BuildProjects();

int main()
{
    int result; 
    struct ProjectDemo** projects = BuildProjects(); 
    do
    {
        result = Orchestrate(projects); 
    } while (result != -1);
    
    for(int i =0; i < PROJECT_COUNT; i++)
       free(projects[i]); 

    return 0; 
}

int Orchestrate(struct ProjectDemo** projects)
{
    printf("\nSelect project to run as below:\n");
    for(int i = 1; i <= PROJECT_COUNT ; i++)
    {
        printf("%d to run project %s\n", i, projects[i-1]->project_name); 
    }
    printf("-1 to exit.\n"); 
    
    int result; 
    int scanResult = scanf("%d", &result); 
    if(scanResult != 1)
    {
        printf("Invalid selection...\n"); 
        return -1; 
    }

    if(result >= 1 && result <= PROJECT_COUNT)
    {
        Project_Demo_To_String(projects[result-1]); 
        
        if(Build(projects[result-1]))
        {
            printf("Failed to build...\n"); 
        }

        if(Run(projects[result-1]))
        {
            printf("Failed to run...\n"); 
        }
        return 0; 
    }
    else if(result == -1)
        return result; 
    else
        printf("Invalid selection..."); 
    
    return result; 
}

struct ProjectDemo** BuildProjects()
{
    struct ProjectDemo** projects = (struct ProjectDemo**)malloc(PROJECT_COUNT * sizeof(struct ProjectDemo*)); 
    
    projects[0] = InitializeNewProjectDemo(
        "../1_Hello_World/C", "hello_world.exe", "main.c", 
        PROJECT_TYPE_C, 1, "hello_world_c"); 
    
    projects[1] = InitializeNewProjectDemo(
        "../1_Hello_World/C#", NULL, "HelloWorldApp.csproj", 
        PROJECT_TYPE_C_SHARP, 2, "hello_world_c_sharp"); 
    
    return projects;
}

