#include <bits/stdc++.h>
using namespace std;

long long sum,N[55],result[55],T;
int num[10],word[8];

long long tinh(){
	return (word[2]*10000+(word[0]+word[4])*1000 + (word[5]+word[1])*100 + (word[6]+word[2])*10 + word[3]*2);
}

int hamsinh(int so, int k){
	int bien;
	if(k==7){
		if(tinh()==N[so]) result[so]++;
		return 0;
	}
	for(int i=0;i<=9;i++){
		if (num[i]==0) {
			if(i==0) if((k==0)||(k==2)) continue;
			word[k]=i;
			num[i]=1;
			hamsinh(so,k+1);
			bien=word[k];
			num[bien]=0;
			word[k]=0;
		}
	}
	return 0;
}

int main(){
	cin>>T;
	for(int i=1;i<=T;i++){
		cin>>N[i];
	}

	for(int i=1;i<=T;i++){
		hamsinh(i,0);
		cout<<result[i]<<endl;
	}


	return 0;
}
