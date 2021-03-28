// 백준
// 2217 번
// 로프

// Greedy

#include <iostream>
#include <algorithm>

using namespace std;

int N, _maxVal;
int rope[100000];

int maxVal() {
	sort(rope, rope + N);
	
	for (int i = 0; i < N; i++) {
		rope[i] = rope[i] * (N-i);

		if (i == 0) {
			_maxVal = rope[i];
		}
		else {
			if (_maxVal < rope[i])
				_maxVal = rope[i];
		}
	}

	return _maxVal;
}

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> rope[i];
	}

	cout << maxVal() << endl;

	return 0;
}