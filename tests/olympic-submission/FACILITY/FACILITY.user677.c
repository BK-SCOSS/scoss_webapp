#include <stdio.h>
#define MAX_INT 50000
#define MAX_V 150000
int N, K, i, j, k;
int V[MAX_V];
int s[MAX_INT], d[MAX_INT], r[MAX_INT];
float p[MAX_INT];
int pos[MAX_INT];
int result = 0;
void SapXepThamLam()
{
    for(i = 0; i < N; ++ i){
        for(j = N-1; j > i; -- j){
            if(p[j] > p[i] || (p[j] == p[i] && r[j] > r[i])){
                int temp = pos[i];
                pos[i] = pos[j];
                pos[j] = temp;
            }
        }
    }
//    for(i = 0; i < N; ++ i){
//        printf("%d ", pos[i]);
//    }
}
int HasDay(int start, int end)
{
    int i;
    for(i = start; i < end; ++ i){
        if(V[i-1] > 0)
            return 1;
    }
    return 0;
}
void ThamLam()
{
    //int length = 0;
    int i, j;
    for(i = 0; i < N; ++i){
        int start = s[pos[i]];
        int end = start + d[pos[i]] + K;
        //printf("start[%d] = %d, end = %d\n", pos[i], start, end);
//        if(end > length)
//            length = end;
        if(HasDay(start, end) == 0){
            for(j = start; j < end; ++ j){
                V[j-1] = r[pos[i]];
            }
            result += r[pos[i]];
        }
    }
}
int main()
{
    scanf("%d%d", &N, &K);
    for(i = 0; i < N; ++ i){
        scanf("%d%d%d", s+i, d+i, r+i);
        p[i] = r[i]*1.0 / d[i];
        pos[i] = i;
    }
    SapXepThamLam();
    ThamLam();
    printf("%d", result);
    return 0;
}
