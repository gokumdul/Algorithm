// programmers
// 월간 코드 챌린지 시즌 1
// 두 개 뽑아서 더하기

// 벡터에서 중복제거 할 땐, sort 먼저하기

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numbers) {
	vector<int> answer;
	for (int i = 0; i < numbers.size(); i++) {
		for (int j = i + 1; j < numbers.size(); j++) {
			answer.push_back(numbers[i] + numbers[j]);
		}
	}
	sort(answer.begin(), answer.end());
	answer.erase(unique(answer.begin(), answer.end()), answer.end());
	return answer;
}