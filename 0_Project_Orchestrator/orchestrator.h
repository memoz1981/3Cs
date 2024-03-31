#define MAX_PATH_LENGTH 512
#define MAX_NAME_LENGTH 64
#define MAX_ARGUMENT_LENGTH 64

//Define the orchestrator
enum project_type
{
    PROJECT_TYPE_C,
    PROJECT_TYPE_C_SHARP,
    PROJECT_TYPE_C_PLUS_PLUS
}; 

typedef struct project_demo
{
    char* relative_path; 
    enum project_type project_type; 
    char* executable_name; 
    char* project_name; 
} project_demo;

struct project_demo* initialize_project(
    char* relative_path, 
    enum project_type project_type,
    char* executable_name, 
    char* project_name); 

int build_project(struct project_demo* project); 

int run_project(struct project_demo* project); 

void print_project(struct project_demo* project); 

void free_project(struct project_demo* project); 