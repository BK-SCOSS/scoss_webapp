#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
	cin.tie(0);

	int soTest;
	cin >> soTest;
	while(soTest > 0){
        int n;
        cin >> n;
        queue<int> group;
        int res = 0;
        for(int i = 0; i < n; i++){
            int temp;
            cin >> temp;
            group.push(temp);
        }
        while(group.size() > 1){
            int l = group.size();
            int time = 0;
            for(int i = 0; i < l/2; i++){
                int a = group.front();
                group.pop();
                int b = group.front();
                group.pop();
                time = max(time,a + b);
                group.push(a + b);
            }
            if( l %2 == 1){
                int a = group.front();
                group.pop();
                group.push(a);
            }
            res += time;
        }
        cout << res << endl;

        soTest --;
	}


}
