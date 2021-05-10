// programmers
// 월간 코드 챌린지 시즌 1
// 3진법 뒤집기

// 오랜만에 stack 사용해서 풀었다
// LIFO

#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>
#include <cmath>

using namespace std;

string toThree(int n) {
	stack<int> tmp;
	string a = "";

	// m: 몫, mod: 나머지
	int m, mod;
	m = n;
	while (m != 0) {
		mod = m % 3;
		tmp.push(mod);
		m = m / 3;
	}
	while (!tmp.empty()) {
		a += to_string(tmp.top());
		tmp.pop();
	}
	return a;
}

// string threeReverse(string a){
//     string reversed = "";
//     for(int i = a.size()-1; i>=0; i--){
//         reversed += a[i];
//     }
//     cout << "reversed: " << reversed;
//     return reversed;
// }

int toTen(string n) {
	int tmp = 0;
	for (int i = 0; i < n.size(); i++) {
		tmp += (int)(n[i] - '0') * pow(3, i);
	}
	return tmp;
}

int solution(int n) {
	int answer = 0;
	string a;
	a = toThree(n);
	answer = toTen(a);

	return answer;
}