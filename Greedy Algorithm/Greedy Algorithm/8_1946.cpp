// 백준
// 1946 번
// 신입사원

// Greedy

#include <iostream>
#include <algorithm>

using namespace std;

struct score {
	int essay;
	int interview;
};

score _score[100000];
// T: test case, m: 지원자 수, passed: 합격자 수
int T, m, passed;
// test case 최대 20개 이므로, 합격자 수 배열도 20개
int p[20];

// 동점자 없다는 전제하에
bool sort_by_essay(const score &s1, const score &s2) {
	return s1.essay < s2.essay;
}

int test() {
	passed = 1;

	sort(_score, _score + m, sort_by_essay);

	int now_interview_rank = _score[0].interview;
	for (int i = 1; i < m; i++) {
		if (now_interview_rank < _score[i].interview) {
			continue;
		}
		else {
			now_interview_rank = _score[i].interview;
			passed++;
		}
	}

	return passed;
}


int main() {
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> m;
		for (int j = 0; j < m; j++) {
			cin >> _score[j].essay >> _score[j].interview;
		}
		p[i] = test();
	}

	for (int i = 0; i < T; i++) {
		cout << p[i] << endl;
	}

	return 0;
}