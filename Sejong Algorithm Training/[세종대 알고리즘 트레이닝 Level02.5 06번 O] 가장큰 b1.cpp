#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level02.5 06번 O] 가장큰 b1
문제:
접근: 
풀이: 
시간복잡도: O()=
*/
int b1,b2,b3,b4;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	cin >> b1 >> b2 >> b3 >> b4;
	if (b1 >= b2 && b1 >= b3 && b1 >= b4) {
		cout << "b1이 가장 크다";
	}
    return 0;
}
