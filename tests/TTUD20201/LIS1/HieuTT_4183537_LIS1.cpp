#include <iostream>

using namespace std;

int main()
{
    int T,n;
        long long int a[100001];
    int dapan[15];
    int mark [100001];
    cin >> T;
    for (int i=0; i<T; i++){
        cin >> n;
        for (int j=0; j<n; j++ ){
            cin >> a[j];
            mark[j] =0;
        }

        int count = 0;
        for (int j = 0; j<n; j++)
        if (mark[j] == 0)
            {
            mark[j] = 1;
            int dem = 1;
            for (int k =j+1; k<n; k++)
            if (a[k] == a[j] + dem ) {
                dem ++;
                mark[k] = 1;
            }
            count = max(count, dem );
        }

        dapan[i] = count;

    }

    for (int i=0; i<T; i++){
            cout << dapan[i] << endl;
    }
    return 0;
}
