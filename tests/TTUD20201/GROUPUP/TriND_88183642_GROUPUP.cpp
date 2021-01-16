#include<bits/stdc++.h>
using namespace std;

int memory[10];
int main()
{
	int n;
	cin >> n;
	for(int i=0;i<n;i++)
	{
		int tg=0;
		int sonhom;
		cin >> sonhom;
		int nhom[sonhom];
		for(int index = 0;index <sonhom;index++)
		{
			cin >> nhom[index];
		}
//		int nhomsau[sonhom];
		while(sonhom!=1){
			int temp=0;int index1 = 0;
			if(sonhom%2==1)
			{
				for(int x=0;x<sonhom-1;x+=2)
				{
					temp = max(temp,nhom[x]+nhom[x+1]);
					nhom[index1] = nhom[x]+nhom[x+1];
					index1++;
				}
				temp = max(temp,nhom[sonhom-1]);
				int tempxx = nhom[sonhom-1];
//				cout << "so le";
				sonhom = sonhom/2 + 1;
				nhom[sonhom-1] = tempxx;
			}
			else
			{
				for(int x=0;x<=sonhom-2;x+=2)
				{
					temp = max(temp,nhom[x]+nhom[x+1]);
					nhom[index1] = nhom[x]+nhom[x+1];
					index1++;
				}
				sonhom = sonhom/2;
//				cout << "so chan";
			}
			tg+=temp;
//			cout << temp <<" ";
		}
		memory[i]=tg;
	}
	for(int xx=0;xx<n;xx++)
	{
		cout << memory[xx];
	}
	return 0;
}
