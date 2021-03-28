// 백준
// 1931번
// 회의실 배정

//Greedy

#include <iostream>
#include <algorithm>

using namespace std;

struct meeting {
	int begin;
	int end;
};

// N <= 100,000
int N;
meeting _meeting[100000];

//bool sort_by_begin(int a, int b) {
//	return a < b;
//}

bool sort_by_end(const meeting &m1, const meeting &m2){
	//return (m1.begin < m2.begin);
	if (m1.end < m2.end) {
		return true;
	}
	else if(m1.end == m2.end){
		return m1.begin < m2.begin;
	}
	else {
		return false;
	}
}

int schedule() {
	sort(_meeting, _meeting + N, sort_by_end);

	int earliest = 0, answer = 0;

	for (int i = 0; i < N; i++) {
		int _begin = _meeting[i].begin, _end = _meeting[i].end;
		if (earliest <= _begin) {
			earliest = _end;
			answer++;
		}
	}

	return answer;
}


int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> _meeting[i].begin >> _meeting[i].end;
	}

	cout << schedule() << endl;

	return 0;
}