#include <bits/stdc++.h>
using namespace std;
int n,k, maxx = -1;

struct khachHang
{
	int start,need,price,end;
};
bool sortt(struct khachHang a, struct khachHang b)
{
	if(a.start == b.start) return a.end < b.end;
	else return a.start < b.start;
}
struct khachHang A[100010];
int main()
{
	int F[100010] = {0};
	cin >> n >> k;
	for(int i = 1 ; i <= n ; i ++)
	{
		cin >> A[i].start >> A[i].need >> A[i].price;
		A[i].end = A[i].start + A[i].need + k;
	}
	sort(A+1, A+n+1,sortt);
	/*for(int i = 1 ; i <= n ; i ++)
	{
		cout << A[i].start <<" " << A[i].end <<" "<<A[i].price<<endl;
	}*/
	F[0] = 0;
	A[0].start = 0, A[0].end = 0, A[0].price = 0;
	for(int i = 0 ; i <= n ; i++)
		F[i] = A[i].price;
	for(int i = 2 ; i <= n ; i ++)
	{
		for(int j = 0 ; j < i ; j ++)
		{
			if(A[j].end <= A[i].start) F[i] = max( F[j] + A[i].price,F[i]);
		}
	}
	//cout << F[4];
	for(int i = 1 ; i<= n;i++) maxx = max(maxx,F[i]);
	cout << maxx;
}
