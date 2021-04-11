// 백준
// 4963 번
// 섬의 개수

// DFS

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int w, h;
int landNum = 0;
bool arr[50][50] = { 0 };
bool isVisited[50][50] = { 0 };

int dw[8] = { 1,0,-1,0,1,1,-1,-1 };
int dh[8] = { 0,1,0,-1,-1,1,-1,1 };

void dfs(int h, int w) {
	isVisited[h][w] = 1;

	for (int i = 0; i < 8; i++) {
		int nw = w + dw[i];
		int nh = h + dh[i];

		if (0 <= nw && nw < 50 && 0 <= nh && nh < 50) {
			if (arr[nh][nw] && !isVisited[nh][nw]) {
				isVisited[nh][nw] = true;
				dfs(nh, nw);
			}
		}
	}
}

int main() {
	while (true) {
		cin >> w >> h;

		if (w == 0 && h == 0)
			break;

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> arr[i][j];
			}
		}

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (arr[i][j] && !isVisited[i][j]) {
					landNum++;
					dfs(i, j);
				}
			}
		}

		cout << landNum << '\n';

		memset(arr, 0, sizeof(arr));
		memset(isVisited, 0, sizeof(isVisited));
		landNum = 0;
	}

	return 0;
}