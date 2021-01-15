#include<iostream>
#include<set>
#include<vector>
#include<cmath>

using namespace std;

set<int> uocso(int n){
    set<int> dsuocso;
    for (int i = 1; i <= n; i++){
        if (n % i == 0){
            dsuocso.insert(i);
        }
    }
    return dsuocso;
}

int uocsot2(int n){
    int t = n*(n+1)*(n+2);
    set<int> dsuocsot = uocso(t);
    int count = 0;
    set<int> a = uocso(t*t);
    set<int>::iterator it = a.begin();
    while(it != a.end()){
        int i = *it;
        if (i >= t){
            break;
        }
        if(dsuocsot.find(i) == dsuocsot.end()){
            count++;
        }
        it++;
    }
    return count;
}

int main(){
    int n; cin >> n;
    int a;
    for (int i = 0; i< n; i++){
        cin >> a;
        cout << uocsot2(a) << endl;
    }
    return 0;

}