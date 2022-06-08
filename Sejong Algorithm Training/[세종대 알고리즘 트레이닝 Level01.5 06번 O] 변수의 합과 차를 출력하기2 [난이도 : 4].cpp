#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level01.5 06번 O] 변수의 합과 차를 출력하기2 [난이도 : 4]
문제:
접근: 
풀이: 
시간복잡도: O()=
*/
int a = 40, b = 60, c = 10;
int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	int g = a + c;
	int h = b - c;
	cout << g << '\n' << h;
    return 0;
}
