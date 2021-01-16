#include <iostream>

using namespace std;

const int TMAX = 11, NMAX = 1e5;
int T;
int a[TMAX][NMAX];
int n[TMAX];
int res[TMAX];
int lasts[TMAX];

void input(){
    cin >> T;
    for(int t=0; t<T; t++){
        cin >> n[t];
        for(int i=1; i<=n[t]; i++){
            cin >> a[t][i];
        }
    }
}

void Try(int start, int t){
    if(start > n[t]){
        return;
    }
    for(int j=start+1; j<=n[t]; j++){
        if(a[t][j] - a[t][start] == 1){
            lasts[t] = a[t][j];
            Try(j, t);
            break;
        }
    }
}

int main()
{
    input();
    for(int t=0; t<T; t++){
        for(int i=1; i<=n[t]; i++){
            lasts[t] = a[t][i];
            Try(i, t);
            res[t] = (res[t] > (lasts[t] - a[t][i]+1))?res[t]:(lasts[t] - a[t][i]+1);
        }
    }
    for(int t=0; t<T; t++){
        cout << res[t] << endl;
    }
    return 0;
}
