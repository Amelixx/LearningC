#include "dep.h"
#include <stdlib.h>
#include <time.h>

_Bool global_flag = 0;
void seed_once() {
  if(!global_flag) {
    srand(time(NULL));
  }
  global_flag = 1;
}
int *get_input() {
  seed_once();
  int *out = malloc (SIZE*sizeof(int));
  for (int i = 0; i < SIZE; i++) out[i] = rand() % RANGE + 1;
  return out;
}