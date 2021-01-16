#include <iostream>
using namespace std;

int m, n, t;
long long a[100], b[100];
int result[10];
int temp = 0;
void solve(){
    cin>>t;
    for(int k=0; k<t; k++){
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    cin>>m;
    for(int j=0; j<m; j++){
        cin>>b[j];
    }
    int counts = 0;
    	for(int i=0; i<n; i++){
        	for(int j=0; j<m; j++){
            	if(a[i]==b[j]) counts++;
        	}
    	}
    	result[temp++] = counts;
	}
	for(int i= 0; i<10; i++){
		if(result[i]!=0){
		cout<<result[i]<<endl;
	}
	}
}

void resolve(){
	for(int k=0; k<t; k++){
    	int counts = 0;
    	for(int i=0; i<n; i++){
        	for(int j=0; j<m; j++){
            	if(a[i]==b[j]) counts++;
        	}
    	}
    	cout<<counts<<endl;  	
	}
}

int main(){
    solve();
    return 0;
}


