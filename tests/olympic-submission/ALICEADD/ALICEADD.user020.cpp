#include <bits/stdc++.h>
using namespace std;
int Chuyen(char a[], char b[], int _a[], int _b[]) {
    int carry = strlen(a);
    int _carry = strlen(b);
    int ans;
    if (carry>_carry) ans=carry;
    else ans = _carry;
    carry--;
    _carry--;
    for (int i=ans-1; i>=0; i--)
    {
        if (carry>=0)
        {
            _a[i] = a[carry]-'0';
            carry--;
        }
        else _a[i]=0;
        if (_carry>=0)
        {
            _b[i] = b[_carry]-'0';
            _carry--;
        }
        else _b[i]=0;
    }
    return ans;
}
int Add(int A[], int B[], int cnt, int C[]) {
    for (int i=cnt-1; i>=0; i--) {
        if (i!=0) {
            int carry = A[i]+B[i];
            C[i]=carry%10;
            B[i-1]=B[i-1]+(carry/10);
        } else C[i]=A[i]+B[i];
    }
    return cnt;
}
int main()
{
    int T;
    cin>>T;
    for(int i=1;i<=T;i++)
    {
        char a[20] = "";
        char b[20] = "";
        cin>>a>>b;
        int cnt;
        int _a[20], _b[20], Sum[20];
        cnt = Chuyen(a, b, _a, _b);
        int __Sum = Add(_a, _b, cnt, Sum);
        for (int i=0; i<__Sum; i++)
        {
            cout<<Sum[i];
        }
        cout<<endl;
    }
}
