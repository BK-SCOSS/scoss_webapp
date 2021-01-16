#include <iostream>

using namespace std;

const int NMAX = 101, MMAX = 101, TMAX = 11;
int a[TMAX][NMAX], b[TMAX][MMAX];
int n[TMAX],m[TMAX];
int T;
int res[TMAX][NMAX];
int counts[TMAX];

void input(){
    cin >> T;
    for(int t=0; t<T; t++){
        cin >> n[t];
        for(int i=1; i<=n[t]; i++){
            cin >> a[t][i];
        }
        cin >> m[t];
        for(int j=1; j<=m[t]; j++){
            cin >> b[t][j];
        }
    }
}

void Try(int t){
    int count = 0;
    for(int i=1; i<=n[t]; i++){
        for(int j=1; j<=m[t]; j++){
            if(a[t][i] == b[t][j]){
                bool found = false;
                for(int r=0; r<count; r++){
                    if(res[t][r] == a[t][i]){
                        found = true;
                    }
                }
                if(!found){
                    res[t][count] = a[t][i];
                    count++;
                    break;
                }
            }
        }
    }
    counts[t] = count;
}

int main()
{
    input();
    for(int t=0; t<T; t++){
        Try(t);
    }
    for(int i=0; i<T; i++){
        cout << counts[i] << endl;
    }
    return 0;
}
