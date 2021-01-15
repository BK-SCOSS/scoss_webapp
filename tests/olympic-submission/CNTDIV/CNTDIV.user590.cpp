#include <iostream>
//#include <vector>
#include <unordered_map>
#include <cmath>

using namespace std;
//void Factorize(std::vector<std::vector<long long>> &result, long long num)
void Factorize(unordered_map<long long, long long> &result, long long num)
{
	long long UpperBound = static_cast<long long>(sqrt(num));
/*
	for (auto &r: result)
	{
		while (num%r[0]==0)
		{
			num/=r[0];
			++r[1];
		}
	}
*/
	for (int iii=2; iii<=UpperBound; ++iii)
	{
		while  (num%iii==0)
		{
			num/=iii;
			++result[iii];
		}
	}
	
	if (num>1)
		++result[num];
}

int main()
{
	int test(0);
	std::cin>>test;

	while (test--)
	{
		long long N(0);
		std::cin>>N;

		std::unordered_map<long long, long long> result;
		result.reserve(N*2);

		Factorize(result, N);
		Factorize(result, N+1);
		Factorize(result, N+2);

		long long output(0);

		for (long long iii=2; iii<N*(N+1)*(N+2); ++iii)
		{
			std::unordered_map<long long, long long> temp;
			Factorize(temp, iii);

			//std::cout<<"iii: "<<iii<<"\n";
			bool isGood(false);
			for (auto &t: temp)
			{
				//std::cout<<"result["<<t.first<<"]: "<<result[t.first]<<"\t\tt.second:"<<t.second<<"\n";
				if (result[t.first*2 < t.second])
				{
					isGood=false;
					break;
				}
				
				if (result[t.first] < t.second && t.second <= 2*result[t.first])
				{
					//std::cout<<"Not this one\n";
					isGood=true;
				}
			}

			if (isGood) ++output;
					//std::cout<<"\n";
		}
		/*
		long long TotalUocOfT(1);
		long long TotalUocOfT2(1);


		for (auto &r: result)
		{
			TotalUocOfT *= (r.second+1);
		}

		for (auto &r: result)
		{
			TotalUocOfT2 *= (r.second*2+1);
		}

		long long output(TotalUocOfT2 - TotalUocOfT);

		*/

		std::cout<<output<<"\n";

	}
	
	return 0;
}	
