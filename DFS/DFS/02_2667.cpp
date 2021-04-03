// 백준
// 2667 번
// 단지번호붙이기

// DFS

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int arr[25][25];
bool isVisited[25][25];
int cnt = 0;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
vector<int> b;

void dfs(int x, int y) {
	cnt++;
	isVisited[x][y] = 1;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= N || ny < 0 || ny >= N)
			continue;
		if (arr[nx][ny] == 1 && !isVisited[nx][ny])
			dfs(nx, ny);
	}

}


int main() {
	cin >> N;

	//input에 공백없이 들어오므로,
	for (int i = 0; i < N; i++) {
		string tmp;
		cin >> tmp;
		for (int j = 0; j < N; j++)
			arr[i][j] = tmp[j] - '0';
	}


	for (int x = 0; x < N; x++) {
		for (int y = 0; y < N; y++) {
			if (arr[x][y] == 1 && !isVisited[x][y]) {
				cnt = 0;
				dfs(x, y);
				b.push_back(cnt);
			}
		}
	}

	sort(b.begin(), b.end());
	cout << b.size() << '\n';
	
	for (int i = 0; i < b.size(); i++)
		cout << b[i] << '\n';

	return 0;
}