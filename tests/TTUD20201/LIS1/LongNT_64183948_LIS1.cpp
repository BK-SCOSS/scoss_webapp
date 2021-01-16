#include <bits/stdc++.h>

using namespace std;

unsigned int T;
//stack<int> s[11];


int main()
{
    cin >> T;
    int m[T];//m[i] la ket qua cua testcase thu i
    for (int i=0; i<T; i++) m[i]=0;
    for (int i=0; i<T; i++){
        int n;
        cin >> n;
        int a[n];
        for (int j=0; j<n; j++) cin >> a[j];
        for (int j=0; j<n; j++) {
            stack<int> s;
            int q;
            q = j;
            s.push(a[q]);
            for (int k=q+1; k<n; k++)
                if (a[k] == a[q]+1)
                {
                    s.push(a[k]);
                    q = k;
                }
            if (s.size() > m[i]) m[i] = s.size();
        }

    }
    for (int i=0; i<T; i++) cout << m[i] << endl;
}
