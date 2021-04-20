// 프로그래머스
// 레벨 2
// 조이스틱

/**
 * 테스트 케이스 11 "ABABAAAAABA"인 경우처럼
 * 오른쪽으로 갔다가 다시 왼쪽으로 되돌아 오는 경우가 최소인 경우의 방법을 고려하는 것이 핵심이었다
 */

/*
 * 원래는 좌측으로만 갔을 때, 우측으로만 갔을 때를 고려했었다.
 * 그러면 테스트 케이스 11에서 실패한다.
 */

// Greedy

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int solution(string name) {
	int answer = 0;

	// 원래 방법
	int fromStart = 0; // 뒤에서 부터 읽어 A 전까지 읽을 것임
	int fromEnd = 0;

	for (int i = name.size()-1; i >= 0; i--) {
		if (name[i] != 'A') {
			fromStart = i;
			break;
		}
	}
	for (int i = 1; i < name.size(); i++) {
		if (name[i] != 'A') {
			fromEnd = i;
			break;
		}
	}
	fromEnd = name.size() - fromEnd;
	for (int i = name.size() - 1; i >= 0; i--) {
		if (name[i] != 'A') {
			fromStart = i;
			break;
		}
	}


	//cout << fromStart << endl;
	//answer = 'Z' - 'A'; // 25
	for (char a : name) {
		if (a > 'N')
			answer += 13 - (a - 'N');
		else {
			answer += a - 'A';	
		}
	}
	
	if (fromEnd > fromStart)
		answer += fromStart;
	else
		answer += fromEnd;

	return answer;
}


int main() {
	cout << solution("ABABAAAAABA") << endl;

	return 0;
}