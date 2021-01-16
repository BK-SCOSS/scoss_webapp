#include<bits/stdc++.h>
using namespace std;

int t,n;
vector<int> a;

main(){
    cin >> t;
    while(t>0){
        int k;
        cin >> n;
        for(int i=0;i<n;i++){
            cin >> k;
            a.push_back(k);
        }
        int m = n;
        int ans=0;
        vector<int> b;
        while(m>0){
            int maxnum = 0;
            int l1 = a.size();
            for(int i=0;i<l1-1;i=i+2){
                int c = a[i]+a[i+1];
                maxnum = max(maxnum,c);
                b.push_back(c);
            }
            if(l1%2==1){
                    b.push_back(a[l1-1]);
                }
            a.clear();
            a=b;
            b.clear();
            ans += maxnum;
            m/=2;
        }
        cout << ans << endl;
        t--;
    }
}
