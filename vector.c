//
// Created by Denis on 08.03.2021.
//
#include "vector.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

struct VectorN_float* summN(struct VectorN_float *v1, struct VectorN_float *v2) {
    if (v1->dimension != v2->dimension) {
        printf("ERROR HAPPENED\n");
    }
    struct VectorN_float *v3 = malloc(sizeof(struct VectorN_float));
    v3->dimension = v1->dimension;
    v3->coordinates = (float*)malloc(sizeof(float)*v3->dimension);
    for (int i = 0; i< v3->dimension; i++) {
        *(v3->coordinates + i) = *(v1->coordinates+i) + *(v2->coordinates+i);
    }
    return v3;
}
struct VectorN_float* putVectorN(void) {
    struct VectorN_float *v = malloc(sizeof(struct VectorN_float));
    printf("Set vector dimension:\n");
    scanf("%d", &v->dimension);
    v->coordinates = (float*) malloc(sizeof(float) * v->dimension);
    for (int i = 0; i < v->dimension; i++) {
        printf("Write %d coordinate:\n", i+1);
        scanf("%f", v->coordinates+i);
    }
    return v;
}
struct VectorN_float* printVectorN(struct VectorN_float *v) {
    printf("Vector dismension %d\n", v->dimension);
    printf("Sum%d: ", v->dimension);
    for (int i=0; i< v->dimension; i++) {
        printf("%d coord = %.2f; ",i+1, *(v->coordinates+i));
    }
}

///////////////////////

void* getN(size_t coord, struct VectorN* v){
    return (void*)((int8_t*) v->coordinates + coord * (v->elementSize));
};
void* setN(size_t coord, void* value, struct VectorN* v){
    void* position = (int8_t*)v->coordinates + coord * v->elementSize;
    memcpy(position, value, v->elementSize);
};

struct VectorN* create0(size_t size, size_t elementSize, void* zero, void* (*sum), void* one, void* (*mult)) {
    struct VectorN* v = malloc(sizeof(struct VectorN));
    v->dimension = size;
    v->elementSize = elementSize;
    v->coordinates = malloc(elementSize*size);
    v->zero = zero;
    v->sum = sum;
    v->one = one;
    v->mult = mult;
    for (size_t i = 0; i < v->dimension; i++){
        int8_t* position = (int8_t*)v->coordinates + i * v->elementSize;
        memcpy((void*)position, v->zero, v->elementSize); //Куда, откуда, сколько
    }
    return v;
};
struct VectorN* create1(size_t size, size_t elementSize, void* zero, void* (*sum), void* one, void* (*mult)) {
    struct VectorN* v = malloc(sizeof(struct VectorN));
    v->dimension = size;
    v->elementSize = elementSize;
    v->coordinates = malloc(elementSize*size);
    v->zero = zero;
    v->sum = sum;
    v->one = one;
    v->mult = mult;
    for (size_t i = 0; i < v->dimension; i++){
        int8_t* position = (int8_t*)v->coordinates + i * v->elementSize;
        memcpy((void*)position, v->one, v->elementSize); //Куда, откуда, сколько
    }
    return v;
};
struct VectorN* createFromValues(size_t size, size_t elementSize, void* values, void* zero, void* (*sum), void* one, void* (*mult)){
    struct VectorN* v = malloc(sizeof(struct VectorN));
    v->dimension = size;
    v->elementSize = elementSize;
    v->coordinates = malloc(elementSize*size);
    v->zero = zero;
    v->one = one;
    v->sum = sum;
    v->mult = mult;
    for(int i = 0; i<v->dimension; i++){
        int8_t* position = (int8_t*)v->coordinates + i * v->elementSize;
        memcpy((void*)position, values+i*v->elementSize, v->elementSize); //Куда, откуда, сколько
    };
    return v;
};

struct VectorN* sumN(struct VectorN* v1, struct VectorN* v2){
    if (v1 && v2){
        if(v1->elementSize == v2->elementSize){
            if (v1->dimension == v2->dimension){
                struct VectorN* v3 = create0(v1->dimension, v1->elementSize, v1->zero, v1->sum, v1->one, v1->mult);
                for (int i = 0; i < v1->dimension; i++){
                    void* el1 = getN(i, v1);
                    void* el2 = getN(i, v2);
                    void* el3 = v3->sum(el1, el2); //v1->sumN(el1, el2);
                    setN(i, el3, v3);
                }
                return v3;
            } else{
                //system("cls"), Error("Dimension error (D(v1) != D(v2))");
                printf("Dimension error (D(v1) != D(v2))");
                return 0;
            }
        } else {
            //system("cls"), Error("Type error (Type(v1) != Type(v2))");
            printf("Type error (Type(v1) != Type(v2))");
            return 0;
        }
    } else{
        //system("cls"), Error("Vector1 and Vector2 = 0");
        printf("Vector1 and Vector2 = 0");
        return 0;
    }
};
struct VectorN* scalarMultN(struct VectorN* v1, struct VectorN* v2)
{
    if (v1 && v2){
        if(v1->elementSize == v2->elementSize){
            if (v1->dimension == v2->dimension){
                struct VectorN* v3 = create0(v1->dimension, v1->elementSize, v1->zero, v1->sum, v1->one, v1->mult);
                for (int i = 0; i < v1->dimension; i++){
                    void* el1 = getN(i, v1);
                    void* el2 = getN(i, v2);
                    void* el3 = v3->mult(el1, el2); //v1->sumN(el1, el2);
                    setN(i, el3, v3);
                }
                return v3;
            } else{
                //system("cls"), Error("Dimension error (D(v1) != D(v2))");
                printf("Dimension error (D(v1) != D(v2))");
                return 0;
            }
        } else {
            //system("cls"), Error("Type error (Type(v1) != Type(v2))");
            printf("Type error (Type(v1) != Type(v2))");
            return 0;
        }
    } else{
        //system("cls"), Error("Vector1 and Vector2 = 0");
        printf("Vector1 and Vector2 = 0");
        return 0;
    }
};

struct VectorN* num_mult_vector(void* scalar, struct VectorN* v)
{
    for(int i = 0; i < v->dimension; i++){
        void* el = getN(i, v);
        void* el_after_mult = v->mult(el, scalar);
        setN(i, el_after_mult, v);
    };
};

void* Error(char* msg)
{
    printf(msg);
    printf("\n");
    system("pause");
    exit(0);
}
void* DeletePointer(void* p)
{
    if (!p)
        system("cls"), Error("Attempt to free null pointer"); //system ("cls") clear console
    free(p);
    p = NULL;
}
void* DeleteVectorN(struct VectorN* v)
{
    if (!v)
        system("cls"), Error("Attempt to free null pointer");
    DeletePointer(v->coordinates);
    DeletePointer(v);
    v = NULL;
}