#include <iostream>
#include <vector>
using namespace std;

int main()
{
    unsigned long long n;
    vector<unsigned long long> answer;
    unsigned long long Acandy,Bcandy;
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>Acandy;
        cin>>Bcandy;
        answer.push_back(Acandy+Bcandy);
    }
    for(int i = 0; i < n; i++){
        cout<<answer[i]<<endl;
    }

    return 0;
}
