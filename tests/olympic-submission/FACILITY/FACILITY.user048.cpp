#include <iostream>

using namespace std;

int s[1000002], d[1000002], r[1000002];
int answer = 0;
int sum = 0;
int x, K;

void swap (int &a, int &b)
{
	int c = a;
	a = b;
	b = c;
}

void Try(int h) {
	if (h == x || s[h] + d[h] + K == s[x]) {
		sum += r[x];
		if (sum > answer) answer = sum;
		sum -= r[x];
		return;
	}
	if (s[h] + d[h] + K > s[x]) {
		if (sum > answer) answer = sum;
		return;
	}
	for (int i = h + 1; i < x; i++)
		if (s[i] >= s[h] + K + d[h]) {
			sum += r[i];
			Try(i);
			sum -= r[i];
		}
}

int main()
{
	cin >> x >> K;
	for (int i = 1; i <= x; i++)
		cin >> s[i] >> d[i] >> r[i];
	
	for (int i = 0; i < x; i ++)
		for (int j = i + 1; j <= x; j++)
			if (s[i] > s[j]) {
				swap(s[i], s[j]);
				swap(d[i], d[j]);
				swap(r[i], r[j]);
			}
	s[0] = -2;
	d[0] = 0;
	r[0] = 0;
	Try(0);		
	cout << answer;
}
