// 프로그래머스
// 레벨 1
// 모의고사

/**
 * 아아닛,,
 * 문제 개수를 10000개, answer를 5개로 고정해 놓고 풀어서 시간 너무 허비했다
 * 문제를 잘 읽자..!!!!!!
 */

 // 완전탐색

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> answers;
vector<int> answer;

int question = 10000;

int a[5] =  { 1, 2, 3, 4, 5 }; 
int b[8] =  { 2, 1, 2, 3, 2, 4, 2, 5 }; 
int c[10] = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };

int myans[3] = { 0 };

void solution() {
	for (int i = 0; i<answers.size(); i++) {
		if (a[i % 5] == answers[i])
			myans[0]++;
		if (b[i % 8] == answers[i])
			myans[1]++;
		if (c[i % 10] == answers[i])
			myans[2]++;
	}

	int _max = max(max(myans[0],myans[1]),myans[2]);

	for (int i = 0; i < 3; i++) {
		if (myans[i] == _max) {
			answer.push_back(i + 1);
		}
	}

	//return answer;
}



int main() {
	answers.push_back(1);
	answers.push_back(3);
	answers.push_back(2);
	answers.push_back(4);
	answers.push_back(2);

	solution();

	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << endl;
	}
	

	return 0;
}