/*
Cho một số nguyên dương N. Hãy đếm số cách điền giá trị cho các ký tự H, U, S, T, O, I, C sao cho
tổng số có 4 chữ số HUST và số có 5 chữ số SOICT bằng N: HUST + SOICT = N. Lưu ý, hai ký tự
khác nhau phải nhận giá trị khác nhau.

input
5
17868
29119
49862
78952
1000002

*/

#include <bits/stdc++.h>
//Tranminhquang 20183972

using namespace std;
int Test;
int N[51];
int a[10];
int Q[51];
int ptcb=0;

int main()
{
    ios_base::sync_with_stdio(false); tie(cin);
    cin >> Test;
    for(int i=1; i<=Test; i++){
        cin >> N[i];
        Q[i]= 0;
    for(int H = 1; H<=9; H++){
        a[1] = H;
        for(int U = 0; U<=9; U++){
            a[2] = U;
            if(a[1]!=a[2])
            for(int S = 1; S<=9; S++){
                a[3] = S;
                if(a[3] != a[1] && a[3] !=a[2])
                for(int T = 0; T<=9; T++){
                    a[4] = T;
                    if(a[4] != a[1] && a[4] !=a[2] && a[4]!=a[3])
                    for(int O = 0; O<=9; O++){
                        a[5] = O;
                        if(a[5] != a[1] && a[5] !=a[2] && a[5]!=a[3] && a[5] != a[4])
                        for(int I = 0; I<=9; I++){
                            a[6] = I;
                            if(a[6] != a[1] && a[6] !=a[2] && a[6]!=a[3] && a[6] != a[4] && a[6] != a[5])
                            for(int C = 0; C<=9; C++){
                                a[7] = C;
                                //ptcb++;
                                if(a[7] != a[1] && a[7] !=a[2] && a[7]!=a[3] && a[7] != a[4] && a[7] != a[5] && a[7] != a[6] && ((H*1000 + U*100 + 2*T + S*10010 + O*1000 + I*100 +C*10)==N[i])){
                                    Q[i]++;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout << Q[i] << endl;
    }
//cout<<ptcb;
    return 0;
}
