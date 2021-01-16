#include <bits/stdc++.h>

#define MAX 1001
#define CHECK 1000000000

using namespace std;



int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T;
    cin >> T;
    while(T--){
        int cnt=0;
        unsigned long long A[MAX], B[MAX];
        int n,m;
        cin >> n;
        map<unsigned long long,int> check;
        for(int i =0;i != n;i++){
            unsigned long long u;
            cin >> u;
            A[i] = u;
            check.insert(make_pair(u,1));

        }
        cin >> m;
        for(int i=0;i != m; i++){
            cin >> B[i];
            if(check.find(B[i])->second == 1){
                cnt++;
            }
        }
        cout << cnt << endl;

    }
    return 0;
}
