#include <iostream>
#include <vector>

using namespace std;
const int maxN = 1e6 + 190;
typedef pair<int,int> ii;
int flag[maxN] , Count[maxN] , Size;
void Split(int N){
    Size = 0;
    int x = N , y = N + 1 , z = N + 2;
    for(int i = 2 ; i <= maxN ; ++i){
        if(x % i == 0 || y % i == 0 || z % i == 0){
            Size++;
            Count[Size] = 0;
            while(x % i == 0){
                x /= i;
                Count[Size]++;
            }
            while(y % i == 0){
                y /= i;
                Count[Size]++;
            }
            while(z % i == 0){
                z /= i;
                Count[Size]++;
            }
        }
        if(flag[x] == flag[y] && flag[y] == flag[z] && flag[z] == 1) break;
    }
    if(x != 1){
        Size++;
        Count[Size] = 1;
    }
    if(y != 1){
        Size++;
        Count[Size] = 1;
    }

    if(z != 1){
        Size++;
        Count[Size] = 1;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    int Q;
    cin >> Q;
    flag[1] = 1;
    for(int i = 2 ; i <= 1e6 + 10 ; ++i){
        if(flag[i] == 0){
            flag[i] = 1;
            for(int j = 2 ; j * i <= 1e6 + 10 ; ++j){
                flag[i*j] = 2;
            }
        }
    }
    int N;
    for(int x = 0 ; x < Q ; ++x){
        //for(int i = 0 ; i < Size ; ++i) Count[i] = 0;
        cin >> N;
        Split(N);
        long long ans2 = 1 , ans1 = 1;
        for(int i = 1 ; i <= Size ; ++i) {
            ans2 *= Count[i] * 2 + 1;
            ans1 *= Count[i] + 1;
        }
        long long ans = ans2 - 2 * ans1 + 1;
        cout << ans / 2 << endl;

    }
    return 0;
}
