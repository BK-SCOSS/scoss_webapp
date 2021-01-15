// Trần Xuân Bách //
// 20-06-2002 //
#include<bits/stdc++.h>;
#define f(i,x,y) for(int i=x;i<=y;i++)
#define fn(i,x,y) for(int i=x;i>=y;i--)
#define pi acos(-1)
using namespace std;
long long n;
unsigned long long a,b;
int main()
{
    ios_base::sync_with_stdio(0);
     cin.tie(0);
     cout.tie(0);
     //freopen("int.txt", "r" , stdin);
     //freopen("out.txt", "w" , stdout);
    cin >> n;
    f(i,1,n)
    {
        cin >> a >> b;
        cout << a+b;
    }
    return 0;
   }
