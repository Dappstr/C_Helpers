#include "stdlib.h"
#include "stdio.h"

struct Vector
{
    void* m_buffer; // Buffer containing data
    int m_size; // Current size of buffer/current amount of elements taken up
    int m_cap; // Maximum capacity of vector
};
