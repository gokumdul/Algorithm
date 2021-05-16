// 프로그래머스
// lvl 3
// 가장 먼 노드

// 그래프

// 인생 첫 그래프 풀이
// bfs로 풀었다.

#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
	int answer = 0;
	int max = 0;
	queue<int> q;
	bool visited[20001] = { false, };
	bool check[20001][20001] = { false, };
	int dist[20001] = { 0, };

	sort(edge.begin(), edge.end());

	for (int i = 0; i < edge.size(); i++) {
		check[edge[i][0]][edge[i][1]] = true;
		check[edge[i][1]][edge[i][0]] = true;
	}

	q.push(1);
	visited[1] = true;

	while (!q.empty()) {
		int node = q.front();
		q.pop();

		for (int i = 2; i <= n; i++){
			if (check[node][i] && !visited[i]){
				q.push(i);
				visited[i] = true;
				dist[i] = dist[node] + 1;

				if (dist[i] > max)
					max = dist[i];
			}
		}
	}

	for (int i = 1; i <= n; i++){
		if (max == dist[i])
			answer++;
	}

	return answer;
}