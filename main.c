#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void *thread_one(void *vargp) {
  int *a = (int *)vargp;
  while (1) {
    *a = 6;
  }
}

void *thread_two(void *vargp) {
  int *a = (int *)vargp;

  while (1) {
    *a = 5;
    if (!(*a == *a)) {
      printf("a does not equal a\n");

      free(a);
      exit(1);
    }
  }
}

int main() {
  int *a = malloc(sizeof(int));
  *a = 5;

  pthread_t thread_o;
  pthread_t thread_t;

  pthread_create(&thread_o, NULL, thread_one, (void *)a);
  pthread_create(&thread_t, NULL, thread_two, (void *)a);

  while (1) {
  }
  free(a);
  return 0;
}
