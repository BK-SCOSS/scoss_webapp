#include <bits/stdc++.h>
using namespace std;

int n, *a, *mem;

int main(){
	int t;
	cin >> t;
	while(t > 0){
		int result = 0;
		cin >> n;
		a = new int[n];
		for(int i = 0; i < n; i++) scanf("%d", &a[i]);
		int temp = 0;
		while(n > 1){
			int temp = 0;
			for(int i = 0; i < n; i+=2) {
				if(i < n - 1) a[i/2] = a[i] + a[i+1];
				else if(i == n - 1) a[(n-1)/2] = a[n-1];
				temp = max(temp, a[i/2]);
				//cout << temp << endl;
			}
			result += temp;
			if(n%2 == 0) n = n/2;
			else n = n/2 + 1;
		}
		cout << result << endl;
		t--;
	}
}

