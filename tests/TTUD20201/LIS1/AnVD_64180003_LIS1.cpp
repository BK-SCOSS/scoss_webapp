#include<bits/stdc++.h>
using namespace std;

int main(){
	int t, n;
	int arr[100005];
	int max_result=1;
	map <int, int> memo;
	scanf("%d", &t);
	
	for(int i=0; i<t; ++i){
		memo.clear();
		max_result=1;
		scanf("%d", &n);
		for(int j=0; j<n; ++j){
			scanf("%d", arr+j);
		}
			
		memo.insert(make_pair(arr[0], 1));
		for(int l=1; l<n; ++l){
			int temp=arr[l]-1, current;
//			if(memo.find(temp+1) != memo.end()){
//				current = memo[temp+1];
//			}
//			else if(memo.find(temp) != memo.end()){
//				current = memo[temp] + 1;
//				memo.insert(make_pair(temp+1, current));
//			}
//			else{
//				current = 1;
//				memo.insert(make_pair(temp+1, current));
//			}

			if(memo.find(temp) != memo.end()){
				if(memo.find(temp+1) != memo.end()){
					if(memo[temp+1] < memo[temp]+1){
						memo[temp+1] = memo[temp] + 1;
					}
				}
				else{
					memo.insert(make_pair(temp+1, memo[temp]+1));
				}
				current = memo[temp+1];
			}
			else{
				memo.insert(make_pair(temp+1, 1));
				current = 1;
			}
			max_result = max(max_result, current);
		}
		cout << max_result << endl;
	}
}
