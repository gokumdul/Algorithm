// 백준
// 1012 번
// 유기농배추

// DFS

#include <iostream>
#include <vector>

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
	cnt++;
	isVisited[x][y] = 1;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= M || ny < 0 || ny >= N) {
			continue;
		}
		if (arr[nx][ny] == 1 && !isVisited[nx][ny])
			dfs(nx, ny);
	}

}

int main() {
	cin >> T;

	int x, y;
	for (int i = 0; i < T; i++) {
		cin >> M >> N >> K;
		vector<int> b;
		for (int j = 0; j < K; j++) {
			cin >> x >> y;
			arr[x][y] = 1;
		}
		for (int x = 0; x < M; x++) {
			for (int y = 0; y < N; y++) {
				if (arr[x][y] == 1 && !isVisited[x][y]) {
					cnt = 0;
					dfs(x, y);
					b.push_back(cnt);
				}
			}
		}
		ans.push_back(b.size());
	}

	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << '\n';
	}


	return 0;
}