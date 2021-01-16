#include<iostream>
using namespace std;

int T, n, a[1000005], kq[1000005];

int main(){
	cin >> T;
	while(T--){
		cin >> n;
		for(int i=0;i<n;i++) cin >> a[i];
		kq[0]=1;
		for(int i=1;i<n;i++){
			int j;
			for(j=i-1;j>=-1;j--){
				if(a[i]==a[j]+1){
					kq[i] = kq[j]+1;
					break;
				} else if(a[i] == a[j]) {
					kq[i] = kq[j];
					break;
				}
			}
			if(j== -1) a[i] = 1;
		}
		int kqmax = 1;
		for(int i=0;i<n;i++){
			if(kqmax < kq[i]) kqmax = kq[i];
		}
		cout << kqmax << endl;
	}
}
