#include "test.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void* sep(){
    printf("------------------------------------------\n");
};

void* test_int()
{
    //Create 0
    sep();
    struct VectorN* v0 = create0Int(3);
    printf("Function Create0 create Vector with 0 coordinates:\n");
    printVectorInt(v0);
    //Create 1
    sep();
    struct VectorN* v1 = create1Int(5);
    printf("Function Create1 create Vector with 1 coordinates:\n");
    printVectorInt(v1);
    //CreateFromValues
    sep();
    //Vector 2 init
    int* h = malloc(sizeof(int)*4);
    for(int i = 0; i < 4; i++)
        *(h+i) = 10 + 2*i;
    struct VectorN* v2 = createFromValuesInt(4, h);
    printf("Function CreateFromValues create Vector with our coordinates:\n");
    //Vector 3 init
    int* h2 = malloc(sizeof(int)*4);
    for(int i = 0; i < 4; i++)
        *(h2+i) = 10 + 3*i;
    struct VectorN* v3 = createFromValuesInt(4, h2);
    printf("Vector2: ");
    printVectorInt(v2);
    printf("Vector3: ");
    printVectorInt(v3);
    //Vector Sum
    struct VectorN* v4 = sumN(v2, v3);
    printf("Sum of Vector2 and Vector3: ");
    printVectorInt(v4);
    //Dimension error---------------------------
    //test_dim_error_int();
    //------------------------------------------

    //Mult
    struct VectorN* v5 = scalarMultN(v2, v3);
    printf("Scalar Multiplication of Vector2 and Vector3 = ");
    printVectorInt(v5);
    //Scalar
    sep();
    int scalar = -3;
    printf("Vector2: ");
    printVectorInt(v2);
    num_mult_vector(&scalar, v2);
    printf("Multiplication of Vector2 by number (%d): ", scalar);
    printVectorInt(v2);
    sep();
    return 1; //if everything good it returns 1
};

void* test_complex()
{
    //Create 0
    sep();
    struct VectorN* v0 = create0compl(3);
    printf("Function Create0 create Vector with 0 coordinates:\n");
    printVectorCompl(v0);
    //Create 1
    sep();
    struct VectorN* v1 = create1compl(5);
    printf("Function Create1 create Vector with 1 coordinates:\n");
    printVectorCompl(v1);
    //CreateFromValues - Vector2 init
    printf("Function CreateFromValues create Vector with our coordinates:\n");
    sep();
    printf("Vector 2 init:\n");
    struct VectorN *v2 = inputComplexVector();


    //Vector 3 init
    /*
    complex* h2 = malloc(sizeof(complex)*5);
    float* re1;
    float* im1;
    for(int i = 0; i < 5; i++){
        *re1 = 4 + i * 3;
        *im1 = -2.0 + i * 5.0;
        *(float*)get_real(h2+i) = *re1;
        *(float*)get_imagine(h2+i) = *im1;
    };*/
    printf("Vector 3 init:\n");
    struct VectorN* v3 = inputComplexVector();
    printf("Vector2: ");
    printVectorCompl(v2);
    printf("Vector3: ");
    printVectorCompl(v3);
    //Vector Sum
    struct VectorN* v4 = sumN(v2, v3);
    printf("Sum of Vector2 and Vector3: ");
    printVectorCompl(v4);
    //Dimension error---------------------------
    test_dim_error_compl();
    //------------------------------------------

    //Mult
    struct VectorN* v5 = scalarMultN(v2, v3);
    printf("Scalar Multiplication of Vector2 and Vector3 = ");
    printVectorCompl(v5);
    //Scalar
    sep();
    float scalar = -6.0;
    printf("Vector2: ");
    printVectorCompl(v2);
    num_mult_vector(&scalar, v2);
    printf("Multiplication of Vector2 by number (%d): ", scalar);
    printVectorCompl(v2);
    sep();
    return 1; //if everything good it returns 1
};

void* test_dim_error_int(){
    sep();
    int* h = malloc(sizeof(int)*4);
    for(int i = 0; i < 4; i++)
        *(h+i) = 10 + i;
    struct VectorN* v2 = createFromValuesInt(4, h);
    struct VectorN* v3 = createFromValuesInt(3, h);
    printf("VectorD4: ");
    printVectorInt(v2);
    printf("VectorD3: ");
    printVectorInt(v3);
    sumN(v2, v3);
};
void* test_dim_error_compl(){
    sep();
    complex* h = malloc(sizeof(complex));
    for(int i = 0; i < 5; i++){
        *(float*)get_real(h+i) = -6.0 + i * 2.0;
        *(float*)get_imagine(h+i) = 3.0 + i * 4.0;
    };
    struct VectorN* v2 = createFromValuesCompl(4, h);
    struct VectorN* v3 = createFromValuesCompl(3, h);
    printf("VectorD4: ");
    printVectorCompl(v2);
    printf("VectorD3: ");
    printVectorCompl(v3);
    sumN(v2, v3);
};