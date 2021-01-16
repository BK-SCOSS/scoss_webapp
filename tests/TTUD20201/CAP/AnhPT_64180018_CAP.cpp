#include <bits/stdc++.h>
using namespace std;
int a[101],b[101];
int A,B;
void Input()
{
    cin>>A;
    for (int i=0;i<A;i++)
    {
        cin>>a[i];
    }
    cin>>B;
    for(int i = 0;i<B;i++)
    {
        cin>>b[i];
    }
}
int check()
{   int s=0;
    for(int i = 0;i<A;i++)
        for(int j=0;j<B;j++)
        {
            if(a[i]==b[j])
            {
                s++;
                break;
            }
        }
    return s;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin>>T;
    while(T--)
    {
        Input();
        cout<<check();
        cout<<endl;     
    }
}