#include <iostream>

using namespace std;

int soict(int s, int o, int i, int c, int t){
    return 10000 * s + 1000 * o + 100 * i + 10 * c + t;
}

int hust(int h, int u, int s, int t){
    return 1000 * h + 100 * u + 10 * s + t;
}

bool check(int h, int u, int s, int o ,int i, int c, int t){
    if(h == u || h == s || h == o || h == i || h ==c || h == t || u ==s || u == o || u == i || u == c || u == t || s ==o || s == i || s == c || s == t || o == i || o == c || o == t || i == c || i ==t || c == t ) return false;
    return true;
}

int main()
{
    int h ,u, s, t, o, i, c;
    int T;
    cin >> T;
    while(T--){
        int result = 0;
        int N;
        cin >> N;
        if(N > 109998) cout << 0;
        else if(N % 2 != 0) cout << 0;
        else{
            for(int s =1; s <= 9; s++){
                for(int o =0; o <= 9; o++){
                    if (o == s) continue;
                    for(int i = 0; i <= 9; i++){
                        if(i == s || i == o) continue;
                        for(int c = 0; c <= 9; c++){
                            if(c == s, c== o, c== i) continue;
                            /*int r = N % 10;
                            t = r / 2;
                            if(t == s || t == o || t == i || t == c) continue;
                            int a = N - soict(s, o, i ,c, t);
                            if (a > 9999 || a < 1000) continue;
                            else{
                                u = (a/100) % 10;
                                h = (a/1000);
                                if(a % 10 == t && (a/10)% 10 == s && check(h, u, s, o, i, c, t)) result++;
                            }

                            t = (r + 10)/ 2;
                            if(t == s || t == o || t == i || t == c) continue;
                            a = N - soict(s, o, i ,c, t);
                            if (a > 9999 || a < 1000) continue;
                            else{
                                u = (a/100) % 10;
                                h = (a/1000);
                                if(a % 10 == t && (a/10)% 10 == s && check(h, u, s, o, i, c, t)) result++;
                            }*/
                            for(int t = 0; t <= 9 ; t++){
                                if(t == s || t == o || t == i || t == c) continue;
                                int a = N - soict(s, o, i ,c, t);
                                if (a > 9999 || a < 1000) continue;
                                else{
                                    u = (a/100) % 10;
                                    h = (a/1000);
                                    if(a % 10 == t && (a/10)% 10 == s && check(h, u, s, o, i, c, t)) result++;
                                }
                            }

                        }
                    }
                }
            }
            cout << result << endl;
        }
    }
    return 0;
}
