#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct STRUCT{
    long long s;
    long long d;
    long long r;
};

bool is_less_than(STRUCT& a1, STRUCT& a2){
    if (a1.d<a2.d) return true;
    return false ;
}
int main()
{

   // freopen("test.txt","r",stdin);

    ios_base::sync_with_stdio(false);

    int n;
    long long k;
    cin>>n>>k;
    STRUCT arr[n+2];
    for (int i=0;i<n;i++){
        cin>>arr[i].s>>arr[i].d>>arr[i].r;
        arr[i].d+=arr[i].s;
    }

    sort(arr,arr+n,is_less_than);
    long long l[n+2];
    long long maxl[n+2];
    for (int i=0;i<n;i++){
        l[i]=arr[i].r;
    }

    maxl[0]=l[0];

    for (int i=1;i<n;i++){
        int bottom=0;
        int top=i-1;
        int p=arr[i].s-k;
        while (bottom<=top){
            int mid=(bottom+top)/2;

            if (arr[mid].d<=p) bottom=mid+1;
                else top=mid-1;
        };

        if (top>=0) l[i]=maxl[top]+arr[i].r;


        maxl[i]=max(maxl[i-1],l[i]);
    }


    cout<<maxl[n-1];
    return 0;
}
