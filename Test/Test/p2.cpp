// programmers
// Summer/Winter Coding(~2018)
// 방문길이

/*
	키포인트!
  1. 좌표계 벗어날 때
  2. 방향성 고려
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool went[11][11][11][11] = { false };

int solution(string dirs) {
	int answer = 0;
	// start x, start y, end x, end y
	int sx = 5, sy = 5, ex = 5, ey = 5;
	for (char a : dirs) {
		cout << a << endl;
		if (a == 'U')
			ey += 1;
		else if (a == 'R')
			ex += 1;
		else if (a == 'D')
			ey -= 1;
		else if (a == 'L')
			ex -= 1;

		// 좌표계 벗어날 때
		if (ex < 0)
			ex = 0;
		else if (ex > 10)
			ex = 10;
		else if (ey < 0)
			ey = 0;
		else if (ey > 10)
			ey = 10;

		// 출발지 도착지 같은 경우 제외
		if (sx == ex && sy == ey)
			continue;

		// 만약 (0,0) 에서 (0,1) 로 간 경우에는
		// went[0][0][0][1] 고려하고
		// went[0][1][0][0] 도 고려해야 한다.
		// ****** 핵심: 방향성 고려하기!! ******
		if (went[sx][sy][ex][ey] != 1 && went[ex][ey][sx][sy] != 1) {
			answer++;
			went[sx][sy][ex][ey] = 1;
			went[ex][ey][sx][sy] = 1;
		}
		sx = ex;
		sy = ey;
	}


	return answer;
}

int main() {
	string a = "RRRRRRRRRRRRRRRRRRRRRUUUUUUUUUUUUULU";
	cout << solution(a) << endl;

}