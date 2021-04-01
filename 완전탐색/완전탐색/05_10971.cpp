// 백준
// 10971 번
// 외판원순회 2

// TSP(Traveling Salesman Problem)
// vector

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// N: 도시 수, 2 <= N <= 10
int N;
// W: 도시간 이동 비용
int W[10][10];
// chk: 도시 방문했는지
bool chk[10];
// m: 순회의 최소 비용, 초기값은 최대 비용: 도시 10개가 최대니깐 1,000,000 *10
int m = 10000000;

void dfs(int st, int y, int sum, int cnt) {
	if (cnt == N && st == y) {
		if (m > sum)
			m = sum;
		return;
	}

	for (int x = 0; x < N; x++) {
		if (W[y][x] == 0)
			continue;
		if (!chk[y]) {
			chk[y] = 1;
			sum += W[y][x];

			if (sum <= m) {
				dfs(st, x, sum, cnt + 1);
			}

			chk[y] = 0;
			sum -= W[y][x];
		}

	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> W[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		dfs(i, i, 0, 0);
	}

	cout << m << '\n';

	return 0;
}