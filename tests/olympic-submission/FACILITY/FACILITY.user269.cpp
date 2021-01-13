#include<bits/stdc++.h>
using namespace std;

void  sxn(int a[],int b[], int k[], int d, int c)
{
	int i,j,tg;
	i=d;
	j=c;
	tg=a[(d+c)/2];
	while (i<=j)
	{
		while (a[i]<tg) i++;
		while (a[j]>tg) j--;
		if (i<=j)
		{
			swap(a[i],a[j]);
			swap(b[i],b[j]);
			swap(k[i],k[j]);
			i++;
			j--;
		}
	}
	if (i<c) sxn(a,b,k,i,c);
	if (d<j) sxn(a,b,k,d,j);
}

int main(){
    int n,k;
    cin >> n >> k;
    int a[n],b[n],c[n];
    for(int i = 0; i < n; i++){
        cin >> a[i] >> b[i] >> c[i];
    }

    sxn(a,b,c,0,n-1);
    int dp[n];
    for(int i = 0; i < n; i++){
        dp[i] = c[i];
    }
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(a[j] >= a[i] + b[i] + k) dp[j] = max(dp[j], dp[i] + c[j]);
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++) ans = max(ans, dp[i]);
    cout << ans << "\n";
}
