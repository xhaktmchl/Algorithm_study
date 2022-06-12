#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level10 07번 O] 리턴값 비교하기 [난이도 : 3]
문제:
접근: 
풀이: 
시간복잡도: O()=
*/

int GOP() {
	int a, b;
	cin >> a >> b;
	return a * b;
}

int SUM() {
	int a, b;
	cin >> a >> b;
	return a + b;
}
int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	int g = GOP();
	int s = SUM();

	if (g > s) { cout << "GOP>SUM"; }
	else if (g < s) { cout << "GOP<SUM";}
	else { cout << "GOP==SUM"; }
	return 0;
}
