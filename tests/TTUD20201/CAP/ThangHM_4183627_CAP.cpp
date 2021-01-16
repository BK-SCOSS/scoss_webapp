#include <iostream>
#include<algorithm>
#include<stack>

using namespace std;

int main()
{
stack <int> B;
const int M=100000;
int n,m;
int a[M];
int b[M];
int cnt;

int T;
cin >>T;


    for(int i=0;i<T;i++){

        cin>>n;
        for(int j=0;j<n;j++)
        cin>>a[j];
        cin>>m;
        for(int j=0;j<m;j++)
            cin>>b[j];}

    for(int p=0;p<T;p++){
            int cnt=0;

            for(int i=0;i<n;i++){

            for(int j=0;j<m;j++){

                if(a[i]==b[j]){

                        cnt++;



            }}}
B.push(cnt);
}


while (!B.empty())
    {
        cout << '\t' << B.top();
       B.pop();
    }

return 0;}


