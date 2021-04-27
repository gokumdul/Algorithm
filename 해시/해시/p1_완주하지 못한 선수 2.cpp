// 프로그래머스
// lvl1
// 완주하지 못한 선수

// 풀이 2 (효율성 성공)

// 해시

/*
  이번에는 vector 이용해 풀었으나
  다음번에는 unordered map 라이브러리를 이용해서 해쉬를 이용해 풀어야겠다.
 */

#include <string>
#include <vector>
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