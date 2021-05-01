// 프로그래머스
// lvl1
// 완주하지 못한 선수

// 풀이 3 (효율성 성공)

// 해시

/*
	map으로 품!
*/

#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
	string answer = "";
	map<string, int> m;
	for (int i = 0; i < participant.size(); i++) {
		m[participant[i]] += 1;
	}

	for (int j = 0; j < completion.size(); j++) {
		m[completion[j]] -= 1;
	}

	for (auto it = m.begin(); it != m.end(); it++) {
		if (it->second == 1) {
			answer = it->first;
		}
	}
	return answer;
}

int main() {
	vector<string> participant = { "leo", "kiki", "eden" };
	vector<string> completion  = { "eden", "kiki" };

	cout << solution(participant, completion) << endl;

	return 0;
}