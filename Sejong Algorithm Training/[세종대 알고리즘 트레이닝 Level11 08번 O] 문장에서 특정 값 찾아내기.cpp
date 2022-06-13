#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level11 08번 O] 문장에서 특정 값 찾아내기
문제:
접근: 
풀이: 
시간복잡도: O()=
*/
string str = "StructPointer";
char ch;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	cin >> ch;
	if (find(str.begin(), str.end(), ch) != str.end()) {
		cout << "발견";
	}
	else { cout << "미발견"; }
	return 0;
}
