#include <iostream> 
 using namespace std;
 int main(int argc, char *argv[]) 
 { 
  int n,a,b;
  
  cin>>n; 
  int C[n-1];
  for(int i=0; i<n; i++) {
  	cin>>a>>b;
  	C[i]=a+b;
  } 
   for(int i=0; i<n; i++){
   	cout<<C[i]<<"\n";
   }
  
  return 0; 
 }
