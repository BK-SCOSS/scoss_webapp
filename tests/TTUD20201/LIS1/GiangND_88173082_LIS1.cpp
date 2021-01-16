#include <iostream>
#include <algorithm>

using namespace std;

int n, t;
long long a[100000];
int result[10];
int temp = 0;
void resolve(){
    cin>>t;
    for(int m=0; m<t; m++){
        int maxx = -100000;
        int counts = 1;
        cin>>n;
        for(int i=0; i<n; i++){
            cin>>a[i];
        }
        for(int j=0; j<n; j++){
            int s = a[j];
            for(int k=j+1; k<n; k++){
                if(a[k]==s+1){
                    counts++;
                    s = a[k];
                }
            }
            maxx = max(counts, maxx);
            counts = 0;
        }
        result[temp++] = maxx;
    }
    for(int i=0; i<10; i++){
        if(result[i]!=0){
            cout<<result[i]<<endl;
        }
    }
}


int main(){
    resolve();
    return 0;
}
