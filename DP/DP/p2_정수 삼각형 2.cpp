// 프로그래머스
// lvl3
// 정수 삼각형

// dp

// 정확성: 64.3
// 효율성: 35.7

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {
	int answer = 0;
	int ans[500][1300] = { 0 };
	ans[0][0] = triangle[0][0];
	for (int i = 1; i < triangle.size(); i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0) {
				ans[i][j] = ans[i - 1][j] + triangle[i][j];
			}
			else if (j == i) {
				ans[i][j] = ans[i - 1][j - 1] + triangle[i][j];
			}
			else {
				ans[i][j] = max(ans[i - 1][j], ans[i - 1][j - 1]) + triangle[i][j];
			}
			if (i == triangle.size() - 1) {
				answer = max(answer, ans[i][j]);
			}
		}
	}
	return answer;
}