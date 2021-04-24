// 프로그래머스
// lvl3
// 등굣길

// greedy

/*
	답은 맞으나 효율성에서 실패

	음 dp로 푼다고 풀었는데
	greedy로 푼정도 밖에 안되는거 같다.

	가상의 0좌표엔 0을 부여하고,
	집엔 1을 부여한다.
	물웅덩이는 0
	초기값 부여시에는 visit = true;
	
	for 문을 돌며 visit = false; 일 때,
	(x,y) = (x-1,y) + (x,y-1)
*/

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int ans[100][100] = { 0 };
bool visit[100][100] = { false };

int solution(int m, int n, vector<vector<int>> puddles) {
	int answer = 0;

	for (int i = 0; i < m; i++) {
		ans[i][0] = 0;
	}
	for (int j = 0; j < m; j++) {
		ans[0][j] = 0;
	}
	for (int i = 0; i < puddles.size(); i++) {
		visit[puddles[i][0]][puddles[i][1]] = true;
		ans[puddles[i][0]][puddles[i][1]] = 0;
	}
	ans[1][1] = 1;

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == 1 && j == 1)
				continue;
			if (!visit[i][j]) {
				visit[i][j] = true;
				ans[i][j] = ans[i][j - 1] + ans[i - 1][j];
			}
		}
	}
	answer = ans[m][n];

	return answer;
}