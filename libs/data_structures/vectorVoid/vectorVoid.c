#include "vectorVoid.h"

vectorVoid createVectorV(const size_t n, const size_t baseTypeSize) {
    vectorVoid v = (vectorVoid) {malloc(baseTypeSize * n), 0, n};
    if (n == 0)
        v.data = NULL;
    else if (v.data == NULL) {
        fprintf(stderr, "bad alloc ");
        exit(1);
    }

    return v;
}

void reserveV(vectorVoid *v, const size_t newCapacity) {
    v->data = (int *) realloc(v->data, v->baseTypeSize * newCapacity);
    if (newCapacity == 0) {
        v->data = NULL;
    } else if (v->data == NULL) {
        fprintf(stderr, "bad alloc ");
        exit(1);
    } else {
        v->capacity = newCapacity;
        v->size = newCapacity < v->size ? newCapacity : v->size;
    }
}

void shrinkToFitV(vectorVoid *v) {
    reserveV(v, v->size);
}

void clearV(vectorVoid *v) {
    v->size = 0;
}

void deleteVectorV(vectorVoid *v) {
    free(v->data);
    v->data = NULL;
    v->size = 0;
    v->capacity = 0;
}