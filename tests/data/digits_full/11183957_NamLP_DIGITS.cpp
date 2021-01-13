#include <bits/stdc++.h>

using namespace std;
int x[8];
int value;
int visited[10], n;
int cnt = 0;

void reset(){
    for(int i = 0; i < 10; i++)
        visited[i] = 0;
    cnt = 0;
    value = 0;
}

bool check(int i, int v){
    if((i == 1 || i == 3) && v == 0) return false;
    if(visited[v]) return false;
    return true;
}

void TRY(int i){
    for(int v = 0; v <= 9; v++){
        if(check(i ,v)){
            x[i] = v;
            visited[v] = 1;
            if(i == 1) value += x[1]*1000;
            else if(i == 2) value += x[2]*100;
            else if(i == 3) value += x[3]*10010;
            else if(i == 4) value += x[4]*2;
            else if(i == 5) value += x[5]*1000;
            else if(i == 6) value += x[6]*100;
            else value += x[7]*10;

            if(i == 7){
                if(value == n) cnt +=1;
            }

            else TRY(i+1);

            visited[v] = 0;
            if(i == 1) value -= x[1]*1000;
            else if(i == 2) value -= x[2]*100;
            else if(i == 3) value -= x[3]*10010;
            else if(i == 4) value -= x[4]*2;
            else if(i == 5) value -= x[5]*1000;
            else if(i == 6) value -= x[6]*100;
            else value -= x[7]*10;
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        reset();
        TRY(1);
        cout << cnt << endl;
    }
    return 0;
}
