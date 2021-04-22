// 프로그래머스
// lvl 2
// 타겟넘버

// DFS

#include <iostream>
#include <vector>

using namespace std;

int answer = 0;

void dfs(vector<int> numbers, int target, int sum, int count) {
	if (numbers.size() == count) {
		if (target == sum) answer++;
		return;
	}

	dfs(numbers, target, sum + numbers[count], count + 1);
	dfs(numbers, target, sum - numbers[count], count + 1);
}

int solution(vector<int> numbers, int target) {
	dfs(numbers, target, 0, 0);
	return answer;
}