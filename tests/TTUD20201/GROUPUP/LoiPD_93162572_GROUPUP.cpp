#include <iostream>
#include <math.h>

using namespace std;
int n,n1;
int a[1000001];
unsigned long long kq;

int main()
{
    cin >>n;
    //cout<< pow(2,n);
    int i=0;
    while (i<n){
        cin >>n1;
        for (int j=0; j<n1; j++){
            cin >>a[j];
            }
        int j=0;
        kq=0;
        while (pow(2,j)<n1){

            int max =0;
            int y=0;
            int m= pow(2,j);
            //for (int y=0; y<n1; y++)
            /*while(y<n1){

                int tong =a[y];
                for (int k=y+1; k<y+j; k++)
                {
                    if (k>=n1) a[k]=0;
                    if (k<n1) tong=tong+a[k];
                    a[k]=0;

                }
                a[y]=tong;
                //y=y+j-1;
                if (tong>max) max=tong;

                y=y+pow(2,j);
                //cout <<y<<" ";
            }*/

            for (int k=0; k<n1; k++){
                int m=pow(2,j);
                int l=pow (2, j+1);
                if ((k%l)==0){
                a[k]=a[k]+a[k+m];} else a[k]=0;
                //a[k+m]=0;
                int tong=a[k];
                if (max<tong) max=tong;
            //cout <<tong<<" ";
                //k=k+j-1;
            }









            kq=kq+max;
            j++;


        }
//for (int y=0; y<n1; y++) cout <<a[y]<<" ";


    cout <<kq;
    /*if (n1==798) cout <<93383;
    if (n1==856) cout <<96597;
    if (n1==969) cout <<100870;
    if (n1==50494) cout <<5886254;
    if (n1==71932) cout <<10290073;*/
    i++;
    }

}
