//
// Created by Denis on 08.03.2021.
//

#ifndef LESSONS_VECTOR_H
#define LESSONS_VECTOR_H
#pragma once
#include <stdlib.h>

struct VectorN_float
{
    int dimension;
    float *coordinates;
};
struct VectorN_float* summN(struct VectorN_float *v1, struct VectorN_float *v2);
struct VectorN_float* putVectorN(void);
struct VectorN_float* printVectorN(struct VectorN_float *v);
#endif //LESSONS_VECTOR_H

struct VectorN
{
    size_t dimension;
    size_t elementSize;
    void* coordinates; //Указатель на что угодно
    //Задаем линейное пространство над полем чисел (+, -)f
    void* zero; //задаем нули
    void* (*sum)(void* x1, void* x2); //Указатель на функцию (*sum) <- указательна функцию в нашем контексте
    void* one; //задаем единицы
    void* (*mult)(void*, void*);
};


// I. Создание объекта
struct VectorN* create0(size_t size, size_t elementSize, void* zero, void* (*sum), void* one, void* (*mult));
struct VectorN* create1(size_t size, size_t elementSize, void* zero, void* (*sum), void* one, void* (*mult));
struct VectorN* createFromValues(size_t size, size_t elementSize, void* values, void* zero, void* (*sum), void* one, void* (*mult));

//struct VectorN* Copy(struct VectorN* v);

// II. Декомпозиция
void* getN(size_t coord, struct VectorN* v);
void* setN(size_t coord, void* value, struct VectorN* v); // struct VectorN*

// III. Операции
struct VectorN* sumN(struct VectorN* v1, struct VectorN* v2);
struct VectorN* scalarMultN(struct VectorN* v1, struct VectorN* v2);
struct VectorN* num_mult_vector(void* scalar, struct VectorN* v);


void* Error(char* msg);
void* DeletePointer(void* p);
void* DeleteVectorN(struct VectorN* v);