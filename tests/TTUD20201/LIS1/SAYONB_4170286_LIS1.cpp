#include<iostream>
#include<list>
using namespace std;
bool same_integral_part(double first,double second){
	return ( int(first)==int(second));
}
int main()
{
	double myArray[]={1,2,2,4,5,6,7,8};
	list<double> mylist (myArray,myArray+8);
	mylish.sort();
	mylish.unique(same_integral_part);
	cout<<"mylist gom cac so:";
	for(list<double>::iterator it = mylish.begin(); it!=mylish.end() ; it++){
		
		cout<< *it<<"";
		return 0;
	}
}
