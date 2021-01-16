#include <iostream>
using namespace std;

int main(){
	int T,sum,c[100];
		cin>>T;
		for(int i=0;i<T;i++){
		
	int n;
    cin >> n;
    int a[100];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    int m;
    cin >> m;
    int b[100];
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
	
	int count=0;
	for (int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if (a[i]==b[j]){
				count++;
			}
		}
	}
	c[sum]=count;
	sum++;
}
	for(int i=0;i<sum;i++){
		cout<<c[i]<<endl;
	}
}
