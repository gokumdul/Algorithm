// 프로그래머스
// lvl 3
// 단어변환

// DFS


#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int answer = 50;
vector<bool> visit(50, false);

void dfs(string begin, string target, vector<string>& words, int rst) {
	if (begin == target) {
		answer = min(answer, rst);
	}

	for (int i = 0; i < words.size(); i++) {
		int cnt = 0;
		for (int j = 0; j < words[i].size(); j++) {
			if (begin[j] != words[i][j]) {
				cnt++;
			}
			if (cnt == 2)
				break;
		}
		if (cnt == 1) {
			if (!visit[i]) {
				visit[i] = true;
				dfs(words[i], target, words, rst + 1);
				visit[i] = false;
			}
		}
	}
}

int solution(string begin, string target, vector<string> words) {

	dfs(begin, target, words, 0);
	if (answer == 50) answer = 0;

	return answer;
}