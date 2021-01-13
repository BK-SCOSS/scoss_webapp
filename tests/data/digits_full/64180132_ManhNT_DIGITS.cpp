#include<iostream>
using namespace std;
int main(){

   int T;
   cin>>T;
   int n;
   int res=0;
   int h,u,s,t,o,i,c;
   while (T>0){
     cin>>n;
     res=0;
     if (n>12000 && n < 110000 && n%2==0){
            for (h=1;h<10;h++){
                for (u=0;u<10;u++){
                    if(u!=h){
                      for(s=1;s<10;s++){
                         if(s!=u && s !=h){
                             for (t=0;t<10;t++){
                                if (t!=h && t!=u && t!=s){
                                    for(o=0;o<10;o++){
                                        if(o!=h && o!=u && o!=s && o!=t){
                                             for(i=0;i<10;i++){
                                                if(i!=h && i!=u && i!=s && i!=t && i!=o){
                                                    for (c=0;c<10;c++){

                                                      if(c!=h && c!=u && c!=s && c!=t && c!=o && c!=i){
                                                           if(1000*(h+o)+(u+i)*100+2*t+s*10010+10*c==n)
                                                            res++;
                                                      }
                                                    }
                                                }
                                             }
                                        }
                                    }
                                }
                             }
                         }
                      }

                    }

                }
            }


     }
     cout<<res<<endl;
     T--;
   }
}
