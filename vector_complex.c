//
// Created by Denis on 14.03.2021.
//
#include "vector_complex.h"
#include <stdio.h>
#include <stdlib.h>

void* get_real(complex* coord){
    return &(coord->real);
};
void* get_imagine(complex* coord){
    return &(coord->imaginary);
};

void* sum_compl(void* x, void* y)
{
    complex* coord_1 = (complex*)x;
    complex* coord_2 = (complex*)y;
    float* coord_1_real = get_real(coord_1);
    float* coord_1_imagine = get_imagine(coord_1);
    float* coord_2_real = get_real(coord_2);
    float* coord_2_imagine = get_imagine(coord_2);
    complex* coord = malloc(sizeof(complex));
    coord->real = *coord_1_real + *coord_2_real;
    coord->imaginary = *coord_1_imagine + *coord_2_imagine;
    return (void*)coord;
};
void* mult_compl(void* x, void* y)
{
    complex* coord_1 = (complex*)x;
    complex* coord_2 = (complex*)y;
    float* coord_1_real = get_real(coord_1);
    float* coord_1_imagine = get_imagine(coord_1);
    float* coord_2_real = get_real(coord_2);
    float* coord_2_imagine = get_imagine(coord_2);
    complex* coord = malloc(sizeof(complex));
    // z1 * z2 = (x1 + y1i) * (x2 + y2i) = (x1*x2 - y1*y2) + (x1*y2 + x2*y1)i
    coord->real = *coord_1_real * *coord_2_real - *coord_1_imagine * *coord_2_imagine;
    coord->imaginary = *coord_1_real * *coord_2_imagine + *coord_2_real * *coord_1_imagine;
    return (void*)coord;
};
complex* zero_compl = NULL;
complex* one_compl = NULL;
void* init_zero_one_compl(){
    if (zero_compl == NULL){ //not zero_float
        zero_compl = malloc(sizeof(complex));
        zero_compl->imaginary = 0;
        zero_compl->real = 0;
        one_compl = malloc(sizeof(complex));
        one_compl->imaginary = 1;
        zero_compl->real = 1;
    }
};
void* complexCoordOutput(complex* z)
{
    printf("(%.2f; %.2fi)", z->real, z->imaginary);
};

struct VectorN* create0compl(size_t size)
{
    init_zero_one_compl();
    return create0(size, sizeof(complex), zero_compl, sum_compl,one_compl, mult_compl);
};
struct VectorN* create1compl(size_t size)
{
    init_zero_one_compl();
    return create1(size, sizeof(complex), zero_compl, sum_compl,one_compl, mult_compl);
};
struct VectorN* createFromValuesCompl(size_t size, void* values)
{
    init_zero_one_compl();
    return createFromValues(size, sizeof(complex), values, zero_compl, sum_compl,one_compl, mult_compl);
};


struct VectorN* printVectorCompl(struct VectorN* v)
{
    printf("[");
    for(int i = 0; i < v->dimension - 1; i++){
        complexCoordOutput(v->coordinates+i*v->elementSize);
        printf(", ");
        //printf("%d, ", *(int*)(v->coordinates+i*v->elementSize));
    }
    complexCoordOutput(v->coordinates+(v->dimension-1)*v->elementSize);
    printf("]\n");
};
struct VectorN* inputComplexVector()
{
    printf("Enter dimension of vector:");
    int dim = 0;
    scanf("%d", &dim);
    complex* h = malloc(sizeof(complex));
    float re = 0;
    float im = 0;
    for(int i = 0; i < dim; i++){
        printf("Enter %d coordinate:\n", i+1);
        printf("Real:");
        scanf("%f", get_real(h+i));
        printf("Imaginary:");
        scanf("%f", get_imagine(h+i));
    };
    return createFromValuesCompl(dim, h);
};