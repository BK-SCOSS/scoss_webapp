#include <iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
    unsigned long long a[n], b[n];
    for(int i=0; i<n; i++) {
        cin>>a[i]>>b[i];
    }
    unsigned long long sum = 0;
    for(int i=0; i<n; i++) {
        sum += a[i];
        sum += b[i];
        cout<<sum<<endl;
    }
    return 0;
}
