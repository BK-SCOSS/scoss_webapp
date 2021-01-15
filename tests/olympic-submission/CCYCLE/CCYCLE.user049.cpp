#include <bits/stdc++.h>
using namespace std;

int distance(int a, int b, int n)
{
	if (a==b) return 0;
	if (a==1)
	{
		if (b%3 == 0)
		{
			int u = 2*b/3 - 1;
			if (u<=n) return u;
			else return 2*n - u;
		}
		if (b%3 == 1) 
		{
			int u= 2*(b-1)/3;
			if (u<=n) return u;
			else return 2*n - u;
		}
		if (b%3 == 2);
		return distance(1, b-1, n) + 1;
	}
	if (b==1) return distance(1, a, n);
	if (a%3 == 2 && a != b) return distance(a-1, b, n) + 1;
	if (b%3 == 2) return distance(a, b-1, n) + 1;
	if (a>b) return distance(b, a, n);
	int mid;
	if (n%2 ==0) mid = 3*n/2 + 1;
	else mid = 3*(n+1)/2;
	if (b > mid)
	{
		if (a>mid) return distance (1, a, n) - distance(1, b, n);
		else 
		{
			int u = distance(1, a, n) + distance(1, b, n);
			if (u<=n) return u;
			else return 2*n - u;
		}
	}
	else return distance(1, b, n) - distance(1, a, n);
}


int func(int a, int b, int l, int n)
{
	if (l < distance(a, b, n)) return 0;
	if (l == distance(a, b, n)) 
	{
		if (distance(a, b, n) == n) return 2;
		else return 1;
	}
	int x, y, z;
	if (a==1) 
	{
		x = 2; y =3; z = 3*n;
		return func(x, b, l-1, n) + func(y, b, l-1, n) + func(z, b, l-1, n);
	}
	if (a==3*n)
	{
		x=1; y=3*n-2;
		return func(x, b, l-1, n) + func(y, b, l-1, n);		
	}
	else
	{
		if (a%3==1)
		{
			x = a-1; y=a+1; z=a+2;
			return func(x, b, l-1, n) + func(y, b, l-1, n) + func(z, b, l-1, n);
		}
		if (a%3==0)
		{
			x = a-2; y=a+1;
			return func(x, b, l-1, n) + func(y, b, l-1, n);
		} 
		if (a%3==1)
		{
			x = a-1;
			return func(x, b, l-1, n);
		}
	}
}

int main()
{
	int n, l, s, t;
	cin >> n >> l >> s >> t;
	cout << func(s, t, l, n) << endl;
	//cout << distance(2, 14, 5);
	
}
