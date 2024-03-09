//Define the orchestrator
enum ProjectType
{
    PROJECT_TYPE_C,
    PROJECT_TYPE_C_SHARP,
    PROJECT_TYPE_C_PLUS_PLUS
}; 

typedef struct ProjectDemo
{
    char current_directory[1024]; 
    char relative_path[1024]; 
    char executable_name[64]; 
    char arguments[256]; 
    enum ProjectType project_type; 
};

struct ProjectDemo* InitializeNewProjectDemo(
    char* relative_path, 
    char* executable_name, 
    char* arguments,
    enum ProjectType project_type); 

int Build(struct ProjectDemo* project); 

int Run(struct ProjectDemo* project); 

