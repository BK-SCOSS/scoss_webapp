#include <iostream>
#include <stdio.h>
#include <vector>
#include <math.h>
#include <string.h>
const int MAX = 1e6;
using namespace std;
int cnt[1000009];
int prime[1000009];
int pr[1000009];
vector <int> coso;
void sangNguyenTo(){
	for(int count = 2;count <= (MAX+5); count++)
		if (prime[count] == 0)
		for (int count1 = count; count1 <=MAX+5; count1+=count)
			prime[count1] = count;
}
void phantich(int n){
	int x = n;
	int dem = 0;
	while(n!=1){
		if (cnt[prime[n]] ==0)
			coso.push_back(prime[n]);
		cnt[prime[n]]++;
		n/=prime[n];
	}
}
int main(){
	sangNguyenTo();
	int t;
	cin >> t;
	while(t--){
		coso.clear();
		int n;
		cin >> n;
		memset(cnt,0,sizeof(cnt));
		phantich(n);
		phantich(n+1);
		phantich(n+2);
		int sumN = 1;
		for (int ptr = 0; ptr < coso.size();ptr++){
				sumN*= (cnt[coso[ptr]]+1);
				cnt[coso[ptr]]*=2;
			}
		long sum = 1;
		for (int ptr = 0; ptr < coso.size();ptr++)
				sum *= (cnt[coso[ptr]]+1);
		cout << (sum-1)/2-sumN +1<< endl;
	}


}
