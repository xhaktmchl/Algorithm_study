#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level15 05번 O] 문장의 길이를 정렬하기
문제:
접근: 
풀이: 
시간복잡도: O()=
*/
string str[5];
int len[5];

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	for (int i = 0; i < 4; i++) {
		cin >> str[i];
		len[i] = str[i].size();
	}

	sort(len, len + 4);
	for (int i = 0; i < 4; i++) {
		cout << len[i] << " ";
	}
	return 0;
}
