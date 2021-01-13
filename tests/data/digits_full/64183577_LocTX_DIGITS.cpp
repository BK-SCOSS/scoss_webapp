#include<bits/stdc++.h>
using namespace std;

int digits[7];
/*
    0: H, 
    1: U, 
    2: S, 
    3: T, 
    4: 0, 
    5: I, 
    6: C
*/

bool used[10];
int n;
int ans;

int calc() {
    int hust = digits[0]*1000 + digits[1]*100 + digits[2]*10 + digits[3];
    int soict = digits[2]*10000 + digits[4]*1000 + digits[5]*100 + digits[6]*10 + digits[3];

    return hust + soict;
}

bool qualify(int i, int k) {
    if(used[i])
        return false;
    
    if(k == 0 || k == 2) 
        return i != 0;

    return true;
}

void Try(int k) {
    for(int i = 0; i < 10; i++) {
        if(!qualify(i, k))
            continue;

        digits[k] = i;
        used[i] = true;

        if(k == 6) {
            if(calc() == n)
                ans++;
        } else {
            Try(k+1);
        }

        used[i] = false;
    }
}


void solve() {
    memset(used, 0, sizeof(used));
    memset(digits, 0, sizeof(digits));
    cin >> n;
    ans = 0;

    Try(0);

    cout << ans << endl;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}