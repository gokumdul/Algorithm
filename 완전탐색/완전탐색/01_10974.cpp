// 백준
// 10974번
// 모든 순열

// 완전 탐색, dfs
// vector

#include <iostream>
#include <vector>

using namespace std;

void dfs();
vector<int> v;
int n; // 1<=n<=8
bool isVisited[9];

void dfs() {
	if (v.size() == n) {
		for (int i = 0; i < n; i++) {
			cout << v[i] << ' ';
		}
		//endl; 이 flush를 같이해서 속도 저하의 원인이 됨
		//cout << endl;
		cout << '\n';
	}
	for (int i = 1; i <= n; i++) {
		if (!isVisited[i]) {
			isVisited[i] = 1;
			v.push_back(i);
			dfs();
			isVisited[i] = 0;
			v.pop_back();
		}
	}


}

int main() {
	cin >> n;
	dfs();
	return 0;
}