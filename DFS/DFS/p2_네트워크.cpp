// 프로그래머스
// lvl 3
// 네트워크

// DFS

#include <string>
#include <vector>

using namespace std;

void dfs(int p, vector<vector<int>>& computers, vector<bool>& visit, int n) {
	visit[p] = true;

	for (int i = 0; i < n; i++) {
		if (!visit[i] && computers[p][i])
			dfs(i, computers, visit, n);
	}
}


int solution(int n, vector<vector<int>> computers) {
	int answer = 0;

	vector<bool> visit(n, false);

	for (int i = 0; i < n; i++) {
		if (!visit[i]) {
			answer++;
			dfs(i, computers, visit, n);
		}
	}

	return answer;
}