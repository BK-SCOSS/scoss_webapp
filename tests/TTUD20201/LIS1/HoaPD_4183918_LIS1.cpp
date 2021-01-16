#include <bits/stdc++.h>
using namespace std;

int t;

int n;
vector<int > a;
vector<int> f;
vector<int> last;
int max_;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	cin >> t;
	max_ = 0;
	for(int i = 0; i< t; i++){
		cin >> n;
		a.resize(n+1);
		f.resize(n+1);
		last.resize(n+1);
		for(int j = 1; j<=n; j++){
			cin >> a[j];
			f[j] = 1;
			last[j] = a[j];
		}
		
		for(int j = 2; j<=n; j++){
			if(a[j] == last[j-1] + 1){
				f[j] = f[j-1]+ 1;
				last[j] = a[j];
			}
			else {
				f[j] = f[j-1];
				last[j] = last[j-1];
			}
		}
		
		for(int j = 1; j<=n; j++){
			if(f[j] > max_ ) max_ = f[j];
		}
		
		cout << max_ << endl;
		
		
	}
}
