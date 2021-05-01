// 프로그래머스
// lvl2
// 위장

// 풀이 1

// 해시

#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

struct cloth{
	string what;
	string type;
};

int solution(vector<vector<string>> clothes) {
	int answer = 1;
	map<string, int> m;
	for (auto cloth : clothes) {
		m[cloth[1]] += 1;
	}

	for (auto it = m.begin(); it != m.end(); it++) {
		answer *= it->second + 1;
	}

	return answer - 1;
}

int main() {
	vector<vector<string>> clothes = { {"yellowhat", "headgear"},{"bluesunglasses", "eyewear"},{"green_turban", "headgear"} };
	cout << solution(clothes) << endl;


	return 0;
}