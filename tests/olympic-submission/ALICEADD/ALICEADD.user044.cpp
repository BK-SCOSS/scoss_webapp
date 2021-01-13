#include <iostream>

using namespace std;

void add(long long a, long long b)
{
    long long a1 = a/10;
    long long b1 = b/10;
    int c = a%10 + b%10;


    if(a1+b1!=0)
        if(c>10)
        {
            cout<<a1+b1+1<<c%10;
        }
        else if(c==10)
        {
            cout<<a1+b1+1;
        }
        else cout<<a1+b1<<c;
    else
        cout<<c;

}

int main()
{
    int n,a,b;
    cin>>n;
    for(int i = 0; i< n; i++)
    {
        cin>>a>>b;
        add(a,b);
    }
    return 0;
}
