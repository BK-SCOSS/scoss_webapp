#include<bits/stdc++.h>
using namespace std;

int n;
int T;
int const Max = 1e5+10;
int a[Max];
int main(){
	cin >> T;
	vector<int> res;
	while(T--){
        cin >> n;
        for(int i=1; i<=n; i++){
            cin >>a[i];
        }
		int count = 0;
		int k = n;
		while(k != 1){
			int max_ = 0;
			int j=1;
			if(k%2==0){
				for(int i=1; i<k; i+=2){
					max_ = max(a[i] + a[i+1], max_);
					a[j] = a[i] + a[i+1];
					j++;
				}
				k = k/2;
			}
			else{
				for(int i=1; i<k-1; i+=2){
					max_ = max(a[i] + a[i+1], max_);
					a[j] = a[i] + a[i+1];
					j++;
				}
				a[(k+1)/2] = a[k];
				k = (k+1)/2;
			}
			count += max_;
		}
		res.push_back(count);
	}
	for(int i=0; i<res.size(); i++){
		cout<<res[i] << endl;
	}
}
