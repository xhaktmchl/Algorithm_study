#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level21 04번 O] 입력받은 Level까지 재귀함수 동작
문제:
접근: 재귀
풀이: 
	//1.입력: 레벨
	//2.재귀
	//출력: 현재 레벨
	//1) 기저조건: 만약 레벨이면 중단
	//2)재귀: cnt+1, 로 2번 씩
시간복잡도: O()=
*/
int level;

void re(int cnt) {
	cout << cnt;
	if (cnt == level) {
		return;
	}

	for (int i = 0; i < 2; i++) {
		re(cnt + 1);
	}
	return;
}

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	//1.입력: 레벨
	cin >> level;
	//2.재귀
	//출력: 현재 레벨
	//1) 기저조건: 만약 레벨이면 중단
	//2)재귀: cnt+1, 로 2번 씩
	re(0);
	return 0;
}
