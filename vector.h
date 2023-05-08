#include "stdlib.h"
#include "stdio.h"

typedef struct
{
    void* m_buffer; // Buffer containing data
    int m_size; // Current size of buffer/current amount of elements taken up
    int m_cap; // Maximum capacity of vector
} Vector;
