#include<iostream>

using namespace std;

int main(){
	
	int T;
	cin >> T;
	for (int k =1; k<=T; k++){
	int n,m;
	int dem =0;
	
	cin >>n;
	int a[n];
	for( int i=0; i <n; i++){
		cin >> a[i];
	}
	
	cin >> m;
	int b[m];
	for( int j=0; j <m; j++){
		cin >> b[j];
	}
	int c[m];
	for (int i =0; i<n; i++){
		for(int j=0; j<m;j++){
			if(b[j] == a[i] && b[j] != c[j] ){
				
				b[j] = c[j];
				dem++;
			}
		}
	}
	cout << dem << endl;
	
}
return 0;
}
