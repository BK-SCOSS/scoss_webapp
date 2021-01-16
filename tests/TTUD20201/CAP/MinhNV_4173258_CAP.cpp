#include <bits/stdc++.h>
#define MAX 100

using namespace std;
int t, n, m;
int a[MAX], b[MAX], res[MAX], mark[MAX];

void test(int temp){
    res[temp] = 0;
    int tem = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(a[i] == b[j]){
				for(int k = 0; k <= temp; k++){
                    if(a[i] == mark[k]){
                        break;
                    }
                    else{
                        mark[tem] = a[i];
                        tem++;
                        res[temp]++;
                    }
				}
				break;
			}
		}
	}
}

int main(){
	cin >> t;

	for(int i = 0; i < t; i++){
		cin >> n;
		for(int j = 0; j < n; j++){
			cin >> a[j];
		}
		cin >> m;
		for(int k = 0; k < m; k++){
			cin >> b[k];
		}
		test(i);
	}
	for(int i = 0; i < t; i++){
		cout << res[i] << endl;
	}
	return 0;
}
