# Welcome to 3Cs Repo

**3Cs Repository** will contain different projects in C, C++ and C# (ASP.NET). 
Hopefully the plan is to make all projects available in 3 different languages, but practically that's a hard target to hit. Will start with C and C# and then will see where it goes from there. Project information will be listed in this file after completing each project. 

As a tribute to "Hello world!!!" phrase - first project will be **Hello World**.

The implementations are far away from being perfect (especially for C and in future for C++) - so any comments and suggestions will be much appreciated. 

# Project Orchestrator
A C project that will be used like UI - from where it will be possible to call
all other C, C# and C++ programs/applications. Trying to use powershell commands. 
With each project/code addition, this needs to be updated to ensure all new projects
appear in the "UI Menu". 

To run the project:
- Go to directory: 0_Project_Orchestrator
- Run following command to build: gcc.exe -o main.exe -w main.c orchestrator.c (or corresponding command for the compiler)
- Run following command to run: .\main.exe
- Follow the menu items

# Hello World !!!
Just wanted to say hello folks... 

# Data Structures
Aim is to implement data structures in C and C# (and later in C++) - using different implementations. Following data structures are planned to be covered in this section: 
- Stack
- Queue
- Linked List
- Binary Search Tree
- Generic List (implemented for integer, float, string and char types)
Note: For List - it was possible to make it generic by defining methods that should be 
implemented by the corresponding type. This should be optimized in future accordingly. 
- HashSet
- Dictionary
