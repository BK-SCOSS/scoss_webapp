#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int t=1;t<=T;t++){

        int N,ans=0;
        cin >> N;
        int n=N;
        for (int s=1; s<=n/10000; s++) {

            n=n-s*10000;
            for (int h=1; h<=n/1000;h++) {

            if (h!=s) {
                for (int o=0; o<=n/1000;o++) {
                if ((o!=s)&&(o!=h)) {
                    n=n-(h+o)*1000;
                    if ((n>0)&&(n/1000<2)&&(o<10)&&(h<10)) {
                    for (int i=0; i<=n/100;i++) {
                    if ((i!=s)&&(i!=h)&&(i!=o)) {
                        for (int u=0;u<=n/100;u++){
                        if ((u!=s)&&(u!=h)&&(u!=o)&&(u!=i)) {
                            n=n-(u+i)*100;
                            if ((n>0)&&(n/100<2)&&(u<10)&&(i<10)){
                            for (int c=0;c<=n/10;c++){
                            if ((c!=s)&&(c!=h)&&(c!=o)&&(c!=i)&&(c!=u)) {
                                n=n-(c+s)*10;
                                if ((n>0)&&(n/10<2)&&(c<10)) {
                                for (int t=0;t<=n;t++){
                                if ((t!=s)&&(t!=h)&&(t!=o)&&(t!=i)&&(t!=u)&&(t!=c)){
                                    n=n-2*t;
                                    if ((n==0)&&(t<10)) {
                                        ans++;

                                        }
                                    n=n+2*t;
                                }
                                }
                                }
                                n=n+(c+s)*10;
                            }
                            }
                            }
                            n=n+(u+i)*100;
                        }
                        }
                    }
                    }
                    }
                    n=n+(h+o)*1000;
                }
                }
            }
            }
            n=n+s*10000;

        }

    cout << ans << " " << endl;
    }

    return 0;
}
