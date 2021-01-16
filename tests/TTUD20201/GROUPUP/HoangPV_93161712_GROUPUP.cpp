#include<bits/stdc++.h>
using namespace std;

int n;
int T;
int const Max = 1e5+10;
int a[Max];

void input(){
	cin >> n;
	for(int i=1; i<=n; i++){
		cin >>a[i];
	}	
}


int main(){
	cin >> T;
	vector<int> res;
	while(T!=0){
		T=T-1;
		input();
		int count = 0;
		int k = n;
		while(k != 1){
//			cout << "k = "<<k << endl;
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
		
			
//			//
//			for(int i=1; i<=k; i++){
//				cout <<a[i] << " ";
//			}
//			cout << endl;
//			//

			count += max_;
//			cout <<"count = " << count << endl;
		}
		res.push_back(count);
	}
	for(int i=0; i<res.size(); i++){
		cout<<res[i] << endl;
	}
	return 0;
}
