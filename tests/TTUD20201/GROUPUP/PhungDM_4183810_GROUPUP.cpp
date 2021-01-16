#include<bits/stdc++.h>
  using namespace std ;
 int main (){
   int T ;
   cin >>T ;
   while (T>=1){
     int n ;
     cin>>n ;
     int a[n];
     stack<int> S ;
     for (int k =0 ;k<n ;k++){
        cin>>a[k] ;
        int x =a[k] ;
        S.push(x) ;
     }
     vector<int> kq ;
      vector<int> vec ;
    int p = n/2 ;
    for (int l =0 ;l<p ;l++){
     while (!S.empty()){
        int a ,b;

        a= S.top() ; S.pop();
        if (S.empty()){
           vec.push_back(a);
        }else {
          b =S.top();  S.pop();
          int c =a+b ;
          vec.push_back(c) ;
         }
        int maxc =0;
        vector <int> ::iterator iter ;
         for (iter =vec.begin();iter!=vec.end();iter++){
            if (*iter >maxc ) maxc =*iter ;
         }
         kq.push_back (maxc);
     }
      vector <int> ::iterator iter1 ;
      for (iter1=vec.begin();iter1!=vec.end();iter1++) {
         S.push(*iter1) ;
      }

    }
    vector <int> ::iterator iter3 ;
     int result =0 ;
     set<int> save ;
     for (iter3 = kq.begin();iter3!=kq.end();iter3++){
       save.insert(*iter3);
     }
      set<int> ::iterator iter4 ;
     for (iter4= save.begin();iter4!=save.end();iter4++){
         result +=*iter4 ;
     }
   cout<<result ;
   }


}