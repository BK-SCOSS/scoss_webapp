#include <iostream>
using namespace std;

int t, n, m;
int a[101];
int b[101];

int main()
{
    cin >> t;
    while(t--){
        cin >> n;
        // cout << n;
        for(int i=1; i<=n; i++){
            cin >> a[i];
            // cout << a[i];
        }
        cin >> m;
        for(int i=1; i<=m; i++){
            cin >> b[i];
        }
        int num = 0;
        for(int i=1; i<=n; i++){
            bool check = false;
            for(int j=1; j<= m; j++){
                if (b[j] == a[i]){
                    check = true;
                    break;
                }
            }
            if(check){
                num +=1;
            }
        }
        cout << num;
    }
    return(0);
}