#include <string>
#include <vector>
#include <iostream>

using namespace std;

int check(char c, int y, int x, vector<string> mmap) {
	if (c == 'P') {
		if (mmap[y - 1][x] == 'P') {
			cout << "1" << endl;
			return 0;
		} 
		else if (mmap[y][x - 1] == 'P') {
			cout << "2" << endl;
			return 0;
		} 
		else if (mmap[y][x + 1] == 'P') {
			cout << "3" << endl;
			return 0;
		} 
		else if (mmap[y + 1][x] == 'P') {
			cout << "4" << endl;
			return 0;
		}
		else { 
			if (mmap[y - 1][x - 1] == 'P' && mmap[y-1][x] != 'X' && mmap[y][x-1] != 'X') {
				return 0;
			}
			else if (mmap[y - 1][x + 1] == 'P' && mmap[y - 1][x] != 'X' && mmap[y][x + 1] != 'X') {
				return 0;
			}
			else if (mmap[y + 1][x - 1] == 'P' && mmap[y][x - 1] != 'X' && mmap[y + 1][x] != 'X') {
				return 0;
			}
			else if (mmap[y + 1][x + 1] == 'P' && mmap[y][x + 1] != 'X' && mmap[y + 1][x] != 'X') {
				return 0;
			}
		}
	}
	else if (c == 'O') {
		int cnt = 0;
		if (mmap[y - 1][x] == 'P') {
			cout << "5" << endl;
			cnt++;
		} 
		else if (mmap[y][x - 1] == 'P') {
			cout << "6" << endl;
			cnt++;
		} 
		else if (mmap[y][x + 1] == 'P') {
			cout << "7" << endl;
			cnt++;
		} 
		else if (mmap[y + 1][x] == 'P') {
			cout << "8" << endl;
			cnt++;
		} 
		if (cnt >= 2) {
			cout << "from here" << endl;
			return 0;
		}

	}
	// if c == 'X'
	else {

		if (mmap[y - 1][x] == 'P' && mmap[y][x - 1] == 'P' && mmap[y - 1][x - 1] != 'X'){
			cout << "9" << endl;
			return 0;
		}
		else if (mmap[y - 1][x] == 'P' && mmap[y][x + 1] == 'P' && mmap[y - 1][x + 1] != 'X'){
			cout << "10" << endl;
			return 0;
		}
		else if (mmap[y][x - 1] == 'P' && mmap[y + 1][x] == 'P' && mmap[y + 1][x - 1] != 'X'){
			cout << "11" << endl;
			return 0;
		}
		else if (mmap[y + 1][x] == 'P' && mmap[y][x + 1] == 'P' && mmap[y + 1][x + 1] != 'X'){
			cout << "12" << endl;
			return 0;
		}

	}
	//대각선
	if (mmap[y - 1][x - 1] == 'P' && mmap[y - 1][x + 1] == 'P' && mmap[y - 1][x] != 'X') {
		return 0;
	}
	else if (mmap[y - 1][x - 1] == 'P' && mmap[y + 1][x - 1] == 'P' && mmap[y][x - 1] != 'X') {
		return 0;
	}
	else if (mmap[y - 1][x + 1] == 'P' && mmap[y + 1][x + 1] == 'P' && mmap[y][x + 1] != 'X') {
		return 0;
	}
	else if (mmap[y + 1][x - 1] == 'P' && mmap[y + 1][x + 1] == 'P' && mmap[y + 1][x] != 'X') {
		return 0;
	}


	return 1;
}

vector<int> places(vector<vector<string>> places) {
	vector<int> answer;
	vector<string> mmap0;
	vector<string> mmap1;
	vector<string> mmap2;
	vector<string> mmap3;
	vector<string> mmap4;
	int size = 5;
	// 1은 거리두기 지키고 있는 것
	int mycheck[5] = { 1,1,1,1,1 };

	for (int i = 0; i < 5; i++) {
		mmap0.push_back(places[0][i]);
		mmap1.push_back(places[1][i]);
		mmap2.push_back(places[2][i]);
		mmap3.push_back(places[3][i]);
		mmap4.push_back(places[4][i]);
	}


	for (int y = 1; y <= 3; y++) {
		for (int x = 1; x <= 3; x++) {
			if (mycheck[0] == 1)
				mycheck[0] = check(mmap0[y][x], y, x, mmap0);
			if (mycheck[1] == 1)
				mycheck[1] = check(mmap1[y][x], y, x, mmap1);
			if (mycheck[2] == 1)
				mycheck[2] = check(mmap2[y][x], y, x, mmap2);
			if (mycheck[3] == 1)
				mycheck[3] = check(mmap3[y][x], y, x, mmap3);
			if (mycheck[4] == 1)
				mycheck[4] = check(mmap4[y][x], y, x, mmap4);
		}
	}

	for (int i = 0; i < 5; i++)
		answer.push_back(mycheck[i]);
	return answer;
}

int main() {
	vector<vector<string>> map = 
	{ 
		{"POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"},
		{"POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP"},
		{"PXOPX", "OXOXP", "OXPXX", "OXXXP", "POOXX"},
		{"OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"},
		{"PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"} 
	};

	vector<int> answer;
	answer = places(map);
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i];
		if (i != answer.size() - 1) cout << ", ";
	}

	return 0;
}