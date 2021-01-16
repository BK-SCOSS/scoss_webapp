#include <iostream>

using namespace std;
const int NMAX = 1e5;
int t;
void CAP(){
    int res=0;
    int n;
    int a[NMAX];
    int m;
    int b[NMAX];
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    cin >> m;
    for(int i=1; i<=m; i++){
        cin >> b[i];
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(a[i]==b[j]){
                res++;
                break;

            }
        }
    }
    cout << res;
}

int main()
{ cin >> t;
for(int k=1; k<=t; k++){
    CAP();
}

    return 0;
}
