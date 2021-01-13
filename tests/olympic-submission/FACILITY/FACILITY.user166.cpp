#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;
const int maxN = 2e6 + 19;
typedef pair<int,int> ii;
typedef pair<ii,int> iii;
//vector<iii> arr ; vector<int> b;
iii arr[maxN] ;
int b[maxN] , End;
ll root[maxN];
//vector<int> c;
int c[maxN];
void updateRoot(int x , ll key){
    while(x <= maxN - 2){
        root[x] = max(root[x],key);
        x += x & (-x);
    }
}
ll getRoot(int x){
    ll ans = 0;
    while(x > 0){
        ans = max(ans , root[x]);
        x -= x & (-x);
    }
    return ans;
}
int main()
{
    //ios_base::sync_with_stdio(false);cin.tie(0);
    int n , k;
    //cin >> n >> k;
    scanf("%d%d",&n,&k);
    int convert = 0;
    for(int i = 1 ; i <= n ; ++i){
        int x , y , z;
        //cin >> x >> y >> z;
        scanf("%d%d%d",&x,&y,&z);
        //b.push_back(x);
        b[i*2-1] = x;
        b[i*2] = x + y + k;
        //b.push_back(x + y + k);
        arr[i] = iii(ii(x,x+y+k),z);
    }
    End = 0;
    sort(b + 1 , b + 2 * n + 1);
    //c.push_back(b[1]);
    c[++End] = b[1];
    for(int i = 2 ; i <= 2 * n ; ++i){
        if(b[i] != b[i-1]) c[++End] = b[i];
    }
    sort(c + 1 , c + End + 1);
    int x, y , z , xx , yy , zz ;
    for(int i = 1 ; i <= n ; ++i){

        x = arr[i].first.first;
        y = arr[i].first.second;
        z = arr[i].second;
        xx = lower_bound(c + 1,c + End + 1 , x) - c;
        yy = lower_bound(c+1,c + End + 1, y) - c;
        arr[i] = iii(ii(xx , yy) , z);

    }
    sort(arr+1 ,arr+n+1);
    long long ans = 0;
    for(int i = 1 ; i <=n ;i++){
        ll tmp = getRoot(arr[i].first.first) + arr[i].second;
        ans = max(ans , tmp);
        updateRoot(arr[i].first.second, tmp);
    }
    cout << ans;
    return 0;
}
