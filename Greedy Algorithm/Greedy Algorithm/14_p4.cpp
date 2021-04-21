// 프로그래머스
// 레벨 2
// 구명 보트

// Greedy

// 효율성에서 틀려버렸다.
/**
   1. 풀이
   - 백터 내림차순 정렬
   - 두 번의 for문
   - 복잡도: O(n^2)
 */

/**
   2. 풀이
   -  효율성 제고를 위해, 벡터의 첫값 끝값씩만 비교했다.
   - 복잡도: O(n)
 */

 

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

int solution2() {
	int answer = 0;
	int head = 0, tail = people.size() - 1;
	sort(people.begin(), people.end()); // 오름차순으로 정렬 

	while (head <= tail) {
		if (people[head] + people[tail] <= limit) {
			head++;
			tail--;
		}
		else {
			tail--;
		}
		answer++;
	}
	return answer;
}


int main() {
	people.push_back(70);
	people.push_back(50);
	people.push_back(80);
	people.push_back(50);

	cout << solution2() << endl;

	return 0;
}