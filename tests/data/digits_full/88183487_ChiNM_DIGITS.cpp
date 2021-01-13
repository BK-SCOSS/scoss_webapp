//
//  main.cpp
//  NopbaiThiGiuaKi
//
//  Created by Matt on 28/11/2020.
//

#include <iostream>

using namespace std;
int T;
int N[50];
int A, B, C, D, E, F, G;
int check[10];

int main()
{
    cin >> T;
    for(int i = 0; i < T; i++){
        cin >> N[i];
    }
    for(int i = 0; i< 10; i++){
        check[i] = 0;
    }

    for(int i = 0; i < T; i++){
        int result = 0;
        for(int j = 0; j < 7; j++){
            int a = N[i] / 10010;
            int a2 = 9>a?a:9;
            for(int a1 = 1; a1 <= a2; a1++){
                if(check[a1] == 1) continue;

                int restA = N[i] - a1*10010;
                if(restA < (1*1000 + 2*1000 + 3* 100 + 4 * 100 + 5*10 + 6* 2)){
                    continue;
                }
                check[a1] = 1;
                int b = restA / 1000;
                int b2 = 9>b?b:9;
                for(int b1 = 1; b1 <= b2; b1++){
                    if(check[b1] == 1) continue;

                    int restB = restA - b1*1000;
                    if(restB < (1*1000 + 2* 100 + 3 * 100 + 4*10 + 5* 2)){
                        continue;
                    }
                    check[b1] = 1;
                    int c = restB / 1000;
                    int c2 = 9>c?c:9;
                    for(int c1 = 0; c1 <= c2; c1++){
                        if(check[c1] == 1) continue;

                        int restC = restB - c1*1000;
                        if(restC < (1* 100 + 2 * 100 + 3*10 + 4* 2)){
                            continue;
                        }
                        check[c1] = 1;
                        int d = restC / 100;
                        int d2 = 9>d?d:9;
                        for(int d1 = 0; d1 <= d2; d1++){
                            if(check[d1] == 1) continue;

                            int restD = restC - d1*100;
                            if(restD < (1 * 100 + 2*10 + 3* 2)){
                                continue;
                            }
                            check[d1] = 1;
                            int e = restD / 100;
                            int e2 = 9>e?e:9;
                            for(int e1 = 0; e1 <= e2; e1++){
                                if(check[e1] == 1) continue;

                                int restE = restD - e1*100;
                                if(restE < (1*10 + 2* 2)){
                                    continue;
                                }
                                check[e1] = 1;
                                int f = restE / 10;
                                int f2 = 9>f?f:9;
                                for(int f1 = 0; f1 <= f2; f1++){
                                    if(check[f1] == 1) continue;

                                    int restF = restE - f1*10;
                                    if(restF < (1* 2)){
                                        continue;
                                    }
                                    check[f1] = 1;
                                    int g = restF / 2;
                                    if(g*2 == restF && g<=9){
                                        if(check[g] == 0){
                                            result += 1;
                                        }
                                    }
                                    check[f1] = 0;
                                    continue;
                                }
                                check[e1] = 0;
                            }
                            check[d1] = 0;
                        }
                        check[c1] = 0;
                    }
                    check[b1] = 0;
                }
                check[a1] = 0;
            }
        }
        cout << result << endl;
    }

    return 0;
}
