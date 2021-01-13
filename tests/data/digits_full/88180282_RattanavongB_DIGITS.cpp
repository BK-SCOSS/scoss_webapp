#include <iostream>
#include <string>
// #include <astream>
using namespace std;

int n; x[55], mark[55];
int m;
int hust, soict;
int sum = 0;
int num;
bool check (){
 //for(int i =1; i<=n; ++i) cout <<x[i] <<"\n"[i==n];
 string H = to_string(x[1]) + to_string(x[2]) + to_string(x[3]) + to_string(x[4]);
 string S = to_string(x[3]) + to_string(x[5]) + to_string(x[6]) + to_string(x[7]) + to_string(x[4]);
 string h1 = to_string(x[1]);
 string s1 = to_string(x[3]);
 hust = stoi(H);
 soict = stoi(S);
 if((stoi(h1) !=0) && (stoi(s1) !=0) && (hust + soict ==sum)){
 return true;
 }
 else return false;
 }
 void backtrack(int i){
 if(1>n){
  if (check())num++;
  return;
 }
 for(int t=0; t<=m; ++t){
 if(mark[t] == 0){
 mark[t]=1;
 x[i]=t;
 backtrack(i+1);
 mark[t]=0;
 }

 }
 }
 int main(){
 n=7;
 m=9;
 int t;
 cin>>t;
 while (t--)
 }
 cin >>sum;
 cout<<sum;
 num=0;
 backtrack(1);
 cout<<"\n";
 cout<<num << "\n";
 }
 return(0);
 }
