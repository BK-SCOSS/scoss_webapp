#include <bits/stdc++.h>
using namespace std;


bool check(int ii, int j){
    // i co 4 chu so
    // j co 5 chu so
    int h = (ii/1000)%10, u = (ii/100)%10, s = (ii/10)%10, t = ii % 10;

    int s2 = (j/10000)%10, o = (j/1000)%10, i = (j/100)%10, c = (j/10)%10, t2 = j % 10;

    std::set<int> test;

    test.insert(h);
    test.insert(u);
    test.insert(s);
    test.insert(t);
    test.insert(o);
    test.insert(i);
    test.insert(c);

    if(s == s2 && t == t2 && test.size() == 7){
        return true;
    }
    return false;
}
void process(int x){
    int dem = 0, j;
    for(int i = 1023; i <= 9876; i ++ ) {
        j = x - i;
        if(j <= 10234) break;
        if(check(i, j)) dem += 1 ;
    }

    cout << dem << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T, i;
    cin >> T;
    int a[T];
    for(i = 0; i <T; i++){
        cin >> a[i];
        if(a[i] >= 9999 + 99999 || a[i] < 10234 || a[i] % 2 != 0)
            cout << 0 << endl;
        else {
            process(a[i]);
        }
    }
    return 0;
} 