#include <iostream>

using namespace std;

int h, u, s, t, o, i, c, N;

int main(){
    cin >> N;
    int a[N];
    for(int i=0;i<N;i++){
        cin >> a[i];
    }
    int count=0;
    int k = 0;
    while(k<N){
        for(h=1;h<=9;h++){
            for(u=0;u<=9;u++){
                for(s=0;s<=9;s++){
                    for(t=0;t<=9;t++){
                        for(o=0;o<9;o++){
                            for(i=0;i<9;i++){
                                for(c=0;c<9;c++){
                                    if((10000*s+1000*o+1000*h+100*u+10*s+t+100*i+10*c+t=a[k])&&
                                    h!=u && h!=s && h!=t && h!=o && h!= i && h!= c &&
                                    u!=s && u!=t && u!=o && u!=i && u!= c && s!= t &&
                                    s!=o && s!=i && s!=c && t!=o && t!= i && t!= c &&
                                    o!=i && o!=c && i!=c){
                                        count++;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        cout << count;
        k++;
    }

}
