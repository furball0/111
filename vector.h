
#ifndef LESSONS_VECTOR_H
#define LESSONS_VECTOR_H
#pragma once
#include <stdlib.h>
#endif //LESSONS_VECTOR_H

struct VectorN
{
    size_t dimension;
    size_t elementSize;
    void* coordinates;
    //Задаем линейное пространство над полем чисел
    void* zero; //задаем нули
    void* (*sum)(void* x1, void* x2); //задаем функцию сложения
    void* one; //задаем единицы
    void* (*mult)(void*, void*); //задаем функцию умножения
};

// I. Создание объекта
struct VectorN* create0(size_t size, size_t elementSize, void* zero, void* (*sum), void* one, void* (*mult));
struct VectorN* create1(size_t size, size_t elementSize, void* zero, void* (*sum), void* one, void* (*mult));
struct VectorN* createFromValues(size_t size, size_t elementSize, void* values, void* zero, void* (*sum), void* one, void* (*mult));

// II. Декомпозиция
void* getN(size_t coord, struct VectorN* v); //Получение
void* setN(size_t coord, void* value, struct VectorN* v); // struct VectorN*

// III. Операции
struct VectorN* sumN(struct VectorN* v1, struct VectorN* v2); //Sum of vectors
struct VectorN* scalarMultN(struct VectorN* v1, struct VectorN* v2); //Scalar multiplication of vectors
struct VectorN* num_mult_vector(void* scalar, struct VectorN* v); //Multiplication of vector by number


void* Error(char* msg);
void* DeletePointer(void* p);
void* DeleteVectorN(struct VectorN* v);