#include <iostream>
#include<algorithm>
#include<stack>

using namespace std;
std::stack<int> B;
std::stack<int> C;
int T;
int ans=0;
int n;
int cnt;
int a[1000000];

void solve(int x){







    for(int i=0;i<n;i++){
            B.push(a[i]);
            cnt=0;

            for(int j=0;j<n;j++){
        if(a[i]==a[j]+1){
            B.push(a[j]);
            solve(x+(j-i));
        }





        }
      }

  cnt=B.size() ;
    C.push(cnt);
    while (!B.empty())
    {
        B.pop();
       ;
    }

}

int main()

{
    int k[1000];

    cin>>T;




    for(int i=0;i<T;i++){
        cin>>n;
        for(int j=0;j<n;j++)
        cin>>a[j];

    }
    solve(0);
    while(!C.empty()){
    for(int i=0;i<n;i++){
        C.top()=k[i];
        C.pop();
    }
}
for(int i=0;i<n;i++){
    ans=max(ans,k[i]);
}
cout<<ans;
}


