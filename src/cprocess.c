// Will contain the compiler process
#include "stdio.h"
#include "stdlib.h"
#include "compiler.h"

struct compile_process* compile_process_create(const char* file_name, const char* out_file_name, int flags) {
    FILE* file = fopen(file_name, "r");
    if(!file) {
        printf("Could not read file from specified file name!\n");
        return NULL;
    }

    FILE* out_file = NULL;
    if(out_file_name) {
        out_file = fopen(out_file_name, "w");
        if(!out_file) {
            printf("Error writing to file!\n");
            return NULL;
        }
    }

    struct compile_process* process = calloc(1, sizeof(struct compile_process));
    process->flags = flags;
    process->cfile.fp = file;
    process->o_file = out_file;

    return process;
}
