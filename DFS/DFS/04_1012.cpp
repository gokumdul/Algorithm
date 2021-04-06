// 백준
// 1012 번
// 유기농배추

// DFS

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

// T: 테스트 케이스 수, M: 가로길이, N: 세로길이, K: 배추 개수
int T, M, N, K;
bool arr[50][50] = { 0 };
bool isVisited[50][50] = { 0 };
vector<int> ans;
int cnt = 0;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

void dfs(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= M || ny < 0 || ny >= N) {
			continue;
		}
		if (arr[nx][ny] == 1 && !isVisited[nx][ny]) {
			isVisited[nx][ny] = 1;
			dfs(nx, ny);
		}
	}

}

int main() {
	cin >> T;

	int x, y;
	for (int i = 0; i < T; i++) {
		cin >> M >> N >> K;

		memset(arr, 0, sizeof(arr));
		memset(isVisited, 0, sizeof(isVisited));
		cnt = 0;

		for (int j = 0; j < K; j++) {
			cin >> x >> y;
			arr[x][y] = 1;
		}
		for (int x = 0; x < M; x++) {
			for (int y = 0; y < N; y++) {
				if (arr[x][y] == 1 && !isVisited[x][y]) {
					cnt++;
					isVisited[x][y] = 1;
					dfs(x, y);
				}
			}
		}
		ans.push_back(cnt);
	}

	for (int i = 0; i < T; i++)
		cout << ans[i] << endl;

	return 0;
}