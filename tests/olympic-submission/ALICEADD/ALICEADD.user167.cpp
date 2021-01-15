#include <iostream>

using namespace std;

int main()
{
    int64_t a;
    int64_t b;
    int64_t res[100];
    int test;
    cin>>test;
    for (int i=0;i<test;i++){
        cin>>a>>b;
        res[i]=a+b;
    }

    for (int i=0;i<test;i++) cout<<res[i]<<endl;
    return 0;
}
