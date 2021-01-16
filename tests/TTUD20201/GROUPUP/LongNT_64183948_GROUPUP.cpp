#include <bits/stdc++.h>

using namespace std;
int T;
vector<int> b;

int main(){
    int T;
    cin >> T;
    int s[T];
    for (int i=0; i<T; i++){
        s[i] = 0;
        int n;
        cin >> n;
        int a[n];
        for (int j=0; j<n; j++){
            cin >> a[j];
            b.push_back(a[j]);
        }
        while (b.size() != 1){
            int maxi = 0;
            for (int j=0; j<(b.size()/2)*2; j=j+2){
                b[j] = b[j]+b[j+1];
                b[j+1] = 0;
                if(b[j]>maxi) maxi = b[j];
            }
            s[i] = s[i]+maxi;
            for (vector<int>::iterator it = b.begin(); it != b.end(); it++)
                if (*it == 0){
                b.erase(it);
                it--;
                }
        }
        b.clear();
    }
    for (int i=0; i<T; i++) cout << s[i] <<endl;

}

