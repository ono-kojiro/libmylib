#include <stdio.h>

#include "mylib.h"

int mylib(void)
{
  printf("this is mylib.\n");
  return 0;
}

int mylib_add(int a, int b)
{
  return a + b;
}

int mylib_sub(int a, int b)
{
  return a - b;
}

