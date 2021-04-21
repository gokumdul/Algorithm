// 프로그래머스
// 레벨 2
// 카펫

// 완전탐색

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(int brown, int yellow) {
	vector<int> answer;
	int w, h, pw, ph;

	for (int i = 1; i <= sqrt(yellow); i++) {
		if (yellow % i == 0) {
			w = yellow / i;
			h = i;
			pw = w + 2;
			ph = h;
			if (pw * 2 + ph * 2 == brown) {
				answer.push_back(pw);
				answer.push_back(ph + 2);
			}
		}
	}

	//cout << answer[0] << ' ' << answer[1] << endl;
	return answer;
}

int main() {
	cout << /*solution(brown, yellow) <<*/ endl;

	return 0;
}
