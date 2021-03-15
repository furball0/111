//
// Created by Denis on 09.03.2021.
//
#include "vector_float.h"
#include "vector.h"
#include <stdio.h>
#include <stdlib.h>

//Стандартный вид всех функций
void* sum_float(void* x, void* y){
    float* a = (float*) x;
    float* b = (float*) y;
    float* c = malloc(sizeof(float));
    *c = *a + *b;
    return (void*)c;
}
void* mult_float(void* x, void* y){
    float* a = (float*)x;
    float* b = (float*)y;
    float* c = malloc(sizeof(float));
    *c = *a * *b;
    return (void*)c;
};

void* zero_float = NULL;
void* one = NULL;

//float zero_float = 0.0f;
//float one = 1.0f;
struct VectorN* create0Float(size_t size){
    if (zero_float == NULL){ //not zero_float
        zero_float = malloc(sizeof(float));
        *(float*)zero_float = 0.0f;
        one = malloc(sizeof(float));
        *(float*)one = 1.0f;
    }
    return create0(size, sizeof(float), zero_float, sum_float, one, mult_float);
};
struct VectorN* create1Float(size_t size){
    if (zero_float == NULL){ //not zero_float
        zero_float = malloc(sizeof(float));
        *(float*)zero_float = 0.0f;
        one = malloc(sizeof(float));
        *(float*)one = 1.0f;
    }
    //*(float*)one = 1.0f;
    //printf("%d ", one);
    return create1(size, sizeof(float), zero_float, sum_float, one, mult_float);
};

struct VectorN* createFromValuesFloat(size_t size, void* values){
    if (zero_float == NULL){ //not zero_float
        zero_float = malloc(sizeof(float));
        *(float*)zero_float = 0.0f;
        one = malloc(sizeof(float));
        *(float*)one = 1.0f;
    }
    //printf("%f", *values);
    return createFromValues(size, sizeof(float), values, zero_float, sum_float, one, mult_float);
};
struct Vectorn* printVector(struct VectorN* v){
    //for(int i = 0; i<v->)
};
//Sum of two vectors with float coordinates
struct VectorN* sumNFloat(struct VectorN* v1, struct VectorN* v2){
    return sumN(v1, v2);
};



