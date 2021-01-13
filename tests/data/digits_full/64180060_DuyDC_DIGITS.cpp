#include <bits/stdc++.h>
using namespace std;

int res = 0;
int n;
int a[8];
bool visited[10];

bool check(){
	int sum = a[3]*10000+a[5]*1000+a[6]*100+a[7]*10+a[4] + a[1]*1000+a[2]*100+a[3]*10+a[4];
	if( sum == n) return true;
	else return false;
}

void Try(int i){
	for(int j = 0; j < 10; j++){
		if(visited[j] == false){
			visited[j] = true;
			a[i] = j;
			if(((i == 1 || i == 3) && a[i] > 0) || (i != 3 && i != 1)) {
			//(i == 4 && (a[i] == (n%10)/2) || a[i] == (n%10 + 10)/2) || (i == 3 && (a[i] == (n/pow(10,5)) || (a[i] == n/pow(10,5)-1)) && a[i] > 0)){
				if(i == 7){
					//for(int i = 1; i < 8; i++) cout << a[i] << " ";
					//cout << endl;
					//cout << check() << endl;
					if(check()) res++;
				}
				else Try(i+1);
			}
			visited[j] = false;
		}
	}
}

int main(){
	int test;
	cin >> test;
	vector<int> result;
	while(test > 0){
		cin >> n;
		res = 0;
		for(int i = 0; i < 10; i++) visited[i] = false;
		if(n > 110000 || n <= 10000 || n%2 == 1) res = 0;
		else {
			Try(1);
		}
		cout << res << endl;
		//result.push_back(res);
		test--;
	}	
}
