#define _POSIX_C_SOURCE 200809L

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

typedef struct
{
    void* m_buffer; // Buffer containing data
    int m_size; // Current size of buffer/current amount of elements taken up
    int m_cap; // Maximum capacity of vector
    int m_elem_size; // Size per element. I.e, if there are ints, it will be of size 4
} Vector;

void* vector_begin(Vector* vec);
void* vector_end(Vector* vec);
void* vector_last_element(Vector* vec);
void vector_init(Vector* vec, int elem_size);
int vector_pop(Vector* vec, void* out_value);
void vector_push(Vector* vec, const void* value);
void vector_push_back(Vector* vec, const void* value);
int vector_size(Vector* vec);
