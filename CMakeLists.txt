# cmake_minimum_required(VERSION <specify CMake version here>)
#"vector(real, complex).c")
project(Lessons C)

set(CMAKE_C_STANDARD 99)

add_executable(Lessons main.c vector.h vector.c vector_float.h vector_float.c vector_int.h vector_int.c vector_complex.h vector_complex.c interface.c interface.h tests.h test.c 1/LaboratoryWork_-1_1k_2s-main/tests.c)