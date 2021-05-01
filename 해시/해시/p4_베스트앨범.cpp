// 프로그래머스
// lvl3
// 베스트 앨범

// 풀이 1
// pair, tuple, make_pair, make_tuple
// get_pair_element  (using iterator -- For example, it->first)
// get_tuple_element (using get<idx_of_tuple_element>(which_tuple) -- For example, get<0>(m[i]))


/*
	두 개 이상의 인자를 할당하기 위해 tuple을 도입했고 tuple 타입의 벡터를 선언하였다.
	세 개의 인자를 지닌 tuple을 원하는 (오름차순/내림차순) 으로 sort 하기 위해서
	mycmp2 함수를 선언하였는데, 이를 구현하기가 굉장히 오래걸렸다.
	
	비교하는 두 값이 같은 경우에만 다음 인자의 비교를 선언해주면 되는 것이었는데
	나는 이 부분에서 해멨던 것!
	하지만 해결하였지!!!!!!
*/

#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>

#define my pair<string,int>
#define my2 tuple<string, int, int>

using namespace std;


// 재생 횟수 : 내림차순
// sort 정의
bool mycmp(const my& a, const my& b) {
	return a.second > b.second;
}

// 이름      : 오름차순
// 재생 횟수 : 내림차순
// 인덱스    : 오름차순 
// sort 정의
bool mycmp2(const my2& a, const my2& b) {
	if (get<0>(a) < get<0>(b)) {
		return true;
	}
	else if (get<0>(a) == get<0>(b)) {
		if (get<1>(a) > get<1>(b)) return true;
		else if (get<1>(a) == get<1>(b)) return get<2>(a) < get<2>(b);
		else return false;
	}
	else return false;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
	vector<int> answer;
	map<string, int> tmp;
	vector<tuple<string, int, int>> m;

	// 장르별 재생 횟수
	for (int i = 0; i < genres.size(); i++) {
		tmp[genres[i]] += plays[i];
	}

	// 재생 횟수 기준 sort 위한 벡터 생성
	vector<my> vec(tmp.begin(), tmp.end());

	// 재생 횟수 기준 내림차순 sort
	sort(vec.begin(), vec.end(), mycmp);

	/*for (auto it = vec.begin(); it != vec.end(); it++) {
		cout << it->first << " and " << it->second << endl;
 	}*/

	// 전체 장르별 재생횟수 m 벡터에 튜플로 저장
	for (int i = 0; i < genres.size(); i++) {
		m.push_back(make_tuple(genres[i], plays[i], i));
	}

	// [장르, 재생횟수, index] [오름차순, 내림차순, 오름차순]으로 정렬
	sort(m.begin(), m.end(), mycmp2);

	/*for (int i = 0; i < m.size(); i++) {
		cout << get<0>(m[i]) << " and " << get<1>(m[i]) 
			<< " and " << get<2>(m[i]) << endl;
	}*/

	// 노래 장르만큼 for문
	for (auto it = vec.begin(); it != vec.end(); it++) {
		int cnt = 0;
		for (int i = 0; i < m.size(); i++) {
			// vec의 장르와, m의 장르가 같은 경우
			if (it->first == get<0>(m[i])) {
				if (cnt < 2) {
					answer.push_back(get<2>(m[i]));
					cnt++;
				}
				else break;
			}
		}
	}
	return answer;
}

int main() {
	vector<int> answer;
	vector<string> genres = { "classic", "pop", "classic", "classic", "classic", "pop" };
	vector<int> plays = { 500, 600, 150, 500, 800, 2500 };

	answer = solution(genres, plays);

	cout << "answer size is: " << answer.size() << endl;
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << ", ";
	}

	return 0;
}