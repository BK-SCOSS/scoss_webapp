#include<iostream>
#include <iomanip>
using namespace std;
int main()
{
 	long long  T;
 	cin>>T;
 	for (int i = 0 ; i < T ; i++) {
        long double a, b;
        cin >> a >> b;
        cout <<setprecision(0)<<fixed<< a+b << "\n";
 	}
}
