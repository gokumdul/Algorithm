// 백준
// 3687 번
// 성냥개비

// DP

#include <iostream>
#include <algorithm>
#define ll long long

using namespace std;

// T: test case
int T, n;
int num[9] = { 0, 0, 1, 7, 4, 2, 0, 8, 10 };
ll m_dp[101];

void DP() {
	for (int i = 1; i < 9; i++) {
		m_dp[i] = num[i];
	}
	m_dp[6] = 6;

	for (int i = 9; i < 101; i++) {
		m_dp[i] = m_dp[i - 2] * 10 + num[2];

		for (int j = 3; j < 8; j++) {
			m_dp[i] = min(m_dp[i], m_dp[i - j] * 10 + num[j]);
		}
	}
}

int main() {

	DP();
	cin >> T;

	while (T--) {
		cin >> n;

		cout << m_dp[n] << " ";

		string Max = "";
		while (n) {
			if (n % 2 != 0) {
				cout << 7;
				n -= 3;
			}
			else {
				cout << 1;
				n -= 2;
			}
		}

		cout << endl;
	}
}