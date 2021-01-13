// C++ program for weighted job scheduling using Naive Recursive Method 
#include <iostream> 
#include <algorithm> 
using namespace std; 
  
// A job has start time, finish time and profit. 
struct Job 
{ 
    int start, finish, profit; 
}; 
  
// A utility function that is used for sorting events 
// according to finish time 
bool jobComparataor(Job s1, Job s2) 
{ 
    return (s1.finish < s2.finish); 
} 
  
// Find the latest job (in sorted array) that doesn't 
// conflict with the job[i]. If there is no compatible job, 
// then it returns -1. 
int latestNonConflict(Job arr[], int i) 
{ 
    for (int j=i-1; j>=0; j--) 
    { 
        if (arr[j].finish <= arr[i-1].start) 
            return j; 
    } 
    return -1; 
} 
  
// A recursive function that returns the maximum possible 
// profit from given array of jobs.  The array of jobs must 
// be sorted according to finish time. 
int findMaxProfitRec(Job arr[], int n) 
{ 
    // Base case 
    if (n == 1) return arr[n-1].profit; 
  
    // Find profit when current job is inclueded 
    int inclProf = arr[n-1].profit; 
    int i = latestNonConflict(arr, n); 
    if (i != -1) 
      inclProf += findMaxProfitRec(arr, i+1); 
  
    // Find profit when current job is excluded 
    int exclProf = findMaxProfitRec(arr, n-1); 
  
    return max(inclProf,  exclProf); 
} 
  
// The main function that returns the maximum possible 
// profit from given array of jobs 
int findMaxProfit(Job arr[], int n) 
{ 
    // Sort jobs according to finish time 
    sort(arr, arr+n, jobComparataor); 
  
    return findMaxProfitRec(arr, n); 
} 
  
// Driver program 
int main() 
{ 
    Job arr[1000001];
    int n,k;
    cin>>n>>k;
    for (int i=0;i<n;i++){
        int s,d,r;
        cin>>s>>d>>r;
        arr[i]={s,d+k,r};
    }
    
    cout << "The optimal profit is " << findMaxProfit(arr, sizeof(arr)/sizeof(arr[0])); 
    return 0; 
}