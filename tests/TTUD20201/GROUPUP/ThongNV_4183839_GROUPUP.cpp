#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t,n;
	cin>>t;
	while(t--){
		cin>>n;
		int x;
		queue<int> s;
		int res=0;
		for(int i=1;i<=n;i++){
			cin>>x;
			s.push(x);
		}
		while(n>1){
			if(n%2==0){
				int max1=0;
				for(int i=1;i<=n/2;i++){
					int u=s.front();
					s.pop();
					int v=s.front();
					s.pop();
					max1=max(max1, (u+v));
					s.push(u+v);
				}
				n=n/2;
				res+=max1;
			}else{
				int max1=0;
				for(int i=1;i<=n/2;i++){
					int u=s.front();
					s.pop();
					int v=s.front();
					s.pop();
					max1=max(max1, (u+v));
					s.push(u+v);
				}
				int k=s.front();
				s.pop();
				s.push(k);
				n=n/2+1;
				res+=max1;
			}
		}
		cout<<res;		
	}


	return 0;
}

