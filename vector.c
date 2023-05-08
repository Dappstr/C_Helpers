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
    return &vec->m_buffer[vec->m_size-1]; 
}

void* vector_end(Vector* vec) {

}

// elem_size can be something like sizeof(int)
void init_vector(Vector* vec, int elem_size) {
    vec->m_buffer = NULL;
    vec->m_size = 0;
    vec->m_cap = 0;
    vec->m_elem_size = elem_size;
}
