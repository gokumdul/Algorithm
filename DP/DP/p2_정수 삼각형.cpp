// 프로그래머스
// lvl3
// 정수 삼각형

// dfs

/*
	dp 문제이나 dfs 로 풀어버렸다.

	답은 맞는데 다음 두 이유로 문제풀이에 실패했다. ㅜㅜ
	실패(signal: segmentation fault(core dumped))
	실패(시간 초과)

	다음 풀이 방법은 dp로 풀것이다ㅠㅠ
*/ 

#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int answer = 0;
bool visit[50][50] = { 0 };

void dfs(vector<vector<int>> triangle, int x, int y, int tmp) {
	if (x == triangle.size()) {
		answer = max(answer, tmp);
		return;
	}

	if (!visit[x][y]) {
		visit[x][y] = true;
		tmp += triangle[x][y];
		dfs(triangle, x + 1, y, tmp);
		dfs(triangle, x + 1, y + 1, tmp);
		visit[x][y] = false;
	}
}

int solution(vector<vector<int>> triangle) {
	dfs(triangle, 0, 0, 0);

	return answer;
}