#include <bits/stdc++.h>

using namespace std;
int n, a[100001];
void Input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}
int check()
{   
    int Max;
    map<int,int> DoDaiChuoi;
    DoDaiChuoi[a[0]]=1;
    for(int i =1;i<n;i++)
    {
    if(DoDaiChuoi.count(a[i]-1)>0) 
    {
        DoDaiChuoi[a[i]]= DoDaiChuoi[a[i]-1]+1;
    }
    else DoDaiChuoi[a[i]]=1;
    }
    for(int i =1;i<n;i++)
    Max = max(Max,DoDaiChuoi[a[i]]);
    return Max;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        Input();
        cout << check();
        cout << endl;
    }
}