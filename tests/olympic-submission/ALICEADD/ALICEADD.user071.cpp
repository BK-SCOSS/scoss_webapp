#include<iostream>
#include<cmath>
#include<cstring>
#include<stack>
using namespace std;
 
void sum(string a,string b){
	int n1=a.length(),n2=b.length(),n=abs(n1-n2);
	string S;
	for(int i=1;i<=n;i++)
	S+='0';
	if(n1<n2) a=S+a;else b=S+b;
	stack<int>s;
	int x=0;
	n=a.length()-1;
	for(int i=n;i>=0;i--){
		x=x+a[i]-'0'+b[i]-'0';
		if(i!=0 && x>=10) {
            s.push(x-10);
			x=1;
		} else 
		if(i!=0 && x<10){
			s.push(x);
			x=0;			
		} else
		if(i==0) s.push(x);
	}
	while(!s.empty()){
		int t=s.top();
		cout<<t;
		s.pop();
	}
	cout<<endl;
}
 
int main(){
	int T;
	cin>>T;
    while(T--){
    string a,b;
	cin>>a>>b;
	sum(a,b);
	}
}
