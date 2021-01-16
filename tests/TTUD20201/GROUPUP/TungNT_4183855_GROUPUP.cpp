#include <bits/stdc++.h>
using namespace std;

int T, n;
int a[100000];
int ans=0;

void init()
{
    cin >> n;
    for (int i=0; i<n; i++)
    {
        cin >> a[i];
    }
}

void TRY(int k, vector <int> member, vector <int> v)
{
    if (k == 0)
    {
        return;
    }
    vector <int> new_vector;
    priority_queue<int> pq;

    int x=0;
    while(x<(member.size()-1))
    {
        pq.push(member[x] + member[x+1]);
        new_vector.push_back(member[x] + member[x+1]);
        x = x + 2;
    }
    if (member.size() % 2 == 1)
    {
        pq.push(member.back());
        new_vector.push_back(member.back());
    }

//    for (int i=0; i<new_vector.size(); i++)
//    {
//        cout << new_vector[i] << " "<<endl;
//    }


    v.push_back(pq.top());
    ans +=pq.top();

    TRY(k-1, new_vector, v);
}

int main()
{
    cin >> T;
    for (int i=0; i<T; i++)
    {
        vector <int> v;
        vector <int> member;
        init();
        for (int i=0; i<n; i++)
        {
            member.push_back(a[i]);
        }
        int k = 0;
        int numbers = 1;

        while(numbers < n)
        {
            numbers = numbers*2;
            k++;
        }

        TRY(k, member, v);

        cout << ans << endl;
        v.clear();
        member.clear();
        ans = 0;
    }
}
