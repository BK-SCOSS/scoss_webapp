#include <bits/stdc++.h>

using namespace std;
int main()
{
   int T ;
   cin >>T ;
   while(T>=1){
   int n ;
   int m ;
   cin>>n ;
   int a[n] ;
   for (int k =0;k<n;k++){
	 cin >>a[k];
   }
   cin>>m;
   int b[m];
   for (int k =0;k<m;k++){
	cin >>b[k] ;
   }
   set<int> giaonhau ;
  for (int i=0;i<n;i++){
	 for (int j =0 ;j<m ;j++){
		if(a[i]==b[j]) giaonhau.insert(a[i]);
	 }
  }
  cout <<giaonhau.size();

   T-- ;
}
   return 0;

}
