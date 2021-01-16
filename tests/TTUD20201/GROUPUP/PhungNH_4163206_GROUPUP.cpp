#include <bits/stdc++.h>
using namespace std;

int T;
int n;
vector<int> VECTOR;


void input() {
    ios_base::sync_with_stdio(0);
    cin >> T;
}

void solve() {
    for(int i = 0; i < n; i++) {
        int u;
        cin >> u;
        VECTOR.push_back(u);
    }

    int result = 0;
    while (VECTOR.size() > 1) {
        vector<int> VECTOR2;
        for(int i = 0; i < VECTOR.size(); i++)
            VECTOR2.push_back(VECTOR[i]);
        VECTOR.clear();
        int temp = 0;
        int i = 0;
        while (i < VECTOR2.size()) {
            if (i < (int)VECTOR2.size() - 1)
            {
                temp = max(temp, VECTOR2[i] + VECTOR2[i + 1]);
                VECTOR.push_back(VECTOR2[i] + VECTOR2[i + 1]);
            } else
            {
                VECTOR.push_back(VECTOR2[i]);
            }
            i += 2;
        }
        result += temp;
    }
    cout << result << endl;
}

int main()
{
    input();
    while (T--)
    {
        VECTOR.clear();
        cin >> n;
        solve();
    }
}