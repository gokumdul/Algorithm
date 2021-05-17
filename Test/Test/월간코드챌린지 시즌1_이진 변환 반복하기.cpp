// programmers
// 월간 코드 챌린지 시즌 1
// 이진 변환 반복하기

// lvl 2

#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

string toTwo(int n) {
	stack<int> tmp;
	string a = "";
	if (n == 0)
		return "0";

	// m: 몫, mod: 나머지
	int m, mod;
	m = n;
	while (m != 0) {
		mod = m % 2;
		tmp.push(mod);
		m = m / 2;
	}
	while (!tmp.empty()) {
		a += to_string(tmp.top());
		tmp.pop();
	}
	return a;
}

vector<int> solution(string s) {
	vector<int> answer;
	int zero_cnt = 0;
	int one_cnt = 0;
	int cnt = 0;
	string s_copy = s;


	while (s_copy != "1") {
		cnt++;
		for (int i = 0; i < s_copy.size(); i++) {
			if (s_copy[i] == '0') {
				zero_cnt++;
			}
			else {
				one_cnt++;
			}
		}
		s_copy = toTwo(one_cnt);
		one_cnt = 0;
	}

	answer.push_back(cnt);
	answer.push_back(zero_cnt);

	return answer;
}