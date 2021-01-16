#include<iostream>
#include<algorithm>
const int N = 100005;
const int T = 11;
using namespace std;


int n,rs[T];
int length;
int a[T][N];

void cal (int i){
	int gt[N];
	int maxx[N];
	int r;
	int index = 0;
	int min = a[i][0];
	
	gt[0] = a[i][0];
	maxx[0] = 1;
	for(int j = 1; j < length; j++){
		if(a[i][j] < min){
			index++;
			gt[index] = a[i][j];
			maxx[index] = 1;
			min = a[i][j];
		}
		else if(a[i][j] > min){
			bool ss = true;
			for(int z = 0; z <= index; z++){
				if(gt[z] + 1 == a[i][j]){
					gt[z] = a[i][j];
					maxx[z]++;
					ss = false;
				}
			}
			if(ss){
				index++;
		    	gt[index] = a[i][j];
	    		maxx[index] = 1;
			}
		}
	}
    r = maxx[0];
	for(int j = 1; j <= index; j++){
		r = max(r,maxx[j]);
	}
	rs[i] = r;
}

int main(){
	
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> length;
		for(int j = 0; j < length; j++){
			cin >> a[i][j];
		}
		cal(i);
	}
	for(int i = 0; i < n; i++){
		cout << rs[i] << endl;
	}
	
	return 0;
}
