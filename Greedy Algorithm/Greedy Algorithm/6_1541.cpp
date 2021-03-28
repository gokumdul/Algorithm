// 백준
// 1541 번
// 잃어버린 괄호

// Greedy, 문자열 처리

// 최적해: '-' 이후 수 전부 '-'처리 

#include <iostream>
#include <string>

using namespace std;

// s: 입력받는 수식, answer: 최소 값
string s;
string tmp = "";
bool minusFlag = false;
int answer = 0;

int get_minVal() {
	for (int i = 0; i <= s.size(); i++) {
		if (s[i] == '+' || s[i] == '-' || s[i] == '\0') {
			if (!minusFlag) {
				answer += stoi(tmp);
			}
			else {
				answer -= stoi(tmp);
			}

			if (s[i] == '-') {
				minusFlag = true;
			}

			tmp = "";
			continue;
		}
		tmp += s[i];
	}

	return answer;
}

int main() {
	cin >> s;
	
	cout << get_minVal() << endl;

	return 0;
}