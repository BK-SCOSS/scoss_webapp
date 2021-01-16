#include<iostream>
using namespace std;
int n;
int A[10001];
int save[10001];
int lis(int i)
{
	if(save[i] != -1) return save[i];
	int ans=1;
	for(int j=1; j<i ; j++)
	{
		if(A[j] ==  A[i] -1 )
		{
			ans = max(ans , 1+ lis(j));
		}
	}
	save[i] = ans;
	return ans;
}
int main()
{
    int stc;
    cin>>stc;
    for(int tc=1; tc<= stc; tc++)
    {
    cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>A[i];
		save[i] = -1;
	}
	int rs=0;
	for(int i=1;i<=n;i++)
	{
		int tmp= lis(i);
		if(tmp > rs) rs= tmp;
	}
	cout<<rs<<endl;
    }

}
