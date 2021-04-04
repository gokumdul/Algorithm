// 백준
// 2606 번
// 바이러스

// 플로이드 와샬

#include<iostream>

using namespace std;

int node, edge;
int edge_arr[101][101] = { 0 };
int virus;

int main()
{
	cin >> node >> edge;
	for (int i = 1; i <= node; i++) {
		for (int j = 1; j <= node; j++) {
			edge_arr[i][j] = 10000;
		}
	}

	int x, y;
	for (int i = 0; i < edge; i++) {
		cin >> x >> y;
		edge_arr[x][y] = 1;
		edge_arr[y][x] = 1;
	}

	for (int k = 1; k <= node; k++) {
		for (int i = 1; i <= node; i++) {
			for (int j = 1; j <= node; j++) {
				if (edge_arr[i][j] > edge_arr[i][k] + edge_arr[k][j]) { 
					edge_arr[i][j] = edge_arr[i][k] + edge_arr[k][j];
				}
			}
		}
	}

	for (int i = 2; i <= node; i++)
	{
		virus += edge_arr[1][i] != 10000;
	}

	cout << virus;

	return 0;
}
