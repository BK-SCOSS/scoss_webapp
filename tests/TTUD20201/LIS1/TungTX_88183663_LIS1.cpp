#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    int T; cin>>T;
    vector<int> result;
    for(int t=0;t<T;++t){
        //nhap lieu:
        int n; cin>>n;
        int* a = new int[n];
        for(int i=0;i<n;++i) cin>>a[i];

        int* b = new int[n];//b[i]: so ptu cua day dep lon nhat bat dau tu i
        for(int i=0;i<n;++i) b[i]=1;

        for(int j=n-1;j>=0;--j)
            for(int J=j+1;J<n;++J)
                if(a[j]==(a[J]-1)){
                    b[j]=b[J]+1;
                    break;
                }

        int maxL = 0;
        for(int i=0;i<n;++i){
            if (b[i]>maxL) maxL = b[i];
        }
        result.push_back(maxL);
        delete[] a;
        delete[] b;
    }
    for(int i:result) cout<<i<<endl;
}
