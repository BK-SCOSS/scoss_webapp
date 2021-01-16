#include <iostream>
#include <set>
using namespace std;

int main(){
    int cas;
    cin >> cas;
    set<int> a;
    int n,m;
    int tmp;
    int cnt;
    while(cas--){
        cnt=0;
        
        cin >> n;
        
        a.clear();
        for(int i=0; i<n; i++){
            cin >> tmp;
            a.insert(tmp);
        }
        cin >> m;
        int siz=a.size();
        for(int i=0; i<m; i++){
            cin >> tmp;
            
            a.insert(tmp);
            if(a.size()==siz){
                cnt++;
            }else{
                siz++;
            }
            
        }
        cout << cnt << endl;
    }
}