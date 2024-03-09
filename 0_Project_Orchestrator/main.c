#include <stdio.h>
#include <stdlib.h>
#include "orchestrator.h"

/*
gcc.exe -o main.exe -w main.c orchestrator.c
.\main.exe
*/

int main()
{
    printf("Make one of following selections:\n"); 
    printf("1 for Hello world app in C.\n"); 
    printf("2 for Hello world app in C#.\n"); 

    struct ProjectDemo* hello_world_c = InitializeNewProjectDemo(
        "../1_Hello_World/C", "hello_world.exe", "main.c", C); 
    struct ProjectDemo* hello_world_c_sharp = InitializeNewProjectDemo(
        "../1_Hello_World/C#", NULL, "HelloWorldApp.csproj", C_Sharp); 

    int result; 
    scanf("%d", result); 

    if(result == 1)
    {
        Build(hello_world_c); 
        Run(hello_world_c); 
    }
    else if(result == 2)
    {
        Build(hello_world_c_sharp); 
        Run(hello_world_c_sharp); 
    }
    else 
    {
        printf("Invalid selection"); 
    }

}

int Orchestrate()
{
    
}

