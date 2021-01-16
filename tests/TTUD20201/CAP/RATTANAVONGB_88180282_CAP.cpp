#include <iostream>

using namespace std;

	main()
	{
		int t;
		cin >> t;
		while(t--)
		{
			int n;
		cin >> n;
			int a[1000];
			for(int i=1;i<=n;i++)
			cin>>a[i];
			int m;
			cin>>m;
			int b[1000];
			for(int i=1;i<=m;i++)
			cin>>b[i];
			int res =0;
			for(int i=1 ;i<=n;i++)
			{
				for(int j=1;j<=m;j++){
			if(a[i]==b[j]) res++;
				}
			}
			cout<<res<<endl;
		}
		
	}


