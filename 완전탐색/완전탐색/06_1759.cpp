// 백준
// 1759 번
// 암호 만들기

// 완전 탐색, dfs, 조합, 문자열
// vector

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// L: 비밀번호 자리 수, C: 알파벳 갯수
int L, C;
char alphabet[15];
char b[15];
string vowel = "aeiou";

bool chk() {
	int vCnt = 0; 
	int cCnt = 0;

	for (int i = 0; i < L; i++) {
		if (vowel.find(b[i]) < vowel.size())
			vCnt++;
		else
			cCnt++;
	}
	return (vCnt >= 1 && cCnt >= 2);
}

void dfs(int start, int depth) {
	if (depth == L) {
		if (chk()) {
			for (int i = 0; i < L; i++) {
				//아 미친,,, 아래 공백 넣어놔서 틀렸었음 미친,,,
				//cout << b[i] << ' ';
				cout << b[i];
			}
			cout << '\n';
		}
		return;
	}
	for (int i = start; i < C; i++) {
		b[depth] = alphabet[i];
		dfs(i + 1, depth + 1);
	}
}

int main() {
	cin >> L >> C;

	for (int i = 0; i < C; i++) {
		cin >> alphabet[i];
	}

	sort(alphabet, alphabet + C);
	
	dfs(0,0);

	return 0;
}