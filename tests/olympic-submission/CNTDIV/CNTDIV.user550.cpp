#include<iostream>
using namespace std;
void algo(unsigned long long int t, unsigned long long int t2) {
	int count = 0;
	for (int i = 2; i < t; i++) {
		if (t2 % i == 0 && t % i != 0)
			count++;
	}
	cout << count << endl;
}
int main() {
	int soTest = 0;
	cin >> soTest;
	unsigned long long int* n = new unsigned long long int[soTest];
	unsigned long long int* t = new unsigned long long int[soTest];
	for (int i = 0; i < soTest; i++) {
		cin >> n[i];
		t[i] = n[i] * (n[i] + 1) * (n[i] + 2);
	}
	for (int i = 0; i < soTest; i++) {
		algo(t[i],t[i]*t[i]);
	}
}