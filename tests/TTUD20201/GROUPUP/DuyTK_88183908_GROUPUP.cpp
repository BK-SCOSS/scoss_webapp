#include<iostream>
using namespace std;
void Merge(int A[100000],int n, int kq){
	if (n==1) cout << kq;
	else
	{
		int Max=0,k;
		if(n%2==0) k=n/2; else k=n/2+1;
		for (int i=0;i<n/2;i++){
			if ((A[2*i]+A[2*i+1])>Max) Max=A[2*i]+A[2*i+1];
		}
		kq+=Max;
		for (int i=0;i<n/2;i++){
			A[i]=A[2*i]+A[2*i+1];
		}
		if (n%2!=0) A[k-1]=A[n-1];
		Merge(A,k,kq);
	}
}
int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
	int T;
	cin >> T;
	for (int i=0;i<T;i++){
		int n,A[100000];
		cin >> n;
		for (int j=0;j<n;j++) cin >> A[j];
		Merge(A,n,0);
	}
	return 0;
}
