#ifndef PEACHCOMPILER_H
#define PEACHCOMPILER_H

#include "stdio.h"

enum
{
    COMPILER_FILE_COMPILED_OK,
    COMPILER_FAILED_WITH_ERRORS,
};

struct compile_process
{
    // Flag = how file should be compiled
    int flags;

    struct compile_process_input_file
    {
        FILE* fp;
        const char* abs_path;
    } cfile;
    
    FILE* o_file;
};

int compile_file(const char* file_name, const char* out_filename, int flags);

#endif
