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
		for(int i=0; i<n; i++) cin>>setdata[i];
		
		//
		int count=0;
		for(;;){
			int maxtest=0;
			int k=0;
			if(n%2==0&&n!=1){
				for(int i=0; i<n; i=i+2){
					setdata[k] = setdata[i]+ setdata[i+1];
					maxtest=max(maxtest, setdata[k]);
					k++;	
				}
				count+=maxtest;
				if(n==2) break;
				//for(int i=k; i<n; i++) setdata[i]=0;
				n=n/2;
			}
			if(n%2==1&&n!=1){
				for(int i=0; i<n-1; i=i+2){
					setdata[k] = setdata[i]+ setdata[i+1];
					maxtest=max(maxtest, setdata[k]);
					k++;	
				}
				maxtest=max(maxtest,setdata[n-1]);
				//k++;
				count+=maxtest;
				//for(int i=k; i<n; i++) setdata[i]=0;
				n=n/2+1;
			}
			
			
			
			
		}
		cout<<count;	
	}
	
		
	return 0;
}
