#include <bits/stdc++.h>
using namespace std;
int F[1000100] = {0};
bool check[1000100];
void sangNguyenTo()
{
	for (int i = 2; i <= 1000100; i++) 
	{
    	check[i] = true;
    }
  	for (int i = 2; i <= 1000100; i++) 
	{
    	if (check[i] == true) 
		{
      		for (int j = 2 * i; j <= 1000100; j += i) {
        	check[j] = false;
      	}
    }
  }
}
int maxx = -1;
void phanTich(int n)
{
	int i = 2;
	while(n > 1 || i <=sqrt(n))
	{
		if(check[n] == true) break;
		if(n%i == 0 )
		{
			n = n / i;
			F[i]++;
			
		}
		else i++;
	}
	if(n!= 0) F[n] ++;
	maxx = max(maxx,n);
}
int main()
{
	sangNguyenTo();
	int q;
	cin >> q;
	while(q --)
	{
		int n;
		cin >> n;
		phanTich(n);
		phanTich(n+1);
		phanTich(n+2);
		//cout << maxx << " ";
		//for(int i = 1 ; i<= sqrt(n+2);i++)	cout << i<<" "<<F[i]<<endl;
		int sum1 = 1, sum2 = 1;
		for(int i = 2 ; i <= maxx; i++)
		{
			if(F[i] != 0)
			{
				sum1 = sum1*(F[i]+1);
				sum2 = sum2*(2*F[i] +1);
			}
		}
		cout << sum2/2 - sum1 + 1 << endl;
		for(int i = 1 ; i <= maxx;i++)
			F[i] = 0;
		maxx = -1;
	}
}
