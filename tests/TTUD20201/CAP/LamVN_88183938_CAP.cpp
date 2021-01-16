#include <iostream>

using namespace std;
long A[101];
long B[101];
int c[100];
int k,n,m;
int l=0;
void NhapDuLieu()
{
    cin >> n;
    for (int i=1;i<=n;i++)
    {
           cin >>A[i];
    }
    cin >> m;
    for (int j=1;j<=m ; j++)
    {
        cin >> B[j];
    }
}
void XuatDuLieu()
{
    cin >>k;
    for (int i=1;i<=k;i++)
    {
        NhapDuLieu();
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=m;j++)
            {
                if(A[i]==B[j])
                {
                    l=l+1;
                }
            }
        }
        cout << l << endl;
    }
}
int main()
{
    XuatDuLieu();
}
