#include<iostream>
#include<algorithm>
const int N = 105;
using namespace std;


int n,rs[N];
int x , y;
int a[N][N], b[N][N];
	
	
void cal(int i){
	int r = 0;
    int p,q;
    int j = 0, k = 0;
    p = a[i][j];
    q = b[i][k];
    
    while(j < x && k < y){
    	if(p == q) {
    		r++;
    		j++;
    		k++;
		}
		else if(p > q){
			k++;
		}
		else if(q > p){
			j++;
		}
		p = a[i][j];
        q = b[i][k]; 
	}
	rs[i] = r;
    
}
int main(){
	
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> x;
		for(int j = 0; j < x; j++){
			cin >> a[i][j];
		}

		cin >> y;
		for(int j = 0; j < y; j++){
			cin >> b[i][j];
		}

		sort(a[i],a[i]+x);
		sort(b[i],b[i]+y);
		cal(i);
	}
	for(int i = 0; i < n; i++){
		cout << rs[i] << endl;
	}
	
	return 0;
}
