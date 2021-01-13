#include <iostream>
#include <stack>
#include <queue>
#include <string>


using namespace std;

int main()
{
  int T;
  cin >> T;
  for (int _ = 0 ; _ < T; _++) {
    int N;
    cin >> N;
    // S*10010 + H*1000 + U*100 + T*2  + O*1000 + I *100 + C*10
    // H & S khac 0
    int result = 0;

    for (int s = 1; s<= 9 ; s++) {
        for (int h = 1 ; h <= 9 ; h++) {
            if (h==s) continue;
            for (int u = 0; u <= 9 ; u++ ) {
                if (u==s || u==h) continue;
                for (int t= 0; t <= 9; t++) {
                    if (t==s || t==h || t==u) continue;
                    for (int o=0; o <= 9; o++) {
                        if (o==s || o==h || o==u || o==t) continue;
                        for (int i = 0 ; i<= 9; i++) {
                            if (i==s || i==h || i==u || i==t || i==o) continue;
                            for (int c=0; c<=9 ; c++) {
                                if (c==s || c==h || c==u || c==t || c==o || c==i) continue;

                                if (s*10010 + h*1000 + u*100 + t*2  + o*1000 + i*100 + c*10 == N) {
                                    result ++;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout << result << endl;
  }

}
