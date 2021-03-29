// 백준
// 10819 번
// 차이를 최대로

// 완전 탐색, 브루트포스, 백트래킹
// vector

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int N, st = 0;
int a[8];
bool isVisited[8];
vector<int> b;

int maxVal = 0, tmp = 0;
//void myMaxVal() {
//	for (int i = 0; i < N - 1; i++) {
//		if(st == 0)
//			maxVal += abs(b[i] - b[i + 1]);
//		else
//			tmp += abs(b[i] - b[i + 1]);
//	}
//	if (maxVal < tmp)
//		maxVal = tmp;
//	tmp = 0;
//}

void myMaxVal() {
	tmp = 0;
	for (int i = 0; i < N - 1; i++) {
		tmp += abs(b[i] - b[i + 1]);
	}
	maxVal = max(maxVal, tmp);
}

void dfs() {
	if (b.size() == N) {
		myMaxVal();
		st=1;
	}
	for (int i = 0; i < N; i++) {
		if (!isVisited[i]) {
			isVisited[i] = 1;
			b.push_back(a[i]);
			dfs();
			isVisited[i] = 0;
			b.pop_back();
		}
	}
	
}


int main() {
	cin >> N;
	int tmp;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	dfs();

	cout << maxVal << endl;
}