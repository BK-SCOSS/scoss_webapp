#include<iostream>
using namespace std;

int N;

int S,O,I,C,T,H,U;

void find(int N){
    if (N%2==1){
        cout<<0<<"\n";
        return;
    }
    if ((N<11000)||(N>109998)){
        cout<<0<<"\n";
        return ;
    }
    
    int count = 0, N_S_T, N_S_T_C, O_H;
    int t[] = {(N%10)/2, ((N%10)+10)/2};
    for (int i=0;i<=1;++i){
        T = t[i];
        int s[] = {N/10000, N/10000 - 1,9};
        for (int j=0; j<=2; ++j) {
            S=s[j];
            if ((S!=T)&&(S!=0)) {
                N_S_T = (N-10010*S-2*T)/10;
                if (N_S_T>=0){
                    C = N_S_T%10;
                    if((C!=S)&&(C!=T)){
                        N_S_T_C = (N_S_T-C)/10;
                        int I_U[] = {N_S_T_C%10, N_S_T_C%10+10};
                        for (int k=0;k<=1;++k){
                            for (I=0;(I<=I_U[k])&&(I<=9);++I){
                                if ((I!=T)&&(I!=S)&&(I!=C)) {
                                    U = I_U[k]-I;
                                    if ((U!=T)&&(U!=S)&&(U!=C)&&(U!=I)&&(U<=9)){
                                        O_H = (N_S_T_C-I-U)/10;
                                        for (int m=0;(m<=O_H)&&(m<=9);++m){
                                            O=m;
                                            if ((O!=T)&&(O!=S)&&(O!=C)&&(O!=I)&&(O!=U)) {
                                                H = O_H -m;
                                                if ((H!=T)&&(H!=S)&&(H!=C)&&(H!=I)&&(H!=U)&&(H!=O)&&(H<=9)&&(H>0)){
                                                    count++;
//                                                    cout<<S<<O<<I<<C<<T<<"\n"<<H<<U<<S<<T<<"\n";
//                                                    cout<<"\n";
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        
    }
    cout<<count<<"\n";
}

int main(){
    int test;
    cin>>test;
    
    for (int i=0;i<test;++i){
        cin>>N;
        find(N);
    }
    return 0;
}
