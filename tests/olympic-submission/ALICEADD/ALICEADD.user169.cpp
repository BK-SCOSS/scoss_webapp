#include <iostream>
using namespace std;

int main()
{
    unsigned long long a,a1,a0,b,b1,b0,c1,c0;
    int T;
    cin>>T;
    for(int i = 1; i<=T; i++){
        cin >> a>>b;
        a0 = a%10;
        a1 = a/10;
        b0 = b%10;
        b1 = b/10;
        c1 = (a0+b0)/10;
        c0 = (a0+b0)%10;
        if((a1+b1+c1) == 0) cout<< c0;
        else cout << a1+b1+c1<<c0<<"\n";
    }
	return 0;
}
