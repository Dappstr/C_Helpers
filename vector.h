#include "stdlib.h"
#include "stdio.h"

typedef struct
{
    void* m_buffer; // Buffer containing data
    int m_size; // Current size of buffer/current amount of elements taken up
    int m_cap; // Maximum capacity of vector
    int m_elem_size; // Size per element. I.e, if there are ints, it will be of size 4
} Vector;

void* vector_begin(Vector* vec);
void* vector_end(Vector* vec);
void vector_pop(Vector* vec);
void vector_push(Vector* vec);
void vector_push_back(int val);
void vector_init(Vector* vec);
