#include <bits/stdc++.h>
using namespace std;
int a[10007];

void sortNumOfDeath(vector<pair<int, int>> &s)
{
    sort(s.begin(), s.end(), [](pair<int, int> a, pair<int, int> b) {
        return a.first < b.first;
    });
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        vector<pair<int, int>> s;
        int k;
        cin >> k;
        a[k];
        for (int i = 0; i < k; i++)
        {
            pair<int, int> pos;
            cin >> pos.first;
            pos.second = i;
            s.push_back(make_pair(pos.first, pos.second));
        }
        sortNumOfDeath(s);
        
        int _max = 1, cnt = 1, jump = 0;
        for (int i = 0; i < k - 1; i++)
        {
            for(int j = i+1; j < k; j++){
                // if(s[i].second > s[j].second) jump = j;
                if(s[j].first != s[i].first+1) {_max = max(_max, cnt); cnt = 1; break;}
                if((s[j].first == s[i].first+1) && (s[j].second > s[i].second)) {cnt++; break;}
            }    
            //i = jump;
        }
        cout << _max << endl;
    }
}