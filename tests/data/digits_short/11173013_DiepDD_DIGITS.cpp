#include <iostream>

using namespace std;

int digit[7];
//digit[0] is H
//digit[1] is U
//digit[2] is S
//digit[3] is T
//digit[4] is O
//digit[5] is I
//digit[6] is C
int t, n, cnt;
bool visited[10] = {false};

bool check(int v, int k) {
    if (visited[v]) return false;
    if ( v==0 && (k==0 || k==2) ) return false;
    return true;
}

void TRY(int k) {
    for (int v = 0; v <= 9; ++v) {
        if ( check(v, k) ) {
            digit[k] = v;
            visited[v] = true;
            if (k == 6) {
                int sum = digit[2]*10000 + (digit[0]+digit[4])*1000 + (digit[1]+digit[5])*100 + (digit[2]+digit[6])*10 + digit[3]*2;
                if (sum == n) {
                    cnt++;
                }
            } else {
                TRY(k+1);
            }
            visited[v] = false;
        }
    }
}

int main()
{
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cin >> n;
        cnt = 0;
        TRY(0);
        cout << cnt << endl;
    }

    return 0;
}
