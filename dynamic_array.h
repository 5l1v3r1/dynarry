// dyn_array.h

#include <stdint.h>
#define VECTOR_INITIAL_CAPACITY 100

// Define a dyn_array type
typedef struct {
  int size;      // slots used so far
  int capacity;  // total available slots
  uint32_t *data;     // array of integers we're storing
} Vector;

void dyn_array_init(Vector *dyn_array);

void dyn_array_append(Vector *dyn_array, uint32_t value);

int dyn_array_get(Vector *dyn_array, int index);

void dyn_array_set(Vector *dyn_array, int index, uint32_t value);

void dyn_array_double_capacity_if_full(Vector *dyn_array);

void dyn_array_free(Vector *dyn_array);
