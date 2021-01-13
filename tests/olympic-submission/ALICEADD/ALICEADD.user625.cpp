#include<iostream>
#include<string>
using namespace std;

char* process(string a, string b)   //process for a.length() > b.length()
{
    int length_a = a.length();
    int length_b = b.length();
    char *res = new char[length_a + 2];
    int remember = 0;
    for(int i = 0 ; i < length_b ; i++){
        int tmp = a[length_a-i-1] - '0' + b[length_b-i-1] - '0';
        tmp = tmp + remember;
        if(tmp >= 10)
            remember = 1;
        else remember = 0;
        tmp = tmp % 10;
        res[length_a - i] = tmp + '0';
    }

    for(int i = 0 ; i < length_a - length_b ; i++){
        int tmp = a[length_a - length_b - 1] - '0';
        tmp = tmp + remember;
        if(tmp >= 10)
            remember = 1;
        else remember = 0;
        tmp = tmp % 10;
        res[length_a - length_b - i] = tmp + '0';
    }

    res[length_a + 1] = '\0';
    if(remember)
        res[0] = '1';
    else{
        for(int i = 0 ; i <= length_a ; i++)
            res[i] = res[i+1];
    }
    return res;
}

char* plus_string(string a, string b)
{
    if(a.length() >= b.length()){
        return process(a, b);
    }else return process(b, a);
}

int main()
{
    int n;
    cin>>n;
    for(int i = 0 ; i < n ; i++){
        string a, b;
        cin>>a>>b;
        cout<<plus_string(a, b);
    }
}
