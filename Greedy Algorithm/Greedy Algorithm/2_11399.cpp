// 백준
// 11399번
// ATM

//Greedy

#include <iostream>
#include <algorithm>

using namespace std;

// 1 <= N <= 1000
// 1. sorting
// 2. 합

int main() {
	int N, answer;
	int t[1000];

	cin >> N;
	answer = 0;

	for (int i = 0; i < N; i++) {
		cin >> t[i];
	}

	sort(t, t + N);

	for (int i = 0; i < N; i++) {
		answer += t[i]*(N-i);
	}

	cout << answer;


	return 0;
}