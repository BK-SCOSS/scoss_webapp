#include<bits/stdc++.h>

using namespace std;

int n, a[100001], T;

int main(){
    cin>>T;
    for(int k=1; k<=T; k++){
        cin>>n;
        for(int i=1; i<=n; i++)
            cin>>a[i];
        int m = n;
        int time = 0;
        while(m != 1){
            int maxx = 0;
            int j=1;
            for(int i=1; i<=m; i=i+2){
                if(i+1<=m)
                    a[j] = a[i] + a[i+1];
                else a[j] = a[i];
                maxx = max(maxx,a[j]);
                j++;
            }
            time+=maxx;
            if(m%2==0)m=m/2;
            else m=(m-1)/2 + 1;
        }
        cout<<time<<endl;
    }
    return 0;
}
