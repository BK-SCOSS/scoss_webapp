#include <bits/stdc++.h>
using namespace std;

int n;
int m;
int t;

int temp;



void input(){
    cin  >> t;
    for (int i = 0; i < t; i++){
        cin  >> n;

        unordered_map<int,int> mem;
        int max = 0;
        for (int j = 0; j < n; j ++){
            cin >> temp;
            mem[temp] = mem[temp-1] + 1;
            if (mem[temp]> max){
                max = mem[temp];
            }
            mem.erase(temp-1);
        }
        cout << max << endl;

    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    input();
}
