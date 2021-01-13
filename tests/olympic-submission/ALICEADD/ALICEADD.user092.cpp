#include <iostream>

using namespace std;



char toChar(int a)
{
	return (char)(a + 48);
}

int toInt(char a)
{
	return (int)a - 48;
}

string tong (string a, string b)
{		
	
	
	int save = 0;
	int l = a.length();
	if(a.length() < b.length())
	{
		swap(a, b);
	}
	for(int i = 0; i < l; i++)
	{
		
		int num = toInt(a.at(l - i - 1))  + save;
		if(b.length() > i )
		{
			num += toInt(b.at(b.length() - i - 1));
		}
		
		if(save == 1)
		{
			save = 0;
		}
		
		if(num >= 10)
		{
			num -= 10;
			save = 1;
		}
		
		a.at(l - i - 1) = toChar(num);
	
	}
	if(save == 1)
	{
		string sum = "1";
		sum += a;
		return sum;
	}
	
	return a;
}

void swap(string * a, string * b)
{
	string * temp = a;
	a = b;
	b = temp;
}

int main()
{
	int n;
	cin >> n;
	string arr[2][n];
	for(int i = 0; i < n; i++)
	{
		cin >> arr[0][i];
		cin >> arr[1][i];
	}
	
	for(int i = 0; i < n; i++)
	{
		cout << tong(arr[0][i], arr[1][i]) << endl;
	}
	
	return 0;
}
