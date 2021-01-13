#include <stdio.h>
#include <stdlib.h>
typedef struct
{
  unsigned long a;
  unsigned long b;
} candy;
int main()
{
  int T, i;
  candy *input;
  scanf("%d", &T);
  input = malloc(T * sizeof(candy));
  for (i = 0; i < T; ++i)
    {
      scanf("%lu %lu", &(input + i)->a, &(input + i)->b);
    }
  for (i = 0; i < T; ++i)
    {
      printf("%lu\n", (input+i)->a + (input+i)->b);
    }
  free(input);
  return 0;
}
