#include<iostream>
#include<math.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	long long t= n*(n+1)*(n+2);
	int a[100];
	int bp[100];
	int rs[100];
	int count=0;
	for(int i=2;i<=sqrt(t);i++){
		if(t%i==0) {
			a[count]=i;
			bp[count]=i*i;
			count++;
			
			
		}
	}
	
	int m=count;
	count++;
		cout<<count;
	for(int i=0;i<=m;i++ ){
		for(int j=0;j<=m;j++){
			long long c= bp[i]*a[j];
			if(c<t && (t%c)!=0){
				bp[count]=c;
				count++;
			} 
			else break;
		}
	}

	
	
	return 0;
}
