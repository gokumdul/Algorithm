// 프로그래머스
// lvl3
// 입국심사

// 이분탐색

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//걸리는 시간을 기준으로 이분탐색
//최소시간을 1분, 최대시간을 인원수(n)*심사하는데 제일 오래걸리는 시간
//최소시간과 최대시간의 평균을 구함.
//이 평균시간동안 가각 심사관들이 몇 명을 심사할 수 있는지 구해서 더함
//최대 인원보다 평균시간동안 심사한 인원이 크거나 같다면
//최대인원보다 많이 심사한 것이므로 최대시간값을 평균 -1로 바꿔주고
//answer를 평균으로 갱신시킨 다음에 다시 계산


long long solution(int n, vector<int> times) {
	long long answer = 0;
	long long minTime = 1, maxTime, avgTime, human = 0;
	maxTime = *max_element(times.begin(), times.end()) * (long long)n;

	while (minTime <= maxTime) {
		avgTime = (minTime + maxTime) / 2;
		for (auto t : times) {
			human += avgTime / t;
		}
		if (human >= n) {
			answer = avgTime;
			maxTime = avgTime - 1;
		}
		else {
			minTime = avgTime + 1;
		}
		human = 0;
	}

	return answer;
}

int main() {
	int n = 6;
	vector<int> times = { 7,10 };
	cout << solution(n, times) << endl;

	return 0;
}