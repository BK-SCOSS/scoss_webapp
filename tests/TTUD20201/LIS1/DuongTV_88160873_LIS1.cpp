#include<bits/stdc++.h>
using namespace std;
unsigned int a[100000];
//int cnt =1;
int cnt[100000];
unsigned short int t,n;
int Try(int i,int res){
//	int cnt =1;
//cout << res;
	if(a[i+1]==res+1){
		cnt[i]++;
		res=res+1;
		
	}
	if(i<n-1){
	Try(i+1,res);
	}
	return cnt[i] ;
}
int main(){
	
    
    cin >>t;
    for(int i=0;i<t;i++){
	
//    int cnt[100000];

	
    n<=100000;
    
    cin >> n;
    
    for(int i=0; i<n;i++){
    	cin >> a[i];
    	cnt[i]=1;
	}
//	int cnt=1;
	for(int i=0; i<n;i++){
		int res= a[i];
    	cnt[i]=Try(i,res);
	}
	
	cout<< *max_element(cnt,cnt+n);
//	cout << cnt[1];
	
    return 0;
	}	
	}
