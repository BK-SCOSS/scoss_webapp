#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	int Test;
	cin >> Test;
	vector<int> result;
	
	for (int test = 0; test < Test; test++)
	{
		queue <int> q;
		int n;
		cin >> n;
		int time, maxtime, totaltime = 0;
		int team_remain = n;
		
		for (int i = 0; i < n; i ++)
		{
			int temp;
			cin >> temp;
			q.push(temp);
		}
		
		while (q.size() != 1)
		{
			int loop = team_remain/2;
			maxtime = 0;
			for (int i = 0; i < loop; i++)
			{
				time = 0;
				time += q.front();
				q.pop();
				time += q.front();
				q.pop();
				q.push(time);
				maxtime = max(time, maxtime);
			}
			if (team_remain % 2 == 1)
			{
				time = q.front();
				q.pop();
				q.push(time);
				maxtime = max(time, maxtime);
				team_remain = loop + 1;
			}
			else team_remain = loop;
			totaltime += maxtime;
		}
		
		result.push_back(totaltime);
	}
	for (int i : result) cout << i << "\n";
	return 0;
}
