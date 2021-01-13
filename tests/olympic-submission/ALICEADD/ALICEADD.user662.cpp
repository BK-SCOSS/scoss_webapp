#include <bits/stdc++.h>
#include <stdio.h>
const int MAX = 1e5;
#define MAX(a,b) ((a<b)?b:a)
using namespace std;
char strA[20];
char strB[20];
int ans[30];
int sum(char *a,char *b){
	int lenA = strlen(a)-1;
	int lenB = strlen(b)-1;
	int temp = 0;
	int count = 0;
	while ((lenA!= -1||lenB!= -1) ){
		int A,B;
		if (lenA == -1) A = 0;
		else A = a[lenA] - '0';
		if (lenB == -1) B = 0;
		else B = b[lenB] - '0';
		int s = A+B+temp;
		ans[count] = s%10;
		count++;
		temp = s/10;
		if (lenA != -1) lenA--;
		if (lenB != -1) lenB--;
	}
	if (temp != 0) {
		ans[count] = temp;
		count++;
	}
	
	return count;
}
int main(void){
	int t;
	cin >> t;
	while(t--){
		cin >> strA;
		cin >> strB;
		int t = sum(strA,strB);
		t--;
		for (t; t>=0;t--)
			cout << ans[t];
		cout << endl;
	}
}
		
