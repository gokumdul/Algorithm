#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cmath>
#include <stack>

//ㅋ.. 효율성 0

using namespace std;

string toString(long long int n) {
	std::stringstream s;
	s << n;
	return s.str();
}

string toTwo(long long n) {
	stack<long long> tmp;
	string a = "";
	if (n == 0)
		return "0";

	// m: 몫, mod: 나머지
	long long m, mod;
	m = n;
	while (m != 0) {
		mod = m % 2;
		tmp.push(mod);
		m = m / 2;
	}
	while (!tmp.empty()) {
		a += to_string(tmp.top());
		tmp.pop();
	}
	return a;
}

long long toTen(string s_numTwo) {
	long long numTen = 0;
	for (long long i = 0; i < s_numTwo.size(); i++) {
		if (s_numTwo[i] == '1') {
			numTen += pow(2,s_numTwo.size()-i-1);
		}
		else {
			continue;
		}
	}
	return numTen;
}

vector<long long> solution(vector<long long> numbers) {
	vector<long long> answer;
	string s_numTwo;
	long long numTen;
	for (long long i = 0; i < numbers.size(); i++) {
		s_numTwo = toTwo(numbers[i]);
		cout << "origin num: " << numbers[i] << " " << "s_numTwo: " << s_numTwo << endl;

		// 1: 끝에서부터 처음 시작하는 1까지 0있는지 확인
		// 2: 없으면 맨앞에 1붙이고 그다음수 0
		for (long long k = s_numTwo.size()-1; k >= 0; k--) {
			// 1
			if (s_numTwo[k] == '0') {
				s_numTwo[k] = '1';
				if (!(k >= s_numTwo.size() - 1)) {
					s_numTwo[k + 1] = '0';
				}
				if(toTen(s_numTwo) == numbers[i])
					s_numTwo[s_numTwo.size() - 1] = '1';
				break;
			}
			// 2
			else if (k == 0) {
				s_numTwo[0] = '0';
				s_numTwo = "1" + s_numTwo;
			}
		}
		numTen = toTen(s_numTwo);
		cout << "numTen: " << numTen << " bigger SnumTwo: " << s_numTwo << endl;
		cout << endl;
		answer.push_back(numTen);
	}
	return answer;
}

int main() {
	vector<long long> answer;
	vector<long long> numbers = {0,1,2,3,4,5,6,7,8,9,10,1000000000000000,999999999999999};

	answer = solution(numbers);
	for (long long i = 0; i < answer.size(); i++) {
		cout << answer[i] << endl;
	}

	return 0;
}