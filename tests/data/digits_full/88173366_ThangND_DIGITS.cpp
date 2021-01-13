#include <iostream>
using namespace std;

const int MAX = 50;
int tests;
int letters[7];
int assigned[7];
// int digits[10];
long ns[MAX];
int ans[MAX];
int curr = 0;
int num = 0;
int count = 0;
int digitAssigned[10];

void input(){
	cin >> tests;
	for(int i=0; i<tests; i++){
		cin >> ns[i];
	}
	for(int i=0; i<7; i++){
		assigned[i] = 0;
	}
	for(int i=0; i<tests; i++){
		ans[i] = 0;
	}
	for(int i=0; i<10; i++){
		digitAssigned[i] = false;
	}
}

void assignDigit(int loop){
	
	if(num == 7){
		if(curr == ns[loop]) ans[loop]++;
		return;
	}
	
		for(int j=0; j<10; j++){
			if(j==0 && (count == 0 || count == 2)){
				continue;
			}
			else if(assigned[count] == 0 && !digitAssigned[j]){
				letters[count] = j;
				assigned[count] = 1;
				digitAssigned[j] = true;
				num++;
				count++;
				curr = (assigned[0]*(letters[0]*1000)+assigned[1]*letters[1]*100+assigned[2]*letters[2]*10010+assigned[3]*letters[3]*2+assigned[4]*letters[4]*1000+assigned[5]*letters[5]*100+assigned[6]*letters[6]*10);
				assignDigit(loop);
				count--;
				num--;
				digitAssigned[j] = false;
				assigned[count] = 0;
			}
			
		}
	
}



/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	input();
	for(int i=0; i<tests; i++){
		if(ns[i] % 2 == 0){
			assignDigit(i);
		}		
	}
	for(int i=0; i<tests; i++){
		cout << ans[i] << endl;
	}
	return 0;
}
