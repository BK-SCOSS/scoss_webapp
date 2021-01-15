/*==========================================================================================*\
**                        _           _ _   _     _  _         _                            **
**                       | |__  _   _/ | |_| |__ | || |  _ __ | |__                         **
**                       | '_ \| | | | | __| '_ \| || |_| '_ \| '_ \                        **
**                       | |_) | |_| | | |_| | | |__   _| | | | | | |                       **
**                       |_.__/ \__,_|_|\__|_| |_|  |_| |_| |_|_| |_|                       **
\*==========================================================================================*/
//=====================================
//Solution Briefing - Foreword



//=====================================
//Libraries and namespaces
//#include <bits/stdc++.h>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <fstream>
#include <functional>
#include <iostream>
#include <iomanip>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <vector>
#include <utility>

#if __cplusplus >= 201103L
#include <unordered_map>
#include <unordered_set>
#include <random>
#include <chrono>
#endif // __cplusplus

using namespace std;

//#define DEBUG
#define OPTIONAL_FEATURE

//=====================================
//Macroes
#define sp ' '
#define el '\n'
#define task ""
#define maxinp ()
#define fi first
#define se second
#define pb push_back
#define whole(x) x.begin(),x.end()
#define whole_1(x) x.begin()+1,x.end()
#define r_whole(x) x.rbegin(),x.rend()
#define FOR(i, x, y) for(auto i=x; i<=y; ++i)
#define FORl(i, x, y) for(auto i=x; i<y; ++i)
#define FORb(i, x, y) for(auto i=x; i>=y; --i)
#define FORlb(i, x, y) for(auto i=x; i>y; --i)
#define MEMS(x, val) memset(x, val, sizeof(x))
#define what_is(x) cerr << #x << " is " << x << endl;
#define FILEOP()                        \
{                                       \
    freopen(task".inp", "r", stdin);    \
    freopen(task".out", "w", stdout);   \
}
#define FILEOP_DEBUG()                  \
{                                       \
    freopen(task".inp", "r", stdin);    \
    freopen(task".out", "w", stdout);   \
    freopen(task".err", "w", stderr);   \
}

//Macroes - Optional
#ifdef OPTIONAL_FEATURE
    #define pc(x) putchar(x)
    #define gc() getchar()
#endif



//=====================================
//Auxilary Functions and Fast I/O
#ifdef OPTIONAL_FEATURE
    template<class T, class R> T max(const T &__X, const R &__Y)
    {
        return __X > __Y ? __X : __Y;
    }
    template<class T, class R> T min(const T &__X, const R &__Y)
    {
        return __X < __Y ? __X : __Y;
    }
    template<class T, class R> void maximize(T &__X, R __Y)
    {
        __X = __X > __Y ? __X : __Y;
    }
    template<class T, class R> void minimize(T &__X, R __Y)
    {
        __X = __X < __Y ? __X : __Y;
    }
    template<class T> int getBit(T &__X, int __i)
    {
        return ((__X >> __i) & 1) == 1;
    }
    template<class T> bool inRange(T __L, T __R, T __X)
    {
        return __L <= __X && __X <= __R;
    }
    template<class T> T __abs(T __X)
    {
        return (__X < 0) ? -__X : __X;
    }
    template<class T> T __sqr(T __X)
    {
        return T(1) * __X * __X;
    }
#endif
//Fast I/O
template<class T> inline void scan(T &__ret)
{
    __ret = T();
    char c = 0;
    bool neg = 0;

    while(isdigit(c) == 0 && c != '-') c = getchar();
    if(c == '-')
    {
        neg = 1;
        c = getchar();
    }

    for(; isdigit(c) != 0; c = getchar()) __ret = __ret * 10 + c - '0';
    __ret = (neg) ? -__ret : __ret;
}
template<class T> void print(T __X)
{
    if(__X < 0)
    {
        putchar('-');
        __X *= -1;
    }

    if(__X > 9) print(__X / 10);
    putchar(__X % 10 + '0');
}

//=====================================
//Constants



//=====================================
//Typedefs
struct data
{
    typedef long long ll;

    int start, done;
    ll revenue;

    data()
    {
        start = done = 0;
        revenue = 0;
    }
    data(int __start, int __done, ll __rev)
    {
        start = __start;
        done = __done;
        revenue = __rev;
    }

    bool operator< (const data &oth)
    {
        return make_tuple(start, done, revenue) < make_tuple(oth.start, oth.done, oth.revenue);
    }
};


vector<data> vect;
//=====================================
//Typedefs
typedef long long ll;
typedef unsigned long long ull;
typedef tuple<int, int, int> iii;
typedef pair<int, int> ii;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<iii> viii;
typedef vector<vii> vvii;
vvi storage_ends;
vi compress;
vll profits;
int n, K;


//=====================================
//Functions and procedures
//File I/O and utilities
void FileInit()
{
    FILEOP()
}
void FileDebug()
{
    #ifdef DEBUG
        FILEOP_DEBUG()
    #else
        FILEOP()
    #endif
}
void FileClose()
{
    fclose(stdin);
    fclose(stdout);
}


//Enter
void Enter()
{
    int u, v, w;
	scanf("%d%d", &n, &K);

	profits = vll(3*n+69, 0LL);
	storage_ends = vvi(3*n+69);

	vect.emplace_back(0,0,0);
	compress.push_back(-99999);

	FOR(i, 1, n)
	{
	    scanf("%d%d%d", &u, &v, &w);
        vect.emplace_back(u, u+v+K-1, w);
        compress.push_back(u);
        compress.push_back(u+v+K-1);
	}


//	cerr << el;
//	cerr << el;
//	for(data x: vect) cerr << x.start << sp << x.done << sp << el;
}

//Check
void CompressInput()
{
    sort(whole(compress));
    FOR(i, 1, n)
    {
        int st = lower_bound(whole_1(compress), vect[i].start) - compress.begin();
        int dn = lower_bound(whole_1(compress), vect[i].done) - compress.begin();

        vect[i].start = st;
        vect[i].done  = dn;
        storage_ends[dn].push_back(i);
    }


//	cerr << el;
//	cerr << el;
//	for(data x: vect) cerr << x.start << sp << x.done << sp << el;
}


//Process
void Solve()
{
    FOR(i, 1, 3*n)
    {
        profits[i] = profits[i-1];
        if(!storage_ends[i].empty()) for(auto p: storage_ends[i])
        {
            maximize(profits[i], profits[vect[p].start - 1] + vect[p].revenue);
        }
    }

    cout << profits[3*n] << el;
}

//Main Procedure
int main()
{
    Enter();
    CompressInput();
    Solve();
    return 0;
}

//=============================================================================//
/**    CTB, you are always in my heart and in my code <3       #30yearsCTB    **/
//=============================================================================//
