#include <iostream>
#include <queue>

using namespace std;

int testcase;
int n[10];
queue<int> a[10];
int x, y;

int main()
{
    cin >> testcase;
    for(int i = 0; i < testcase; i++){
        cin >> n[i];
        for(int j = 0; j < n[i]; j++){
            cin >> x;
            a[i].push(x);
        }
    }
    for( int i = 0; i < testcase; i++){
        int length = n[i];
        int ans = 0, b = 0;
        while(length > 1){
            b = 0;
            if(length % 2) a[i].push(0);
            for(int j = 0; j < length; j+=2){
                x = a[i].front();
                a[i].pop();
                y = a[i].front();
                a[i].pop();
                a[i].push(x+y);
                if(x+y> b) b = x+y;
            }
            length = (length+1)/2;
            ans += b;
        }
        cout << ans << endl;
    }
    return 0;
}
