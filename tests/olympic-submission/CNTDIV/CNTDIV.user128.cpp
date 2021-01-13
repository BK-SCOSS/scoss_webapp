#include <iostream>

using namespace std;

int main()
{

    int Q, i, j, cnt;
    cin >> Q;
    long N[Q];
    for (i = 0; i < Q; i++) {
        cin >> N[i];
        N[i] = N[i] * (N[i] + 1) * (N[i] + 2);
    }
    for (i = 0; i < Q; i++) {
        cnt = 0;
        for (j = 2; j < N[i]; j++) {
            if (N[i]*N[i] % j == 0 && N[i] % j != 0) cnt++;
        }
        cout << cnt << endl;
    }

    return 0;
}
