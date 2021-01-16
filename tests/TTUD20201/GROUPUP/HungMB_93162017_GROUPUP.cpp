#include<bits/stdc++.h>
using namespace std;

vector<int> a;
int n, T;
int rs[100];

int main(){
	cin >> T;
	int t0=T;
	while(T>0){
		T--;
		cin >> n;
		for(int i=1;i<=n;i++){
			int temp1;
			cin>> temp1;
			a.push_back(temp1);
		}
		int time=0;
		while(a.size()>1){
			vector<int> temp;
			int best=0;
			for(int i=0;i<(a.size()/2);i++){
				temp.push_back(a[2*i]+a[2*i+1]);
				best= max(best,(a[2*i]+a[2*i+1]));
			}
//			cout<<best<<endl;
			time+=best;
			if(a.size()%2) temp.push_back(a[a.size()-1]);
			a.clear();
			for(int i=0;i<temp.size();i++){
				a.push_back(temp[i]);
			}
//			for(int i=0;i<a.size();i++){
//				cout<<a[i]<<" ";
//			}
//			cout<<endl;
		}
		rs[T]= time;
	}
	for(int i=t0;i>0;i--){
		cout<<rs[T]<<endl;
	}
}
