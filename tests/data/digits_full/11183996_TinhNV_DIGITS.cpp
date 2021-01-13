#include<bits/stdc++.h>

using namespace std;
int t,H,U,S,T,O,I,C;

int digits(unsigned int n){
    int ans=0;
    if(n%2!=0) return 0;
    for(H=1;H<=9;H++){
        for(U=0;U<=9;U++){
            if(U!=H)
            for(S=1;S<=9;S++){
                if(S!=U&&S!=H)
                for(T=0;T<=9;T++){
                    if(T!=S&&T!=U&&T!=H)
                    for(O =0;O<=9;O++){
                        if(O!=T&&O!=S&&O!=U&&O!=H)
                        for(I=0;I<=9;I++){
                            if(I!=O&&I!=T&&I!=S&&I!=U&&I!=H)
                            for(C=0;C<=9;C++){
                                if(C!=I&&C!=O&&C!=T&&C!=S&&C!=U&&C!=H){
                                    unsigned int num = S*10000+(H+O)*1000+(U+I)*100+(S+C)*10+T*2;
                                    if(num==n) ans++;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return ans;
}

int main(){
    cin>>t;
    unsigned int a[t];
    for(int i=0;i<t;i++){
        cin>>a[i];
    }
    for(int i=0;i<t;i++){
        cout<<digits(a[i])<<endl;
    }

}
