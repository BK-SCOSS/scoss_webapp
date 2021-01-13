#include<stdio.h>
#include<string>
#include<iostream>

using namespace std;

int main(){
    int t;
    string a, b;
    scanf("%d", &t);
    while (t--){
        //scanf("%s %s", &a, &b);
        cin >> a >> b;
        if (a.length() < b.length()){
            string tg = a;
            a = b;
            b = tg;
        }
        while (b.length() < a.length()) b = '0' + b;
        int len = a.length();
        //cout << a << " " << b << "\n";
        string c;
        int d = 0;
        while (len != 0){
            int tg = (int)(a[len-1]-48) + (int)(b[len-1]-48) + d;
            if (tg > 9) d = 1; else d = 0;
            c = char(tg % 10 + 48) + c;
            //cout << c << "\n";
            len--;
        }
        if (d == 1) cout << 1;
        cout << c << "\n";
    }
}
