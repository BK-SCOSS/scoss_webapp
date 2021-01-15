#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
vector<int> so;
vector<int> mu;
vector<int> mu1;
bool isPrime(int n){
	if (n<=1) return false;
	for (int i=2;i<=sqrt(n);i++)
	if (n%i==0) return false;
	return true;
}
void phantich(int n){
	int dem;
	for (int i=2;i<=n;i++){
		dem=0;
		if (isPrime(i)&&n%i==0){
			while (n%i==0){
				dem++;
				n=n/i;
			}
		so.push_back(i);
		mu.push_back(dem);	
		}
	}
}

int main(){
int t,n;
cin>>t;
while (t--){
cin>>n;

phantich(n);phantich(n+1);phantich(n+2);

for (int i=0;i<so.size()-1;i++){
	for (int j=i+1;j<so.size();j++){
		if (so[i]>so[j]) {
		swap (so[i],so[j]);
		swap (mu[i],mu[j]);
		
	}
}	
}
int s1=1,s2=1;
int chay=so[0];int dem=mu[0];
for (int i=1;i<=so.size();i++){
	if (so[i]==chay) dem+=mu[i];
	else {
		s1*=(dem+1);
		s2*=(dem*2+1);
		chay=so[i];dem=mu[i];
	}
}
	cout<<(s2+1)/2-s1<<endl;
	mu.erase(mu.begin(),mu.end());
	mu1.erase(mu1.begin(),mu1.end());
	so.erase(so.begin(),so.end());
}
return 0;
}
