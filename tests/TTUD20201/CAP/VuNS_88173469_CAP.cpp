#include<bits/stdc++.h>

using namespace std;
int n, m, T;
unsigned long long a[1000], b[1000];

int main(int argc, char const *argv[]){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int count = 0;
    cin >> T;
	for(int i = 0; i < T; i++){
		cin >> n;
		for( int j = 0;j < n; j++){
			cin >> a[j];
		}
		cin >> m;
		for (int k = 0; k < m;k++){
			cin >> b[k];
			for(int x = 0; x < n; x++){
				if (a[x] == b[k]){
					count++;
					break;
				}
			}
		}
			
	}
	cout << count;
    return 0;
}
