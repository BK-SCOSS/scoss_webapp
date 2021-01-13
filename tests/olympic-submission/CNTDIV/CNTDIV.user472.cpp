#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int Uoc(int N)
{
    int count = 0;
    for (int i = 1; i < N; i++)
    {
        if (N*N % i == 0){
            if(N%i!=0){
                count++;
            }
            
        }
    }
    return count;
}
int main()
{
    int n;
    int count;
    int a[100];
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=0;i<n;i++){
        count = Uoc(a[i]*(a[i]+1)*(a[i]+2));
        cout << count << endl;
    }
    
  return 0;
}