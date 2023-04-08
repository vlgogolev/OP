#include "vectorVoid.h"

vectorVoid createVectorV(const size_t n, const size_t baseTypeSize) {
    vectorVoid v = (vectorVoid) {malloc(baseTypeSize * n), 0, n, baseTypeSize};
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

bool isEmptyV(const vectorVoid *v) {
    return v->size == 0;
}

bool isFullV(const vectorVoid *v) {
    return v->size == v->capacity;
}

void getVectorValueV(vectorVoid *v, const size_t index, void *destination) {
    if (index >= v->size) {
        fprintf(stderr, "IndexError: a[%zu] is not exists", index);
        exit(1);
    }
    const char *source = (char *) v->data + index * v->baseTypeSize;
    memcpy(destination, source, v->baseTypeSize);
}

void setVectorValueV(vectorVoid *v, const size_t index, const void *source) {
    if (index >= v->size) {
        fprintf(stderr, "IndexError: a[%zu] is not exists", index);
        exit(1);
    }
    char *destination = (char *) v->data + index * v->baseTypeSize;
    memcpy(destination, source, v->baseTypeSize);
}

void popBackV(vectorVoid *v) {
    if (isEmptyV(v)) {
        fprintf(stderr, "IndexError: vector is empty");
        exit(1);
    } else
        v->size--;
}

void pushBackV(vectorVoid *v, void *source) {
    if (v->capacity == 0) {
        v->capacity++;
        reserveV(v, v->capacity);
    } else if (isFullV(v))
        reserveV(v, 2 * v->capacity);
    char *destination = (char *) v->data + v->size * v->baseTypeSize;
    memcpy(destination, source, v->baseTypeSize);
    v->size++;
}