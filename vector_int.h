//
// Created by Denis on 14.03.2021.
//

#ifndef LESSONS_VECTOR_INT_H
#define LESSONS_VECTOR_INT_H

#endif //LESSONS_VECTOR_INT_H

#include "vector.h"


void* sum_int(void* x, void* y);
void* mult_int(void* x, void* y);
void* init_zero_one();

struct VectorN* create0Int(size_t size);
struct VectorN* create1Int(size_t size);
struct VectorN* createFromValuesInt(size_t size, void* values);

struct VectorN* inputIntVector();
struct VectorN* printVectorInt(struct VectorN* v);