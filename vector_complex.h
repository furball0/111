#ifndef LESSONS_VECTOR_COMPLEX_H
#define LESSONS_VECTOR_COMPLEX_H

#endif //LESSONS_VECTOR_COMPLEX_H

#include "vector.h"

typedef struct complex{
    float real;
    float imaginary;
} complex;
void* get_real();
void* get_imagine();
void* complexCoordOutput(); //v->coordinates in () here
void* sum_compl(void* x, void* y);
void* mult_compl(void* x, void* y);
void* init_zero_one_compl();

struct VectorN* create0compl(size_t size);
struct VectorN* create1compl(size_t size);
struct VectorN* createFromValuesCompl(size_t size, void* values);

struct VectorN* inputComplexVector();
struct VectorN* printVectorCompl(struct VectorN* v);