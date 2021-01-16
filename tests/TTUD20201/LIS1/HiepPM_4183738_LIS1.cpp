#include <iostream>
#include <climits>

using namespace std;
int n, t;
// Iterative function to find length of longest increasing subsequence
// of given array
int LIS(long long arr[], int n)
{
    // array to store sub-problem solution. L[i] stores the length
    // of the longest increasing subsequence ends with arr[i]
    int L[n] = { 0 };

    // longest increasing subsequence ending with arr[0] has length 1
    L[0] = 1;

    // start from second element in the array
    for (int i = 1; i < n; i++)
    {
        // do for each element in subarray arr[0..i-1]
        for (int j = 0; j < i; j++)
        {
            // find longest increasing subsequence that ends with arr[j]
            // where arr[j] is less than the current element arr[i]

            if (arr[j] + 1 == arr[i] && L[j] > L[i])
                L[i] = L[j];
        }

        // include arr[i] in LIS
        L[i]++;
    }

    // find longest increasing subsequence (having maximum length)
    int lis = INT_MIN;
    for (int x : L)
        lis = max(lis, x);

    return lis;
}
void input(long long arr[]){

    for(int i = 0; i < n; i++) cin >> arr[i];
}

int main()
{
    cin >> t;
    while(t--){
        cin >> n;
        long long arr[n];
        input(arr);
        cout << LIS(arr, n) << endl;

    }



    return 0;
}




