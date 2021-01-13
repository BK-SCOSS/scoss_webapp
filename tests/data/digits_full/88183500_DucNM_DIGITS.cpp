#include <iostream>
using namespace std;

int main(){
    int n,count =0;
    int a[50], x=0;
    int h,u,s,t,o,i,c;
    while ((cin>>n)&&(n!=0)){
    for (h=0;h<10;h++)
    for (u=0;u<10;u++)
    if (u!=h)
            for (s=0;s<10;s++)
            if ((s!=h) && (s!=u))
            for (t=0;t<10;t++)
            if((t!=h) && (t!=u)&&(t!=s))
            for (o=0;o<10;o++)
            if((o!=h) && (o!=u)&&(o!=s)&&(o!=t))
            for (i=0;i<10;i++)
            if((i!=h) && (i!=u)&&(i!=s)&&(i!=t)&&(i!=o))
            for (c=0;c<10;c++)
            if((c!=h) && (c!=u)&&(c!=s)&&(c!=t)&&(c!=o)&&(c!=i))
            if(h*1000+u*100+s*10+t+s*10000+o*1000+i*100+c*10+t==n) count ++;


    cout << count;

    }
    return 0 ;
}
