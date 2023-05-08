#include "vector.h"

//...TODO

void* vector_begin(Vector* vec) {
    assert(vec->m_size >= 1);
    return &vec->m_buffer; 
}

void* vector_end(Vector* vec) {
    return (char*)vec->m_buffer + vec->m_size * vec->m_elem_size; // Get the last area of memory
                                                             // We first cast to a char pointer to allow for pointer arithmetic
                                                             // Since C cannot do pointer arithmetic on type of void*
                                                             // We get the product of m_size and m_elem_size because
                                                             // the amount of memory allocated will be the amount times the size of the type
                                                             // so a buffer of 3 ints will be 3 * 4 since an int is 4 bytes, and then add on m_buffer
                                                             // to get the memory location that is 1 byte past.
}

void* vector_last_element(Vector* vec) {
    return (char*)vec->m_buffer + (vec->m_size - 1) * vec->m_elem_size;
}

// elem_size can be something like sizeof(int)
Vector* vector_init(Vector* vec, int elem_size) {
    vec->m_buffer = NULL;
    vec->m_size = 0;
    vec->m_cap = 0;
    vec->m_elem_size = elem_size;
    
    return vec;
}

int vector_pop(Vector* vec, void* out_value) {
    assert(vec->m_size > 0);
    if(vec->m_size == 0) {
        fprintf(stderr, "Error! Not enough elements in vector to pop!\n");
        return -1;
    }

    void* backup_buffer = malloc(vec->m_cap);
    memcpy(&backup_buffer, &vec->m_buffer, vec->m_cap * vec->m_elem_size);
    
    void* last_element_addr = vector_last_element(vec);
    memcpy(out_value, last_element_addr, vec->m_elem_size);
    
    if(memcmp(vector_last_element(vec), last_element_addr, vec->m_elem_size) != 0)  {
        fprintf(stderr, "Error! Popping value failed!\n");
        memcpy(vec->m_buffer, backup_buffer, vec->m_cap * vec->m_elem_size);
    }

    vec->m_size--;
    free(backup_buffer);
    return 0;
}

void vector_push(Vector* vec, const void* value) {
    assert(vec->m_size >= vec->m_cap);
    
    // Check if the vector is full
    if (vec->m_size == vec->m_cap) {
        
        int new_cap = vec->m_cap == 0 ? 4 : vec->m_cap * 2;
        void* new_buffer = realloc(vec->m_buffer, new_cap * vec->m_elem_size);
        
        if(new_buffer == NULL) {
            free(new_buffer);
            fprintf(stderr, "Failed to reallocate after pushing!\n");
            return;
        }
        
        vec->m_buffer = new_buffer;
        vec->m_cap = new_cap;
    }

    memcpy(vector_end(vec), value, vec->m_elem_size);
    vec->m_size++;

}

void vector_push_back(Vector* vec, const void* value) {
    if(vec->m_size >= vec->m_cap) {
        
        int new_cap = vec->m_cap == 0 ? 4 : vec->m_cap * 2;
        void* new_buffer = realloc(vec->m_buffer, new_cap * vec->m_elem_size);
        
        if(!new_buffer) {
            free(new_buffer);
            fprintf(stderr, "Error! Buffer corrupted!\n");
            return;
        }
        
        vec->m_buffer = new_buffer;
        vec->m_cap = new_cap;            
    }

    memcpy(vector_end(vec), value, vec->m_elem_size); 
    vec->m_size++;
}

int vector_size(Vector* vec) {
    return vec->m_size;
}

void vector_destroy(Vector* vec) {
    free(vec->m_buffer);
    vec->m_buffer = NULL; // Make null to not have a dangling pointer
}
void* vector_at(Vector* vec, int index) {
    assert(index <= vec->m_size-1);
    if(index > vec->m_size || index > vec->m_cap) {
        fprintf(stderr, "Invalid location for `at`\n");
        return NULL;
    }
    return (char*) vec->m_buffer + (index * vec->m_elem_size);
}
