#include<iostream>
using namespace std;

bool checkDiff (int arr[7]){
	bool flag = true;
	for ( int i = 0 ; i<7 ; i++ ){
		for ( int j = 0; j < 7; j++){
			if ((i!=j) && (arr[i]==arr[j])) {
				flag = false;
				break;
			} 
		}
	}
	return flag;
}
int tryCount(int testNum){
	//	HUST + SOICT = N
	//int H0,U1,S2,T3,O4,I5,C6;
	int count = 0;
	int a[7];
	for ( a[0] = 0; a[0] < 10; a[0]++)	
		for ( a[1] = 0; a[1] < 10; a[1]++)
			for ( a[2] = 0; a[2] < 10; a[2]++)
				for ( a[3] = 0; a[3] < 10; a[3]++)
					for ( a[4] = 0; a[4] < 10; a[4]++)
						for ( a[5] = 0; a[5] < 10; a[5]++)
								for ( a[6] = 0; a[6] < 10; a[6]++){
								int SUM = 10000*a[2] + 1000*(a[4]+a[0]) + 100*(a[1]+a[5]) + 10*(a[2]+a[6]) + 2*a[3];
								if ( checkDiff(a) && (SUM == testNum) && ( a[0] != 0) && ( a[2]) !=0 ) {
									count++;
									//cout<<testNum<<" = "<<a[0]<<a[1]<<a[2]<<a[3]<<" + "<<a[2]<<a[4]<<a[5]<<a[6]<<a[3]<<endl;	
								}
								}
	return count;
}

int main(){
	int testCount;
	cin>>testCount;
	int testCase[testCount];
	for ( int i = 0 ; i < testCount ; i++ )	cin >> testCase[i];
	for ( int i = 0 ; i < testCount ; i++ )	cout<<tryCount(testCase[i])<<endl;

	return 0;
}
