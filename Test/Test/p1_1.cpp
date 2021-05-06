// programmers
// 테스트

// 해시로 다시 풀었다

#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(vector<vector<int> > v) {
	vector<int> ans;
	map<int, int> x;
	map<int, int> y;

	for (int i = 0; i < 3; i++) {
		x[v[i][0]]++;
		y[v[i][1]]++;
	}

	for (auto it = x.begin(); it != x.end(); it++) {
		if (it->second == 1) {
			ans.push_back(it->first);
		}
	}
	for (auto it = y.begin(); it != y.end(); it++) {
		if (it->second == 1) {
			ans.push_back(it->first);
		}
	}

	return ans;
}