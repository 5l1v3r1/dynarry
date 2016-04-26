// dyn_array-usage.c

#include <stdio.h>
#include "dynamic_array.h"

int main() {
  // declare and initialize a new dyn_array
  Vector dyn_array;
  dyn_array_init(&dyn_array);

  // fill it up with 150 arbitrary values
  // this should expand capacity up to 200
  int i;
  for (i = 200; i > -50; i--) {
    dyn_array_append(&dyn_array, i);
  }

  // set a value at an arbitrary index
  // this will expand and zero-fill the dyn_array to fit
  dyn_array_set(&dyn_array, 4452, 21312984);

  // print out an arbitrary value in the dyn_array
  printf("Heres the value at 27: %d\n", dyn_array_get(&dyn_array, 27));

  // we're all done playing with our dyn_array, 
  // so free its underlying data array
  dyn_array_free(&dyn_array);
}

