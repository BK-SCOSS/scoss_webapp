#include <iostream>
#include <vector>

using namespace std;

int testcase;
int n[10];
int m[10];
long long int a[10][100];
long long int b[10][100];
vector<int> check[10];

int main()
{
    int ans;
    cin >> testcase;
    for(int i = 0; i< testcase; i++){
        cin >> n[i];
        for(int j = 0; j < n[i]; j++){
            cin >> a[i][j];
        }
        cin >> m[i];
        for(int j = 0; j < m[i]; j++){
            cin >> b[i][j];
        }
    }
    for(int i = 0; i < testcase; i++){
        ans = 0;
        for(int j = 0; j< n[i]; j++){
            bool visited = false;
            for(int k : check[i]){
                if(a[i][j] == k){
                    visited = true;
                    break;
                }
            }
            if(!visited){
            for(int k = 0; k < m[i]; k++){
                if(a[i][j] == b[i][k]){
                    ans ++;
                    break;
                }
            }
            }
            check[i].push_back(a[i][j]);
        }
        cout << ans << endl;
    }
    return 0;
}
