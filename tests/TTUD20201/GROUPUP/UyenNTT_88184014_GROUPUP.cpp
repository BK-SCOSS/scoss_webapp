#include <iostream>

using namespace std;

const int MAX = 100000;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    int a[MAX];
    int time, maxx;
    int t;
    cin >> t;
    while(t--) {
        time = 0;
        cin >> n;
        for(int i = 0; i<n; i++) cin >>a[i];
        a[n] = 0;
        while(a[1]!= 0) {
        a[0] = a[0] + a[1];
        maxx = a[0];
        a[1] = 0;
        for(int i = 2; i<n; i+=2) {
            a[i/2] = a[i] + a[i+1];
            a[i] = 0;
            a[i+1] = 0;
            maxx = max(maxx, a[i/2]);
        }
        time += maxx;
        if(n%2 == 0) n = n/2;
        else n = n/2 + 1;
        }
        cout << time << endl;
    }
}
