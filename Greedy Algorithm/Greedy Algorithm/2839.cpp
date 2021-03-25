// 백준
// 2839번
// 설탕 배달

//Greedy

#include <iostream>

using namespace std;

int main() {
	//N 킬로그람, m 몫, mod 나머지, answer 답
	int N, m, mod, answer;

	cin >> N;
	m = N / 5;

	while (m >= 0) {

		answer = 0;
		mod = 0;

		if (m > 0) {
			mod = N - 5 * m;
			answer = m;
		}
		// m == 0
		else {
			mod = N;
		}

		answer += mod / 3;
		mod = mod % 3;

		if (mod == 0) {
			cout << answer;
			break;
		}
		m--;
	}
	if (mod != 0) {
		cout << -1;
	}
}