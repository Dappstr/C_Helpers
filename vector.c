#ifndef VECTOR_H
#define VECTOR_H

#endif
#include "vector.h"
#include "stdlib.h"
#include "stdio.h"
#include "assert.h"

//...TODO

void* vector_begin(Vector* vec) {
    assert(vec->m_size >= 1);
    return &vec->m_buffer; 
}

void* vector_end(Vector* vec) {
    assert(vec->m_size >= 1);
    return (char*)vec->m_buffer + vec->m_size * vec->m_elem_size; // Get the last area of memory
                                                             // We first cast to a char pointer to allow for pointer arithmetic
                                                             // Since C cannot do pointer arithmetic on type of void*
                                                             // We get the product of m_size and m_elem_size because
                                                             // the amount of memory allocated will be the amount times the size of the type
                                                             // so a buffer of 3 ints will be 3 * 4 since an int is 4 bytes, and then add on m_buffer
                                                             // to get the memory location that is 1 byte past.
}

// elem_size can be something like sizeof(int)
void init_vector(Vector* vec, int elem_size) {
    vec->m_buffer = NULL;
    vec->m_size = 0;
    vec->m_cap = 0;
    vec->m_elem_size = elem_size;
}
