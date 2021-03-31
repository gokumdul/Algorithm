// ¹éÁØ
// 2309 ¹ø
// ÀÏ°ö³­ÀïÀÌ

// dfs
// vector

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int sm[9];
int b[7];


int tmp = 0;
void dfs(int start, int depth) {
	if (depth == 7) {
		for (int i = 0; i < 7; i++) {
			tmp += b[i];
		}
		if (tmp == 100) {
			sort(b, b + 7);
			for (int i = 0; i < 7; i++) {
				cout << b[i] << '\n';
			}
		}
		tmp = 0;
	}

	for (int i = start; i < 9; i++) {
		b[depth] = sm[i];
		dfs(i + 1, depth + 1);
	}

}

int main() {
	for (int i = 0; i < 9; i++) {
		cin >> sm[i];
	}
	dfs(0,0);

	return 0;
}