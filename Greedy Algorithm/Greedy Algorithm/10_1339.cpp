// 백준
// 10162 번
// 전자레인지

// alphaMathVal() - else - for - if 문에 'break;' 안 넣어 줘서 한참을 고생했던 문제 ㅜㅜ

// Greedy

#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

// N: 단어 개수
int N, answer = 0;
string s[10];

struct my {
	char alphabet;
	int  cnt;
};

bool sort_by_cnt(const my& m1, const my& m2) {
	return m1.cnt > m2.cnt;
}

my _my[10];
int st = 0;

int alphaMathVal() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < s[i].size(); j++) {
			if (i == 0 && j == 0) {
				_my[0].alphabet = s[0].at(0);
				_my[0].cnt = pow(10, s[0].size()-j-1);
				st = 1;
			}
			else {
				for (int k = 0; k < st; k++) {
					if (_my[k].alphabet == s[i].at(j)) {
						_my[k].cnt += pow(10, s[i].size() - j - 1);
						break;
					}
					else {
						if (k == st - 1) {
							_my[st].alphabet = s[i].at(j);
							_my[st].cnt = pow(10, s[i].size() - j - 1);
							st++;
							break;
						}
					}
				}
			}
		}
	}
	
	sort(_my, _my + st, sort_by_cnt);
	for (int i = 0; i < st; i++) {
		answer += _my[i].cnt * (9 - i);
	}

//	for (int i = 0; i < st; i++) {
//		cout << _my[i].alphabet << " " << _my[i].cnt << endl;
//	}

	return answer;
}

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> s[i];
	}

	cout << alphaMathVal() << endl;

	return 0;
}