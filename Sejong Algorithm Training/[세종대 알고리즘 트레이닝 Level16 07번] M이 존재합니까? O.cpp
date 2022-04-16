#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level16 07번] M이 존재합니까? O
문제: 
접근: 
풀이:
시간복잡도: O()
*/

string a[10];
bool flag = 0;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	
	// 1.입력
	for (int i = 0; i < 3; i++) {
		cin >> a[i];
	}
	// 2.각 문자열에서 M 탐색
	// 있으면 부울저장
	for (int i = 0; i < 3; i++) {
		if (find(a[i].begin(), a[i].end(), 'M') != a[i].end()) {
			flag = 1;
			break;
		}
		
	}
	// 3.출력
	if (flag) {
		cout << "M이 존재합니다" << '\n';
	}
	else { cout << "M이 존재하지 않습니다" << '\n'; }
	return 0;
}
