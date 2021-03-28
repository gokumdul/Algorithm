// 백준
// 5585 번
// 거스름돈

//Greedy

#include <iostream>
#include <algorithm>

using namespace std;

//1000원은 고정 상수, price: 물건 값
const int paid{ 1000 };
int price, remain;
int change[6] = { 500, 100, 50, 10, 5, 1 };

//m: 몫, mod: 나머지, answer: 최종 동전 개수
int m, mod, answer;
int change_count() {
	remain = paid - price;

	for (int i = 0; i < 6; i++) {
		if (change[i] > remain) {
			continue;
		}
		else {
			m = remain / change[i];
			if (m > 0) {
				mod = remain - m * change[i];
				answer += m;
				remain = mod;
			}
			else {
				mod = remain;
			}
		}
	}

	return answer;
}


int main() {
	cin >> price;

	cout << change_count() << endl;

	return 0;
}