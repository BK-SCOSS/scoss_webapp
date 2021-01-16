#include<iostream>
#include<list>
using namespace std;

int T, A,B, n, m;

int main(){
	cin >> T;

	while(T--){
		list<int> a;
		list<int> b;
		list<int> c;
		list<int> d;
		cin >> n;
		for(int i=0;i<n;i++){
			cin >> A;
			a.push_back(A);
			d.push_back(A);
		}
		
		cin >> m;
		for(int i=0;i<m;i++){
			cin >> B;
			b.push_back(B);
			c.push_back(B);
		}		
		int dem=0;
	

		a.sort();
		b.sort();
		c.sort();
		d.sort();
		a.unique();
		b.unique();
		c.unique();
		d.unique();
		b.merge(a);
		b.unique();
		dem = d.size()+c.size()-b.size();
	
		cout << dem << endl;
	}
}

