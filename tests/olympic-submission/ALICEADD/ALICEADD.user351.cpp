#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
void process(){
    long m, n, i;
    char a[40], b[40], c[40], d[40], kq[40];
    cin>>c;
    cin>>d;
    m = strlen(c);
    n = strlen(d);
    long p = max(m, n);
    for (i = 0; i <= p - m; i++){
        a[i] = '0';
    }
    for (i = 0; i < m; i++){
        a[i+p-m+1] = c[i]; 
    }
    a[p + 1] = 0;
    b[p + 1] = 0;
    for (i = 0; i <= p - n; i++){
        b[i] = '0';
    }
    for (i = 0; i < n; i++){
        b[i+p-n+1] = d[i];
    }
    kq[p+1] = 0;
    long nho = 0;
    for (i = p; i >= 0; i--){
        long sum = (a[i] -48) + (b[i] - 48) + nho;
        kq[i] = sum%10 + 48;
        nho = sum/10;
    }
    long begin = 0;
    while (kq[begin] == '0') begin++;
    for (i = begin; i <= p; i++) cout<<kq[i];
    cout<<endl;


}
int main(int argc, char const *argv[])
{
    long i, t;
    cin>>t;
    for (i = 1; i <= t; i++) process();
    return 0;
}

