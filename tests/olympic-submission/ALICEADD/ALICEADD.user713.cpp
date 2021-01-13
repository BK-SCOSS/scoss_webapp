#include <iostream>
#include <string>
#include <queue>

using namespace std;
int main(){
    int t;
    cin>>t;
    queue<unsigned long long> q, q1; 
    while(t--){

      unsigned long long a, b, c;
        cin>>a>>b;
    unsigned long long fff0=a%10;
    unsigned long long fff1=(a-fff0)/10;
    unsigned long long ff0=b%10;
    unsigned long long ff1=(b-ff0)/10;
    unsigned long long f0= (fff0+ff0) %10;
    unsigned long long f1= (fff0+ff0-f0)/10;
    f1=fff1+ff1+f1;
    
    q1.push(f1);
    q.push(f0);
    }
    while(!q.empty()){
      if(q1.front()>0) cout<<q1.front();
      cout<<q.front();
      q1.pop();
      q.pop();
      cout<<endl;
    }
}