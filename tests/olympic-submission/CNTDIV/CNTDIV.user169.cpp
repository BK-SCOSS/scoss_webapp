#include <iostream>
using namespace std;

int main()
{
    unsigned long long Q;
    unsigned long long N;
    unsigned long long count=0;
    unsigned long long T,T2;
    cin>>Q;
    for(int j= 1;j<=Q;j++)
    {
        cin>>N;
        count=0;
        T = N*(N+1)*(N+2);
        T2= T*T;
        for(int i= 2;i<= T;i++)
        {
            if(T2%i == 0 && T%i != 0)
                {
                    count++;
                }
        }
        cout<<count<<"\n";
    }
	return 0;
}
