#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
	int T;
	cin>>T;
	for(int x=0; x<T; x++){
	int n,m;
	cin>>n;
	vector<int> setdata1(n);
	for(int i=0; i<n; i++) cin>>setdata1[i];
	sort(setdata1.begin(),setdata1.end());
	for(int i=0; i<n; i++) {
		if(setdata1[i] == setdata1[i+1]) setdata1[i] == 0;
	}
	
	cin>>m;
	vector<int> setdata2(m);
	for(int i=0; i<m; i++) cin>>setdata2[i];
	sort(setdata2.begin(), setdata2.end());
	for(int i=0; i<m; i++){
		if(setdata2[i] == setdata2[i+1]) setdata2[i] == 0;
	}
	
	
	
	int count=0;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(setdata1[i] == setdata2[j]&&setdata1[i]!=0&&setdata2[j]!=0) count++;
		}
	}
	cout<<count;
	}
	
	return 0;
}
