#include <iostream>
#define endl '\n'
#define ll unsigned long long
using namespace std;
const long long Base = 1e18;
int main()
{
    //ios_base::sync_with_stdio(false);cin.tie(0);
    int T;
    cin >> T;
    ll a, b;
    for(int x = 0 ; x < T ; ++x){
        cin >> a >> b;
        if(a > Base && b > Base){

            ll c , d , tmp;
            c = a / Base;
            d = b / Base;
            a %= Base;
            b %= Base;
            tmp = (a + b) / Base;
            printf("%llu%018llu\n",c+d+tmp,(a+b)%Base);
            //cout << (c + d + tmp) << (a + b) / Base << endl;
        }
        else printf("%llu\n",a + b);
    }

    return 0;
}
//9999999999999999999
