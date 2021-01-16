#include <bits/stdc++.h>
#define MAX 100000
using namespace std;
int t, n;
int a[MAX],s[MAX], res[MAX];

void test(int temp){
    s[0] = 1;
    int test = s[0];
    for(int i = 1; i < n; i++){
        s[i] = 1;
        for(int j = 0; j < i; j++){
            if(a[j] == a[i] - 1){
                if(s[i] < s[j] + 1){
                    s[i] = s[j] + 1;
                }
            }
        }
        if(s[i] > test){
            test = s[i];
        }
    }
    res[temp] = test;
}

int main(){
	cin >> t;
    for(int j = 0; j < t; j++){
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        test(j);
    }
    for(int i = 0; i < t; i++){
        cout << res[i] << endl;
    }
	return 0;
}
