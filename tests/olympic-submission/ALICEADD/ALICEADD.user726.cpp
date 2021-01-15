#include <bits/stdc++.h>
using namespace std;
void dao(char *a, char *b)
{
	for(int i  = strlen(a)-1; i>= strlen(a)-strlen(b); i--)
		{
			b[i] = b[i-1];
		}

		for(int i = 0; i<strlen(a)-strlen(b); i++)
		b[i] = 0;
}
void suma(char *a, char *b)
{
	if(strlen(a)>strlen(b)) dao(a, b);
	if(strlen(b)> strlen(a)) dao(b,a);
	char s[25];
	char nho =0; 
	for(int i = strlen(a)-1; i>= 0; i--)
	{
		int j = i+1;
		//cout <<"   " << a[i] << " " << b[i] << endl;
		s[j] = (char)(((int)a[i]+(int)b[i]-96)%10 + (int)nho+48);
		nho =(char)(((int)a[i] +(int)b[i]-96) /10);
		nho = (nho > 0) ? nho : 0;
		//cout <<" " << (int)nho << endl;
		//cout <<j <<" " <<s[j] << endl;
	}
	s[0] = 0; 
	s[0] += nho+ 48;
	int ok = 0;
	
	for(int i = 0; i<strlen(s);i++)
	{
		if(s[i]!= '0') ok = 1;
		if(ok) cout <<s[i] ;
	}
	
}
void trans(long long a, char *b)
{
	int i = 20;
	do
	{	
		int c = a%10;
		b[i] = c+48;
		//cout << b[i] << endl;
		a = a/10;
		i--;
	} while (a != 0);
	for(i; i >=0; i--)
	b[i] = 48;
	
}
int main()
{
	int T ; 
	cin >> T;
	if(T>10 || T<=0) return 0;
	for(int i = 0; i<T; i++)
	{
	char a[21], b[21];
	long long c;
	cin >> c; 
	trans(c, a);
	cin >> c;
	trans(c,b);
	suma(a,b);
	cout << endl;
	}
	
	//cout << c << endl;
	

	
}