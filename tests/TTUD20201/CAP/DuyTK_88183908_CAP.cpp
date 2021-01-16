#include<iostream>
using namespace std;
int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
	int n,a,b,ans,A[10000],B[10000],C[100],temp;
	cin >> n;
	for (int i=0;i<n;i++){
		ans=0;
		cin >> a;
		for (int x=0;x<a;x++) cin >> A[x];
		cin >> b;
		for (int x=0;x<b;x++) cin >> B[x];
		for (int x=0;x<a;x++)
			for (int y=x;y<a-1;y++){
				if (A[x]>A[y]){
					temp=A[x];A[x]=A[y];A[y]=temp;
				}
			}
		for (int x=0;x<b;x++)
			for (int y=x;y<b-1;y++){
				if (B[x]>B[y]){
					temp=B[x];B[x]=B[y];B[y]=temp;
				}
			}
		for (int x=0;x<a;x++){
			for (int y=0;y<b;y++){
				if (A[x]==A[x-1]) continue;
				if (B[y]==B[y-1]) continue;
				if (A[x]==B[y]){
					ans++;
					break;
				}
			}
		}
		C[i]=ans;
	}
	for (int i=0;i<n;i++) cout << C[i] << endl;
	return 0;
}
