// 백준
// 6603 번
// 로또

// 수학, 조합론, 백트래킹, 재귀
// vector

#include <iostream>
#include <vector>

using namespace std;

int k;
int a[13];
int b[6];
void combination(int, int);


void combination(int start, int depth) {
	if (depth == 6) {
		for (int i = 0; i < 6; i++) {
			cout << b[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = start; i < k; i++) {
		b[depth] = a[i];
		combination(i + 1, depth + 1);
	}
}

int main() {
	while (true) {
		cin >> k;
		if (k == 0)
			break;
		else {
			for (int i = 0; i < k; i++) {
				cin >> a[i];
			}
			combination(0,0);
			cout << '\n';
		}
	}

	return 0;
}