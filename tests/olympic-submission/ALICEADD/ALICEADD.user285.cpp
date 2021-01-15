#include <iostream>
#include <fstream>

using namespace std;

int main(){
    ifstream finp;
    finp.open("input.txt");
    ofstream fout;
    fout.open("output.txt");
    unsigned long long solan;
    finp>>solan;
    unsigned long long a,b;
    for (int i=1;i<=solan;i++){
        finp>>a>>b;
        fout<<a+b<<endl;
    }
    finp.close();
    fout.close();
}
