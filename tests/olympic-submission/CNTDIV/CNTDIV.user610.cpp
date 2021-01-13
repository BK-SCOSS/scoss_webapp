#include <bits/stdc++.h>

using namespace std;

int n;

int slv(int x){
    int ans=0;
    for (int i=1;i<n*(n+1)*(n+2);i++)
    {
        if (x % i == 0 && n*(n+1)*(n+2) % i !=0 ) ans++;
    }
    return ans;
}
int main()
{

    int t;
    cin>>t;
    while (t--){
        cin >> n;
        cout<<slv(n*(n+1)*(n+2)*n*(n+1)*(n+2))<<"\n";
    }
    return 0;
}
