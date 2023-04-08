#include "vector.h"

vector createVector(const size_t n) {
    vector v = (vector) {malloc(sizeof(int) * n), 0, n};
    if (n == 0)
        v.data = NULL;
    else if (v.data == NULL) {
        fprintf(stderr, "bad alloc ");
        exit(1);
    }

    return v;
}

void reserve(vector *v, const size_t newCapacity) {
    v->data = (int *) realloc(v->data, sizeof(int) * newCapacity);
    if (newCapacity == 0)
        v->data = NULL;
    else if (v->data == NULL) {
        fprintf(stderr, "bad alloc ");
        exit(1);
    } else {
        v->capacity = newCapacity;
        v->size = newCapacity < v->size ? newCapacity : v->size;
    }
}

void clear(vector *v) {
    v->size = 0;
}

void shrinkToFit(vector *v) {
    reserve(v, v->size);
}

void deleteVector(vector *v) {
    free(v->data);
}