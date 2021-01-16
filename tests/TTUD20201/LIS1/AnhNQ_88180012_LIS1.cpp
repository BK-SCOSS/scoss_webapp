#include <iostream>
using namespace std;
int tim(int a[],int n,int x){
	for(int i=0;i<n;i++){
		if(a[i]==x);
		return i;
	}
	return -1;
}
int nhap(int a[],int n){
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
}
int main(){
	int T,c[10000];
	int dem=0;
	cin>>T;
	for (int i=0;i<T;i++){
		int n;
		int a[10000];
		cin>>n;
		nhap(a,n);
		int count,result=0;
		int flag=0;
		for(int i=0;i<n;i++){
			count=1;
			int j=i+1;
			int tmp=a[i];
			while(j > i && j< n)
            {
                if (a[j]==tmp+1)
                {
                    tmp = a[j];
                    count ++;
                }
                j ++ ;
            }
            result = max (result,count);
        }
        c[dem]=result;
		dem++;
		}
	for(int i=0;i<dem;i++){
		cout<<c[i]<<endl;
	}	
	}

