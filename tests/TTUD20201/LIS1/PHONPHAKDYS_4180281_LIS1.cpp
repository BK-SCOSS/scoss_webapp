#include <iostream>
#include <map>
using namespace std;
int a[100000];
int f[100000];
int n;
map<int,int> d;
map<int,int>::iterator it;
int main(){
    int t,r;
    cin>>t;
    for (int j=1;j<=t;j++){
    	d.clear();
    	r=0;
        cin>>n;
        for (int i=0;i<=n-1;i++) scanf("%d",&a[i]);
        for (int i=0;i<=n-1;i++) f[i]=1;
       	for (int i=0;i<=n-1;i++) {
       		it=d.find(a[i]-1);
       		if (it!=d.end()){
       			f[i]=f[it->second]+1;
       		} else {
       			f[i]=1;
       		}
       		d[a[i]]=i;
       		r=max(r,f[i]);
       	}
        cout<<r<<endl;
    }
}