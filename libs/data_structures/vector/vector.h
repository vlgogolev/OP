#ifndef INC_VECTOR_H
#define INC_VECTOR_H

#include <stdio.h>
#include <malloc.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct vector {
    int *data; // указатель на элементы вектора
    size_t size; // размер вектора
    size_t capacity; // вместимость вектора
} vector;

vector createVector( const size_t n);

void reserve(vector *v, const size_t newCapacity);

void clear(vector *v);

void shrinkToFit(vector *v);

void deleteVector(vector *v);


#endif
