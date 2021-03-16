#include "vector.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void* getN(size_t coord, struct VectorN* v){
    return (void*)((int8_t*) v->coordinates + coord * (v->elementSize));
}
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
        memcpy((void*)position, v->zero, v->elementSize);
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
        memcpy((void*)position, v->one, v->elementSize);
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
        memcpy((void*)position, values+i*v->elementSize, v->elementSize);
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
                    void* el3 = v3->sum(el1, el2);
                    setN(i, el3, v3);
                }
                return v3;
            } else{
                Error("Dimension error (D(v1) != D(v2))");
                return 0;
            }
        } else {
            Error("Type error (Type(v1) != Type(v2))");
            return 0;
        }
    } else{
        Error("Vector1 and Vector2 = 0");
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
                    void* el3 = v3->mult(el1, el2);
                    setN(i, el3, v3);
                }
                return v3;
            } else{
                Error("Dimension error (D(v1) != D(v2))");
                return 0;
            }
        } else {
            Error("Type error (Type(v1) != Type(v2))");
            return 0;
        }
    } else{
        Error("Vector1 and Vector2 = 0");
        return 0;
    }
};

struct VectorN* num_mult_vector(void* scalar, struct VectorN* v)
{
    for(int i = 0; i < v->dimension; i++){
        void* el = getN(i, v);
        void* el_after_mult = v->mult(el, scalar);
        setN(i, el_after_mult, v);
    }
};

void* Error(char* msg)
{
    printf(msg);
    printf("\n");
    system("pause");
    exit(0);
}
