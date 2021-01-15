#include <iostream>
using namespace std;
int result(unsigned int N) {
    int res = 0;
    unsigned long long T = N*(N+1)*(N+2);
    for(unsigned int i=2; i<T; i++) {
        if(T%i==0) {
            continue;
        }
        if(T*T%i==0) {
            res++;
        }
    }
    return res;
}
int main() {
    unsigned int Q;
    cin>>Q;
    unsigned int N[Q];
    for(int i=0; i<Q; i++) {
        cin>>N[i];
    }
    for(int i=0; i<Q; i++) {
        cout<<result(N[i])<<endl;
    }
    return 0;
}
