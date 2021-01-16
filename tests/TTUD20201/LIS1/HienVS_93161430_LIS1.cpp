#include<bits/stdc++.h>
using namespace std;

int n;
int a[100000];
int l[100000];
int t;

main(){
    cin >> t;
    while(t>0){
        cin >> n;
        for(int i=0;i<n;i++){
            cin >> a[i];
        }
        for(int i=0;i<n;i++){
            int num = a[i];
            for(int j=i+1;j<n;j++){
                if(a[j]==(num+1)){
                    l[i]++;
                    num++;
                }
            }
        }
        int ans = l[1];
        for(int i=0;i<n;i++){
            ans = max(ans,l[i]);
        }
        cout << ans+1 << endl;
        t--;
    }
}