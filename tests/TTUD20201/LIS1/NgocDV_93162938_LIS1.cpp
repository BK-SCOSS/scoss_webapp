#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


int main(){
	int T;
	cin>>T;
	for(int x=0; x<T; x++){
	int n;
	cin>>n;
	vector<int> setdata(n);
	for(int i=0; i<n;i++) cin>>setdata[i];
	//sort(setdata.begin(), setdata.end());
	int maxtest=0;
	for(int i=0; i<n; i++){
		int count=1;
		for(int j=1; j<n; j++){
			
			if(setdata[i] + 1 == setdata[j] ){
				i=j;
				count++;	
			}
			
		}
		maxtest=max(maxtest, count);
	}
	cout<<maxtest;	
		
	
	}
	
		
	
}
