#include <iostream>

using namespace std;
long long a[100001];
int n;
int mem[100001];

void init(){
    for (int i = 0; i < 100001; i++) {
        mem[i] = -1;
    }
}

int lis(int i) {
    if (mem[i] != -1){
        return mem[i];
    }
    int res = 1;
    for (int j = 0; j < i; j++){
        if ((a[j] + 1) == a[i]){
            res = max(res, 1 + lis(j));
        }
    }
    mem[i] = res;
    return res;
}

int main(){
    int result[11];
    int T;
    cin >> T;
    for (int k = 0; k < T; k++) {
        init();
        cin >> n;
        for(int i = 0; i < n; i++) cin >> a[i];
        int res = 1, pos = 0;
        for(int i = 1; i < n; i++){
            if (res < lis(i)){
                res = lis(i);
                pos = i;
            }
        }
        result[k] = res;
    }
    for (int i = 0; i < T; i++) {
        cout << result[i] << endl;
    }
    return 0;
}

