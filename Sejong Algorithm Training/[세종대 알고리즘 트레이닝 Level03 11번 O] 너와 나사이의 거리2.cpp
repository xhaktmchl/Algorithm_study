#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level03 11번 O] 너와 나사이의 거리2
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
	for (int i = a; i <= b; i++) {
		cout << i;
	}
    return 0;
}
