#include <bits/stdc++.h>
using namespace std;
int N, dem = 0;
bool a[9] = {false};
string s[] = {"0","1","2","3","4","5","6","7","8","9"};
string gan[] = {"H","U","S","T","O","I","C"};
 
bool kiemtra(){
	stringstream gx(gan[0] + gan[1] + gan[2] +gan[3]);
	int x;
	gx >> x;
	int y;
	stringstream gz(gan[3] + gan[4] + gan[5] + gan[2] +gan[6]);
	gx >>y;
	if( (x+y) == N ){
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
