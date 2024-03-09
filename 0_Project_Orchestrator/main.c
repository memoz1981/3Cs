#include <stdio.h>
#include <stdlib.h>
#include "orchestrator.h"

/*
gcc.exe -o main.exe -w main.c orchestrator.c
.\main.exe
*/

int main()
{
    int result; 
    do
    {
        result = Orchestrate(); 
    } while (result != -1);
    
    return 0; 
}

int Orchestrate()
{
    struct ProjectDemo* hello_world_c = InitializeNewProjectDemo(
        "../1_Hello_World/C", "hello_world.exe", "main.c", PROJECT_TYPE_C); 
    struct ProjectDemo* hello_world_c_sharp = InitializeNewProjectDemo(
        "../1_Hello_World/C#", NULL, "HelloWorldApp.csproj", PROJECT_TYPE_C_SHARP); 
    printf("\nMake one of following selections:\n"); 
    printf("1 for Hello world app in C.\n"); 
    printf("2 for Hello world app in C#.\n");
    printf("-1 to exit.\n"); 
    
    int result; 
    int scanResult = scanf("%d", &result); 
    if(scanResult != 1)
    {
        printf("Invalid selection...\n"); 
        return -1; 
    }
    
    if(result == 1)
    {
        if(Build(hello_world_c))
        {
            printf("Build failed..."); 
        }

        if(Run(hello_world_c))
        {
            printf("Build failed..."); 
        }
        return 0; 
    }
    else if(result == 2)
    {
        if(Build(hello_world_c_sharp))
        {
            printf("Build failed..."); 
        }

        if(Run(hello_world_c_sharp))
        {
            printf("Build failed..."); 
        }
    }
    else if(result == -1)
    {
        printf("-1 selected. exiting. ");
    }
    else 
    {
        printf("Invalid selection"); 
    }
    return result; 
}

