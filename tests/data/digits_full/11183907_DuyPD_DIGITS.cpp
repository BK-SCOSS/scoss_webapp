#include <iostream>

using namespace std;
int N;
int a[10];

bool check(int a[])

{
    int cnt = 0;
    for(int i=1; i<=7; i++){
        for(int j=1; j<=7; j++){
            if(i!=j && a[i] == a[j]){
                cnt++;
            }
        }
    }
    if(cnt==0){
        return true;
    }else return false;
}

void input()
{
    cin >> N;
}
int solve()
{
    int Q= 0;
    for(int S = 1; S<=9; S++){
        a[1] = S;
        for(int H = 1; H<=9; H++){
            a[2] = H;
            for(int O = 0; O<=9; O++){
                a[3] = O;
                for(int I = 0; I<=9; I++){
                    a[4] = I;
                    for(int U = 0; U<=9; U++){
                        a[5] = U;
                        for(int C = 0; C<=9; C++){
                            a[6] = C;
                            for(int T = 0; T<=9; T++){
                                a[7] = T;
                                if(check(a) && ((10010*S + 1000*(H+O) + 100*(I+U) + 10*C + 2*T)==N)){
                                    Q++;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return Q;
}
int main()
{
    int t;
    cin>> t;
    int b[t];
    for (int i = 1; i <= t; i++){
        input();
        b[i] = solve();
    }
    for (int i = 1; i <= t; i++){
    cout << b[i] << endl;
    }
    return 0;
}
