using namespace std;
#include<bits/stdc++.h>
#include<iostream>
#include<iomanip>
#define FOR(i,a,b) for(int i=(a),b_=(b);i<b_;++i)
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define openfile ({freopen("in.inp","r",stdin);freopen("ou.out","w",stdout);})

#define N 100005


int n;
int a[N];
int test;
int tmp;
int result;
int main(){	
	int c[1000];
	int dem=0;
    cin >> test;
    vector<int> u,v;
    FOR(k,0,test)
    {
        cin >> n;
        FOR(i,0,n) cin >> a[i];
        vector<int> u(a,a+n);
        int j = 0;
        int result = 0;
        int tmp = 0;
        int flag = 0;
        //cout << u.size() << " "<<u.back();
        while (flag == 0)
        {
            int tmp = 0;
            int j=0;
            while (j<u.size())
            {
                //cout << u[j] << " ";
                if (j==u.size()-1) break;
                v.push_back(u[j]+u[j+1]);
                //cout << u[j] + u[j+1] << " ";
                tmp = max(tmp, u[j]+u[j+1]);
                j+=2;
            }
            if (u.size()%2 == 1)
            {
                v.push_back(u.back());
               // tmp = max (tmp, u.back());
            }
            result += tmp;
            u.clear();
            vector<int>::iterator it;
            for (it = v.begin(); it != v.end(); it++)
                {
                    u.push_back(*it);
                    //cout << u.back() << " ";
                }
            v.clear();
            if (u.size()==1) flag = 1;
        }
        c[dem]=result;
		dem++;
    }
    for(int i=0;i<dem;i++){
		cout<<c[i]<<endl;
	}	
}
