#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

string numbers = "0123456789";

int solution(string s) {
	int answer = 0;
	vector<tuple<char, string, int>> num;
	string tmp = "";
	string tmp_num = "";
	bool chk = false;

	int idx_st = 0;
	int idx_end = 0;

	num.push_back(make_tuple('0', "zero", 4));
	num.push_back(make_tuple('1', "one", 3));
	num.push_back(make_tuple('2', "two", 3));
	num.push_back(make_tuple('3', "three", 5));
	num.push_back(make_tuple('4', "four", 4));
	num.push_back(make_tuple('5', "five", 4));
	num.push_back(make_tuple('6', "six", 3));
	num.push_back(make_tuple('7', "seven", 5));
	num.push_back(make_tuple('8', "eight", 5));
	num.push_back(make_tuple('9', "nine", 9));

	for (int i = 0; i < s.size(); i++) {
		chk = false;
		// 숫자를 찾으면 그대로 대입
		cout << "i is: " << i << endl;
		if (numbers.find(s[i]) != std::string::npos) {
			tmp += s[i];
			cout << "tmp is: " << tmp << endl;
		}
		// 숫자가 아니면
		else {
			tmp_num += s[i];
			for (int j = 0; j < num.size(); j++) {
				if (tmp_num == get<1>(num[j])) {
					tmp += get<0>(num[j]);
					tmp_num = "";
				}
			}
		}
	}
	answer = stoi(tmp);
	return answer;
}

int main() {
	cout << solution("one4seveneight8") << endl;

	return 0;
}