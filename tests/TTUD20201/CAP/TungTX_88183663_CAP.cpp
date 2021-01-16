#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
using namespace std;

//int cap(int n, set<int> a, int m, set<int> b)
//{
//    set<int> c;
//    for(int i:a){
//        for(int j:b){
//            if(i==j){
//                c.insert(i);
//                break;
//            }
//        }
//    }
//    return c.size();
//}

int main()
{
    ios_base::sync_with_stdio(0);
    int T; cin>>T;
    int n,m;
    int temp;
    vector<int> result;
    for(int t=0;t<T;++t){
        set<int> a;
        set<int> b;
        //nhap a,b
        cin>>n;
        for(int i=0;i<n;++i){
            cin>>temp;
            a.insert(temp);
        }
        cin>>m;
        for(int i=0;i<m;++i){
            cin>>temp;
            b.insert(temp);
        }

        set<int> c;
        for(int i:a){
            for(int j:b){
                if(i==j){
                    c.insert(i);
                    break;
                }
            }
        }
        result.push_back(c.size());
    }
    for(auto i:result) cout<<i<<endl;
}
