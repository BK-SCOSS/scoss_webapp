#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

struct hire{
    int s, d, r;
};

struct timerun{
    int start, end, idx;
};


bool compareByLength(const hire &a, const hire &b)
{
    return a.s < b.s;
}

bool comp(const timerun &a, const timerun &b){
    return a.end < b.end;
}


int main() {
  //  freopen("/home/du/CLionProjects/AliceAdd/data", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, K;
    cin >> n >> K;
    vector<hire> sc;

    for(int i = 0; i < n; i++){
        hire tmp;
        cin >> tmp.s >> tmp.d >> tmp.r;
        sc.push_back(tmp);
    }

    sort(sc.begin(), sc.end(), compareByLength);

    vector<timerun> timeList;
    for(int i = 0;i < sc.size(); i ++){
        timerun tmp1;
        tmp1.start = sc[i].s;
        tmp1.end = sc[i].s + sc[i].d + K;
        tmp1.idx = i;
        timeList.push_back(tmp1);
    }
    sort(timeList.begin(), timeList.end(), comp);


    vector<int> F(sc.size(), -1);
    int res = -1;

    F[0] = sc[0].r;
    for(int i = 1; i < sc.size(); i ++){

        F[i] = sc[i].r;

        for(int j = 0; j < timeList.size(); j ++){
            if(sc[i].s >= timeList[j].end){
                F[i] = max(sc[i].r + F[timeList[j].idx], F[i]);
            }
            else {
                break;
            }
        }

        res = max(res, F[i]);
    }

    cout << res;
}