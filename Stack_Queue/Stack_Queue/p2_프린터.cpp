// 프로그래머스

// 프린터
// lvl 2

// 큐 (FIFO)

#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
	int answer = 0;
	priority_queue<int> pq;
	queue<pair<int, int>> q;

	int size = priorities.size();
	for (int i = 0; i < size; i++) {
		q.push(make_pair(i, priorities[i]));
		pq.push(priorities[i]);
	}

	while (!q.empty()) {
		int i = q.front().first;
		int p = q.front().second;
		q.pop();

		if (p == pq.top()) {
			pq.pop();
			answer += 1;

			if (i == location) {
				break;
			}
		}
		else {
			q.push(make_pair(i, p));
		}
	}
	return answer;
}


int main() {
	vector<int> priorities = { 2,1,3,2 };
	int location = 2;

	cout << solution(priorities, location) << endl;


	return 0;
}