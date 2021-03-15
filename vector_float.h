#ifndef LESSONS_VECTOR_FLOAT_H
#define LESSONS_VECTOR_FLOAT_H

#endif //LESSONS_VECTOR_FLOAT_H
#include "vector.h"

void* sum_float(void*, void*);
void* mult_float();


struct VectorN* create0Float(size_t size);
struct VectorN* create1Float(size_t size);
struct VectorN* createFromValuesFloat(size_t size, void* values);
struct Vectorn* printVector(struct VectorN* v);
struct VectorN* sumNFloat(struct VectorN* v1, struct VectorN* v2);
