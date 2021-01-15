#include <iostream>
#include <math.h>
#include <string>
using namespace std;
int n, K,mx=-1;
typedef struct {
	int bd;
	int kt;
	int mon;
}fac;
fac a[100];
void quicksort(fac a[], int l, int r) {
	int i = l;
	int j = r;
	int mid = (l + r) / 2;
	while (i < j)
	{
		while (a[mid].bd > a[i].bd) i++;
		while (a[mid].bd < a[j].bd) j--;
		if (i <= j)
		{
			fac temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			i++; j--;
		}
	}
	if (j > l) quicksort(a, l, j);
	if (r > i) quicksort(a, i, r);
}
fac b[10004];
int total(fac b[],int k) {
	int t = 0;
	for (int i = 0; i <= k; i++)
		t += b[i].mon;
	return t;
}
bool check(int k,int i)
{
	if (b[k-1].kt <= a[i].bd && b[k-1].bd < a[i].bd)
		return true;
	return false;
}
void Try(int k)
{
	for(int i=0;i<n;i++)
		if (check(k,i))
		{
			b[k] = a[i];
			if (total(b,k) > mx)
			{
				mx = total(b,k);
			}
				Try(k + 1);
		}
}
int main() {
	cin >> n >> K;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i].bd >> a[i].kt >> a[i].mon;
		a[i].kt += (a[i].bd + K);
	}
	quicksort(a, 0, n - 1);
	Try(0);
	cout << mx;
	return 0;
}
