#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level04 12번 O] index값 입력받고 끝까지 출력
문제:
접근: 
풀이: 
시간복잡도: O()=
*/
int a[15] = { 5,25,54,2,-33,57,82,-8,13,1 };
int n;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	cin >> n;
	for (int i = n; i < 10; i++) {
		cout << a[i] << '\n';
	}
    return 0;
}
