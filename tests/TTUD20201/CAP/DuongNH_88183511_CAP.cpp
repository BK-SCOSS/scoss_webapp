#include <bits/stdc++.h>
using namespace std;
#define ll long long

// ll n,m;
// ll testcase;
int testcase;
int n, m;

// short int sttA[1000000001];
// short int sttB[1000000001];

ll A[200], B[200];
map<ll,short int> MapA,MapB;


void create_map(){
    for(int i = 1; i <= n; i++){
        ll querry = A[i];
        auto search = MapA.find(querry);
        if (search == MapA.end()){
            MapA.insert({A[i],1});
        }
    }
    for(int i = 1; i <= m; i++){
        ll querry = B[i];
        auto search = MapB.find(querry);
        if (search == MapB.end()){
            MapB.insert({B[i],1});
        }
    }
}

int main(){
    cin >> testcase;
    
    while(testcase--){
        MapA.clear();
        MapB.clear();
        // memset(sttA,0, sizeof(sttA));
        // memset(sttB,0,sizeof(sttB));
        
        cin >> n;
        for(ll i = 1; i <= n; i++){
            cin >> A[i];
        }
        cin >> m;
        for(ll i = 1; i <= m; i++){
            cin >> B[i];
        }
        create_map();
        ll count = 0;
        ll min = *min_element(A + 1,A + n + 1);
        ll max = *max_element(A + 1, A + n + 1);
        for(int value = min; value <= max; value++){
            int querry = value;
            auto searchA = MapA.find(querry);
            auto searchB = MapB.find(querry);
            if (searchA != MapA.end()){
                if (searchB != MapB.end()){ count++;
                }
            }
        }

        cout << count << endl;
    }
    return 0;
    
}