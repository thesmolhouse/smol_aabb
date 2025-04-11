# Smol AABB
A smol lib about aabb collisions.
It's only for study, but if you can use it, use it. (**\***)  
> \* Consider using it in game development.

## How to use?
``` c
#include <stdio.h>
#define SMOL_AABB_IMPLEMENTATION
#include "smol_aabb.h"

int main () {
  smol_aabb_rect a = {0, 0, 3, 3};
  smol_aabb_rect b = {1, 1, 1, 1};
  smol_aabb_rect c = {4, 1, 2, 2};

  printf("Rect a and b: ");
  if (smol_aabb_intersects(a, b)) {
    printf("True\n");
  } else {
    printf("False\n");
  }

  printf("Rect a and c: ");
  if (smol_aabb_intersects(a, c)) {
    printf("True\n");
  } else {
    printf("False\n");
  }

  return 0;
}
```
