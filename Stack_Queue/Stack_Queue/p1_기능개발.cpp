// 프로그래머스

// 기능개발
// lvl 2

// 스택/큐


#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;
	vector<int> remain;
	int tmp;

	for (int i = 0; i < progresses.size(); i++) {
		tmp = (100 - progresses[i]) % speeds[i];
		if (tmp == 0) {
			remain.push_back((100 - progresses[i]) / speeds[i]);
		}
		else {
			remain.push_back(((100 - progresses[i]) / speeds[i]) + 1);
		}
	}
	cout << "remain: ";
	for (int i = 0; i < remain.size(); i++) {
		cout << remain[i] << ' ';
	}
	cout << endl;
 	
	int tmp2 = 1;
	int tmp3;
	for (int i = 0; i < remain.size(); i++) {
		tmp3 = i;
		for (int j = i+1; j < remain.size(); j++) {
			// 7 3 9
			if (remain[tmp3] >= remain[j]) {
				tmp2++;
				i = j;
			}
			else {
				break;
			}
		}
		//cout << "i: " << i << endl;
		answer.push_back(tmp2);
		tmp2 = 1;
	}

	return answer;
}

int main() {
	vector<int> answer;
	vector<int> progresses = { 99, 1, 99, 1 };
	vector<int> speeds = { 1, 1, 1, 1 };

	answer = solution(progresses, speeds);

	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << ' ';
	}
	cout << '\n';

	return 0;
}