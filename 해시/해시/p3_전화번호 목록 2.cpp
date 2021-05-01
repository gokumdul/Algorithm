// 프로그래머스
// lvl2
// 전화번호 목록

// 풀이 2

/*
	phone_book[i]의 값을 phone_book의 index i+1 부터, .size()의 끝까지 탐색했었는데,
사실 생각해보니 바로 i+1 값만 확인하면 된다.
*/

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
	bool answer = true;
	vector<string> a;

	sort(phone_book.begin(), phone_book.end());
	for (int i = 0; i < phone_book.size()-1; i++) {
			if (phone_book[i+1].find(phone_book[i]) == 0) {
				return false;
		}
	}

	return answer;
}

int main() {
	vector<string> phone_book = { "119", "97674223", "1195524421" };
	cout << solution(phone_book) << endl;

	return 0;
}