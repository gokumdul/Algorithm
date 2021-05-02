// 카카오 인턴십 2020

// 키패드 누르기
// lvl 1


#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(vector<int> numbers, string hand) {
	string answer = "";
	int leftHand = 10, rightHand = 12, leftDist = 0, rightDist = 0;
	
	for (int i = 0; i < numbers.size(); i++) {
		if (numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7) {
			answer += "L";
			leftHand = numbers[i];
		}
		else if (numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9) {
			answer += "R";
			rightHand = numbers[i];
		}
		else {
			if (numbers[i] == 0)
				numbers[i] = 11;
			int left_tmp = abs(numbers[i] - leftHand);
			int right_tmp = abs(numbers[i] - rightHand);

			leftDist = (left_tmp / 3) + (left_tmp % 3);
			rightDist = (right_tmp / 3) + (right_tmp % 3);

			if (leftDist < rightDist) {
				leftHand = numbers[i];
				answer += "L";
			}
			else if (leftDist > rightDist) {
				rightHand = numbers[i];
				answer += "R";
			}
			// leftDist == rightDist
			else {
				if (hand == "left") {
					leftHand = numbers[i];
					answer += "L";
				}
				else {
					rightHand = numbers[i];
					answer += "R";
				}
			}
		}
	}

	return answer;
}

int main() {
	vector<int> numbers = { 7, 0, 8, 2, 8, 3, 1, 5, 7, 6, 2 };
	string hand = "left";

	cout << solution(numbers, hand) << endl;

}