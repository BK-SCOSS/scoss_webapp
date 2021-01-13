#include<bits/stdc++.h>
using namespace std;

main(){
	int T;
	cin >> T;
    for(int i = 1; i <= T; i ++){
        char a[21], b[21], x[21], y[21], z[21];
        cin >> a >> b;
        int lena = strlen(a);
        int lenb = strlen(b);
        int ma = max(lena, lenb)+1;
        for(int i = 0; i < ma; i ++){
            if(i < ma-lena) x[i] = '0';
                else x[i] = a[i-ma+lena];
            if(i < ma-lenb) y[i] = '0';
                else y[i] = b[i-ma+lenb];
        }
        int miss = 0;
        for(int i = ma-1; i >= 0; i --){
            int cmp = int(x[i]) + int(y[i]) - 96;
            z[i] = char((cmp+miss)%10+48);
            if(cmp + miss >= 10) miss = 1;
                else miss = 0;
        }
        int ans = 0;
        while(z[ans] == '0') ans ++;
        for(int i = ans; i < ma; i ++) cout << z[i];
    }
	return 0;
}
