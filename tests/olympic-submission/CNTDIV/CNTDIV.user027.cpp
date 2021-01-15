// Trần Xuân Bách //
// 20-06-2002 //
#include<bits/stdc++.h>;
#define f(i,x,y) for(int i=x;i<=y;i++)
#define fn(i,x,y) for(int i=x;i>=y;i--)
#define pi acos(-1)
using namespace std;
int x,n,kq;
unsigned long long t,t2;
int main()
{
    ios_base::sync_with_stdio(0);
     cin.tie(0);
     cout.tie(0);
     //freopen("int.txt", "r" , stdin);
     //freopen("out.txt", "w" , stdout);
     cin >> x;
     f(j,1,x){
         kq=0;
    cin >> n;
    t=n*(n+1)*(n+2);
    t2=t*t;
    f(i,1,t)
    {
        if(t2%i==0&&t%i!=0)kq++;
    }
    cout << kq << endl;}
    return 0;
   }
