#define MAX_PATH_LENGTH 512
#define MAX_NAME_LENGTH 64
#define MAX_ARGUMENT_LENGTH 64

//Define the orchestrator
enum ProjectType
{
    PROJECT_TYPE_C,
    PROJECT_TYPE_C_SHARP,
    PROJECT_TYPE_C_PLUS_PLUS
}; 

typedef struct ProjectDemo
{
    char current_directory[MAX_PATH_LENGTH]; 
    char relative_path[MAX_PATH_LENGTH]; 
    char executable_name[MAX_NAME_LENGTH]; 
    char build_arguments[MAX_ARGUMENT_LENGTH]; 
    enum ProjectType project_type; 
    int project_id;
    char project_name[MAX_NAME_LENGTH]; 
    char run_arguments[MAX_ARGUMENT_LENGTH]; 
};

struct ProjectDemo* InitializeNewProjectDemo(
    char* relative_path, 
    char* executable_name, 
    char* build_arguments,
    enum ProjectType project_type,
    int project_id,
    char* project_name,
    char* run_arguments); 

int Build(struct ProjectDemo* project); 

int Run(struct ProjectDemo* project); 

void Project_Demo_To_String(struct ProjectDemo* project); 
