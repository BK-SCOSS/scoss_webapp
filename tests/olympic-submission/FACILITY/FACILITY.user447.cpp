#include<bits/stdc++.h>
using namespace std;
const int N = 1000001;

unsigned int n;
unsigned long K;
unsigned long c[N][3];
unsigned long x[N];
unsigned long long fk, fopt;

vector<pair<unsigned long,unsigned int>> vect;

bool check(int y, int k) {
    //if ( c[vect[y].second][0]  <  (c[x[k-1]][0] + c[x[k-1]][1] + K) ) return false;
    for (int j = 2; j < k; j++) {
        if (x[j] == vect[y].second) return false;
    }
    return true;
}

void TRY (int k) {
    for(int y = 0; y < n; y++) {
        if (y == n - 1) {
            fopt = (fk > fopt) ? fk : fopt;
        }

        if ( c[vect[y].second][0]  <  (c[x[k-1]][0] + c[x[k-1]][1] + K) ) continue;
        if (check(y, k)) {
            x[k] = vect[y].second;
            fk += c[x[k]][2];
            TRY(k+1);
            fk -= c[x[k]][2];
        }
    }
}

int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> K;
    for(int i = 0; i < n; i++) {
        cin>> c[i][0] >> c[i][1] >> c[i][2];
    }

    for(int i = 0; i < n; i++) {
        vect.push_back(make_pair(c[i][0], i));
    }
    sort(vect.begin(), vect.end(), less<pair<unsigned long,unsigned int>>());
    /*for(int i = 0; i < n; i++) {
        cout<<vect[i].second<<endl;
    }*/
    fopt = 0;
    for(int i = 0; i < n; i++) {
        fk = 0;
        x[1] = vect[i].second;
        fk += c[x[1]][2];
        TRY(2);
    }
    cout<<fopt;
    return 0;
}

