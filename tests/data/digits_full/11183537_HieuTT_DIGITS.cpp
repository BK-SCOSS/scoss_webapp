#include <iostream>
#include <vector>
#include <array>
using namespace std;

int a[8];
int check[10];
int ketqua = 0;
int n[51];

void solution(int n){
    if (a[0] == 0 || a[2] ==0) return;
    int tmp = a[0]*1000 + a[1]*100 + a[2]*10 + a[3]
    + a[2]*10000 + a[4]*1000 + a[5] *100 + a[6]*10 + a[3];
    if (tmp == n) ketqua++;
}


void process(int n,int k){
    for (int i = 0; i<=9; i++)
    if (check[i] == 0){
            a[k] = i;
            check[i] = 1;
            if (k == 6) {
                solution(n);
            }
            else{
            process(n,k+1);
            }
            check[i] = 0;
    }
}
int T;
void input(){

    cin >> T;
    for (int i = 1; i<= T; i++)
    {
        cin >> n[i];
    }
}
int main()
{
    input();
    for (int i =1;i<=T; i++)
    {
        ketqua = 0;
        if (n[i] %2 == 0)
        process(n[i],0);
        cout << ketqua<< endl;
    }
    return 0;
}
