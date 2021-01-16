#include<bits/stdc++.h>
using namespace std;

int t,n,i,j,a[101010],f[101010],ans;
int b[1000001];

int main()
{
	cin>>t;
	while (t--)
	{
		ans=0;
		
		cin>>n;
		for (i=1;i<=n;i++) cin>>a[i];
		
		if (n<1001)
		{
			f[1]=1;
			for (i=2;i<=n;i++)
			{
			f[i]=1;
			for (j=1;j<i;j++) if (a[i]==a[j]+1)
			{
				f[i]=max(f[i],f[j]+1);
			}
			}
			for (i=1;i<=n;i++) ans=max(ans,f[i]);
		}
		else 
		{
			int x;
			for (i=0;i<=1000000;i++) b[i]=0;
			b[a[1]]=1;
			
			for (i=2;i<=n;i++)
			{
				x=a[i];
				b[x]=1;
				if (b[x-1]>=1) b[x]=max(b[x-1]+1,b[x]);
			}
			
			for (i=1;i<=n;i++) ans=max(ans,b[a[i]]);
		}
		
		cout<<ans;
	}	
	return 0;
}

