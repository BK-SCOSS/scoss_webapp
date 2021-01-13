#include <iostream>
using namespace std;
int main(){
    int n;
    cout<<""; cin>>n;
    if( n<10000 || n> 99999 || n%2!=0 ) return 0;
    else {
        int s = n/10000;
        int t = (n%10)/2;
        int count =0;
        int c = (n%100)/10 - s;
        int ho = (n%10000)/1000;
        int ui = (n%1000)/100;
        // cout<<s<<endl;
        // cout<<t<<endl;
        // cout<<ho<<endl;
        // cout<<ui<<endl;
        for(int h=0; h<=ho && h!=s && h!=t && h!=c; ++h){
            int o= ho -h;
            if(o!=s && o!=t && o!=c && o!=h){
                for(int u=0; u<= ui && u!=s && u!=t && u!=c && u!= h && u!= o; ++u){
                    int i = ui -u;
                    if(i!=s && i!=t && i!=c && i!= h && i!= o && i!=u) {
                        ++count;
                    }
                }
            }
        }
        cout<<count;
    }
    
    return 0;
}