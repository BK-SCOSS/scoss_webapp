#include<bits/stdc++.h>
using namespace std;

int n, L, s, t;
unsigned long long counter=0;
vector <vector <int>> edge;
int *visit;
int *x;

void Try(int k){
	if(x[k-1] == t){
		counter++;
	}
	else{
		for(int i: edge[x[k-1]]){
			if(visit[i] == 0){
				visit[i] = 1;
				x[k] = i;
				Try(k+1);
				visit[i] = 0;
			}
		}
	}
}

int main(){
	cin >> n >> L >> s >> t;
	s--;
	t--;
	for(int i=0; i<3*n; ++i){
		vector <int> temp;
		edge.push_back(temp);
	}

	for(int i=1; i<n; ++i){
		edge[3*i].push_back(3*i+1);
		edge[3*i].push_back(3*i+2);
		edge[3*i].push_back(3*i-1);
		edge[3*i-1].push_back(3*i);
		edge[3*i+1].push_back(3*i);
		edge[3*i+2].push_back(3*i);
	}
	
	edge[0].push_back(1);
	edge[0].push_back(2);
	edge[0].push_back(3*n-1);
	edge[1].push_back(0);
	edge[2].push_back(0);
	edge[3*n-1].push_back(0);
	
	visit = new int[3*n];
	for(int i=0; i<3*n; ++i)
		visit[i] = 0;
	
	x = new int[3*n];
	x[0] = s;
	Try(1);
	cout << counter << endl;
}
