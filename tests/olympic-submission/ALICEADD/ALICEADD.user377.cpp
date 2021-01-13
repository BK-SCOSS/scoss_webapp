#include <iostream>
#include <string>

using namespace std;

int char2int(char a){
    return a - 48;
}

int int2char(int a){
    return a + 48;
}

void add(string a, string b){


    if(a.length() < b.length()){
        string c = a;
        b = a;
        a = c;
    }

    string res[a.length() + 1];

    int posB = b.length() - 1;
    int posA = a.length() - 1;
    int cur = 0;
    int carry = 0;
    int r;

    while (posB >= 0){
        int sum = char2int(a[posA]) + char2int(b[posB]) + carry;
        carry = sum / 10;
        r = sum % 10;

        res[cur] = int2char(r);

        posA --;
        posB --;
        cur ++;
    }

    while (posA >= 0){
        int sum = char2int(a[posA]) + carry;
        carry = sum / 10;
        r = sum % 10;

        res[cur] = int2char(r);

        cur++;
        posA--;
    }

    if(carry > 0) {
        res[cur] = int2char(carry);
        cur ++;
    }

    cur --;
    while (cur >= 0){
        cout << res[cur];
        cur--;
    }

    cout << endl;
}


int main() {
   int T;
   string a, b;

   cin >> T;
   for(int i = 0; i < T; i++){
       cin >> a >> b;
       add(a, b);
   }
}