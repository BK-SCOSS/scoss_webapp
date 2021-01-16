#include <iostream>
#include <vector>
using namespace std;
int main(){
    vector<int> a;
    int T,n,tg;
    cin>> T;
    while(T>0){
        T--;
        cin>> n;
        for(int i=0;i<n;i++){
            scanf("%d",&tg);
            a.push_back(tg);
        }
        int total_time = 0;
        int time = 0;
        while(a.size()!=1){
            vector<int> b;
            time = 0;
            int len = a.size();
            for(int i=0;i<len-1;i+=2){
                time = max(time, a[i]+a[i+1]);
                b.push_back(a[i]+a[i+1]);
            }
            if(len%2!=0){
                b.push_back(a[len-1]);
            }
            total_time+= time;
            a = b;
        }
        cout<< total_time<< endl;
    }
    return 0;
}
