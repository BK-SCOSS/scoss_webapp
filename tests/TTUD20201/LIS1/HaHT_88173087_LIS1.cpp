#include <iostream>
using namespace std;
const int NMAX = 1e5;
int t;
void lis(){
    int res = 1;
    int maxr = 0;
    int n;
    int a[NMAX];
    cin >> n;
    for(int i=1; i <=n; i++){
        cin >> a[i];
    }

    for(int i=1; i<=n; i++){
        for(int j = i+1; j <= n; j++){
            if(a[i]+1 == a[j]){
                res++;
                i=j;
            }

        }
        if(res>maxr){
            maxr=res;}
            res =0;

    }


cout << maxr;

}


int main(){
    cin >> t;
for(int k=1;k<=t;k++){
        lis();
}
return 0;}
