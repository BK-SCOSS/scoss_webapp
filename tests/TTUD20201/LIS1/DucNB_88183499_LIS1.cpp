#include<bits/stdc++.h>

using namespace std;

int main(){
	int T,n;
	cin>>T;
	while(T--){
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		int maxcount=1;
		
		int mangtang[100005][1];
		int count[n];
		int soday =1;
		mangtang[0][0]=a[0];
		for(int i=0;i<n;i++){
			count[i]=0;
		}
		count[0]=1;
		for(int i=1;i<n;i++){
			for(int j=0;j<soday;j++){
				if(mangtang[j][0]+1==a[i]){
					mangtang[j][0]=a[i];
					count[j]++;
					break;
				}
				if(j==soday-1){
					count[soday]=1;
					mangtang[soday][0]=a[i];
					soday++;
					break;
				}
			}
		}
		for(int i=0;i<soday;i++){
			if(count[i]>maxcount) maxcount=count[i];
		}
		cout<<maxcount<<endl;
	}
}
