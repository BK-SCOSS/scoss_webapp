#include <bits/stdc++.h>
#include <string>
using namespace std;
#define long long ll

void solve()
{
    string str1, str2;
    cin >> str1 >> str2;
    if (str1.length() > str2.length()) 
        swap(str1, str2); 
  
    string str = ""; 
  
    int n1 = str1.length(), n2 = str2.length(); 
  
    reverse(str1.begin(), str1.end()); 
    reverse(str2.begin(), str2.end()); 
  
    int carry = 0; 
    for (int i=0; i<n1; i++) 
    { 
        int sum = ((str1[i]-'0')+(str2[i]-'0')+carry); 
        str.push_back(sum%10 + '0'); 
  
        carry = sum/10; 
    } 
   
    for (int i=n1; i<n2; i++) 
    { 
        int sum = ((str2[i]-'0')+carry); 
        str.push_back(sum%10 + '0'); 
        carry = sum/10; 
    } 
  
    if (carry) 
        str.push_back(carry+'0'); 
   
    reverse(str.begin(), str.end()); 
  
    cout << str << endl; 
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie();
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}
