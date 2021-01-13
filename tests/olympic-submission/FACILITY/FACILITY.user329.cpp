#include <bits/stdc++.h>
using namespace std;

struct Don
{
	long long int start, until, loinhuan, end;
	void Nhap()
	{
		cin >> start >> until >> loinhuan;	
	}	
	bool operator < (const Don & don)
	{
		return this->end < don.end;
	}
};

int main()
{
	long long int n, K;
	cin >> n >> K;
	vector <Don> DonHang;
	for (int i = 1; i <= n; i++)
	{
		Don temp;
		temp.Nhap();
		temp.until += K;
		temp.end = temp.start + temp.until - 1;
		DonHang.push_back(temp);
	}
	sort(DonHang.begin(), DonHang.end());
	
	long long int * MaxLoi = new long long int[DonHang.back().end + 5];
	bool * isCheck = new bool[DonHang.back().end + 5];
	vector <vector <int>> vitri; 
	vitri.push_back(vector <int>());
	for (int i = 1; i <= DonHang.back().end; i++)
	{
		isCheck[i] = false;
		vitri.push_back(vector <int>());
	}
	for (int i = 0; i < DonHang.size(); i++)
	{
		isCheck[DonHang[i].end] = true;
		vitri[DonHang[i].end].push_back(i);
	}
	MaxLoi[0] = 0;
	MaxLoi[1] = 0;
	for (int i = 2; i <= DonHang.back().end + 2; i++)
	{
		if (!isCheck[i])
		{
			MaxLoi[i] = MaxLoi[i - 1];
		}
		else
		{
			MaxLoi[i] = MaxLoi[i - 1];
			for (auto it : vitri[i])
			{
				MaxLoi[i] = max(MaxLoi[i], MaxLoi[DonHang[it].start - 1] + DonHang[it].loinhuan);	
			}
		}
	}
//	cout << endl;
//	for (auto it : DonHang) cout << it.start << " " << it.end << endl;
//	cout << endl;
//	
//	cout << endl;
//	for (int i = 1; i <= DonHang.back().end; i++) cout << MaxLoi[i] << "  ";
//	cout << endl;
	
	cout << MaxLoi[DonHang.back().end] << endl;
	
	return 0;
}
