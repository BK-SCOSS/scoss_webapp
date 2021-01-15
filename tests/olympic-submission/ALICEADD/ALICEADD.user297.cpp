#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

struct c{
    unsigned long int	 alice;
    unsigned long int	 bob;
};
bool KT(unsigned long int	 a){
  if(a>=0&&a<=pow(10,19)) {
    return true;
  }else return false;
}
int main()
{
    int T;
    cin >> T;
    if(T<=10&&T>=1){
      c a[T];
      for(int i=0;i<T;i++){
        cin >> a[i].alice >> a[i].bob;
      };
      for(int i=0;i<T;i++){
            if(KT(a[i].alice)&&KT(a[i].bob)){
        cout << a[i].alice + a[i].bob << endl;}
        else return 0;
      };
    }else
      return 0;
}
