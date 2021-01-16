#include<bits/stdc++.h>
using namespace std;
int T,n,ans, max_tmp, length, sum;
int a[100007], b[100007], v;

int main(){
//    ios_base:: sync_with_stdio(0);
//    cin.tie(0);
    // freopen("in.txt", "r", stdin);
    cin >> T;
    for(int k = 0; k < T; k++) {
        cin >> n;
        for(int i = 0;i < n;i++) cin >> a[i];
        
        ans = 0;
        length = n;
        max_tmp = 0;
        sum = 0;
        while(length > 1) {
            bool le = length % 2;
            length = (length+1)/2;
            // cout << "length " << length << endl;
            if(le) a[2*length - 1] = 0;
            // cout << endl << "b[]" << endl;
            for(int i = 0; i < length; i++) {
                b[i] = a[2*i] + a[2*i+1];
                // cout << b[i] << " ";
                if(i == length - 1 && le) continue;
                if(b[i] > max_tmp) max_tmp = b[i];
            }
            sum += max_tmp;
            for(int i = 0; i < length; i++) {
                a[i] = b[i];
            }
        }

        cout << sum << endl;
    }
}
