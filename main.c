#include <stdio.h>
#include <stdlib.h>
#include "vector_float.h"

#include "interface.h" //here includes vector_int.h, vector_complex.h -> vector.h

int main()
{
    //struct VectorN_float *v1 = putVectorN();
    //struct VectorN_float *v2 = putVectorN();
    //struct VectorN_float *v3 = summN(v1, v2);
    //printVectorN(v3);
    //struct VectorN* v1 = create1Float(4);
    //printf("%f", *(float*)v1->coordinates);

    //float* x = malloc(sizeof(float));
    //float a = 0;
    /*int t = 0;
    int* r = malloc(sizeof(int));
    for(int i=0; i<3; i++) {
        printf("Enter %d coordinate: ", i+1);
        scanf("%d", &t);
        *(r + i) = t;
        //printf("%d ", *(x + i));
    };*/
    /* for(int i=0; i<3; i++) {
        printf("Enter first vector number %d =", i+1);
        scanf("%f", &a);
        *(x + i) = a;
        //printf("%d ", *(x + i));
    }; */
    //float* y = malloc(sizeof(float));
    //float b = 0;
    //for(int i=0; i<3; i++) {
        //printf("Enter second vector number %d =", i+1);
        //scanf("%f", &b);
        //*(y + i) = b;
        //printf("%d ", *(x + i));
    //*y = 10;
    /*int p = 12;
    struct VectorN* v = createFromValuesInt(3, r);
    struct VectorN* v2 = createFromValuesInt(3, r);
    struct VectorN* v3 = scalarMultN(v, v2);
    struct VectorN* v4 = sumN(v, v2);
    num_mult_vector(&p, v);

    //struct VectorN* v1 = createFromValuesFloat(3, y);
    //struct VectorN* v3 = scalarMultN(v, v1);
    //num_mult_vector(y, v);
    printVectorInt(v);
    for(int i = 0; i<v->dimension; i++){
         //printf("%d ", *(x + i));
        //printf("%d\n", *((int*)values+i));
        //int8_t* position = (int8_t*)v->coordinates + i * v->elementSize;
        //memcpy((void*)position, values, v->elementSize);
        //printf("\n | %d |\n", *(int*)(v->coordinates+i));
        //printf("%i - %d |", i+1, *(int*)(v1->coordinates+i))
        //printf("\n %d - %d coord of vector1", *(int*)(v->coordinates+i*v->elementSize), i+1);
        //printf("\n %d - %d coord of vector2", *(int*)(v->coordinates+i*v->elementSize), i+1);
    };
    */
    ui();
    ///printVectorCompl(v11);
    /*
    complex* h = malloc(sizeof(complex));
    float re = 0;
    float im = 0;

    for(int i = 0; i < 3; i++){
        printf("Enter %d coordinate:\n", i+1);
        printf("Real: ");
        scanf("%f", get_real(h+i));
        printf("Imaginary: \n");
        scanf("%f", get_imagine(h+i));
    };
    complex* h1 = malloc(sizeof(complex));


    for(int i = 0; i < 3; i++){
        printf("Enter %d coordinate:\n", i+1);
        printf("Real: ");
        scanf("%f", get_real(h1+i));
        printf("Imaginary: \n");
        scanf("%f", get_imagine(h1+i));
    };
    struct VectorN* v = createFromValuesCompl(3, h);
    struct VectorN* v1 = createFromValuesCompl(3, h1);

   // float* p = get_imagine(v->coordinates);
    struct VectorN* v2 = sumN(v, v1);
    //complex* coord = (complex*)mult_compl(v->coordinates, v->coordinates+1);
    printVectorCompl(v);
    printVectorCompl(v1);
    printVectorCompl(v2);
*/
    //printf("%f", get_real(coord));
    //for(int i = 0; i<3; i++)
   //     complexCoordOutput(v->coordinates+i*v->elementSize);
    //printf("%f", *p);

    return 0;
    /*
     * Структура интерфейса
     * Выберите тип Int or Complex. После чего функции должны работать только int или float. Моожно реализовать через case:1, case: 2;
     * После чего создаем вектор, уже зная наш тип, можно реализовать через case: 1 case 2;
     */
}



