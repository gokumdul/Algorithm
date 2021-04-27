// 프로그래머스
// lvl1
// 완주하지 못한 선수

// 풀이 2

// 해시

/*
  이번에는 vector 이용해 풀었으나
  다음번에는 unordered map 라이브러리를 이용해서 해쉬를 이용해 풀어야겠다.
 */

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
	sort(participant.begin(), participant.end());
	sort(completion.begin(), completion.end());
	for (int i = 0; i < completion.size(); i++) {
		if (participant[i] != completion[i]) {
			return participant[i];
		}
	}
	return participant[participant.size() - 1];
}

int main() {
	vector<string> a = { "marina", "josipa", "nikola", "vinko", "filipa" };
	vector<string> b = { "josipa", "filipa", "marina", "nikola" };
	cout << solution(a, b) << endl;
	return 0;
}