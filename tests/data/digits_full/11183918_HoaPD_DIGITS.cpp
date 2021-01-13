#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define MOD 1000000007
#define PI 3.14159265358979323846264338328
typedef unsigned long long ull;
const int N = 1e6 + 1;

using namespace std;


int n;
int t;
int mark[10] ;
int a[7];
int cnt = 0;

bool check(){
	if( (1000*a[0] + 100*a[1] + 10* a[2]+ a[3]+ 10000*a[2]+1000*a[4]+100*a[5]+10*a[6]+a[3] )== n) return true;
	else return false; 
}

void TRY(int k){
	for(int i = 0; i<= 9; ++i){
		if(mark[i] == 0 and a[0]!= 0 and a[2] != 0 ){
			a[k] = i;
			mark[i] = 1;
			if(k == 6){
				if(check()) cnt++;
			}
			else TRY(k+1);
			a[k] = -1;
			mark[i] = 0;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> t;
	for(int i = 0; i< t; ++i){
		cin >> n;
		memset(a,-1, sizeof(a));
		memset(mark,0, sizeof(mark));
		cnt = 0;
		TRY(0);
		cout << cnt << endl;
	}
	
	return 0;
}

