// 프로그래머스
// 레벨 2
// 조이스틱

/**
 * 테스트 케이스 11 "ABABAAAAABA"인 경우처럼
 * 오른쪽으로 갔다가 다시 왼쪽으로 되돌아 오는 경우가 최소인 경우의 방법을 고려하는 것이 핵심이었다
 * 
 * + 음.. 더 생각해보니
 * 더 최적의 해를 위해서 i 가 name.size()의 half 까지만 고려해도 되겠다.
 * 그 이상부터는 무조건 오른쪽으로 한번에 가는게 최소 값이니깐
 *
 * ++ 최적해를 고려하여 코드 첫 for 문의 조건을 name.size()/2로 변경하였다.
 *
 */

// Greedy

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int solution(string name) {
	int answer = 0;
	int last = 0;
	int num = name.size()-1;
	for (int i = 0; i < name.size() / 2; i++) {
		for (int j = i+1; j < name.size(); j++) {
			if (name[j] != 'A') {
				last = name.size()-j;
				break;
			}
		}
		num = min(num, i * 2 + last);
	}

	//answer = 'Z' - 'A'; // 25
	for (char a : name) {
		if (a > 'N')
			answer += 13 - (a - 'N');
		else {
			answer += a - 'A';	
		}
	}
	cout << "num is: " << num << endl;
	cout << "answer is: " << answer << endl;
	answer += num;
	return answer;
}


int main() {
	cout << solution("ABABAAAAABA") << endl;

	return 0;
}