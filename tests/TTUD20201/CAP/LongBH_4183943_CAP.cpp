#include<iostream>
#include<set>
using namespace std;
const int MAX = 100;

int main() {
	int t, n, m, inp;
	set<int> a, b;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> inp;
			a.insert(inp);
		}
		cin >> m;
		for (int j = 0; j < m; j++) {
			cin >> inp;
			b.insert(inp);
		}
		
		set<int> c = a;
    	set<int>::iterator tmp;
    	for (set<int>::iterator it=a.begin(); it!=a.end(); ++it) {
    		tmp = b.find(*it);
    		if ( tmp == b.end())
        		c.erase(*it);
    	}
		
		cout << c.size() << endl;
	}
}
