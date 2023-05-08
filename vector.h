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

//TBI = To Be Implemented (Not yet implemented)

// Returns the address of the starting index within the buffer.
void* vector_begin(Vector* vec);

// Returns the address after the last element, commonly used for iteration to express where to stop.
void* vector_end(Vector* vec);

// Returns the address of the actual last element in the buffer.
void* vector_last_element(Vector* vec);

// Default initializes a vector.
void vector_init(Vector* vec, int elem_size);

// Will remove the last element from the given buffer, and will store it in out_value which will be returned.
int vector_pop(Vector* vec, void* out_value);

// Will push a value into the buffer assuming there is enough room for it.
void vector_push(Vector* vec, const void* value);

// Pushes all elements back and inserts a new value.
void vector_push_back(Vector* vec, const void* value);

// Returns the current size of the buffer.
int vector_size(Vector* vec);

// Destroys the current buffer setting the buffer pointer to NULL.
void vector_destroy(Vector* vec);

//TBI
// Resizes the vector, preserving the existing data, and initializes any new elements to a specified value (if the new size is larger).
int vector_resize(Vector* vec, int new_size, const void* init_value);

//TBI
// Reserves a specified amount of capacity for the vector, so that future `push_back` operations do not need to reallocate memory frequently.
int vector_reserve(Vector* vec, int new_capacity);

//TBI
// Removes all elements from the vector, setting its size to 0 but preserving its capacity.
void vector_clear(Vector* vec);

//TBI
// Inserts an element at a specified position in the vector, shifting existing elements to make room for the new element.
int vector_insert(Vector* vec, int index, const void* value);

//TBI
// Removes an element at a specified position in the vector, shifting existing elements to fill the gap.
int vector_erase(Vector* vec, int index);

//TBI
// Returns a pointer to the element at a specified position in the vector.
void* vector_at(Vector* vec, int index);

//TBI
// Returns 1 if the vector is empty, and 0 otherwise.
int vector_empty(Vector* vec);

//TBI
// Returns the current capacity of the vector.
int vector_capacity(Vector* vec);

//TBI
// Reduces the capacity of the vector to match its size, minimizing the memory usage.
int vector_shrink_to_fit(Vector* vec);
