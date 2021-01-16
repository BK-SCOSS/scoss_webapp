#include<bits/stdc++.h>
using namespace std;


int lis1(long long arr[], int n)
{

    int dp[n];
    for (int i = 0; i< n; i++)
        dp[i] = 1;


    for (int i=1; i<n; i++)
    {

        for (int j=0; j<i; j++)
        {

            if (arr[i] == arr[j]+1)

                dp[i] = max(dp[i], dp[j]+1);
        }
    }


    int result = 1;
    for (int i = 0 ; i < n ; i++)
        if (result < dp[i])
            result = dp[i];
    return result;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie();
    int T,n;
    cin>>T;
    for(int t=0;t<T;t++){
       cin>>n;
       long long arr[n];
       for(int i=0;i<n;i++){
         cin>>arr[i];
       }
       cout << lis1(arr, n);
    }
    return 0;
}

