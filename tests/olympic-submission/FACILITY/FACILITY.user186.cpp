#include <bits/stdc++.h>

#define MAX_INT 2e9
#define maxl 1000007
#define ln length()
#define ff(i,a,b) for(int i = a; i <= b; i++)
#define fb(i,a,b) for(int i = a; i >= b; i--)
typedef long long ll;
using namespace std;

int n, k, summ = 0, maxsum = 0, curr;
int s[maxl], d[maxl], r[maxl];
bool used[maxl];

void TRY(int p) {
    // cout << "Get into " << p << endl;
    used[p] = 1;
    summ += r[p];
    int temp = curr;
    curr = s[p] + d[p] + k;
    // cout << "Curr = " << curr << endl;
    bool canvisit = 0;
    for (int i = 1; i <= n; i++) {
        // cout << "Try " << i << endl;
        // cout << used[i] << " and " << s[]
        if (!used[i] && s[i] >= curr) {
            canvisit = 1;
            TRY(i);
        }
    }
    if (!canvisit) {
        // cout << "Nah, cant visit more" << endl;
        maxsum = max(summ, maxsum);
    }
    used[p] = 0;
    summ -= r[p];
    curr = temp;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> s[i] >> d[i] >> r[i];
    }
    for (int i = 1; i <= n; i++) {
        TRY(i);
    }
    // TRY(5);
    cout << maxsum;
}
