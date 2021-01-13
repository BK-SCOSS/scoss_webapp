#include <iostream>
#include <algorithm>
#include <stdlib.h>
using namespace std;

int a[7];
int b[100000];
int k=7;int Q,rs =0;
bool check=false;

int sum() {
    return 1000 * a[0] + 100*a[1] + 10010*a[2] +2* a[3] + 1000 * a[4] + 100 * a[5] + 10 * a[6];
}


void backtrack(int i) { 
    for (int j = a[i - 1] + 1; j <= 9 - k + i; j++) { 
        a[i] = j; 
        if (i == k) { 
            do {
                if (sum() == Q) rs++;
           } while (a+1, a + k+1);
        }
        else {
            backtrack(i + 1); 
       }

   }
}
void toHop() {
    if (k >= 0 && k <= 9) {
       a[0] = 0; 
        backtrack(1);
    }
}


int main()
{  
	int x;
	cin>>x; int N[x];
	for(int i=0;i<x;i++) cin>>N[i];
	for(int i=0;i<x;i++){
	Q=N[i];
   toHop();
    cout << rs;
    return 0;}
}
