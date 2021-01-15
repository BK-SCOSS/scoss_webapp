#include <iostream>
#include <bits/stdc++.h>

using namespace std;
long long n;
long long a[7][10000];
long long row[7];
long long total;
int countRes;
long long res[1000000];
long long div1;
int printRes[300000];
void findPartDivision(int p){
    long long m=n+p;
    row[p]=0;row[p+3]=0;
    for (int i=1;i<=trunc(sqrt(m));i++){
        if (m%i==0){
         //   cout<<"m = "<<m<<" ,i = "<<i<<endl;
            a[p][row[p]]=i;
            a[p+3][row[p+3]]=i;
            row[p]++;row[p+3]++;
            a[p][row[p]]=m/i;
            a[p+3][row[p+3]]=m/i;
            row[p]++;row[p+3]++;
        }
    }
};

void findDivision(int u){
    //cout<<total<<endl;
    for (int i=0;i<row[u];i++)
        if (a[u][i]<=total/div1){
            div1=div1*a[u][i];
            if (u==5){
                res[countRes]=div1;
             //   cout<<res[countRes]<<endl;
                countRes++;
            }
            else findDivision(u+1);
            div1=div1/a[u][i];
        }
        else break;
}
int main()
{
    int test;
    cin>>test;
    for (int i=0;i<test;i++){
        cin>>n;
        total=n*(n+1)*(n+2);
        for (int j=0;j<6;j++) row[j]=0;
        for (int j=0;j<=2;j++) findPartDivision(j);

        for (int j=0;j<6;j++) sort(a[j],a[j]+row[j]);

        countRes=0;
        div1=1;

        findDivision(0);
        sort(res,res+countRes);

        int temp=total%res[0]==0?0:1;
        for (int j=1;j<countRes;j++)
            if (res[j]!=res[j-1] && total % res[j]!=0) temp++;
        printRes[i]=temp;
    }

    for (int i=0;i<test;i++) cout<<printRes[i]<<endl;


    return 0;
}
