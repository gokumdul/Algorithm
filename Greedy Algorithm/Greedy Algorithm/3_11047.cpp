// 백준
// 11047번
// 동전 0

//Greedy

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	//N: 동전 종류 수, total: 최종 만들어야 하는 값, tmp: 최종 값보다 동전 값이 큰지 확인 위함
	int N, total, tmp, cnt, answer;
	int value[10];

	cin >> N >> total;
	cnt = 0;
	// 동전 종류 입력받음
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		if (tmp > total) {
			continue;
		}
		else {
			value[cnt] = tmp;
			cnt++;
		}
	}

	answer = 0;

	int m, mod;
	//m: 몫, mod: 나머지
	for (int i = cnt-1; i >= 0; i--) {
		m = total / value[i];
		if (m > 0) {
			answer += m;
			mod = total - m * value[i];
		}
		else if (m == 0  && mod == 0){
			break;
		}
		else {
			mod = total;
		}
		total = mod;
	}

	cout << answer;


	return 0;
}