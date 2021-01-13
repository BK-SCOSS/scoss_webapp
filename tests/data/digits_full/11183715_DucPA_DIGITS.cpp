#include<bits/stdc++.h>
using namespace std;
int N, Q=0, cnt, test;
int a[7];
int visitted[10];
bool check(int i, int k){
	if( k == 0 || k == 2){
		if(i == 0) return false;
	}
	if( visitted[i] ==1) return false;
	return true;
}

void TRY(int k){
  for( int i=0; i<=9; i++){
  	if(check(i,k)){
	    a[k]=i;
		visitted[i]=1; 
	    if( k==6 ){
	      if( (a[0]*1000+a[1]*100+a[2]*10+a[3] +a[2]*10000+a[4]*1000+a[5]*100+a[6]*10+a[3] )==N ) Q++;
	    }
	    else {
       TRY(k+1);
      }
	    visitted[i]=0;
	}
  }
}

int main(){
  cin >> test;
while(test--){
  Q = 0;
  for( int i=0; i<=9; i++){
    visitted[i]=0;
  }
cin >> N;
  TRY(0);  
  cout << Q << endl; 
}
  return 0;
}