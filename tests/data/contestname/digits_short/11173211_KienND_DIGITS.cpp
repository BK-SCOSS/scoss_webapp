#include <bits/stdc++.h>
#include <iostream>

using namespace std;
int test3(int X){
	int kq=0;
	int i1,i2,i3,i4,i5,i6,i7;
	if(X%2==1){
		kq=0;
		return kq;
	}
	else{
	for (i1 = 0;i1<=9; i1++){
		for (i2 = 0;i2<=9; i2++){
			for (i3 = 0;i3<=9; i3++){
				for ( i4 = 0;i4<=9; i4++){
					for (  i5 = 0;i5<=9; i5++){
						for ( i6 = 0;i6<=9; i6++){
							for ( i7 = 0;i7<=9; i7++){
		if(10010*i1+1000*i2+1000*i3+100*i4+100*i5+10*i6+2*i7==X){kq++;}
}
}
		
}
}		
}
}
}
}
	
	return kq;
}

int main(){
	int n;
	cin >> n;
	int a[n];
	for (int i=0;i<n;i++){
		cin >> a[i];
	}
	for (int i=0;i<n;i++){
		cout << test3(a[i])<<endl;
	}
	
	return 0;	
}
