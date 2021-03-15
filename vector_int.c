//
// Created by Denis on 14.03.2021.
//

#include "vector_int.h"
#include <stdio.h>
#include <stdlib.h>

void* sum_int(void* x, void* y)
{
    int* a = (int*) x;
    int* b = (int*) y;
    int* c = malloc(sizeof(int));
    *c = *a + *b;
    return (void*)c;
};
void* mult_int(void* x, void* y)
{
    int* a = (int*) x;
    int* b = (int*) y;
    int* c = malloc(sizeof(int));
    *c = *a * *b;
    return (void*)c;
};
void* zero_int = NULL;
void* one_int = NULL;
void* init_zero_one(){
    if (zero_int == NULL){ //not zero_float
        zero_int = malloc(sizeof(int));
        *(int*)zero_int = 0;
        one_int = malloc(sizeof(int));
        *(int*)one_int = 1;
    }
};

struct VectorN* create0Int(size_t size)
{
    init_zero_one();
    return create0(size, sizeof(int), zero_int, sum_int, one_int, mult_int);
};
struct VectorN* create1Int(size_t size)
{
    init_zero_one();
    return create1(size, sizeof(int), zero_int, sum_int, one_int, mult_int);
};
struct VectorN* createFromValuesInt(size_t size, void* values){
    init_zero_one();
    return createFromValues(size, sizeof(int), values, zero_int, sum_int, one_int, mult_int);
};
struct VectorN* printVectorInt(struct VectorN* v)
{
    printf("[");
    for(int i = 0; i < v->dimension - 1; i++){
        printf("%d, ", *(int*)(v->coordinates+i*v->elementSize));
    }
    printf("%d", *(int*)(v->coordinates + (v->dimension-1)*v->elementSize));
    printf("]\n");
};

struct VectorN* inputIntVector()
{
    printf("Enter dimension of vector:");
    int dim = 0;
    scanf("%d", &dim);
    int* coord = malloc(sizeof(int)*dim);
    for(int i = 0; i < dim; i++)
    {
        printf("Enter %d coordinate:", i+1);
        scanf("%d", coord+i);
    };
    return createFromValuesInt(dim, coord);
};