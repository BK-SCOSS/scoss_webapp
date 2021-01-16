#include<bits/stdc++.h>

using namespace std;

int n;
unsigned long long a[100000],b[100000];
int count;

int main(int argc, char const *argv[]){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    int count,max=0;
    int k;
    for(int i=0;i<n;i++){
    	cin>>a[i];
	}
	while(n!=0){
		for(int i=0;i<n;i++){
			a[i] = (a[k] + a[k+1]);
			k = k+2;
		}
		for(int i=0;i <= (n/2) ;i++){
			if(max < a[i]){
				max = a[i];
			}
		}
			count = count + max;
//			cout << max;
			max = 0;
		k=0;
//		for(int i=0;i<n;i++){
//   	cout<<a[i];
//	}
		n=n/2;
	}
    
    cout << count;
    
    return 0;
}
