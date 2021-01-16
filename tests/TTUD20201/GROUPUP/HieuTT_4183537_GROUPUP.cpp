#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int T;
    int n;
    int a [100001];
    long long int  dapan[15];
    cin >> T;
    for (int t=0; t<T; t++){
    long long int count = 0;

    cin >> n;
    for (int i = 0; i<n; i++) {
        cin>>    a[i];
    }
    while (n > 1){
        long long int count2 =0;
        for (int i =0; i<n; i = i+2){
            a[i/2]= a[i]+a[i+1];
        }

        if (n%2 == 1)
        {a[n/2] = a[n-1];
        n = n/2 +1;
        }
        else n = n/2;

        for (int i = 0; i<n; i++)
        {
            if (a[i] > count2) count2 = a[i];
        }
        count += count2;
    }
    dapan[t] = count;
    }
    for (int i=0; i<T; i++){
        cout << dapan[i]<<endl;
    }
}
