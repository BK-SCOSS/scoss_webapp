
#include<bits/stdc++.h>
using namespace std;
int kiemtra(int a[], int b[], int c, int d){
	int t=0;
	for(int i=0;i<c; i++){
		for(int j=0; j<d; j++){
			if(b[j]==a[i]&&b[j]>0){ t++;
			b[j]=0;
			}
		}
}
return t;
}

int main(){
	int n;    cin >> n; 
	for(int i=0; i<n; i++){
		int c,d;
		cin>>c;
		int a[c];
		for(int i=0;i<c; i++){
			cin >>a[i];
		}
		cin >> d;
		int b[d];
		for(int i=0; i<d; i++){
			cin >> b[i];
		}
		cout << kiemtra(a,b, c,d);
	}

    return 0 ;
    
}
