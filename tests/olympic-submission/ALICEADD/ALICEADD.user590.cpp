#include <iostream>

using ULL= unsigned long long;

int main()
{
	int test(0);
	std::cin>>test;
	while (test--)
	{
		ULL a(0), b(0);
		std::cin>>a>>b;
		ULL c=(a/10+b/10+(a%10+b%10)/10);
		if (a/10+b/10==0)
			std::cout<<a+b<<"\n";
		else 
			std::cout<<c<<(a%10+b%10)%10<<"\n";
	}
	
	return 0;
}	
