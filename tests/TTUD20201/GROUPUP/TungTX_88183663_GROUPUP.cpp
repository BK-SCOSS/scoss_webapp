#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
using namespace std;

int isOdd(int n){
    return (n%2);
}

int findMax(int* b, int n)
{
    int maxB=0;
    for(int i=0;i<n;++i)
        if(b[i]>maxB) maxB = b[i];
    return maxB;
}

int CAL(int n, int* a, int &sum)
{
    int n2;
    if(isOdd(n)){
        n2 = n/2+1;
        int b[n2];
        for(int i=0;i<n2-1;++i)
            b[i]=a[i*2]+a[i*2+1];
        b[n2-1] = a[n-1];
        sum+=findMax(b,n2);
        if(n2!=1) return CAL(n2, b, sum);
        else return sum;
    }
    else{
        n2= n/2;
        int b[n2];
        for(int i=0;i<n2;++i)
            b[i]=a[i*2] + a[i*2+1];
        sum+=findMax(b,n2);
        if(n2!=1) return CAL(n2, b, sum);
        else return sum;
    }


}

int main()
{
    int T; cin>>T;
    int n;
    vector<int> result;
    for(int t=0;t<T;++t){
        cin>>n;
        int* a = new int[n];
        for(int i=0;i<n;++i) cin>>a[i];
        //solve:
        int sum=0;
        result.push_back(CAL(n,a,sum));
    }
    for(int v:result) cout<<v<<endl;
}
