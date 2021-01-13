#include<bits/stdc++.h>

int main(){
    // int H,U,S,T,O,I,C;
    // int n;
    int m;
    
    scanf("%d",&m);
    int sum_[50] = {};
    int n[50] = {};
    for (int i=0;i<m;i++)
    {
            scanf("%d",&n[i]);
    }
    int count = 0;
    for (int h=1;h<10;h++){
        for (int u=0;u<10;u++){
            if (u!=h){
        for (int s=1;s<10;s++){
            if (s!= u and s!=h){
                        for (int t=0;t<10;t++){
                            if (t!= u and t!=h and t!= s){
        for (int o=0;o<10;o++){
            if (o!= u and o!=h and o!= s and o!=t){
                        for (int i=0;i<10;i++){
            if (i!= u and i!=h and i!= s and i!=t and i!=o){
        for (int c=0;c<10 ;c++){
            int sum_s = 1000*(h+o) +100*(u+i) + 10*(s+c) +(t+t) +10000*s;
            for (int z=0;z<m;z++){
            if (sum_s == n[z] and c!= u and c!=h and c!= s and c!=t and c!=o and c!=i){
                sum_[z] += 1;
                // printf("sum --- hust %d%d%d%d soict %d%d%d%d%d %d %d\n",h,u,s,t,s,o,i,c,t,sum_s, n[z]);
            }}
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
        for (int i=0;i<m;i++)
    {
            printf("%d\n",sum_[i]);
    }
    return 0;

}