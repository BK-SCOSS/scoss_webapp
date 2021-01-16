#include<bits/stdc++.h>
using namespace std;

int main()
{
    int sobotest;
    cin>>sobotest;
    for(int k=0; k<sobotest; k++)
    {
        int a[100], b[100];
        int sophantua, sophantub;
        int i, j;
        int cnt=0;
        //nhap mang a
        cin>>sophantua;
        for( i=0; i<sophantua; i++)
        {
            cin>>a[i];
        }

        //nhap mang b
        cin>>sophantub;
        for( j=0; j<sophantub; j++)
        {
            cin>>b[j];
        }
        // sap xep mang a, b
        for(i=0; i<sophantua; i++)
        {
            for(int m=i; m<sophantua; m++)
            {
                if(a[i] > a[m])
                {
                    int tmp;
                    tmp=a[i];
                    a[i]=a[m];
                    a[m]=tmp;
                }
            }
        }
        for(j=0; j<sophantub; j++)
        {
            for(int m=j; m<sophantub; m++)
            {
                if(b[j] > b[m])
                {
                    int tmp;
                    tmp=b[j];
                    b[j]=b[m];
                    b[m]=tmp;
                }
            }
        }

        //chon phan tu giao nhau
        for(int i=0; i<sophantua; i++)
        {
            for(int j=0; j<sophantub; j++)
            {
                if(a[i]==b[j] && a[i]!=a[i+1] && b[j]!=b[j+1]) cnt++;
            }
        }
        //in ket qua
        cout<<cnt;
    }
}

