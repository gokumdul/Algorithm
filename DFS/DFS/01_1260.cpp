// 백준
// 1260 번
// DFS 와 BFS

// DFS, BFS

#include <iostream>
#include <queue>

using namespace std;


// N: node, M: edge, start: start node
int N, M, start;
bool edge[1001][1001] = { 0 };
int b[1001];
bool isVisited[1001];


void DFS(int start){
	cout << start << ' ';
	isVisited[start] = 1;
	for (int i = 1; i <= N; i++) {
		if(!isVisited[i] && edge[start][i] != 0)
			DFS(i);
	}
}

void BFS(int start) {
	queue<int> q;
	q.push(start);
	isVisited[start] = 0;

	while (!q.empty()) {
		start = q.front();
		cout << start << ' ';
		q.pop();
		for (int i = 1; i <= N; i++) {
			if (isVisited[i] && edge[start][i] != 0) {
				q.push(i);
				isVisited[i] = 0;
			}
		}
	}
}

int main() {
	cin >> N >> M >> start;
	int x, y;
	for (int i = 0; i < M; i++) {
		cin >> x >> y;
		edge[x][y] = 1;
		edge[y][x] = 1;
	}

	DFS(start);
	cout << endl;
	BFS(start);

	return 0;
}