#include<iostream>
using namespace std;
int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
	long n,a,check1,check2,check3=99999,Max;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> a;
		Max=0;
		int *A = new int [a];
		for (int j=0;j<a;j++){
			cin >> A[j];
		}
		for (int j=0;j<a;j++){
			if ((A[j]>=check3)&&(A[j]<=(check3+Max))) continue;
			check1 = A[j]+1;check2=1;
			for (int k=j;k<a;k++){
				if (A[k]==check1){
					check1++;
					check2++;
				}
			}
			if (check2>Max){
				Max=check2;
				check3=A[j];
			}
			
		}
		cout << Max;
		delete A;
	}
	return 0;
}
