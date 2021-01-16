/*

 * @author SangND
 * IT2 - 03
 * HUST - K63
 * -- Must try to do something for the future and someone --

				 ─────▄██▀▀▀▀▀▀▀▀▀▀▀▀▀██▄─────
				 ────███───────────────███────
				 ───███─────────────────███───
				 ──███───▄▀▀▄─────▄▀▀▄───███──
				 ─████─▄▀────▀▄─▄▀────▀▄─████─
				  ████──▄████─────████▄──█████
				 █████─██▓▓▓██───██▓▓▓██─█████
				 █████─██▓█▓██───██▓█▓██─█████
				 █████─██▓▓▓█▀─▄─▀█▓▓▓██─█████
				 ████▀──▀▀▀▀▀─▄█▄─▀▀▀▀▀──▀████
				 ███─▄▀▀▀▄────███────▄▀▀▀▄─███
				 ███──▄▀▄─█──█████──█─▄▀▄──███
				 ███─█──█─█──█████──█─█──█─███
				 ███─█─▀──█─▄█████▄─█──▀─█─███
				 ███▄─▀▀▀▀──█─▀█▀─█──▀▀▀▀─▄███
				 ████─────────────────────████
				 ─███───▀█████████████▀───████
				 ─███───────█─────█───────████
				 ─████─────█───────█─────█████
				 ───███▄──█────█────█──▄█████─
				 ─────▀█████▄▄███▄▄█████▀─────
				 ──────────█▄─────▄█──────────
				 ──────────▄█─────█▄──────────
				 ───────▄████─────████▄───────
				 ─────▄███████───███████▄─────
				 ───▄█████████████████████▄───
				 ─▄███▀───███████████───▀███▄─
				 ███▀─────███████████─────▀███
				 ▌▌▌▌▒▒───███████████───▒▒▐▐▐▐
				 ─────▒▒──███████████──▒▒─────
				 ──────▒▒─███████████─▒▒──────
				 ───────▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒───────
				 ─────────████░░█████─────────
				 ────────█████░░██████────────
				 ──────███████░░███████───────
				 ─────█████──█░░█──█████──────
				 ─────█████──████──█████──────
				 ──────████──████──████───────
				 ──────████──████──████───────
				 ──────████───██───████───────
				 ──────████───██───████───────
				 ──────████──████──████───────
				 ─██────██───████───██─────██─
				 ─██───████──████──████────██─
				 ─███████████████████████████─
				 ─██─────────████──────────██─
				 ─██─────────████──────────██─
				 ────────────████─────────────
				 ─────────────██──────────────
-  Play with me and enjoy coding...

------------------------------------------------------------------------
- *** Everything will be okay in the end
-   If it isn't okay, it isn't the end ***
			-- From someone who has been --

*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <assert.h>
#include <algorithm>
#include <math.h>
#include <string.h>
#include <limits.h>
#include <numeric>
#include <chrono>
#include <random>
#include <functional>
#include <tuple>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <list>
#include <array>
#include <bitset>
#include <unordered_map>

#define lb lower_bound
#define up upper_bound
#define ll long long
#define ull unsigned long long
#define pb push_back
#define pob pop_back
#define fs first
#define sd second
#define gcd __gcd
#define endl "\n"
#define NDS ios_base::sync_with_stdio(false);cin.tie(0);
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<ll> vl;
typedef vector<vl> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int Max = 1e5 + 1;

vector<int> a;
int n, x;
void solve(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x;
        a.pb(x);
    }
    int maxs = 0;
    int ans = 0;
    while(a.size() > 1){
        for(int i = 0; i < a.size(); i++){
            if(i%2 == 1){
                a[i] += a[i - 1];
                maxs = max(maxs, a[i]);
            }
        }

        if(a.size()%2 == 0){
            for(int i = a.size() - 1; i >= 0; i--){
                if(i%2 == 0){
                    a.erase(a.begin() + i, a.begin() + i + 1);
                }
            }
        }
        else{
            for(int i = a.size() - 2; i >= 0; i--){
                if(i%2 == 0){
                    a.erase(a.begin() + i, a.begin() + i + 1);
                }
            }
        }
        ans += maxs;
        maxs = 0;
    }
    cout << ans << endl;
    a.clear();
}

int main () {
	NDS
    int t;
    cin >> t;
    while(t--){
        solve();
    }

}
