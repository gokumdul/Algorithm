// 백준
// 10162 번
// 전자레인지

// Greedy

#include <iostream>
#include <algorithm>

using namespace std;

//total: 최종 전자레인지 돌릴 초 <= 10,000
int total;
//a: 300초, b: 60초, c: 10초 버튼 눌린 횟수
int a = 0, b = 0, c = 0;
//m: 몫, mod: 나머지
int m, mod;

int button[3] = { 300, 60, 10 };


void microwave() {
	if (total % 10 != 0) {
		cout << "-1" << endl;
		return;
	}
	else {
		for (int i = 0; i < 3; i++) {
			if (button[i] <= total) {
				m = total / button[i];
				mod = total - m * button[i];
				total = mod;

				if (i == 0)
					a+=m;
				else if (i == 1)
					b+=m;
				else
					c+=m;
			}
		}
	}


	cout << a << " " << b << " " << c << endl;
}

int main() {
	cin >> total;

	microwave();

	return 0;
}