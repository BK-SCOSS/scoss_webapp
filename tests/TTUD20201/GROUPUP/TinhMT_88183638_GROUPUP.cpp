#include <iostream>
#include <vector>
using namespace std;
int n;
int c=0;
void Tim(vector<int> a){
    if( a.size() == 1)
        return;
    vector<int> b;
    int tmpM = 0;
    int tmp;
    int s = a.size();
    if( s % 2 == 0){
        int i = 0;
        while( i< s ){
            tmp = a[i] + a[i+1];
            tmpM = max(tmpM, tmp);
            b.push_back(tmp);
            i= i+2;
        }
        c+= tmpM;
    }
    else{
        int i = 0;
        while( i != s -1 ){
            tmp = a[i] +a[i+1];
            tmpM = max(tmpM, tmp);
            b.push_back(tmp);
            i= i+2;
        }
        b.push_back(a[i]);
        c += tmpM;
    }
    Tim(b);
}
int main()
{
    int t;
    cin>>t;
    int x;
    vector<int> rs;
    int i;
    while(t--){
        cin>>n;
        vector<int> a;
        c=0;
        for( i =0; i< n;i++){
            cin>>x;
            a.push_back(x);
        }
        Tim(a);
        //rs.push_back(c);
        cout<<c<<endl;
    }
//    for( i=0; i< rs.size(); i++){
//        cout<< rs[i]<<endl;
//    }
    return 0;
}
