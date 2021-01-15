#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;
	unsigned long long a,b,c, a1, a2,b1,b2,c2;
	while(t--){
    cin>>a>>b;
	a1=a/10;
	a2=a%10;
	b1=b/10;
	b2=b%10;
	c=a1+b1;
	c2=a2+b2;
	if(c2>=10)
		c++;
	c2=c2%10;
	if(c==0){
		cout<<c2;
	}
	else
		cout<<c<<c2;
    cout<<endl;
	}
	return 0;
}
