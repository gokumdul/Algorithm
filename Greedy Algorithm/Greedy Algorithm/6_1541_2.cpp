//int get_minVal() {
//	int tmp = 0, prevIdx = 0;
//
//	for (int i = 0; i < l; i++) {
//		if (s[i] == '+' || s[i] == '-' || i == l-1) {
//			tmp = stoi(s.substr(prevIdx, i));
//			prevIdx = i + 1;
//			
//			if (!minusFlag) {
//				answer += tmp;
//			}
//			else {
//				answer -= tmp;
//			}
//
//			if (s[i] == '-') {
//				minusFlag = true;
//			}
//			
//			tmp = 0;
//		}
//	}
//	return answer;
//}