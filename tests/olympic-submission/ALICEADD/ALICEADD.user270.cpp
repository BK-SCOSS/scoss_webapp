#include<bits/stdc++.h>
using namespace std;

int main ()
{
    int T;
    cin>>T;
    string a, b;
    for (int i=1; i<=T; i++) {
        cin>>a>>b;
        int la, lb;
        la = a.length();
        lb = b.length();
        int A[21], B[21], sum[21];
        for (int j=0; j<21; j++) {
            A[j]=0;
            B[j]=0;
            sum[j]=0;
        }
        for (int j=20; j>20-la; j--) {
            A[j] = a[la+j-21] - '0';
        }
        for (int j=20; j>20-lb; j--) {
            B[j] = b[lb+j-21] - '0';
        }
        for (int j=20; j>0; j--) {
            sum[j] = A[j] + B[j];
        }
        for (int j=20; j>0; j--) {
            if (sum[j]>=10) {
                sum[j]-=10;
                sum[j-1]+=1;
            }
        }
        int k;
        for(int j=0; j<21; j++) {
            if (sum[j]!=0) {
                k=j;
                break;
            }
        }
        for (int j=k; j<21; j++) {
            cout<<sum[j];
        }
    }
    return 0;
}
