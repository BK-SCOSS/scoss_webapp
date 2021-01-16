#include <bits/stdc++.h>
using namespace std;

int main(){
	int T, n;
	int a[100005];
	
	cin >> T;
	for (int d=1;d<=T;d++){
		int time = 0;
		
		cin >> n;
		for (int i=1;i<=n;i++){
			cin >> a[i];
		}
		
		int spt = n;
		int max = 0;
		while (spt != 1){
			if (spt % 2 ==0){
				for (int i = 1; i <= spt/2; i++){
					a[i] = a[2*i - 1] + a[2*i];
					if (max < a[i]) max = a[i];
				}
				spt = spt/2;
			} else {
				for (int i = 1;i <= spt/2; i++){
					a[i] = a[2*i - 1] + a[2*i];
					if (max < a[i]) max = a[i];
				}
				a[spt/2 + 1] = a[spt];
				if (max < a[spt/2+1]) 
					max = a[spt/2+1];
				spt = spt/2 +1;
			}
			
			time += max;
		}
		printf("%d\n",time);
	}
}
