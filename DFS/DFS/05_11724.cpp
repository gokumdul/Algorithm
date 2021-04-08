// 백준
// 11724 번
// 연결 요소의 개수

// DFS, undirected graph

#include <iostream>
#include <vector>

using namespace std;

// N: node, M: edge
int N, M;
bool isVisited[1001] = { 0 };
vector<int> arr[1001];


void dfs(int start) {
	isVisited[start] = 1;
	for (int i = 0; i < arr[start].size(); i++) {
		int next = arr[start][i];
		if (!isVisited[next])
			dfs(next);
	}
}

int main() {
	cin >> N >> M;

	int x, y;
	for (int i = 0; i < M; i++) {
		cin >> x >> y;
		arr[x].push_back(y);
		arr[y].push_back(x);
	}

	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		if (!isVisited[i]) {
			dfs(i);
			cnt++;
		}
	}

	cout << cnt << endl;

	return 0;
}