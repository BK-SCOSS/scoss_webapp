#include <stdio.h>

int main()
{
  int N;
  int T[1000];
  int T1[1000];
  int Q;
  do
  {
      scanf("%d", &Q);
  } while (Q<0);
  int i, j;
  for(i=0; i<Q; i++)
    {
        do
        {
            scanf("%d", &N);
        } while(N<=0);
        T[i]=N*(N+1)*(N+2);
        T1[i]=N*(N+1)*(N+2)*N*(N+1)*(N+2);
    }
  int T2[1000];
  for(i=0; i<Q; i++)
    T2[i]=0;
  for(i=0; i<Q; i++)
    {
        for(j=2; j<T[i]; j++)
            {
                if(T1[i]%j==0 && T[i]%j!=0)
                    T2[i]++;
            }
      }
   for(i=0; i<Q; i++)
        printf("%d\n",T2[i]);
   return 0;
}
