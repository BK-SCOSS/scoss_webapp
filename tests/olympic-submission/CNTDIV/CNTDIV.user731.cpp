#include <iostream>
#include <math.h>
#include <stack>
using namespace std;
int a[1000010];
int size=0;
int d[1000010];
void ngto(int n){
    //cout<< "n="<<n<< endl;
    bool B[1000010];
    for(int i=0;i<=n;i++){
        B[i]=true;
    } 
    for(int i=2;i<=sqrt(n);i++){
        if(B[i]){
            // cout<< i<<" ";
            for(int j=i*i;j<=n;j+=i) 
                {
                    //cout<<"j="<<j<<"  ";
                    B[j]=false;
                }
        }
    }
    //cout<<"\n----"<< size<<"------------------\n";
    for(int i=2;i<=n;i++){
        if(B[i]) {
            //cout<< i<<" ";
            d[size++]=i;
        }
    } 

}





unsigned long long resutl(int n){
	int n0,n1,n2;
	n0=n;
	n1=n+1;
	n2=n+2;
	for(int i = 0; i < 1000010; ++i)a[i]=0;
    for(int i = 0;i<=size && d[i]<=n+2; i++){
        while(n0%d[i]==0){
            a[d[i]]++;
            n0/= d[i];
        }
        while(n1%d[i] == 0){
            a[d[i]]++;
            n1/= d[i];
        }
        while(n2%d[i]==0){
        	a[d[i]]++;
        	n2/=d[i];
        }        
    }
    // for(int i =0;i< size && d[i]<=n+2;i++){
    //     cout<< a[d[i]]<<" ";
    // }
    unsigned long long su1,su2;
    su1=su2=1;
    for(int i=0;i<=size && d[i]<=n+2;++i){
    	su1*=(a[d[i]]+1);
    	su2*=(2*a[d[i]]+1);
    }
    su2--;
    su1--;
    // cout<<su1<<su2;
    return su2/2-su1;
}


 
int main(){
    int n;
    int k;
    cin>>n;
    ngto(1000002);
    // for(int i=0;i<size;i++){
    //      cout<< d[i]<<"-";
    //  }
    for (int i = 0; i < n; ++i)
    {
    	cin>>k;
    	cout<<resutl(k)<<'\n';
    }

    

}