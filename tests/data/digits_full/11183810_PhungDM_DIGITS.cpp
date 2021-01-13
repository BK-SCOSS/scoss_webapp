#include <bits/stdc++.h>
using namespace std ;
int X[7];// X[0] = I, X[1] = C, X[2] = T, X[4] = H, X[5] = U, X[6] = S, X[3] = O
int appeared[10];
int ans,N;
void solution()
{
    int T = X[4]*1000 + X[5]*100 + X[6]*10+X[2] +X[6]*10000+X[3]*1000+X[0]*100+ X[1]*10+ X[2];
    if(T == N)
    {
        ans++;

    }
}
void init()
{
    for(int v = 1; v <= 9; v++) appeared[v] = 0;
}
void TRY(int k)
{
    for(int v = 1; v <= 9; v++)
    {
        if(appeared[v] == 0)
        {
            X[k] = v;
            appeared[v] = 1;
            if(k == 6)
            {
                solution();
            }
            else
            {
                TRY(k+1);
            }
            appeared[v] = 0;
        }
    }
}

int main()
{
    int j ;
    cin >>j ;
    for (int i=0; i<j; i++)
    {
        cin>>N;
        init();
        ans = 0;
        TRY(0);
        cout<<ans <<endl;
    }
}
