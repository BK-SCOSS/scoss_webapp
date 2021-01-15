#include<iostream>
#include<vector>
using namespace std;
int demuocso(int a){
    int b,c,d;
    int dem=1;
    b=a+1;
    c=a+2;
    d=a;
    vector<int> an;
    for(int i = 2; i <=  a+2; i++){
        if(d%i==0 || b%i==0|| c%i==0){
            an.push_back(0);
            while(d%i==0){
                d/=i;
                an[an.size()-1]++;
            }
            while(b%i==0){
                b/=i;
                an[an.size()-1]++;
            }
            while(c%i==0){
                c/=i;
                an[an.size()-1]++;
            }
        }
    }
    int mono1=1;
    int mono2=1;
    for(int i=0; i < an.size();i++){
        mono1*=an[i]+1;
        mono2*=2*an[i]+1;
    }
    if(mono2%2==0){
    	return mono2/2-mono1;
	} else return mono2/2+1-mono1;
}
int main(){
	int n;
	vector<int> ans;
	int so1172100;
	cin>>n;
	for(int i = 0; i < n; i++){
		cin>>so1172100;
		ans.push_back(demuocso(so1172100));
	}
	for(int i = 0; i < n; i++){
	    cout<<ans[i]<<endl;
	}
	return 0;
}
