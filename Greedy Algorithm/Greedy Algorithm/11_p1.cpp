// 프로그래머스
// 레벨 1
// 체육복

// 음.. 무엇보다 중복되는 애들 처리가 가장 중요했던 거 같다

// Greedy

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int n, tmp = 0, answer = 0;
vector<int> lost;
vector<int> reserve;

// test case: 5 [2, 3, 4][1, 2, 3] 4

int solution(int n, vector<int> lost, vector<int> reserve) {
	sort(lost.begin(), lost.end());
	sort(reserve.begin(), reserve.end());
	answer = n - lost.size();

	// 중복되는 수 tmp 추가 후 벡터에서 삭제
	for (int i = 0; i < reserve.size(); i++) {
		for (int j = 0; j < lost.size(); j++) {
			if (reserve[i] == lost[j]) {
				reserve.erase(reserve.begin() + i);
				lost.erase(lost.begin() + j);
				tmp++;
			}
		}
	}

	// 체육복 수 크기가 1차이 이상이 안나면 answer++
	for (int i = 0; i < reserve.size(); i++) {
		for (int j = 0; j < lost.size(); j++) {
			if (abs(reserve[i] - lost[j]) <= 1) {
				answer++;
				lost.erase(lost.begin());
				break;
			}
		}
	}

	// tmp 에는 체육복 하나씩 있는 애들 수니까 answer에 더해줌
	answer += tmp;
	return answer;
}

//int main() {
//	cin >> n;
//
//	lost.push_back(2);
//	lost.push_back(3);
//	lost.push_back(4);
//	//lost.push_back(4);
//
//	reserve.push_back(5);
//	reserve.push_back(2);
//	reserve.push_back(3);
//	//reserve.push_back(3);
//	//reserve.push_back(5);
//
//	greedy();
//
//
//	return 0;
//}