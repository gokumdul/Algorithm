#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

int numDivide(int n) {
	int elenum = 0;
	for (int i = 1; i <= n; i++) {
		if (n % i == 0)
			elenum++;
	}
	return elenum;
}

int solution(int left, int right) {
	int answer = 0;
	for (int i = left; i <= right; i++) {
		if (numDivide(i) % 2 == 0) {
			answer += i;
		}
		else {
			answer -= i;
		}
	}

	return answer;
}