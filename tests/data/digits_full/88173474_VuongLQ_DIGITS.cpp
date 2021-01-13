#include<iostream>
using namespace std;
int main(){
	int tc;
	cin >> tc;
	for (int test = 0; test < tc; test++){
		int N,NTemp, res = 0;
		cin >> N;
		NTemp = N;
		if (N > 99999 || N < 10000){
			cout << 0 << endl;
		}else{
			int a1,a2,a3,a4,a5;
			a5 = N % 10;
			N = N/10;
			a4 = N % 10;
			N = N/10;
			a3 = N % 10;
			N = N/10;
			a2 = N % 10;
			N = N/10;
			a1 = N % 10;
			//cout << a1 << a2 << a3 << a4 << a5 << endl;
			int a[10] = {0 , 1, 2 ,3,5,6,7,8,9};
			int h,u,s[10],t[10],o,i;
			int sC = a1, tC = 0;
			for (int i = 1; i <= a1; i++){
				s[i-1] = i; 
			}
			for (int i = 0; i < 10; i ++){
				if (i*2 == a5 || i*2 == (a5 + 10)){
					t[tC] = i;
					tC++;
				}
			}
			if (tC == 0){
				cout << 0 <<endl;
			} else{
				//cout << "ingame" << endl;
				//cout << tC << sC << endl;
				bool kt = false;
				int sR = 0,hR = 0,uR = 0,tR = 0,oR = 0, iR, cR;
				for (int i1 = 0; i1 < sC; i1++){
					sR = s[i1];
					for (int i2 = 0; i2 < tC; i2++){
						if (t[i2] != sR) {
							tR = t[i2];
						}
						//cout << sR << tR << endl;
						int arr[8], count = 0;
						for (int j = 0; j < 10; j++){
							if (j != sR && j != tR){
								arr[count] = j;
								count ++;
							}
						}
						for (int k1 = 0; k1 < count; k1++){
							if (arr[k1] != 0){
								hR =arr[k1];
								for (int k2 = 0; k2 < count; k2 ++){
									if (arr[k2] != hR){
										uR = arr[k2];
											for (int k3 = 0; k3 < count; k3 ++){
												if (arr[k3] != hR && arr[k3] != uR){
												oR = arr[k3];
												for (int k4 = 0; k4 < count; k4 ++){
													if (arr[k4] != hR && arr[k4] != uR && arr[k4] != oR){
														iR = arr[k4];
														for (int k5 = 0; k5 < count; k5++){
															if (arr[k5] != hR && arr[k5] != uR && arr[k5] != oR && arr[k5] != iR){
																cR = arr[k5];
																int hust = hR*1000+uR*100+sR*10+tR;
																int soict = sR*10000+oR*1000+iR*100+cR*10+tR;
																if (hust+soict == NTemp){
																	//cout << hR << uR << sR << tR << endl;
																	//scout << sR << oR << iR << cR << tR << endl;
																	
																	res++;
																	kt =true;
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
				
				if (kt == true){
					cout << res << endl;
				}else{
					cout << 0 << endl;
				}
			}
		}
	}
    return 0;
}
