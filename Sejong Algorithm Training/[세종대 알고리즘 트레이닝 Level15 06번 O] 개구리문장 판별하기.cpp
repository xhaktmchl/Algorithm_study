#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level15 06번 O] 개구리문장 판별하기
문제:
접근: 
풀이: 
시간복잡도: O()=
*/
string str;
bool flag = 1;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	cin >> str;
	int len = str.size();
	for (int i = 0; i < len; i++) {
		if (i % 2 == 0) {
			if (str[i] < 'A' || str[i]>'Z') {
				flag = 0;
				break;
			}
		}
		else {
			if (str[i] < 'a' || str[i]>'z') {
				flag = 0;
				break;
			}
		}
	}

	if (flag == 1) { cout << "개구리문장"; }
	else { cout << "일반문장"; }
	return 0;
}
