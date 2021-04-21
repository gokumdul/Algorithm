// 프로그래머스
// 레벨 2
// 구명 보트

// Greedy

// 효율성에서 틀려버렸다.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> people;
int limit = 100;

int solution() {
	int answer = 0;

	sort(people.rbegin(), people.rend());

	int mod = 0; int cnt = 0;
	for (int i = 0; i < people.size(); i++) {
		cnt++;
		mod = limit - people[i];

		for (int j = i + 1; j < people.size(); j++) {
			if (mod - people[j] >= 0 && cnt == 1) {
				people.erase(people.begin()+j);
				answer++;
				cnt = 0;
			}
		}
		if (cnt == 1) {
			answer++;
			cnt = 0;
		}
	}

	return answer;
}


int main() {
	people.push_back(70);
	people.push_back(50);
	people.push_back(80);
	people.push_back(50);

	cout << solution() << endl;

	return 0;
}