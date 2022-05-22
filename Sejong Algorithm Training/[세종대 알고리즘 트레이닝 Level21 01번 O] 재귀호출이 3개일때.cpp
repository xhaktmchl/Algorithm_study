#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level21 01번 O] 재귀호출이 3개일때
문제:
접근: 재귀
풀이:
	//1.재귀 (cnt몇 층)
	//1)기저조건: 만약 2 층이면 중단
	//2)재귀 3 개 cnt+1
시간복잡도: O()=
*/

//1.재귀 (cnt몇 층)
//1)기저조건: 만약 2 층이면 중단
//2)재귀 3 개 cnt+1
void re(int cnt) {
	if (cnt == 2) {
		return;
	}

	re(cnt + 1);
	re(cnt + 1);
	re(cnt + 1);
}

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	re(0);
	return 0;
}
