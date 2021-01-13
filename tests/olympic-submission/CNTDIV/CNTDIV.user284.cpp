//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>
#include <set>
#include <vector>
// #define pair<int,int> ii;
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
using namespace std;
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int n;
vector<pair<int,int> > s;
unsigned long long t;
set<unsigned long long> d;
vector<int> p;
int res;
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void bt(int i,unsigned long long q){
	if (q>=t) return;
	if (i==(int)s.size()){
		if (t%q!=0) {
			// res++;
			// p.push_back((int)q);
			d.insert(q);
			// cout<<q<<' ';
		}
		return;
	}
	for (int j=0;j<=s[i].second;j++){
		if ((float) q*pow(s[i].first,j)>t*2) break;
		bt(i+1,q*pow(s[i].first,j));
	} 
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void solve1(){
	for (int i=n;i<=n+2;i++) {
		int u=i;
		for (int j=2;j*j<=u;j++) if (u%j==0){
			bool stop=false;
			for (int k=0;k<=(int)s.size()-1;k++) if (s[k].first==j){
				stop=true;
				while (u%j==0){
					u/=j;
					s[k].second++;
				}
				break;
			}
			if (!stop){
				s.push_back(make_pair(j,0));
				while (u%j==0){
					u/=j;
					s[s.size()-1].second++;
				}
			}
		}
		if (u>1) {
			bool stop=false;
			for (int i=0;i<=(int)s.size()-1;i++) if (s[i].first==u){
				stop=true;
				s[i].second++;
			}
			if (!stop) s.push_back(make_pair(u,1));
		}
	}
	for (int i=0;i<=(int)s.size()-1;i++) s[i].second*=2;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void solve2(){	
    res=0;
	bt(0,1);
	// sort(p.begin(),p.end());
	// for (int i=0;i<=(int)p.size()-1;i++) cout<<p[i]<<' ';
	cout<<d.size()<<endl;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void solve3(){
	res=0;
	for (int i=1;i<=t-1;i++) if (t*t%i==0&&t%i!=0) res++;
	cout<<res<<endl;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int main(){
    // freopen("2.txt","r",stdin);
    int q;
    cin>>q;
    for (int i=1;i<=q;i++){
    	d.clear();
    	p.clear();
    	s.clear();
    	// cout<<d.size()<<p.size()<<endl;
        cin>>n;
        t=n*(n+1)*(n+2);
        solve1();
        solve2();
        // solve3();
    }
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~