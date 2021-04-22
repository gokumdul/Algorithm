// programmers
// 테스트

// greedy

// 베베 꼬아 생각해서 푸느라 너무 오래걸린 문제.. 진짜 바보같이 풀었더라
// iterator 쓰고 find 쓰는 것도 괜찮은 풀이였겠다.

// x 좌표 vector, y좌표 vector, 1차원으로 새로 생성하고
// iter find() 써서 end면 x[0], end아니면 리턴값이 2일땐 x[1], 3일땐 x[2]
// 해서 int x 값 할당해주면 될 거 같다


#include <iostream>
#include <vector>
using namespace std;

vector<int> ans;

void solution(vector<vector<int> > v) {
	vector<int> ans;
	int x = v[0][0];
	int y = v[0][1];

	if (x == v[1][0]) {
		x = v[2][0];
	}
	else {
		if (v[1][0] != v[2][0]) {
			x = v[1][0];
		}
	}

	if (y == v[1][1]) {
		y = v[2][1];
	}
	else {
		if (v[1][1] != v[2][1]) {
			y = v[1][1];
		}
	}

	ans.push_back(x);
	ans.push_back(y);

	//return ans;
}

int main() {
	vector<vector<int>> v = { {1, 4},{3, 4},{3, 10} };
	solution(v);

	/*for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << endl;
	}*/


	return 0;
}