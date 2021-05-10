// programmers
// 월간 코드 챌린지 시즌 1
// 내적

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int solution(vector<int> a, vector<int> b) {
	int answer = 0;
	for (int i = 0; i < a.size(); i++) {
		answer += a[i] * b[i];
	}
	return answer;
}