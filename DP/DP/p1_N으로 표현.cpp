// 프로그래머스
// lvl3
// N으로 표현

// dfs

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int answer = 9;

void dfs(int N, int number, int cnt, int cal) {
	if (cnt >= 9) {
		return;
	}
	if (cal == number) {
		answer = min(answer, cnt);
		return;
	}

	int tempnum = 0;
	for (int i = 0; i+cnt < 9; i++) {
		tempnum = tempnum * 10 + N;
		dfs(N, number, cnt + 1+i, cal + tempnum);
		dfs(N, number, cnt + 1+i, cal - tempnum);
		dfs(N, number, cnt + 1+i, cal * tempnum);
		dfs(N, number, cnt + 1+i, cal / tempnum);
	}

}

int solution(int N, int number) {

	//N: base, number: 조합의 결과로 만들어질 수
	dfs(N, number, 0, 0);
	if (answer == 9)
		return -1;

	return answer;
}

int main() {
	cout << solution(5, 12) << endl;


	return 0;
}