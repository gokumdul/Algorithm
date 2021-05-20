#include <string>
#include <vector>
#include <iostream>

using namespace std;

//n == 10011*110*0
//k 는 110 시작 지점
string make_smaller(string n, int k) {
	int kk = k;
	for (int i = 0; i < n.size() - 2; i++) {
		if (n[i] == '1' && n[i + 1] == '1' && n[i + 2] == '1') {
			if (i < k) {
				n[i + 2] = '0';
				n[k + 2] = '1';
				cout << "n: " << n << endl;
				return n;
			}
			else {
				if(n[k+2])
				for (int j = kk + 3; j < n.size() - 2; j++) {
					if (n[j] == 0) {
						n[kk] = '0';
						n[kk+1] = '1';
						n[kk+2] = '1';
						n[kk+3] = '0';
						kk = kk + 1;
					}
				}
			}
			//else break;
		}
	}
	return n;
}

vector<string> solution(vector<string> s) {
	vector<string> answer;
	bool flag = false;

	for (int i = 0; i < s.size(); i++) {
		for (int k = 0; k < s[i].size() - 2; k++) {
			if (s[i][k] == '1' && s[i][k + 1] == '1' && s[i][k + 2] == '0') {
				s[i] = make_smaller(s[i], k);
				if (flag) {
					answer.pop_back();
					answer.push_back(s[i]);
					flag = true;
				}
				else {
					answer.push_back(s[i]);
					flag = true;
				}
			}
		}
		if (flag == false) {
			answer.push_back(s[i]);
		}
		flag = false;
	}

	return answer;
}

int main() {
	vector<string> answer;
	vector<string> s = { "1110", "1000000", "000000","000", "110", "11000"};

	answer = solution(s);
	cout << "hello" << endl;
	for (int i = 0; i < answer.size(); i++) {
		cout << "answer[i]: " << answer[i] << endl;
	}


	return 0;
}