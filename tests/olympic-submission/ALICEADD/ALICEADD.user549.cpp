#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

string reverse(string s) {
    string temp = "";
    for (int i = s.length() - 1; i >= 0; i--) {
        temp += s.at(i);
    }
    return temp;
}

string addTwoNumber(string a, string b) {
    int pos_a = a.length() - 1;
    int pos_b = b.length() - 1;
    int nho = 0, tong_thanh_phan;
    string sum = "";

    while (pos_a >= 0 || pos_b >=0) {

        if (pos_a >= 0 && pos_b >= 0) {
            tong_thanh_phan = a.at(pos_a)- 48 + b.at(pos_b) - 48 + nho;
        } else if (pos_a >= 0 && pos_b < 0) {
            tong_thanh_phan = a.at(pos_a) - 48 + nho;
        } else if (pos_a < 0 && pos_b >= 0) {
            tong_thanh_phan = b.at(pos_b) - 48 + nho;
        }
        sum += (tong_thanh_phan % 10 + 48);
        nho = tong_thanh_phan / 10;
        pos_a--;
        pos_b--;
    }
    if (nho == 1) {
        sum += 1 + 48;
    }
    sum = reverse(sum);
    return sum;
}

int main() {
    unsigned long long int T, i, temp_a, temp_b;
    cin >> T;
    string kq[T], a, b;
    for (i = 0; i < T; i++) {
        cin >> temp_a >> temp_b;
        a = to_string(temp_a);
        b = to_string(temp_b);
        kq[i] = addTwoNumber(a, b);
    }
    for (i = 0; i < T; i++) {
        cout << kq[i] << endl;
    }
}