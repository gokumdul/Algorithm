// 프로그래머스
// lvl 3
// 단어변환

// DFS

// 아니 진짜 저놈의 cnt 없이는 왜 안되는 겨

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int max_cnt = 0;
vector<string> answer;
vector<string> temp;
vector<bool> visit(10000, false);

void dfs(string start, vector<vector<string>>& tickets, int cnt) {
	temp.push_back(start);

	if (max_cnt < cnt) {
		max_cnt = cnt;
		answer = temp;
	}
	/*if (temp.size() == tickets.size() + 1) {
		answer = temp;
		return;
	}*/

	for (int i = 0; i < tickets.size(); i++) {
		if (start == tickets[i][0] && !visit[i]) {
			visit[i] = true;
			dfs(tickets[i][1], tickets, cnt + 1);
			visit[i] = false;
		}
	}
	temp.pop_back();
}

void solution(vector<vector<string>> tickets) {
	sort(tickets.begin(), tickets.end());
	for (int i = 0; i < tickets.size(); i++) {
		cout << tickets[i][0] << " ";
	}
	cout << endl;
	dfs("ICN", tickets, 0);
	//return answer;
}

int main() {
	vector<vector<string>> tickets = { {"ICN", "SFO"},{"ICN", "ATL"},{"SFO", "ATL"},{"ATL", "ICN"},{"ATL", "SFO"} };
	solution(tickets);
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << " ";
	}
		cout << endl;

	return 0;
}