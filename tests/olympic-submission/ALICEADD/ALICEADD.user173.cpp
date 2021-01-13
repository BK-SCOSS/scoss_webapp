#include<bits/stdc++.h>

using namespace std;
string sum(string a, string b){
    while (a.size()<b.size()) a='0'+a;
				while (b.size()<a.size()) b='0'+b;
				int nho=0;
				string kq="";
				for (int i=a.size()-1;i>=0;i--){
				int id=int(a[i])+int(b[i])-96+nho;
				kq=char(id%10+48)+kq;nho=id/10;
}
    if (nho>0) kq='1'+kq;
    return kq;
}
int main(){
    string a,b;
    int n;
    cin>>n;
    while (n--){
				cin>>a>>b;
    cout<<sum(a,b)<<"\n";
}
				return 0;
}