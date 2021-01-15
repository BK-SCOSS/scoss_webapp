#include <bits/stdc++.h>
using namespace std;
int const maxx = 100002;
int n;
unsigned int k;
unsigned int s[maxx];
unsigned int r[maxx];
unsigned int d[maxx];
int vs[maxx];
unsigned int rs;
unsigned int tmp;
unsigned int timee;
void try1(int i) {
    for (int j = 0; j < n; j++) {
        if(vs[j]!=1 && timee <= s[j]) {
            unsigned tempp = timee;
            timee = s[j] + d[j] + k;
            tmp += r[j];
            if(tmp >rs) rs =tmp;
            try1(j);
            timee = tempp;
            tmp -= r[j];

        }
    }
}
int main() {
    cin >>n>>k;
    for (int i =0; i<n;i++){
        cin >> s[i] >>d[i] >>r[i];
    }
    for(int i =0;i<n;i++){
        unsigned tempp = timee;
        timee += (s[i]+d[i]+k);
        tmp+=r[i];
        if(tmp>rs) rs = tmp;
        try1(i);
        timee = tempp;
        tmp -=r[i];


    }
    cout << rs;
    return 0;
}
