#include<bits/stdc++.h>

using namespace std;
long long a[100000];
int n, T;
int main(int argc, char const *argv[]){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    cin >> n;
    long long  temp = 0;
    int count = 1, max = 0;
    for(int t =0 ;t < T;t++){
    for(int i = 0; i < n;i++){
    	cin >> a[i];
	}
	for(int i = 0; i < n;i++){
		temp = a[i];
    	for(int j = i + 1; j < n;j++){
    		if((temp+1) == a[j]){
   				count++;
   				temp++;

   			}
   			if(max < count)
   				max = count;
		}
		count = 1;
	}
    cout << max;
}
    return 0;
}
