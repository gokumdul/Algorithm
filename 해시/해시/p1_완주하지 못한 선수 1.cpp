// 프로그래머스
// lvl1
// 완주하지 못한 선수

// 풀이 1

// 해시

/*
  시간초과로 인한 효율성 실패
 */

#include <string>
#include <vector>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
	string answer = "";
	for (int i = 0; i < completion.size(); i++) {
		for (int j = 0; j < participant.size(); j++) {
			if (completion[i] == participant[j]) {
				participant.erase(participant.begin() + j);
				j--;
				break;
			}
		}
	}
	answer = participant[0];

	return answer;
}