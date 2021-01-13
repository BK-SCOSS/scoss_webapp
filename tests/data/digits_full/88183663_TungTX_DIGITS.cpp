#include<bits/stdc++.h>
using namespace std;


int legit(int H, int U, int S, int T, int O, int I, int C, int N){
    int n = H*1000 + U*100 + S*10 + T + S*10000 + O*1000 + I*100 + C*10 + T;
    if(n==N) return 1;
    else return 0;
}

int countWays(int N){
    int dup[10];
    int _count = 0;
    for(int h=1;h<10;++h){
        dup[h] = 1;
        for(int u=0;u<10;++u){
            if(dup[u]==1) continue;
            dup[u] = 1;
            for(int s=0;s<10;++s){
                if(dup[s]==1) continue;
                dup[s] = 1;
                for(int t=0;t<10;++t){
                    if(dup[t]==1) continue;
                    dup[t] = 1;
                    for(int o=0;o<10;++o){
                        if(dup[o]==1) continue;
                        dup[o] = 1;
                        for(int i=0;i<10;++i){
                            if(dup[i]==1) continue;
                            dup[i] = 1;
                            for(int c=0;c<10;++i){
                                if(dup[c]==1) continue;
                                dup[c]=1;
                                if(legit(h,u,s,t,o,i,c,N)) _count++;
                                dup[c]=0;
                            }
                            dup[i] = 0;
                        }
                        dup[o] = 0;
                    }
                    dup[t] = 0;
                }
                dup[s] = 0;
            }
            dup[u] = 0;
        }
        dup[h] = 0;
    }
    return _count;
}

int main()
{
    int test;
    int N;
    cin>> test;
    int result[test];
    for(int i=0;i<test;++i){
        cin>>N;
        result[i] = countWays(N);
    }
    for(int i=0;i<test;++i){
        cout<<result[i]<<endl;
    }
}
