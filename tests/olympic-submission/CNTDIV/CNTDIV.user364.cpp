#include<iostream>
#include<vector>
using namespace std;
void dequi(long long x,long long y,vector<int> v,vector<int> dem,int& cnt,int u)
	{
		for(int i=u;i<v.size();i++)
			{
					if (dem[i]==0) continue;
					y=y*v[i];
//					cout<<u<<" "<<y<<" "<<cnt<<endl;
					dem[i]--;
					if(y>=x) return;
					if(x%y!=0) cnt++;
					dequi(x,y,v,dem,cnt,i);
					y=(int)y/v[i];
					//dem[i]++;
			}
	}
int main()
{
	int t;
	int n;
	cin>>t;
	for(int i=0;i<t;i++)
		{
			cin>>n;
			int cnt=0;
			long long k;
			vector<int> v(0),dem(0),cs(n+2);
			long long j=2;
			k=n*(n+1)*(n+2);
			long long q=k;
			while(k!=1)
				{
					if (k%j==0)
					{
					v.push_back(j);
					dem.push_back(0);
					while(k%j==0)
						{
							k=k/j;
					//		cout<<k<<" "<<dem.size()-1<<endl;
							dem[dem.size()-1]+=2;
						}
					}
			//		dem[dem.size()-1]=dem[dem.size()-1]*2;
					j++;
				}
		//	for(int i=0;i<v.size();i++) cout<<dem[i]<<" "<<v[i]<<endl;
			dequi(q,1,v,dem,cnt,0);
			cout<<cnt<<endl;			
		}	
	return 0;
}
