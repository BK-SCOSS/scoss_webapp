#include <iostream>
#include <vector>

using namespace std;

int testcase;
int n[10];
int a[10][100001];
int res[10][100001];
int k;

int main()
{
    cin >> testcase;
    for(int i = 0; i < testcase; i++){
        cin >> n[i];
        for(int j = 0; j < n[i]; j++){
            cin >> a[i][j];
        }
    }
    for(int i = 0; i < testcase; i++){
        int ans = 0;
        for(int j = 0; j< n[i]; j++){
            res[i][j] = 1;
            k = j - 1;
            while(k>=0){
                if(a[i][k] == a[i][j] - 1){
                    res[i][j] += res[i][k];
                    break;
                }
                k--;
            }
            if(res[i][j] > ans) ans = res[i][j];
        }
        cout << ans << endl;
    }

    return 0;
}
