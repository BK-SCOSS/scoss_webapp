#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin >> T;
    while(T--){
    string a,b;
    cin >> a >> b;
    stack<int> a_st,b_st,res_st;
    for(int i=0;i<a.length();i++) a_st.push(a[i]-'0');
    for(int i=0;i<b.length();i++) b_st.push(b[i]-'0');
    int carry{0},sum,ele1,ele2;
    while(!a_st.empty() || !b_st.empty()){
        if(a_st.empty()) ele1 = 0;
        else{
            ele1 = a_st.top();
            a_st.pop();
        }
        if(b_st.empty()) ele2 = 0;
        else{ 
            ele2 = b_st.top();
            b_st.pop();
        }
        res_st.push((ele1+ele2+carry)%10);
        carry = (ele1+ele2+carry)/10;
    }
    if(carry>0) res_st.push(carry);
    while(!res_st.empty()){
        cout << res_st.top();
        res_st.pop();
    }
    }
}