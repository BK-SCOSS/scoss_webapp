//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
using namespace std;
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int a1[30],a2[30],a[30];
int n1,n2;
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void input(){
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void solve(){

}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int main(){
    // freopen("2.txt","r",stdin);
    int t;
    string s1,s2;
    cin>>t;
    for (int i=1;i<=t;i++){
        cin>>s1>>s2;
        n1=s1.length();
        n2=s2.length();
        for (int i=0;i<=max(n1,n2)+1;i++) a[i]=0,a1[i]=0,a2[i]=0;
        for (int i=0;i<=n1-1;i++) a1[i]=s1[n1-1-i]-'0';
        for (int i=0;i<=n2-1;i++) a2[i]=s2[n2-1-i]-'0';
        // for (int i=n1-1;i>=0;i--) cout<<a1[i];
        // cout<<' ';
        // for (int i=n2-1;i>=0;i--) cout<<a2[i];
        // cout<<' ';

        for (int i=0;i<=max(n1,n2)-1;i++) {
            a[i]+=a1[i]+a2[i];
            if (a[i]>9){
                a[i]-=10;
                a[i+1]++;
            }
        }
        if (a[max(n1,n2)]>0) cout<<a[max(n1,n2)];
        for (int i=max(n1,n2)-1;i>=0;i--){
            cout<<a[i];
        }
        cout<<endl;
    }
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

