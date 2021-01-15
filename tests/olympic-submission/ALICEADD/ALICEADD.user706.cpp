#include <bits/stdc++.h>

using namespace std;
int main()
{ int n;
cin >> n;
unsigned long long a[n];
unsigned long long b[n];
for (int i=0;i<n;i++) {
    cin >> a[i] >> b[i];}
    for (int i=0;i<n;i++) cout << a[i]+b[i] << endl;
return 0;
}
