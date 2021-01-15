#include<iostream>

using namespace std;

void input(int n[], int q){
    for(int i = 0; i < q; i++)
        cin>>n[i];
}

void output(int t[], int tdb[], int q){
    for(int i = 0; i < q; i++){
        int dem = 0;
        for(int j = 1; j < t[i]; j++){
            if(tdb[i]%j == 0 && t[i]%j != 0)
                dem++;
        }
        cout<<dem<<endl;
    }
}

int main(){
    int Q;
    cin>>Q;
    int N[100], T[100], Tdb[100];
    input(N,Q);
    for(int i = 0; i < Q; i++){
        T[i] = N[i] * (N[i]+1) * (N[i]+2);
        Tdb[i] = T[i] * T[i];
    }

    output(T,Tdb,Q);

}