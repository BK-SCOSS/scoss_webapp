#include <bits/stdc++.h>

using namespace std;

int a[100000];

int k=0;

int main(){
    int T;
    cin >> T;
    int ans = 0;
    while(T--){
        int n;
        cin >> n;
        for(int i = 0; i<n ; i++){
            cin >> a[i];
        }
        
        while(pow(2,k)<n){
	        int j;
	        for(j=0; j<n/2;j++){
	        	a[j] = a[2*j]+a[2*j+1];
			}
			for(j=n/2;j<n;j++){
				a[j] = 0;
			}
			int	max = a[0];
			for(j=0; j<n; j++){
					if(max < a[j])
						max = a[j];
				}
			ans += max;
            k++;
        }
        cout << ans;
    }	
}




