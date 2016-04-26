// dyn_array.c

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "dynamic_array.h"


void dyn_array_init(Vector *dyn_array) {
  // initialize size and capacity
  dyn_array->size = 0;
  dyn_array->capacity = VECTOR_INITIAL_CAPACITY;

  // allocate memory for dyn_array->data
  dyn_array->data = malloc(sizeof(int) * dyn_array->capacity);
}

void dyn_array_append(Vector *dyn_array, uint32_t value) {
  // make sure there's room to expand into
  dyn_array_double_capacity_if_full(dyn_array);

  // append the value and increment dyn_array->size
  dyn_array->data[dyn_array->size++] = value;
}

int dyn_array_get(Vector *dyn_array, int index) {
  if (index >= dyn_array->size || index < 0) {
    printf("Index %d out of bounds for dyn_array of size %d\n", index, dyn_array->size);
    exit(1);
  }
  return dyn_array->data[index];
}

void dyn_array_set(Vector *dyn_array, int index, uint32_t value) {
  // zero fill the dyn_array up to the desired index
  while (index >= dyn_array->size) {
    dyn_array_append(dyn_array, 0);
  }

  // set the value at the desired index
  dyn_array->data[index] = value;
}

void dyn_array_double_capacity_if_full(Vector *dyn_array) {
  if (dyn_array->size >= dyn_array->capacity) {
    // double dyn_array->capacity and resize the allocated memory accordingly
    dyn_array->capacity *= 2;
    dyn_array->data = realloc(dyn_array->data, sizeof(int) * dyn_array->capacity);
  }
}

void dyn_array_free(Vector *dyn_array) {
  free(dyn_array->data);
}
