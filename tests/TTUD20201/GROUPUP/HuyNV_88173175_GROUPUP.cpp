#include <bits/stdc++.h>
using namespace std;

int T, n;
//int *a;
queue<int> result;

deque<int> group;

int totalTime;

int process(deque<int> group) {
	if(group.size() == 1) {
		return 0;
	}
	bool run = true;
	deque<int> tempGroup;
	int cnt = 0;
	
	bool chan = true;

	while(run) {
		if(group.size() == 0 && cnt == 0) {
			run = false;
			chan = true;
			break;
		} else if(group.size() == 0 && cnt == 1) {
			run = false;
			chan = false;
			break;
		}
		tempGroup.push_back(group.front());
		group.pop_front();
		cnt++;
		if (cnt == 2) {
			int x = tempGroup.back();
			tempGroup.pop_back();
			int y = tempGroup.back();
			tempGroup.pop_back();
			int time = x + y;
			tempGroup.push_back(time);
			cnt = 0;
		}
	}
	if(chan) {
		int maxTime = 0;
		for(auto i = tempGroup.begin(); i != tempGroup.end(); i++) {
			if(*i > maxTime) maxTime = *i;
		}
		totalTime += maxTime;
	} else {
		int maxTime = 0;
		for(auto i = tempGroup.begin(); i != tempGroup.end() - 1; i++) {
			if(*i > maxTime) maxTime = *i;
		}
		totalTime += maxTime;
	}
	process(tempGroup);
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> T;
    while(T--) {
		cin >> n;
//    	a = new int[n];
    	for (int i = 0; i < n; i++) {
    		int numOfPeople;
    		cin >> numOfPeople;
    		group.push_back(numOfPeople);
		}
		totalTime = 0;
		process(group);
		result.push(totalTime);
	}

	while(!result.empty()) {
    	cout << result.front() << endl;
    	result.pop();
	}
	
	return 0;
}
