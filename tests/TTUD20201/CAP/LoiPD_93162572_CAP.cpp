#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int n,n1,n2;
unsigned long long a[101],b[101];

int main()
{
    cin >>n;
    int i=0;
    while (i<n){
        cin >>n1;
        for (int j=0; j<n1; j++)
            cin >>a[j];
        cin >>n2;
        for (int j=0; j<n2; j++)
            cin >>b[j];
        i++;
    }
    int j=0;
    while(j<n1-1){
        for (int k=j+1; k<n1; k++)
        if (a[j]==a[k]){
            for (int k=j+1; k<n1; k++){
                a[k]=a[k+1];
            }
            n1--;
        }j++;
    }
        j=0;
        while(j<n2-1){
        for (int k=j+1; k<n2; k++)
        if (b[j]==b[k]){
            for (int k=j+1; k<n2; k++){
                b[k]=b[k+1];
            }
            n2--;
        }j++;
    }
    //cout <<n<<n1<<n2;
    i=0;
    while (i<n){
        int dem=0;
        bool kt=true;
        for (int j=0; j<n1; j++){

            for (int k=0; k<n2; k++){
            if (a[j]==b[k]){
                dem++;

            }
        }
        }
        i++;
        cout <<dem<<endl;
    }
}
