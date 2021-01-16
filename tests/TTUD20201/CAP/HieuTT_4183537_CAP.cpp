#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    long long int a[200];
    long long int b[200];
    int ketqua[20];
    int T,n,m;
    cin >> T;
    for (int i=0; i<T; i++){
        cin >> n;
        for (int j=0; j<n; j++) cin >> a[j];
        cin >> m;
        for (int j=0; j<m; j++) cin >> b[j];

        int count =0;
        sort (a,a+n);
        sort (b,b+m);
        int  tmp = 0;
        for (int j =0; j<n; j++)
        for (int k =0; k<m; k++){
        if (a[j] == b[k] && a[j] > tmp && b[k] >tmp ) {
                count++;
                tmp = a[j];
        }
        ketqua[i] = count;
        }
    }

    for (int i=0; i<T; i++){
            cout <<ketqua[i] <<endl;
    }

}
