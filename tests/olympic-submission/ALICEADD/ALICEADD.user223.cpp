#include <iostream>
#include <string>
using namespace std;

int main()
{
	int T,a,b;

	//cout << "T = ";
	// getline(cin, studentName);

	cin >> T;
	
	for (int i=0;i<T;i++){
		//cout << "Alice co so " 
		cin >> a >>b ;
		cout << "Tong so keo la: "<<a+b << endl; 
	}
	


	fflush(stdin);
	cin.get();
	return 0;
}
