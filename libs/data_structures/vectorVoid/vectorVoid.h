#ifndef INC_VECTORVOID_H
#define INC_VECTORVOID_H

#include <stdio.h>
#include <limits.h>
#include <malloc.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>

typedef struct vectorVoid {
    void *data; // указатель на нулевой элемент вектора
    size_t size; // размер вектора
    size_t capacity; // вместимость вектора
    size_t baseTypeSize; // размер базового типа:
    // например, если вектор хранит int -
    // то поле baseTypeSize = sizeof(int)
    // если вектор хранит float -
    // то поле baseTypeSize = sizeof(float)
} vectorVoid;

vectorVoid createVectorV(const size_t n, const size_t baseTypeSize);

void reserveV(vectorVoid *v, const size_t newCapacity);

void shrinkToFitV(vectorVoid *v);

void clearV(vectorVoid *v);

void deleteVectorV(vectorVoid *v);

bool isEmptyV(const vectorVoid *v);

bool isFullV(const vectorVoid *v);

void getVectorValueV(vectorVoid *v, const size_t index, void *destination);

void setVectorValueV(vectorVoid *v, const size_t index, const void *source);

void popBackV(vectorVoid *v);

void pushBackV(vectorVoid *v, const void *source);

#endif
