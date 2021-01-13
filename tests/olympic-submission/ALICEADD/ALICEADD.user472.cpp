#include <iostream>
#include <string>
using namespace std;

int main()
{
  int t;
  unsigned long long a[10];
  unsigned long long b[10];
  unsigned long long sum[10];
  cin >> t;
  for(int i=0;i<t;i++){
      cin >> a[i];
      cin >> b[i];
      sum[i] = a[i]+b[i];
  }
  for(int i=0;i<t;i++){
      cout << sum[i] << endl; 
  }
  return 0;
}