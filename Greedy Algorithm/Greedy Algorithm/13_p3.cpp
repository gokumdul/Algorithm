// 프로그래머스
// 레벨 2
// 큰 수 만들기

// Greedy

//이 문제는 number의 크기가 100,000,000 까지 가능해서
//dfs로 풀면 시간 초과 에러가 난다고 한다
//향후에 dfs로 풀어보자 꼬오오오옥

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string solution(string number, int k) {
	string answer = "";

	for (int i = 0, idx = -1; i < number.size() - k; i++) {
		char a = 0;
		for (int j = idx+1; j <= k+i; j++) {
			if (a < number[j]) {
				a = number[j];
				idx = j;
			}
		}
		answer += a;
	}
	return answer;
}

int main() {
	cout << solution("1489", 2) << endl;

	return 0;
}