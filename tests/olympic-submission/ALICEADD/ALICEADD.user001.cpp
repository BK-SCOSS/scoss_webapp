#include <iostream>
#include <math.h>
#include <string>

using namespace std;
int main()
{
    int T;
    cin>>T;
    string a[11], b[11];
    for (int i=0;i<T;i++){
        cin>>a[i]>>b[i];
        if (a[i].length()>b[i].length()){
        	while (a[i].length()>b[i].length())
        		b[i] = "0" + b[i];
		}
		else{
			while (b[i].length()>a[i].length())
        		a[i] = "0" + a[i];
		}
    }
    for (int i=0;i<T;i++){
    	string s = "";
    	int y = 0;
    	for(int j = (a[i].length())-1; j>=0; j--){
        	int x=((int)a[i][j]-48) + ((int)b[i][j]-48) + y;
        	y = x/10;
        	x = x%10+48;
        	s = (char)(x)+s;
    	}
    	if (y>0) s = "1"+s;
        cout<<s<<endl;
    }
    return 0;
}

