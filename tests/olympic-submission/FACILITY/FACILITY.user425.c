#include <stdio.h>
#include <stdlib.h>
typedef struct
{
  unsigned long long a;
  unsigned long long b;
} candy;
int main()
{
  int T, i;
  candy *input;
  scanf("%d", &T);
  input = malloc(T * sizeof(candy));
  for (i = 0; i < T; ++i)
    {
      scanf("%llu %llu", &(input + i)->a, &(input + i)->b);
    }
  for (i = 0; i < T; ++i)
    {
      printf("%llu\n", (input+i)->a + (input+i)->b);
    }
  free(input);
  return 0;
}
