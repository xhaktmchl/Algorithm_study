#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level03 04번 O] 둘 다 참이면
문제:
접근: 
풀이: 
시간복잡도: O()=
*/
int a,b;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	cin >> a >> b;
	if (a == 7 && b == 9) {
		cout << "인증됨";
	}
	else { cout << "재시도"; }
    return 0;
}
