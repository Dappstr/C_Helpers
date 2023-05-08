#include "stdio.h"
#include "stdlib.h"
#include "./helpers/vector.h"

int main()
{
    Vector* vec = vector_init(vec, sizeof(int));
    int x = 20;
    vector_push(vec, &x);
    printf("%d", *(int*)vector_at(vec, 0));
    
    vector_destroy(vec);
    return 0;
}
