#include <bits/stdc++.h>
using namespace std;

int main(){
	int T, n;
	int a[100005];
	int dem[10005];
	
	cin >> T;
	for (int i=1;i<=T;i++){
		cin >> n;
		int max = 0;
		for (int j=1;j<=n;j++)
			cin >> a[j];
		for (int j=0;j<=10000;j++)
			dem[j]=0;
		for (int j=1;j<=n;j++){
			if (dem[a[j]-1]>0)
				dem[a[j]] = dem[a[j]-1] + 1;
			else 
				dem[a[j]] = 1;
		}
		for (int j=1;j<=10000;j++){
			if (max<dem[j]) 
				max = dem[j];
		}
		printf("%d\n",max);
	}
}
