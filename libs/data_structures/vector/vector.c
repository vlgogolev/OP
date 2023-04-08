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

bool isEmpty(const vector *v) {
    return v->size == 0;
}

bool isFull(const vector *v) {
    return v->size == v->capacity;
}

int getVectorValue(const vector *v, const size_t i) {
    return *(v->data + i);
}

void pushBack(vector *v, const int x) {
    if (v->capacity == 0) {
        v->capacity++;
        reserve(v, v->capacity);
    } else if (isFull(v))
        reserve(v, 2 * v->capacity);
    v->data[v->size] = x;
    v->size++;
}

void popBack(vector *v) {
    if (isEmpty(v)) {
        fprintf(stderr, "bad alloc ");
        exit(1);
    } else
        v->size--;
}

int *atVector(const vector *v, const size_t index) {
    if (index < 0 || index >= v->size || isEmpty(v)) {
        fprintf(stderr, "IndexError: a[%zu] is not exists", index);
        exit(1);
    }

    return v->data + index;
}

int *back(const vector *v) {
    if (isEmpty(v)) {
        fprintf(stderr, "IndexError: vector is empty");
        exit(1);
    }
    return &(v->data[v->size - 1]);
}

int *front(const vector *v) {
    if (isEmpty(v)) {
        fprintf(stderr, "IndexError: vector is empty");
        exit(1);
    }
    return &(v->data[0]);
}