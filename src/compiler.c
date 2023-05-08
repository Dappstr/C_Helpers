#include "compiler.h"

struct compile_process* compile_process_create(const char* file_name, const char* out_file_name, int flags);

// Will do the main compilation operations, where the user declares a type of file output representing the flag
int compile_file(const char* file_name, const char* out_filename, int flags) {
    
    struct compile_process* process = compile_process_create(file_name, out_filename, flags);
    
    if(!process) 
       return COMPILER_FAILED_WITH_ERRORS; 

    return COMPILER_FILE_COMPILED_OK;
}
