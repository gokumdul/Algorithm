// 프로그래머스

// 다리를 지나는 트럭
// lvl 2

// 큐 (FIFO)

#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	queue<int> q;
	int time = 0;
	int sum = 0;
	int truck = 0;

	while (1) {
		time++;

		if (q.size() == bridge_length) {
			sum -= q.front();
			q.pop();
		}

		if (sum + truck_weights[truck] <= weight) {
			if (truck == truck_weights.size() - 1) {
				time += bridge_length;
				break;
			}

			q.push(truck_weights[truck]);
			sum += truck_weights[truck];
			truck++;
		}
		else {
			q.push(0);
		}
	}
	return time;
}
