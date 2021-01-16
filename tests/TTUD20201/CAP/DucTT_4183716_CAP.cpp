#include <bits/stdc++.h>

using namespace std;

int n1, n2;
set<long long>a,b;
set<long long>::iterator it;
int ans[12];
int cnt = 0;

void input(){
    cin >> n1;
    for(int i = 0; i < n1; i++){
        int u;
        cin >> u;
        a.insert(u);
    }
    cin >> n2;
    for(int i = 0; i < n2; i++){
        int u;
        cin >> u;
        b.insert(u);
    }
}


int main()
{
    int T;
    cin >> T;
    for(int i = 1; i <= T; i++){
        input();
        for(it = a.begin(); it != a.end(); it++){
            if(b.find(*it)!= b.end()) cnt++;
        }
        ans[i] = cnt;
        cnt = 0;
    }
    for(int i = 1; i <= T; i++) cout << ans[i] << endl;
    return 0;
}
