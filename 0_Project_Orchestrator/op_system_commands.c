char* return_clear_screen_command()
{
    #ifdef _WIN32
        return "cls";
    #elif __linux__
        return "clear";
    #else
        return ""; 
    #endif

}