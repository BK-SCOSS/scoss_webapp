#include <bits/stdc++.h>
using namespace std;

int main(){
	int T, n, m;
	int a[105], b[105];
	int stt = 0;
	
	cin >> T;
	for (int d=1;d<=T;d++){
		int cnt = 0;
		
		
		cin >> n;
		for (int i=1;i<=n;i++)
			cin >> a[i];
		a[0] = -1;
		for (int i=n;i>1;i--)
			for (int j=1;j<i;j++){
				if(a[j]>a[i]){
					int temp = a[i];
					a[i] = a[j];
					a[j] = temp;
				}
			}
		
		cin >> m;
		for (int i=1;i<=m;i++)
			cin >> b[i];
		for (int i=m;i>1;i--)
			for (int j=1;j<i;j++){
				if(b[j]>b[i]){
					int temp = b[i];
					b[i] = b[j];
					b[j] = temp;
				}
			}
		
		for (int i=1;i<=n;i++){
			if (a[i]>a[i-1]){
				for (int j=1;j<=m;j++){
					if (a[i]==b[j]) 
						cnt++;
				}
			}
		}
		
		printf("%d\n",cnt);
	}
}
