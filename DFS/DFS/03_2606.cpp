// 백준
// 2606 번
// 바이러스

// DFS
// 런타임 에러남!

#include <iostream>

using namespace std;

int node, edge;
int edge_arr[101][101] = { 0 };
bool isVisited[101] = { 0 };
int virus = 0;

void dfs(int start) {
	isVisited[start] = 1;
	virus++;

	for (int i = 1; i <= edge; i++) {
		if (edge_arr[start][i] == 1 && !isVisited[i]) {
			dfs(i);
		}
	}
}


int main() {
	cin >> node >> edge;

	int x, y;
	for (int i = 0; i < edge; i++) {
		cin >> x >> y;
		edge_arr[x][y] = 1;
		edge_arr[y][x] = 1;
	}

	dfs(1);

	cout << virus - 1;

	return 0;
}