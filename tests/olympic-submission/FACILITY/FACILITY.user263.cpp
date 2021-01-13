#include<bits/stdc++.h>
#define MAX 10000000
using namespace std;

typedef struct {
    int x;
    int y;
    int z;
}don;

don d[MAX];
set<int> s[MAX];

int n, k;

bool check(don d1, don d2){
    if(d2.x<=d1.x && d1.x<=d2.y) return true;
    if(d2.x<=d1.y && d1.y<=d2.y) return true;
    return false;
}

int main(){
    int tmp;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>d[i].x>>tmp>>d[i].z;
        d[i].y=d[i].x+tmp+1;
    }
    set<int>::iterator it;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(!check(d[i], d[j]))
                if(s[i].empty())
                    s[i].insert(j);
                else{
                        int index=1;
                    for(it=s[i].begin();it!=s[i].end();it++){
                        if(check(d[j], d[*it])){
                            index=0; break;
                        }
                    }
                    if(index==1) s[i].insert(j);
                }
        }
    }

    int maxx=0;
    int tam=0;

    for(int i=1;i<=n;i++){
            tam=d[i].z;
        for(it=s[i].begin(); it!=s[i].end(); it++){
            tam+=d[*it].z;
        }
        maxx=max(tam, maxx);
    }

    cout<<maxx;

    return 0;
}
