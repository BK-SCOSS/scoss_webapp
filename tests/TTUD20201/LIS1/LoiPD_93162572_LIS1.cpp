#include <iostream>


using namespace std;
unsigned long long n, n1,dem;
unsigned long long a[1000000];
/*void demdaycon(array *a,  n1){
    unsigned long long max =0;
    for (int j=0; j<n1-1; j++){
        int dem=0;
        for (int k=j+1; k<n1; k++){
            if (a[j]+1==a[k]) dem++
    }
        if (dem> max) max=dem;
    }
    cout <<dem;
    return 0;
}*/

int main()
{
    cin >>n;
    int i=0;
    while (i<n){
        cin >>n1;
        for (int j=0; j<n1; j++)
            cin >>a[j];


        unsigned long long max =0;
    for (int j=0; j<n1-1; j++){
        dem=1;
        unsigned long long tgian=a[j];
        for (int k=j+1; k<n1; k++){
            if (tgian+1==a[k]) {dem++;tgian++;}
        }
        if (dem> max) max=dem;
    }
    cout << max<<endl;



        i++;}

}
