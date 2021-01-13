#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[8];
int cnt = 0;
bool b[10];

bool check(int i, int k) {
	if(b[i] && a[1] != 0 && a[4] != 0 ) return true;
	return false;
}

void Try(int k) {
	for(int i = 1; i <= 9; i++)
	if(check(i,k))
	{
		a[k] = i;
		b[i] = false;
		if(k == 9 ) {
			if((a[1]*1000 + a[2] *100 + a[3]*10 + a[4]) + (a[3]*10000 + a[5]*1000 + a[6]*100 + a[7]*10 + a[4]) == n) {
				cnt++;
			}
		}
		else Try(k + 1);
		b[i] = true;
	}
}

int main() {
	cin>>m;
	for(int i = 0;i<m;i++){
        cin>>n;
        for(int i = 0 ; i< 10 ; i++){
            b[i] = true;
        }
        Try(1);
        cout << cnt << "\n";
	}
}
