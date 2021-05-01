// 프로그래머스
// lvl2
// 전화번호 목록

// 풀이 1


#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

/*
	처음풀이는,
	phone_book[j].find(phone_book[i]) != std::string::npos
	의 조건으로 풀었기에
	접두사가 아닐 때도 false를 반환해서 틀렸다

	무조건 접두사야 하므로
	phone_book[j].find(phone_book[i] ) == 0
	조건으로 변경!
	그랬더니 답은 맞았으나 효율성 3, 4 번 틀림!
*/

bool solution(vector<string> phone_book) {
	bool answer = true;

	vector<string> a;

	sort(phone_book.begin(), phone_book.end());
	for (int i = 0; i < phone_book.size(); i++) {
		for (int j = i + 1; j < phone_book.size(); j++) {
			if (phone_book[j].find(phone_book[i]) == 0) {
				return false;
			}
		}
	}


	return answer;
}

int main() {
	vector<string> phone_book = { "119", "97674223", "1195524421" };
	cout << solution(phone_book) << endl;

	return 0;
}