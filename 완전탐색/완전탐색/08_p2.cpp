// 프로그래머스
// 레벨 2
// 소수찾기

// 완전탐색

#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

bool isPrime(int n) {
	if (n < 2) {
		return false;
	}

	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0)
			return false;
	}

	return true;
}

int solution(string numbers) {
	int answer = 0;
	vector<char> paper;
	vector<int> rnum;
	for (char a : numbers) {
		paper.push_back(a);
	}
	sort(paper.begin(), paper.end());

	do {
		string tmp = "";
		for (int i = 0; i < paper.size(); i++) {
			tmp.push_back(paper[i]);
			rnum.push_back(stoi(tmp));
		}
	} while (next_permutation(paper.begin(), paper.end()));

	sort(rnum.begin(), rnum.end());
	rnum.erase(unique(rnum.begin(),rnum.end()),rnum.end());

	for (int i = 0; i < rnum.size(); i++) {
		if (isPrime(rnum[i]))
			answer++;
	}
	return answer;
}


int main() {


	return 0;
}