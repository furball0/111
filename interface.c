//
// Created by Denis on 15.03.2021.
//
#include <stdio.h>
#include <stdlib.h>
#include "interface.h"
int max_command_len = 100;




void* sep(){
    printf("------------------------------------------\n");
};

void* ui()
{
    char* command = (char*)malloc(max_command_len * sizeof(char));

    printf("Select type of numbers:\n");
    printf("i - integer type | c - complex type: ");
    gets(command);

    if (*command == 'i') {
        sep();
        printf("commands:\n");
        printf("	1 - Sum of Vectors\n");
        printf("	2 - Scalar multiplication of Vectors\n");
        printf("	3 - Multiplication of a vector\n");
        printf("	/ - test\n");
        printf("	0 - exit\n");
        printf("Enter a number:");
        gets(command);

        //exit
        if (*command == '0') {
            exit(0);
        }

        //sum of vectors
        if (*command == '1') {
            struct VectorN *v1 = inputIntVector();
            struct VectorN *v2 = inputIntVector();
            struct VectorN *v3 = sumN(v1, v2);
            printf("Vector 1 = ");
            printVectorCompl(v1);
            printf("Vector 2 = ");
            printVectorCompl(v2);
            printf("Sum of vectors = ");
            printVectorInt(v3);
        };

        //scalar mult
        if (*command == '2') {
            struct VectorN *v1 = inputIntVector();
            struct VectorN *v2 = inputIntVector();
            struct VectorN *v3 = scalarMultN(v1, v2);
            printf("Vector 1 = ");
            printVectorCompl(v1);
            printf("Vector 2 = ");
            printVectorCompl(v2);
            printf("Scalar multiplication of vectors = ");
            printVectorInt(v3);
        };

        //mult vector on number
        if (*command == '3') {
            struct VectorN *v = inputIntVector();
            int num = 0;
            printf("\nEnter a number:");
            scanf("%d", &num);
            num_mult_vector(&num, v);
            printf("Vector multiplied by a number %d = ", num);
            printVectorInt(v);
        };
        if (*command == '/') {
            //Test for integer;
            printf("Testing started\n");
            if (1)/*test()*/
                printf("Testing finished\n");
            else
                printf("Testing failed\n");
        };
    } else if (*command == 'c') {
        sep();
        printf("commands:\n");
        printf("	1 - Sum of Vectors\n");
        printf("	2 - Scalar multiplication of Vectors\n");
        printf("	3 - Multiplication of a vector with a scalar \n");
        printf("	/ - Test\n");
        printf("	0 - exit\n");
        gets(command);
        if (*command == '0')
            exit(0);
        // sum of vectors
        if (*command == '1') {
            struct VectorN *v1 = inputComplexVector();
            struct VectorN *v2 = inputComplexVector();
            printf("Vector 1 = ");
            printVectorCompl(v1);
            printf("Vector 2 = ");
            printVectorCompl(v2);
            struct VectorN* v3 = sumN(v1, v2);
            printf("Sum of vectors = ");
            printVectorCompl(v3);
        };
        // scalar mult
        if (*command == '2') {
            struct VectorN *v1 = inputComplexVector();
            struct VectorN *v2 = inputComplexVector();
            struct VectorN *v3 = scalarMultN(v1, v2);
            printf("Vector 1 = ");
            printVectorCompl(v1);
            printf("Vector 2 = ");
            printVectorCompl(v2);
            printf("Scalar multiplication of vectors = ");
            printVectorCompl(v3);
        };
        //mult vector on number
        if (*command == '3') {
            struct VectorN *v = inputComplexVector();
            complex* num = malloc(sizeof(complex));
            printf("\nEnter a number:\n");
            printf("Real:");
            scanf("%f", &num->real);
            printf("Imaginary:");
            scanf("%f", &num->imaginary);
            num_mult_vector(num, v);
            printf("Vector multiplied by a number: ");
            complexCoordOutput(num);
            printf(" = ");
            printVectorCompl(v);
        };
        //test
        if (*command == '/') {
            //Test for complex
            printf("Testing started\n");
            if (1)/*test()*/
                printf("Testing finished\n");
            else
                printf("Testing failed\n");
        };
    } else{
        printf("\n");
        sep();
        printf("\nThe type is incorrect. Please, enter the correct type.\n");
        sep();
        ui();
    };

    //test
    if (*command == '/') {
        printf("Testing started\n");
        if(1)/*test()*/
            printf("Testing finished\n");
        else
            printf("Testing failed\n");
    };


};

