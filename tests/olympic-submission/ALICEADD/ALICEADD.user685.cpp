#include<iostream>
using namespace std;
int stringToNum(char c)     // chuyen char sang so
{
    return c - '0';
}
char numToString(int n)     // chuyen so sang char
{
    return (char)(n+48);
}
string sum(string a, string b)  // tong 2 so
{
    string s = "";
    int l = a.length();
     
    int temp = 0;
    for (int i=l-1; i>=0; i--)   // duyet va cong
    {
        temp = stringToNum(a[i]) + stringToNum(b[i]) + temp;    // tinh tong tung doi mot
        s.insert(0,1,numToString(temp%10));         // gan phan don vi vao
        temp = temp/10;     // lay lai phan hang chuc
    }
    if (temp>0)  // neu hang chuc > 0 thi them vao KQ
    {
        s.insert(0,1,numToString(temp));
    } 
    return s;
}
int main(){
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		long long a,b;
		cin>>a>>b;
		string c= to_string(a);
		string d= to_string(b);
		cout<<sum(c,d);
	}
	return 0;
	}
	

 



 
    
