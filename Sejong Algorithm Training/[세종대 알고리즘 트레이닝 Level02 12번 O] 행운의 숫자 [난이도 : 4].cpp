#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level02 12번 O] 행운의 숫자 [난이도 : 4]
문제:
접근: 
풀이: 
시간복잡도: O()=
*/
int a,c,b;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	cin >> a >> b >> c;
	if (a + b + c >= a * b * c) { cout << "행운의 수"; }
	else { cout << "소소한 수"; }
    return 0;
}
