#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level07 05번 O] 단순 채점 프로그램 [난이도 : 3]
문제:
접근: 
풀이: 
시간복잡도: O()=
*/
int n;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	cin >> n;
	if (n >= 80) { cout << "수"; }
	else if (n >= 70) { cout << "우"; }
	else if (n >= 60) { cout << "미"; }
	else { cout << "재시도"; }
    return 0;
}
