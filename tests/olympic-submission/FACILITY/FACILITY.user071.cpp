#include<bits/stdc++.h>
using namespace std;
int n , k;
typedef struct{
	int f, l , t;// dau cuoi tien
}job;
bool check(job a , job b){
	return a.f < b.f;
}
void init(job cv[]){
    for(int i = 1 ; i <= n ; i++){
    	cin >> cv[i].f >> cv[i].l >> cv[i].t;
    	cv[i].l = cv[i].l + cv[i].f + k;
	}
	sort(cv+1,cv+1+n,check);  	
}
long long res(job cv[]){
	long long sum = cv[1].t;
	int last = cv[1].l;
	for(int i = 2 ; i <= n ; i++){
		if(cv[i].f >= last){
			sum = sum + cv[i].t;
			last= cv[i].l;
		}
	}
	return sum;
}
int main(){
    cin >> n >> k;
    job cv[n+1];
    init(cv);
	cout << res(cv) << endl;
}

