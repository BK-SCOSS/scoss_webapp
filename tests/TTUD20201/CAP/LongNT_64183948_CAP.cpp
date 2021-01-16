#include <iostream>

using namespace std;

int main()
{
    int T, n, m;
    cin >> T;
    int s[T];
    for (int i=0; i<T; i++){
        s[i] = 0;
        cin >> n;
        unsigned int a[n];
        for (int j=0; j<n; j++) cin >> a[j];
        cin >> m;
        unsigned int b[m];
        for (int j=0; j<m; j++) cin >> b[j];
        for (int j=0; j<n; j++)
            for (int k=0; k<m; k++)
                if (a[j] == b[k]) s[i] = s[i]+1;
    }
    for (int i=0; i<T; i++) cout << s[i] << endl;
}
