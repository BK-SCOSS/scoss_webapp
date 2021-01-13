#include <bits/stdc++.h>
using namespace std;

// ICT-K62+HUST=N - I,C,T,H,U,S,K
int N, dem = 0;
bool a[9] = {false};
string s[] = {"1","2","3","4","5","6","7","8","9"};
string gan[] = {"I","C","T","H","U","S","K"};

bool kiemtra(){
	stringstream gx(gan[0] + gan[1] + gan[2]);
	int x;
	gx >> x;
	int y;
	stringstream gy(gan[6] + "62");
	gy >> y;
	int z;
	stringstream gz(gan[3] + gan[4] + gan[5] + gan[2]);
	gz >> z;
	if( (x-y+z) == N ){
		return true;
	}
	return false;
}

void Try(int k){
	for(int i=0; i<9; i++){
		if(!a[i]){
			gan[k] = s[i];
			a[i] = true;
			if(k == 6){
				if(kiemtra()){
					dem++;
				}
			}else{
				Try(k+1);
			}
			a[i]=false;
		}
	}
}

int main(){
	cin >> N;
	Try(0);
	cout << dem;
	return 0;
}
