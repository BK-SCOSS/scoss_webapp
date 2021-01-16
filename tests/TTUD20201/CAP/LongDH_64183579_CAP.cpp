#include<bits/stdc++.h>
using namespace std;
int a[100000];
int b[100000];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t){
        t--;
        int n,m,res=0;
        cin >>n;
        for(int i=0;i<n;i++){
            cin >> a[i];
        }
        cin >>m;
        for(int i=0;i<m;i++){
            cin >> b[i];
        }
        int res1 =0;
        int res2 =0;
        for(int i=0;i<n;i++){
             for(int j=0;j<m;j++){
                if(a[i]==b[j]){
                    res++;
                    break;
                }
            }
        }
        cout<<res<<endl;
       //for(int i=0;i<m;i++){
          //  for(int j=0;j<n;j++){
            //    if(b[i]==a[j]){
           //         res2++;
            //        break;
             //   }
            //}
        //}
        //cout<<res1<<" "<<res2<<endl;
        //res = max(res1,res2);
        //cout<<res<<endl;
    }
    return 0;
}
