#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <string>
using namespace std;

void add_func(string A_str, string B_str);

int main() {
    string A_inp, B_inp;
    int cnt;
    cin >> cnt; 
    for(int i = 0; i < cnt; i++){
        cin >> A_inp >> B_inp;
        add_func(A_inp, B_inp);
    }
}

void add_func(string A_str, string B_str)
{
    // init
    int i = 0, my_carry_var = 0, sum_int = 0;
    if (A_str.length() < B_str.length())
    {
        swap(A_str, B_str);
    }
    // get length
    int A_len = A_str.length();
    int B_len = B_str.length();
    // time to reverse
    reverse(A_str.begin(), A_str.end());
    reverse(B_str.begin(), B_str.end());
    string sum_str = "";
    for (i = 0; i < A_len; i++) {
        sum_int = (((A_str[i] - '0') + (B_str[i] - '0')) + (my_carry_var));
        sum_str.push_back((sum_int % 10) + '0');
        my_carry_var = sum_int / 10;
    }
    for (i = A_len; i < B_len; i++) {
        sum_int = ((B_str[i] - '0') + (my_carry_var));
        sum_str.push_back((sum_int % 10) + '0');
        my_carry_var = sum_int / 10;
    }
    if (my_carry_var) {
        sum_str.push_back(my_carry_var + '0');
    }
    reverse(sum_str.begin(), sum_str.end());
    cout << sum_str << "\n";
}